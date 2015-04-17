//@author A0119754X
// Task.cpp
// Implementation of functions in the Task class

#include "Task.h"
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

void Task::done() {
	_isDone = true;
}

void Task::undone() {
	_isDone = false;
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

//@author A0110783L
bool Task::isBetween(const Date &date) {
	bool isBetween = false;

	if (_startDate->operator<=(date) && _endDate->operator>=(date)) {
		isBetween = true;
	}
	
	return isBetween;
}

//@author A0119754X
void Task::setDescription(std::string description) {
	_description = description;
}

void Task::setLocation(std::string location) {
	_location = location;
}

void Task::setStartDate(Date* startDate) {
	_startDate = startDate;
}

void Task::setEndDate(Date* endDate) {
	_endDate = endDate;

}

void Task::hide() {
	_isHidden = true;
}

void Task::display() {
	_isHidden = false;
}

//@author A0085731A
int Task::getTaskTypeCode() {
	if ((_startDate == NULL) && (_endDate == NULL)) {
		return TASKTYPECODE_FLOATING;
	}
	if (_startDate == NULL) {
		return TASKTYPECODE_DEADLINE;
	}
	if (_endDate == NULL) {
		return TASKTYPECODE_PARTIALTIMED;
	}
	return TASKTYPECODE_TIMED;
}

// Gets the string of this task to be shown in the feedback box
std::string Task::toString() {
	std::string returnString = "";
	switch (getTaskTypeCode()) {
	case TASKTYPECODE_FLOATING:
		returnString += TASKTYPE_FLOATING;
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

	return returnString;
}

//@author A0110783L
// Gets the string of this task to be rendered in GUI elements, ie. sidebar, etc.
std::string Task::toGUIString() {
	std::string returnString = " task - " + DESCRIPTION + ": \"" + _description + "\"";

	if (hasStartDate()) {
		returnString += "; " + STARTDATETIME + ": " + _startDate->toString();
	}

	if (hasEndDate()) {
		returnString += "; " + ENDDATETIME + ": " + _endDate->toString();
	}

	if (_location != "") {
		returnString += "; " + LOCATION + ": \"" + _location + "\"";
	}

	return returnString;
}

//@author A0119754X
// Gets the string of this task to be rendered in calendar
std::string Task::toCalString() {
	if (_description.size() <= 9) {
		return _description;
	}
	return (_description.substr(0, 8) + "...");
}