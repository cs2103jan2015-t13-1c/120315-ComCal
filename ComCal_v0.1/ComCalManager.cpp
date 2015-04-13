//@author A0110783L

#include "ComCalManager.h"
#include "Add.h"
#include "Delete.h"
#include "Edit.h"
#include "Load.h"
#include "Save.h"
#include "Search.h"
#include "Show.h"
#include "timeDateInfo.h"
#include "keywords.h"
#include "TextStorage.h"
#include "Done.h"
#include "Undone.h"

#include <string>
#include <vector>


// Global static pointer used to ensure a single instance of the class
ComCalManager* ComCalManager::_instance = NULL;

ComCalManager::ComCalManager(){
	_commandIndex = 0;
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

//@author A0119754X
std::string ComCalManager::deduceCommand(std::string userInput) {
	_commands.push_back(userInput);
	resetCommandIndex();
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
		_commandHistory.push(command);
		populateSideBar();
		while (!_undoHistory.empty()) {
			_undoHistory.pop();
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
		while (!_commandHistory.empty()) {
			_commandHistory.pop();
		}
		while (!_undoHistory.empty()) {
			_undoHistory.pop();
		}
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
	else if (function.compare(COMMAND_DONE) == 0) {
		command = new Done();
		feedBackMessage = command->execute(argument);
		populateSideBar();
	}
	else if (function.compare(COMMAND_UNDONE) == 0) {
		command = new Undone();
		feedBackMessage = command->execute(argument);
		populateSideBar();
	}
	else {
		feedBackMessage = INVALID_COMMAND;
	}

	return feedBackMessage;
}

//@author A0110783L
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
	int todoSize = TextStorage::getInstance()->getNumberOfTasks();

	_sideBarView->clear();
	Task* tempTask;
	Date* startDate;
	Date* endDate;
	std::string location;
	for (int i = 0; i < todoSize; i++) {
		tempTask = TextStorage::getInstance()->getTask(i);
		if (!tempTask->isHidden()) {
			_sideBarView->push_back(std::to_string(i+1) + INDEX_DESCRIPTION_SEPARATOR + "Desc: " + tempTask->getDescription() + " [" + (tempTask->getIsDone() ? "done" : "todo") + "]");

			if (tempTask->hasStartDate()) {
				startDate = tempTask->getStartDate();
				if (tempTask->hasEndDate()) { // Has both start date and end date
					endDate = tempTask->getEndDate();
					_sideBarView->push_back("    Time: " + startDate->toString()  + " to " + endDate->toString());
				}
				else { // Has only start date
					_sideBarView->push_back("    Time: " + startDate->toString());
				}
			}
			else if (tempTask->hasEndDate()) { // Has only end date
				endDate = tempTask->getEndDate();
				_sideBarView->push_back("    Time: by " + endDate->toString());
			}

			location = tempTask->getLocation();
			if (location.size() > 0) {
				_sideBarView->push_back("    Loc: " + location);
			}

			_sideBarView->push_back("");
		}
	}
}

void ComCalManager::setSideBarTitle(std::string sideBarTitle) {
	_sideBarTitle = sideBarTitle;
}

void ComCalManager::resetCommandIndex() {
	_commandIndex = _commands.size();
}

std::string ComCalManager::moveCommandIndexUp() {
	_commandIndex--;
	if (_commandIndex < 0) {
		_commandIndex = 0;
	}
	if (_commands.size() <= 0) {
		return "";
	}
	return _commands[_commandIndex];
}

std::string ComCalManager::moveCommandIndexDown() {
	_commandIndex++;
	int size = _commands.size();
	if (_commandIndex >= size) {
		_commandIndex = size;
		return "";
	}
	return _commands[_commandIndex];
}