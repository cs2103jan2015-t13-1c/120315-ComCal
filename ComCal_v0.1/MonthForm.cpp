//@author A0110783L
#include <wchar.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include "MonthForm.h"
#include "timeDateInfo.h"
#include "typeConversions.h"
#include "TextStorage.h"
#include "ErrorLog.h"
#include "Exceptions.h"
#include "Date.h"
#include "HelpForm.h"

using namespace ComCal_v01;
using namespace System::Windows::Forms;

MonthForm::MonthForm(int argc, array<String^>^ argv)
{
	InitializeComponent();

	storeDateTextBlockInList();
	storeTasksTextBlockInList();

	const char** charFileNames = new const char*[argc];

	if (argc > 0) {
		MonthForm::convertArrStrToConststrArr(argv, charFileNames, argc);
	}

	ComCalManager::getInstance()->initialise(argc, charFileNames);
	TextStorage::getInstance()->displayMonthTasks(ALL_CODE,ComCalManager::getInstance()->getTimeDetails()->tm_year+1900,ComCalManager::getInstance()->getTimeDetails()->tm_mon + 1);
	ComCalManager::getInstance()->setSideBarTitle(timeDateInfo::getMonthStr(ComCalManager::getInstance()->getTimeDetails()->tm_mon) + " " + typeConversions::intToString(ComCalManager::getInstance()->getTimeDetails()->tm_year + 1900));
	_ctrlHeld = false;

	defaultView(nullptr, nullptr);
}

std::string MonthForm::convertStrTostr(System::String^ userInput) {
	std::string strInput;

	strInput = msclr::interop::marshal_as<std::string>(userInput);

	return strInput;
}

// Converts std::string into System::String^
System::String^ MonthForm::convertstrToStr(std::string userInput) {
	System::String^ strInput;

	strInput = msclr::interop::marshal_as<System::String^>(userInput);

	return strInput;
}

void MonthForm::convertArrStrToConststrArr(array<System::String^>^ fileNames, const char** strFilesNames, int numOfSpecifiedFiles) {

	msclr::interop::marshal_context^ context = gcnew msclr::interop::marshal_context();
	strFilesNames = new const char*[numOfSpecifiedFiles];
	for (int i = 0; i < numOfSpecifiedFiles; i++) {
		strFilesNames[i] = context->marshal_as<const char*>(fileNames[i]);

		context = nullptr;
	}

}

MonthForm::~MonthForm()
{
	TextStorage::getInstance()->saveTasks(FILENAME_TODODEFAULT);
	if (components)	{
		delete components;
	}
}

System::Void MonthForm::defaultView(System::Object^  sender, System::EventArgs^  e) {
	setCalendarDate_MonthForm(timeDateInfo::setStructTm());
	ComCalManager::getInstance()->populateSideBar();
	updateSideBar();
}

void MonthForm::guiUpdate() {
	updateSideBar();
	updateCalendar();
}

