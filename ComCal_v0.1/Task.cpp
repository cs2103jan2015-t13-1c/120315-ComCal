#include "Task.h"

Task::Task(){

}

Task::Task(int index, std::string description, std::string location, int startDay, int startMonth, int startYear, int startTime, int endDay, int endMonth, int endYear, int endTime) {
	_index = index;
	_description = description;
	_location = location;
	_startDate = new Date(startDay, startMonth, startYear, startTime);
	_endDate = new Date(endDay, endMonth, endYear, endTime);
}

Task::Task(int index, std::string description, std::string location, Date* startDate, Date* endDate) {
	_index = index;
	_description = description;
	_location = location;
	_startDate = startDate;
	_endDate = endDate;
}

Task::~Task() {
	if (_startDate != NULL) {
		delete _startDate;
	}

	if (_endDate != NULL) {
		delete _endDate;
	}
}

int Task::getIndex(){
	return _index;
}

std::string Task::getDescription() {
	return _description;
}

// Converts the Task object into a String to save into text file
std::string Task::toString() {
	return (_description + "\n" + _location + "\n" + _startDate->toString() + "\n" + _endDate->toString());
}