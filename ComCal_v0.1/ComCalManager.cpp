#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include "ComCalManager.h"
#include "Add.h"
#include "Delete.h"
#include "Edit.h"
#include "Redo.h"
#include "Search.h"
#include "Show.h"
#include "Undo.h"
#include "timeDateInfo.h"
#include "keywords.h"
#include "TextStorage.h"
#include "typeConversions.h"

// Global static pointer used to ensure a single instance of the class
ComCalManager* ComCalManager::_instance = NULL;

ComCalManager::ComCalManager(){
	_sideBarView = new std::vector<std::string>();

	isShowMonth = false;
	isShowDayTaskSearch = false;

	monthDetails = timeDateInfo::setStructTm();
}

//Have not initialised TextStorage
void ComCalManager::initialise(int numOfFiles, const char** fileNames) {

	std::string todoFileName;
	std::string doneFileName;
	if (numOfFiles == NOFILENAMEENTERED) {
		todoFileName = FILENAME_TODODEFAULT;
		doneFileName = FILENAME_DONEDEFAULT;
	}
	else if (numOfFiles == TODOFILENAMEENTERED) {
		todoFileName = fileNames[0];
		doneFileName = FILENAME_DONEDEFAULT;
	}
	else {
		todoFileName = fileNames[0];
		doneFileName = fileNames[1];
	}

	
	TextStorage::getInstance()->initialize(todoFileName, doneFileName);
}

ComCalManager::~ComCalManager() {
	delete _sideBarView;
}

ComCalManager* ComCalManager::getInstance() {
	if (_instance == NULL)
		_instance = new ComCalManager();
	return _instance;
}

System::String^ ComCalManager::deduceCommand(System::String^ userInputString) {
	System::String^ feedBackMessage;

	std::string userInput = typeConversions::convertStrTostr(userInputString);

	int space = userInput.find(" ");
	std::string function = typeConversions::toLowerCase(userInput.substr(0, space));
	std::string argument = userInput.substr(space + 1, userInput.length() - space - 1);

	Command* command = NULL;
	if (function.compare(COMMAND_ADD) == 0) {
		command = new Add();
	}
	else if (function.compare(COMMAND_DELETE) == 0) {
		command = new Delete();
	}
	else if (function.compare(COMMAND_EDIT) == 0) {
		command = new Edit();
	}
	else if (function.compare(COMMAND_UNDO) == 0) {
		command = new Undo();
	}
	else if (function.compare(COMMAND_REDO) == 0) {
		command = new Redo();
	}
	else if (function.compare(COMMAND_SEARCH) == 0) {
		command = new Search();
	}
	else if (function.compare(COMMAND_SHOW) == 0) {
		command = new Show();
	}

	if (command != NULL) {
		feedBackMessage = typeConversions::convertstrToStr(command->execute(argument));
		delete command; // TODO Instead of deleting it, do something to it for future function implementations (eg undo/redo)
	}
	else {
		feedBackMessage = typeConversions::convertstrToStr(INVALID_COMMAND);
	}

	return feedBackMessage;
}

void ComCalManager::setDefaultSideBar() {

	int todoSize = TextStorage::getInstance()->getTodoTask()->size();

	_sideBarView->clear();
	for (int i = 0; i < todoSize; i++) {
		_sideBarView->push_back(typeConversions::intToString(TextStorage::getInstance()->getTodoTask()->at(i)->getIndex())
			+ INDEX_DESCRIPTION_SEPARATOR
			+ TextStorage::getInstance()->getTodoTask()->at(i)->getDescription()
			+ NEWLINE);
	}
}

std::vector<std::string>* ComCalManager::getSideVec() {
	return _sideBarView;
}

struct tm* ComCalManager::getMonthDetails() {
	return monthDetails;
}

bool ComCalManager::getIsShowMonth() {
	return isShowMonth;
}

bool ComCalManager::getIsShowDayTaskSearch() {
	return isShowDayTaskSearch;
}