//@author A0119754X
System::Void MonthForm::userEnter(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	String^ feedBack;

	if (_ctrlHeld) {
		if (e->KeyCode == Keys::D) {
			setCalendarDate_MonthForm(timeDateInfo::setStructTm());
			guiUpdate();
			feedBackBox->Text = MonthForm::convertstrToStr("show reset");
			userInputBox->Text = nullptr;
		}
		else if (e->KeyCode == Keys::Z) {
			// Undo
			ComCalManager* managerInstance = ComCalManager::getInstance();
			feedBack = MonthForm::convertstrToStr(managerInstance->deduceCommand("undo"));
			guiUpdate();
			feedBackBox->Text = feedBack;
			managerInstance->resetCommandIndex();
			userInputBox->Text = nullptr;
		}
		else if (e->KeyCode == Keys::Y) {
			// Redo
			ComCalManager* managerInstance = ComCalManager::getInstance();
			feedBack = MonthForm::convertstrToStr(managerInstance->deduceCommand("redo"));
			guiUpdate();
			feedBackBox->Text = feedBack;
			managerInstance->resetCommandIndex();
			userInputBox->Text = nullptr;
		}
		_ctrlHeld = false;
	}
	else if (e->KeyCode == Keys::Enter) {

		if (userInputBox->Text == "help") {
			ComCal_v01::HelpForm^ helpForm = gcnew HelpForm();
			helpForm->ShowDialog();
			userInputBox->Text = nullptr;
		}
		else if (userInputBox->Text == "exit" || userInputBox->Text == "close") {
				Application::Exit();
		}
		else{
			ComCalManager* managerInstance = ComCalManager::getInstance();
			try {
				feedBack = MonthForm::convertstrToStr(managerInstance->deduceCommand(typeConversions::trimExtraSpaces(MonthForm::convertStrTostr(userInputBox->Text))));
			}
			catch (std::exception& exception) {
				feedBack = MonthForm::convertstrToStr(exception.what());
			}

			guiUpdate();
			feedBackBox->Text = feedBack;
			managerInstance->resetCommandIndex();
			userInputBox->Text = nullptr;
		}
	}
	else if (e->KeyCode == Keys::Up) {
		std::string str = ComCalManager::getInstance()->moveCommandIndexUp();
		userInputBox->Text = ((str.size() <= 0) ? nullptr : MonthForm::convertstrToStr(str));
	}
	else if (e->KeyCode == Keys::Down) {
		std::string str = ComCalManager::getInstance()->moveCommandIndexDown();
		userInputBox->Text = ((str.size() <= 0) ? nullptr : MonthForm::convertstrToStr(str));
	}
}

//@author A0110783L
System::Void MonthForm::ctrlHold(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::ControlKey) {
		_ctrlHeld = true;
	}
}

void ComCal_v01::MonthForm::setCalendarDate_MonthForm(struct tm* newtime) {
	String^ dateNum = "1";
	std::string monthTitleStr;

	newtime->tm_mday = 1;;
	mktime(newtime);

	//set the title
	monthFormTitle->Text = setMonthPageTitle(newtime);

	//set the calendar texts to nullptr
	for (int j = 0; j < NUM_BLOCKS_IN_CALENDAR; j++) {
		dateList[j]->Text = nullptr;
	}

	//sets remaining dates on the month grid
	for (int i = newtime->tm_wday; i < (newtime->tm_wday + timeDateInfo::getDaysInMonth(newtime->tm_mon, newtime->tm_year)); ++i) {
		dateList[i]->Text = dateNum;

		dateNum = incrementStringDate(dateNum, 1);
	}

	loadCalendarTodoTasks(newtime);
}

String^ MonthForm::incrementStringDate(String^ dateNum, int incrementSize) {
	std::string dateNumStr = MonthForm::convertStrTostr(dateNum);
	std::stringstream convert;
	int dateNumInt;

	convert << dateNumStr;
	convert >> dateNumInt;

	dateNumInt += incrementSize;
	dateNum = dateNumInt.ToString();

	return dateNum;
}

System::String^ ComCal_v01::MonthForm::setMonthPageTitle(struct tm* newtime) {
	int currentYear = newtime->tm_year + 1900;
	std::string yearStr;
	std::string title;

	std::stringstream convert;
	convert << currentYear;
	yearStr = convert.str();

	title += timeDateInfo::getMonthStr(newtime->tm_mon);
	title += " ";
	title += yearStr;

	System::String^ titleStr = gcnew System::String(title.c_str());

	return titleStr;
}

void ComCal_v01::MonthForm::updateCalendar() {
	setCalendarDate_MonthForm(ComCalManager::getInstance()->getTimeDetails());
}

int MonthForm::searchTaskMonth(struct tm* newtime) {
	int iter = -1;
	int desiredMnth = newtime->tm_mon + 1;
	int desiredYr = newtime->tm_year;

	Task* tempTask;
	while (iter++) {
		tempTask = TextStorage::getInstance()->getTask(iter);
		if (tempTask->getStartDate()->getMonth() == desiredMnth && tempTask->getStartDate()->getYear() == desiredYr) {
			break;
		}
		if (iter + 1 == TextStorage::getInstance()->getNumberOfTasks()) {
			break;
		}
	}
	
	return iter;
}

