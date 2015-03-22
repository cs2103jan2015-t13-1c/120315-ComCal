#include "MonthForm.h"
#include "keywords.h"
#include "typeConversions.h"
#include "timeDateInfo.h"
#include <wchar.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>

using namespace ComCal_v01;
using namespace System;
using namespace System::Windows::Forms;

MonthForm::MonthForm(int argc, array<String^>^ argv)
{
	InitializeComponent();
	
	storeDateTextBlockInList();
	storeTasksTextBlockInList();

	const char** charFileNames = new const char*[argc];

	if (argc > 0){
		typeConversions::convertArrStrToConststrArr(argv, charFileNames, argc);
	}

	_manager = new ComCalManager(argc, charFileNames);
	_ctrlHeld = false;

	defaultView(nullptr, nullptr);
}


System::Void MonthForm::defaultView(System::Object^  sender, System::EventArgs^  e) {
	setCalendarDate_MonthForm(timeDateInfo::setStructTm());
}

bool MonthForm::isShowSearchFlagged(){
	bool flagged = false;

	if (_manager->isShowDayTaskSearch || _manager->isShowMonth){
		flagged = true;
	}

	return flagged;
}

void MonthForm::guiUpdate(){

	try{
		if (_manager->isShowDayTaskSearch){
			updateSideBar();
		}
		else{
			if (_manager->isShowMonth){

			}
			else{
				throw GUI_UPDATE_ERROR;
			}
		}	
	}
	catch (std::string errorMsg){
		ErrorLog::inputErrorLog(errorMsg);
	}
}

System::Void MonthForm::userEnter(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	String^ feedBack;

	if (e->KeyCode == Keys::Enter){
		if (userInputBox->Text == "exit" || userInputBox->Text == "close"){
			Application::Exit();
		}
		else{
			feedBack = _manager->deduceCommand(userInputBox->Text);

			if (isShowSearchFlagged()){
				guiUpdate();
			}
			
			userInputBox->Text = nullptr;
		}
	}

	if (e->KeyCode == Keys::D){
		if (_ctrlHeld == true){
			setCalendarDate_MonthForm(timeDateInfo::setStructTm());

			_ctrlHeld = false;
		}
	}
}

System::Void MonthForm::ctrlHold(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	 _ctrlHeld = false;

	if (e->KeyCode == Keys::Control){
		_ctrlHeld = true;
	}
}

void ComCal_v01::MonthForm::setCalendarDate_MonthForm(struct tm* newtime){
	String^ dateNum = "1";
	std::string monthTitleStr;
	int daysInMonth[MONTHS_IN_YEAR] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	newtime->tm_mday = 1;;
	mktime(newtime);

	//set the title
	monthFormTitle->Text = setMonthPageTitle(newtime);

	//February has 29 days during a leap year
	if ((newtime->tm_mon == 1) && timeDateInfo::isLeapYear(newtime->tm_year + 1900)){
		daysInMonth[1] = 29;
	}

	//sets remaining dates on the month grid
	for (int i = newtime->tm_wday; i < (newtime->tm_wday + daysInMonth[newtime->tm_mon]); ++i){
		dateList[i]->Text = dateNum;

		dateNum = incrementStringDate(dateNum, 1);
	}

}

String^ MonthForm::incrementStringDate(String^ dateNum, int incrementSize){
	std::string dateNumStr = typeConversions::convertStrTostr(dateNum);
	std::stringstream convert;
	int dateNumInt;

	convert << dateNumStr;
	convert >> dateNumInt;

	dateNumInt += incrementSize;
	dateNum = dateNumInt.ToString();

	return dateNum;
}

System::String^ ComCal_v01::MonthForm::setMonthPageTitle(struct tm* newtime){
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

void ComCal_v01::MonthForm::updateCalendar(){

}

void ComCal_v01::MonthForm::loadCalendarTodoTasks(){

}

void ComCal_v01::MonthForm::updateSideBar(){
	int numOfLines = _manager->getSideVec()->size();
	std::string sideBarStr;
	std::vector<Task*>* sideVec = new std::vector<Task*>();

	sideBar->Text = nullptr;
	sideVec = _manager->getSideVec();

	for (int i = 0; i < numOfLines; i++){
		sideBarStr += typeConversions::convertTaskToStr(sideVec->at(i)) + NEWLINE;
	}

	delete sideVec;

	sideBar->Text = typeConversions::convertstrToStr(sideBarStr);
}


void ComCal_v01::MonthForm::storeDateTextBlockInList(){
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
}

void ComCal_v01::MonthForm::storeTasksTextBlockInList(){
	int i = 0;

	taskList.Insert(i, taskBox11);
	taskList.Insert(++i, taskBox12);
	taskList.Insert(++i, taskBox13);
	taskList.Insert(++i, taskBox14);
	taskList.Insert(++i, taskBox15);
	taskList.Insert(++i, taskBox16);
	taskList.Insert(++i, dateBox17);

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
}