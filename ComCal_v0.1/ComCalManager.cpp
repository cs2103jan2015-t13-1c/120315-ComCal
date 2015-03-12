#include "ComCalManager.h"
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>

#include "keywords.h"
#include "typeConversions.h"

//Have not initialised TextStorage
ComCalManager::ComCalManager(int numOfFiles, const char** fileNames) {
	_todoTasks = new std::vector<Task*>();
	_doneTasks = new std::vector<Task*>();

	if (numOfFiles == NOFILENAMEENTERED) {
		_todoFileName = FILENAME_TODODEFAULT;
		_doneFileName = FILENAME_DONEDEFAULT;
	}
	else if (numOfFiles == TODOFILENAMEENTERED) {
		_todoFileName = fileNames[0];
		_doneFileName = FILENAME_DONEDEFAULT;
	}
	else {
		_todoFileName = fileNames[0];
		_doneFileName = fileNames[1];
	}
}

ComCalManager::~ComCalManager() {
	delete _todoTasks;
	delete _doneTasks;
}

System::String^ ComCalManager::deduceCommand(System::String^ userInputString) {
	System::String^ feedBackMessage;

	std::string userInput = typeConversions::convertStrTostr(userInputString);

	int space = userInput.find(" ");
	std::string function = typeConversions::toLowerCase(userInput.substr(0, space));
	std::string argument = userInput.substr(space + 1, userInput.length() - space - 1);

	if (function.compare("add") == 0) {
		feedBackMessage = typeConversions::convertstrToStr(addMainCom(argument));
	}

	return feedBackMessage;
}

//I have a feeling this will be taken out
void ComCalManager::saveTasks(std::string fileName) {
	std::ofstream outputFile(fileName);
	int size = _todoTasks->size();
	
	if (outputFile.is_open()) {
		outputFile << size << std::endl;
		for (int i = 0; i < size; i++) {
			outputFile << (*_todoTasks)[i]->toString() << std::endl;
		}
		outputFile.close();
	}
}

//Should be taken out as well
void ComCalManager::loadTasks(std::string fileName) {
	std::string numberOfTasks;
	std::string task[10];

	_todoTasks->clear();

	std::ifstream inputFile(fileName);
	if (inputFile.is_open()) {
		getline(inputFile, numberOfTasks);
		int n = typeConversions::stringToInt(numberOfTasks);

		for (int x = 0; x < n; x++) {
			for (int i = 0; i < 10; i++) {
				getline(inputFile, task[i]);
			}
			_todoTasks->push_back(new Task(task[0],
									   task[1],
									   typeConversions::stringToInt(task[2]),
									   typeConversions::stringToInt(task[3]),
									   typeConversions::stringToInt(task[4]),
									   typeConversions::stringToInt(task[5]),
									   typeConversions::stringToInt(task[6]),
									   typeConversions::stringToInt(task[7]),
									   typeConversions::stringToInt(task[8]),
									   typeConversions::stringToInt(task[9])));
		}
		inputFile.close();
	}
}

std::string ComCalManager::addMainCom(std::string argument) {

	int d = argument.find(".d");
	int s = argument.find(".s");
	int e = argument.find(".e");
	int l = argument.find(".l");

	// TODO Assuming the user enters all of .d, .s, .e and .l for now.
	// Have to correct this later on
	std::string description = argument.substr(d + 3, s - d - 4);
	std::string startDate = argument.substr(s + 3, e - s - 4);
	std::string endDate = argument.substr(e + 3, l - e - 4);
	std::string location = argument.substr(l + 3, argument.length() - l - 3);

	Task* newTask = new Task(description, location, new Date(startDate), new Date(endDate));
	_todoTasks->push_back(newTask);

	return ("Added " + (*_todoTasks)[_todoTasks->size() - 1]->getDescription());
}

std::string ComCalManager::showMainCom(std::string) {
	return "";
}

std::string ComCalManager::deleteMainCom(std::string) {
	return "";
}

std::string ComCalManager::editMainCom(std::string) {
	return "";
}

std::string ComCalManager::undoMainCom(std::string) {
	return "";
}

std::string ComCalManager::redoMainCom(std::string) {
	return "";
}

std::string ComCalManager::searchMainCom(std::string) {
	return "";
}

bool ComCalManager::isAddFormatValid(std::string) {
	return true;
}

bool ComCalManager::isShowFormatValid(std::string) {
	return true;
}

bool ComCalManager::isDeleteFormatValid(std::string) {
	return true;
}

bool ComCalManager::isEditFormatValid(std::string) {
	return true;
}