void ComCal_v01::MonthForm::loadCalendarTodoTasks(struct tm* newtime) {

	int todoSize = TextStorage::getInstance()->getNumberOfTasks();
	int monthRef = newtime->tm_mon + 1;
	int year = newtime->tm_year;
	std::string taskStr[NUM_BLOCKS_IN_CALENDAR];
	System::Collections::Generic::List<System::String^> taskStrList;

	for (int k = 0; k < NUM_BLOCKS_IN_CALENDAR; k++){
		taskStrList.Insert(k, nullptr);
	}

	if (todoSize > 0) {

		//to loop through taskList and dateList
		for (int i = newtime->tm_wday; i < (newtime->tm_wday + timeDateInfo::getDaysInMonth(newtime->tm_mon, newtime->tm_year)); ++i) {

			//to loop through todoVec
			for (int j = 0; j < todoSize; j++) {
				Task* tempTask = TextStorage::getInstance()->getTask(j);

				if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE) {
					if ((System::Int32::Parse(dateList[i]->Text) == tempTask->getEndDate()->getDay()) && (monthRef == tempTask->getEndDate()->getMonth()) && (year == tempTask->getEndDate()->getYear())) {
						taskStrList[i] = String::Concat(taskStrList[i], MonthForm::convertstrToStr(typeConversions::intToString(j + 1) + INDEX_DESCRIPTION_SEPARATOR + tempTask->toCalString()), Environment::NewLine);
					}
				}

				if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED) {
					
					if ((System::Int32::Parse(dateList[i]->Text) == tempTask->getStartDate()->getDay()) && (monthRef == tempTask->getStartDate()->getMonth()) && (year == tempTask->getStartDate()->getYear())) {
						taskStrList[i]= String::Concat(taskStrList[i], MonthForm::convertstrToStr(typeConversions::intToString(j + 1) + INDEX_DESCRIPTION_SEPARATOR + tempTask->toCalString()), Environment::NewLine);
					}
				}

				if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED) {
					Date * refDate = new Date(System::Int32::Parse(dateList[i]->Text), monthRef, year, 0000);

					if (tempTask->isBetween(*refDate)) {
						taskStrList[i] = String::Concat(taskStrList[i], MonthForm::convertstrToStr(typeConversions::intToString(j + 1) + INDEX_DESCRIPTION_SEPARATOR + tempTask->toCalString()), Environment::NewLine);
					}

					delete refDate;
					refDate = NULL;
				}//end of tasktypecode_timed

			}

		}
	}
	else {
		ErrorLog::inputErrorLog(NO_TASKS_IN_VECTOR);
	}

	//adds the tasks to the task lists in the calendar for viewing
	for (int k = 0; k < NUM_BLOCKS_IN_CALENDAR; k++) {
		taskList[k]->Text = nullptr;
		taskList[k]->Text = taskStrList[k];
	}
}

void ComCal_v01::MonthForm::updateSideBar() {
	sideBarTitle->Text = nullptr;
	sideBarTitle->Text = MonthForm::convertstrToStr(ComCalManager::getInstance()->getSideBarTitle());

	int numOfLines = ComCalManager::getInstance()->getSideVec()->size();
	std::string sideBarStr;
	std::vector<std::string>* sideVec = ComCalManager::getInstance()->getSideVec();
	sideBar->Text = nullptr;

	for (int i = 0; i < numOfLines; i++) {
		sideBar->Text = String::Concat(sideBar->Text, MonthForm::convertstrToStr(sideVec->at(i)), Environment::NewLine);
	}
}

