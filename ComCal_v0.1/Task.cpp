// Task.cpp
// Implementation of functions in the Task class
//@author A0119754X

#include "Task.h"

Task::Task() {
	_description = "";
	_location = "";
	_startDate = NULL;
	_endDate = NULL;
	_isDone = false;
	_isHidden = false;
	_taskTypeCode = TASKTYPECODE_FLOATING;
}

Task::Task(std::string description, std::string location, int startDay, int startMonth, int startYear, int startTime, int endDay, int endMonth, int endYear, int endTime) {
	_description = description;
	_location = location;
	_startDate = new Date(startDay, startMonth, startYear, startTime);
	_endDate = new Date(endDay, endMonth, endYear, endTime);
	_isDone = false;
	_isHidden = false;
	if (_startDate != NULL&&_endDate != NULL) {
		_taskTypeCode = TASKTYPECODE_TIMED;
	}
	else if (_startDate != NULL && _endDate == NULL) {
		_taskTypeCode = TASKTYPECODE_PARTIALTIMED;
	}
	else if (_startDate == NULL && _endDate != NULL) {
		_taskTypeCode = TASKTYPECODE_DEADLINE;
	}
	else {
		_taskTypeCode = TASKTYPECODE_FLOATING;
	}
}

Task::Task(std::string description, std::string location, Date* startDate, Date* endDate) {
	_description = description;
	_location = location;
	_startDate = startDate;
	_endDate = endDate;
	_isDone = false;
	_isHidden = false;
	if (_startDate != NULL&&_endDate != NULL) {
		_taskTypeCode = TASKTYPECODE_TIMED;
	}
	else if (_startDate != NULL && _endDate == NULL) {
		_taskTypeCode = TASKTYPECODE_PARTIALTIMED;
	}
	else if (_startDate == NULL && _endDate != NULL) {
		_taskTypeCode = TASKTYPECODE_DEADLINE;
	}
	else {
		_taskTypeCode = TASKTYPECODE_FLOATING;
	}
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

void Task::setDescription(std::string description) {
	_description = description;
}

void Task::setLocation(std::string location) {
	_location = location;
}

void Task::setStartDate(Date* startDate) {
	_startDate = startDate;

	if (_endDate == NULL) {
		_taskTypeCode = TASKTYPECODE_PARTIALTIMED;
	}
	else {
		_taskTypeCode = TASKTYPECODE_TIMED;
	}
}

void Task::setEndDate(Date* endDate) {
	_endDate = endDate;

	if (_startDate == NULL) {
		_taskTypeCode = TASKTYPECODE_DEADLINE;
	}
	else {
		_taskTypeCode = TASKTYPECODE_TIMED;
	}
}

void Task::hide() {
	_isHidden = true;
}

void Task::display() {
	_isHidden = false;
}

int Task::getTaskTypeCode() {
	return _taskTypeCode;
}

// Gets the string of this task to be shown in the feedback box
std::string Task::toString() {
	std::string returnString = "";
	switch (_taskTypeCode) {
	case TASKTYPECODE_FLOATING:
		returnString += TASKTYPECODE_FLOATING;
		break;
	case TASKTYPECODE_DEADLINE:
		returnString += TASKTYPE_DEADLINE;
		break;
	case TASKTYPECODE_PARTIALTIMED:
		returnString += TASKTYPE_PARTIALTIMED;
		break;
	case TASKTYPECODE_TIMED:
		returnString += TASKTYPE_TIMED;
		break;
	} 
		
<<<<<<< HEAD
	returnString += " task - " + DESCRIPTION + ": \"" + _description + "\"";

	if (hasStartDate()) {
		returnString += "; " + STARTDATETIME + ": " + _startDate->toString();
	}

	if (hasEndDate()) {
		returnString += "; " + ENDDATETIME + ": " + _endDate->toString();
	}
	
	if (_location != "") {
		returnString += "; " + LOCATION + ": \"" + _location + "\"";
	}
=======
	returnString += " task - " + toGUIString();
>>>>>>> 38bc7baea9468b564006ea9d36b6e0c333516bd4

	return returnString;
}

// Gets the string of this task to be rendered in GUI elements, ie. calendar, sidebar, etc.
std::string Task::toGUIString() {
	std::string returnString = DESCRIPTION + ": \"" + _description + "\"; ";
	
	if (hasStartDate()) {
		returnString += STARTDATETIME + ": " + _startDate->toString() + "; ";
	}

	if (hasEndDate()) {
		returnString += ENDDATETIME + ": " + _endDate->toString() + "; ";
	}

<<<<<<< HEAD
	if (_location != "") {
		returnString += LOCATION + ": \"" + _location + "\"";
=======
	if (_location.size() > 0) {
		returnString += LOCATION + ": " + _location;
>>>>>>> 38bc7baea9468b564006ea9d36b6e0c333516bd4
	}

	return returnString;
}