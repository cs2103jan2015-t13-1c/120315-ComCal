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

	_isAllTodo = true;
	_isShowMonth = false;
	_isShowDayTaskSearch = false;

	_monthDetails = timeDateInfo::setStructTm();
}

//Have not initialised TextStorage
void ComCalManager::initialise(int numOfFiles, const char** fileNames) {

	std::string todoFileName;
	if (numOfFiles == NOFILENAMEENTERED) {
		todoFileName = FILENAME_TODODEFAULT;
	}
	else if (numOfFiles == TODOFILENAMEENTERED) {
		todoFileName = fileNames[0];
	}
	else {
		todoFileName = fileNames[0];
	}

	
	TextStorage::getInstance()->initialize(todoFileName);

	setDefaultSideBar();
}

ComCalManager::~ComCalManager() {
	delete _sideBarView;
}

std::string ComCalManager::deduceCommand(std::string userInput) {
	std::string feedBackMessage;

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
		feedBackMessage = command->execute(argument);
		delete command; // TODO Instead of deleting it, do something to it for future function implementations (eg undo/redo)
	}
	else {
		feedBackMessage = INVALID_COMMAND;
	}

	return feedBackMessage;
}

//Getter methods

ComCalManager* ComCalManager::getInstance() {
	if (_instance == NULL)
		_instance = new ComCalManager();
	return _instance;
}

std::vector<std::string>* ComCalManager::getSideVec() {
	return _sideBarView;
}

struct tm* ComCalManager::getMonthDetails() {
	return _monthDetails;
}

bool ComCalManager::getIsShowMonth() {
	return _isShowMonth;
}

bool ComCalManager::getIsShowDayTaskSearch() {
	return _isShowDayTaskSearch;
}

bool ComCalManager::getIsAllTodo(){
	return _isAllTodo;
}

std::string ComCalManager::getSideBarTitle(){
	return _sideBarTitle;
}



//Setter methods

void ComCalManager::setDefaultSideBar() {

	_sideBarTitle = ALL_TODO_TITLE;

	int todoSize = TextStorage::getInstance()->getTodoTask()->size();

	_sideBarView->clear();
	for (int i = 0; i < todoSize; i++) {
		if (!TextStorage::getInstance()->getTodoTask()->at(i)->getIsDone()) {

			_sideBarView->push_back(TextStorage::getInstance()->getTodoTask()->at(i)->toGUIString());
		}
	}
}

void ComCalManager::setIsShowMonth(bool isShowMonth) {
	_isShowMonth = isShowMonth;
}

void ComCalManager::setIsShowDayTaskSearch(bool isShowDayTaskSearch) {
	_isShowDayTaskSearch = isShowDayTaskSearch;
}

void ComCalManager::setIsAllTodo(bool isAllTodo){
	_isAllTodo = isAllTodo;
}

void ComCalManager::setMonthDetails(struct tm* monthDetails){
	_monthDetails = monthDetails;
}

void ComCalManager::setSideBarTitle(std::string sideBarTitle){
	_sideBarTitle = sideBarTitle;
}