void ComCal_v01::MonthForm::storeDateTextBlockInList() {
	int i = 0;

	dateList.Insert(i, dateBox11);
	dateList.Insert(++i, dateBox12);
	dateList.Insert(++i, dateBox13);
	dateList.Insert(++i, dateBox14);
	dateList.Insert(++i, dateBox15);
	dateList.Insert(++i, dateBox16);
	dateList.Insert(++i, dateBox17);

	dateList.Insert(++i, dateBox21);
	dateList.Insert(++i, dateBox22);
	dateList.Insert(++i, dateBox23);
	dateList.Insert(++i, dateBox24);
	dateList.Insert(++i, dateBox25);
	dateList.Insert(++i, dateBox26);
	dateList.Insert(++i, dateBox27);

	dateList.Insert(++i, dateBox31);
	dateList.Insert(++i, dateBox32);
	dateList.Insert(++i, dateBox33);
	dateList.Insert(++i, dateBox34);
	dateList.Insert(++i, dateBox35);
	dateList.Insert(++i, dateBox36);
	dateList.Insert(++i, dateBox37);

	dateList.Insert(++i, dateBox41);
	dateList.Insert(++i, dateBox42);
	dateList.Insert(++i, dateBox43);
	dateList.Insert(++i, dateBox44);
	dateList.Insert(++i, dateBox45);
	dateList.Insert(++i, dateBox46);
	dateList.Insert(++i, dateBox47);

	dateList.Insert(++i, dateBox51);
	dateList.Insert(++i, dateBox52);
	dateList.Insert(++i, dateBox53);
	dateList.Insert(++i, dateBox54);
	dateList.Insert(++i, dateBox55);
	dateList.Insert(++i, dateBox56);
	dateList.Insert(++i, dateBox57);

	dateList.Insert(++i, dateBox61);
	dateList.Insert(++i, dateBox62);
	dateList.Insert(++i, dateBox63);
	dateList.Insert(++i, dateBox64);
	dateList.Insert(++i, dateBox65);
	dateList.Insert(++i, dateBox66);
	dateList.Insert(++i, dateBox67);
}

void ComCal_v01::MonthForm::storeTasksTextBlockInList() {
	int i = 0;

	taskList.Insert(i, taskBox11);
	taskList.Insert(++i, taskBox12);
	taskList.Insert(++i, taskBox13);
	taskList.Insert(++i, taskBox14);
	taskList.Insert(++i, taskBox15);
	taskList.Insert(++i, taskBox16);
	taskList.Insert(++i, taskBox17);

	taskList.Insert(++i, taskBox21);
	taskList.Insert(++i, taskBox22);
	taskList.Insert(++i, taskBox23);
	taskList.Insert(++i, taskBox24);
	taskList.Insert(++i, taskBox25);
	taskList.Insert(++i, taskBox26);
	taskList.Insert(++i, taskBox27);

	taskList.Insert(++i, taskBox31);
	taskList.Insert(++i, taskBox32);
	taskList.Insert(++i, taskBox33);
	taskList.Insert(++i, taskBox34);
	taskList.Insert(++i, taskBox35);
	taskList.Insert(++i, taskBox36);
	taskList.Insert(++i, taskBox37);

	taskList.Insert(++i, taskBox41);
	taskList.Insert(++i, taskBox42);
	taskList.Insert(++i, taskBox43);
	taskList.Insert(++i, taskBox44);
	taskList.Insert(++i, taskBox45);
	taskList.Insert(++i, taskBox46);
	taskList.Insert(++i, taskBox47);

	taskList.Insert(++i, taskBox51);
	taskList.Insert(++i, taskBox52);
	taskList.Insert(++i, taskBox53);
	taskList.Insert(++i, taskBox54);
	taskList.Insert(++i, taskBox55);
	taskList.Insert(++i, taskBox56);
	taskList.Insert(++i, taskBox57);

	taskList.Insert(++i, taskBox61);
	taskList.Insert(++i, taskBox62);
	taskList.Insert(++i, taskBox63);
	taskList.Insert(++i, taskBox64);
	taskList.Insert(++i, taskBox65);
	taskList.Insert(++i, taskBox66);
	taskList.Insert(++i, taskBox67);
}