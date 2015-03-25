// Add.cpp
// Implementation of functions in the Add class
//@author A0119754X

#include "Add.h"
#include "Task.h"
#include "TextStorage.h"

std::string Add::execute(std::string argument) {
	int d = argument.find(".d");
	int s = argument.find(".s");
	int e = argument.find(".e");
	int l = argument.find(".l");

	// TODO Assuming the user enters all of .d, .s, .e and .l for now.
	// Have to correct this later on
	int index = 1;
	std::string description = argument.substr(d + 3, s - d - 4);
	std::string startDate = argument.substr(s + 3, e - s - 4);
	std::string endDate = argument.substr(e + 3, l - e - 4);
	std::string location = argument.substr(l + 3, argument.length() - l - 3);

	Task* newTask = new Task(index, description, location, new Date(startDate), new Date(endDate));
	TextStorage::getInstance()->getTodoTask()->push_back(newTask);
	// _todoTasks->push_back(newTask);
	// TODO Add newly created task into one of the vectors in TextStorage
	//return ("Added " + (*_todoTasks)[_todoTasks->size() - 1]->getDescription());

	std::string feedBackMessage = "Added " + TextStorage::getInstance()->getTodoTask()->at(TextStorage::getInstance()->getTodoTask()->size() - 1)->getDescription();

	return feedBackMessage;
}