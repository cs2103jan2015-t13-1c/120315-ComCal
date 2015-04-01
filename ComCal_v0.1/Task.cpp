// Task.cpp
// Implementation of functions in the Task class
//@author A0119754X

#include "Task.h"
#include "keywords.h"
#include "typeConversions.h"

Task::Task() {
	_description = "";
	_location = "";
	_startDate = NULL;
	_endDate = NULL;
	_isDone = false;
	_isHidden = false;
}

Task::Task(std::string description, std::string location, int startDay, int startMonth, int startYear, int startTime, int endDay, int endMonth, int endYear, int endTime) {
	_description = description;
	_location = location;
	_startDate = new Date(startDay, startMonth, startYear, startTime);
	_endDate = new Date(endDay, endMonth, endYear, endTime);
	_isDone = false;
	_isHidden = false;
}

Task::Task(std::string description, std::string location, Date* startDate, Date* endDate) {
	_description = description;
	_location = location;
	_startDate = startDate;
	_endDate = endDate;
	_isDone = false;
	_isHidden = false;
}

Task::~Task() {
	if (_startDate != NULL) {
		delete _startDate;
	}

	if (_endDate != NULL) {
		delete _endDate;
	}
}

Date* Task::getStartDate() {
	return _startDate;
}

Date* Task::getEndDate() {
	return _endDate;
}

std::string Task::getDescription() {
	return _description;
}

std::string Task::getLocation() {
	return _location;
}

bool Task::getIsDone() {
	return _isDone;
}

bool Task::hasStartDate() {
	return !(_startDate == NULL);
}

bool Task::hasEndDate() {
	return !(_endDate == NULL);
}

bool Task::isHidden() {
	return _isHidden;
}

void Task::hide() {
	_isHidden = true;
}

void Task::display() {
	_isHidden = false;
}

// Converts the Task object into a String to save into text file
std::string Task::toString() {
	std::string returnString =  _description + " " + _location + " ";
	if (hasStartDate()) {
		returnString += _startDate->toString() + " ";
	}
	if (hasEndDate()) {
		returnString += _endDate->toString();
	}
	return returnString;
}

// Converts Task object into a string for GUI
std::string Task::toGUIString() {
	std::string returnString = _description + " " + _location + " ";
	if (hasStartDate()) {
		returnString += _startDate->toString() + " ";
	}
	if (hasEndDate()) {
		returnString += _endDate->toString();
	}
	return returnString;
}