#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include "ComCalManager.h"
#include "Add.h"
#include "Delete.h"
#include "Edit.h"
#include "Load.h"
#include "Redo.h"
#include "Save.h"
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
}

ComCalManager::~ComCalManager() {
	delete _sideBarView;
}

std::string ComCalManager::deduceCommand(std::string userInput) {
	std::string feedBackMessage;

	int space = userInput.find(" ");
	std::string function = typeConversions::toLowerCase(userInput);
	std::string argument = "";

	if ((space != std::string::npos) && (space != -1)) {
		function = function.substr(0, space);
	}
	if ((space != std::string::npos) && (space != -1)) {
		argument = userInput.substr(space + 1, userInput.length() - space - 1);
	}

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
	else if (function.compare(COMMAND_LOAD) == 0) {
		command = new Load();
	}
	else if (function.compare(COMMAND_REDO) == 0) {
		command = new Redo();
	}
	else if (function.compare(COMMAND_SAVE) == 0) {
		command = new Save();
	}
	else if (function.compare(COMMAND_SEARCH) == 0) {
		command = new Search();
	}
	else if (function.compare(COMMAND_SHOW) == 0) {
		command = new Show();
	}
	else if (function.compare(COMMAND_UNDO) == 0) {
		command = new Undo();
	}

	if (command != NULL) {
		feedBackMessage = command->execute(argument);
		delete command; // TODO Instead of deleting it, do something to it for future function implementations (eg undo/redo)
		populateSideBar();
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
std::string ComCalManager::getSideBarTitle(){
	return _sideBarTitle;
}

void ComCalManager::populateSideBar() {

	_sideBarTitle = ALL_TODO_TITLE;

	int todoSize = TextStorage::getInstance()->getNumberOfTasks();

	_sideBarView->clear();
	Task* tempTask;
	for (int i = 0; i < todoSize; i++) {
		tempTask = TextStorage::getInstance()->getTask(i);
		if (!tempTask->isHidden()) {
			_sideBarView->push_back(typeConversions::intToString(i + 1) + INDEX_DESCRIPTION_SEPARATOR + tempTask->toGUIString());
		}
	}
}

void ComCalManager::setSideBarTitle(std::string sideBarTitle){
	_sideBarTitle = sideBarTitle;
}