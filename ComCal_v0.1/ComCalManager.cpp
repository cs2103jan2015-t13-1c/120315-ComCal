#include "ComCalManager.h"
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>

#include "keywords.h"
#include "typeConversions.h"
#include "TextStorage.h"
#include "Add.h"

//Have not initialised TextStorage
ComCalManager::ComCalManager(int numOfFiles, const char** fileNames) {
	_sideBarView = new std::vector<std::string>();

	isShowMonth = false;
	isShowDayTaskSearch = false;

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

std::vector<std::string>* ComCalManager::getSideVec(){
	return _sideBarView;
}

struct tm* ComCalManager::getMonthDetails(){
	return monthDetails;
}

System::String^ ComCalManager::deduceCommand(System::String^ userInputString) {
	System::String^ feedBackMessage;

	std::string userInput = typeConversions::convertStrTostr(userInputString);

	int space = userInput.find(" ");
	std::string function = typeConversions::toLowerCase(userInput.substr(0, space));
	std::string argument = userInput.substr(space + 1, userInput.length() - space - 1);

	Command* command;
	if (function.compare("add") == 0) {
		command = new Add();
		feedBackMessage = typeConversions::convertstrToStr(command->execute(argument));
		delete command; // TODO Instead of deleting it, do something to it for future function implementations (eg undo/redo)
	}

	return feedBackMessage;
}