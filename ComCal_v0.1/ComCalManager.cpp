#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include "ComCalManager.h"

// Global static pointer used to ensure a single instance of the class
ComCalManager* ComCalManager::_instance = NULL;

ComCalManager::ComCalManager(){
	_sideBarView = new std::vector<std::string>();
	_timeDetails = timeDateInfo::setStructTm();
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
		argument = userInput.substr(space + 1);
	}

	Command* command;

	if (function.compare(COMMAND_ADD) == 0) {
		command = new Add();
		feedBackMessage = command->execute(argument);
		if (feedBackMessage.substr(0, 5) == "Added") {
			_commandHistory.push(command);
			populateSideBar();
		}
	}
	else if (function.compare(COMMAND_DELETE) == 0) {
		command = new Delete();
		feedBackMessage = command->execute(argument);
		if (feedBackMessage.substr(0, 7) == "Task(s)") {
			_commandHistory.push(command);
			while (!_undoHistory.empty()) {
				_undoHistory.pop();
			}
			populateSideBar();
		}
	}
	else if (function.compare(COMMAND_EDIT) == 0) {
		command = new Edit();
		feedBackMessage = command->execute(argument);
		_commandHistory.push(command);
		populateSideBar();
	}
	else if (function.compare(COMMAND_LOAD) == 0) {
		command = new Load();
		feedBackMessage = command->execute(argument);
		populateSideBar();
	}
	else if (function.compare(COMMAND_REDO) == 0) {
		if (!_undoHistory.empty()) {
			command = _undoHistory.top();
			_commandHistory.push(command);
			_undoHistory.pop();
			feedBackMessage = command->redo();
			populateSideBar();
		}
		else {
			feedBackMessage = "Error: No previous undo actions to redo.";
		}
	}
	else if (function.compare(COMMAND_SAVE) == 0) {
		command = new Save();
		feedBackMessage = command->execute(argument);
		populateSideBar();
	}
	else if (function.compare(COMMAND_SEARCH) == 0) {
		command = new Search();
		feedBackMessage = command->execute(argument);
		populateSideBar();
	}
	else if (function.compare(COMMAND_SHOW) == 0) {
		command = new Show();
		feedBackMessage = command->execute(argument);
		populateSideBar();
	}
	else if (function.compare(COMMAND_UNDO) == 0) {
		if (!_commandHistory.empty()) {
			command = _commandHistory.top();
			_undoHistory.push(command);
			_commandHistory.pop();
			feedBackMessage = command->undo();
			populateSideBar();
		}
		else {
			feedBackMessage = "Error: No previous actions to undo.";
		}
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

struct tm* ComCalManager::getTimeDetails(){
	return _timeDetails;
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

void ComCalManager::setTimeDetails(struct tm* timeDetails){
	_timeDetails = timeDetails;
}