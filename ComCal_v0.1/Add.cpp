// Add.cpp
// Implementation of functions in the Add class
//@author A0119754X

// TODO Have Date handle strings like "Tuesday", "Friday", "next Wednesday", "last Saturday", etc.
// TODO Implement "no end date, only end time" so that end date = start date
// TODO Make sure that end date > start date

#include "Add.h"
#include "Task.h"
#include "TextStorage.h"
#include "typeConversions.h"
#include "ComCalManager.h"

Add::Add() : Command() {
}

Add::~Add() {
}

bool Add::canFind(int index) {
	return ((index != std::string::npos) && (index != -1));
}

std::string Add::checkIfValid() {
	// Check if argument is valid
	if (!canFind(_l)) {
		return "Invalid add command: No location given";
	}
	if (!canFind(_s)) {
		_hasStartDate = false;
	}
	if (!canFind(_e)) {
		_hasEndDate = false;
	}
	if ((_hasStartDate) && (_d > _s)) {
		return "Invalid add command: Description should be given before start date/time";
	}
	if ((_hasEndDate) && (_d > _e)) {
		return "Invalid add command: Description should be given before end date/time";
	}
	if (_d > _l) {
		return "Invalid add command: Description should be given before location";
	}
	if ((_hasStartDate) && (_hasEndDate) && (_s > _e)) {
		return "Invalid add command: Start date/time should be given before end date/time";
	}
	if ((_hasStartDate) && (_s > _l)) {
		return "Invalid add command: Start date/time (" + typeConversions::intToString(_s) + ") should be given before location (" + typeConversions::intToString(_l) + ")";
	}
	if ((_hasEndDate) && (_e > _l)) {
		return "Invalid add command: End date/time should be given before location";
	}

	_isValid = true;
	return "";
}

void Add::findDSEL() {
	_d = _argument.find(".d");

	_s = _argument.find(".s");
	if (!canFind(_s)) {
		_s = _argument.find(" from ");
		if (canFind(_s)) {
			_usesFrom = true;
		}
		else {
			_s = _argument.find(" on ");
			if (canFind(_s)) {
				_usesOn = true;
			}
		}
	}

	_e = _argument.find(".e");
	if (!canFind(_e)) {
		_e = _argument.find(" to ");
		if (canFind(_e)) {
			_usesTo = true;
		}
		else {
			_e = _argument.find(" by ");
			if (canFind(_e)) {
			_usesBy = true;
			}
		}
	}

	_l = _argument.find(".l");
	if (!canFind(_l)) {
		_l = _argument.find(" in ");
		if (canFind(_l)) {
			_usesIn = true;
		}
	}
}

void Add::getFourParameters() {
	int position;
	int length;

	position = (canFind(_d) ? _d + 3 : 0);

	if (_hasStartDate) {
		length = _s - position - (((_usesFrom) || (_usesOn)) ? 0 : 1);
	}
	else if (_hasEndDate) {
		length = _e - position - (((_usesTo) || (_usesBy)) ? 0 : 1);
	}
	else {
		length = _l - position - (_usesIn ? 0 : 1);
	}

	_description = _argument.substr(position, length);

	if (_hasStartDate) {
		if (_usesFrom) {
			position = _s + 6;
		}
		else if (_usesOn) {
			position = _s + 4;
		}
		else {
			position = _s + 3;
		}

		if (_hasEndDate) {
			if ((_usesTo) || (_usesBy)) {
				length = _e - position;
			}
			else {
				length = _e - position - 1;
			}
		}
		else {
			if (_usesIn) {
				length = _l - position;
			}
			else {
				length = _l - position - 1;
			}
		}

		_startDate = _argument.substr(position, length);
	}

	if (_hasEndDate) {
		if ((_usesTo) || (_usesBy)) {
			position = _e + 4;
		}
		else {
			position = _e + 3;
		}
		if (_usesIn) {
			length = _l - position;
		}
		else {
			length = _l - position - 1;
		}
		_endDate = _argument.substr(position, length);
	}
	
	if (_usesIn) {
		position = _l + 4;
	}
	else {
		position = _l + 3;
	}
	length = _argument.length() - position;
	_location = _argument.substr(position, length);
}

std::string Add::execute(std::string argument) {
	// Delimiters used in the Add command:
	// 1) .d, _			(indicates description)
	// 2) .s, from, on	(indicates start date and time)
	// 3) .e, to, by	(indicates end date and time)
	// 4) .l, in		(indicates location)

	// Available add formats:
	// 1) All four delimiters in
	// 2) All four delimiters in, but there is no end date, only end time
	//    - End date will be set as the same as start date
	// 3) No start date and time
	// 4) No end date and time
	// 5) Neither start date and time nor end date and time

	// string::find() returns string::npos if no matches are found
	// string::substr() takes in position and length as arguments

	_argument = argument;

	_isValid = false;
	_usesFrom = false;
	_usesOn = false; // Used because all the delimiters are of length 2,
	_usesTo = false; // other than _ for description which is 0,
	_usesBy = false; // "on", "to", "by", "in", which is 4,
	_usesIn = false; // "from", which is 6
	_hasStartDate = true;
	_hasEndDate = true;

	_description = "";
	_startDate = "";
	_endDate = "";
	_location = "";

	findDSEL();

	std::string errorMessage = checkIfValid();
	if (!_isValid)
		return errorMessage;

	getFourParameters();

	Date* objStartDate = NULL;
	Date* objEndDate = NULL;
	if (_hasStartDate) {
		objStartDate = new Date();
		if (!objStartDate->setDate(_startDate)) {
			delete objStartDate;
			return "Invalid add command: Invalid start date and time format";
		}
	}
	if (_hasEndDate) {
		objEndDate = new Date();
		if (!objEndDate->setDate(_endDate)) {
			delete objEndDate;
			return "Invalid add command: Invalid end date and time format";
		}
	}
	Task* newTask = new Task(_description, _location, objStartDate, objEndDate);
	TextStorage::getInstance()->addTask(newTask);
	_taskIndex = TextStorage::getInstance()->getNumberOfTasks();

	return ("Added " + newTask->toString());
}

//@author A0085731A
std::string Add::undo() {
	std::string feedback;

	TextStorage::getInstance()->deleteTask(_taskIndex);

	feedback = "Task (" + typeConversions::intToString(_taskIndex) + ") deleted.";

	return feedback;
}

std::string Add::redo() {
	Date* startDate = new Date;
	startDate->setDate(_startDate);
	Date* endDate = new Date;
	endDate->setDate(_endDate);

	Task* newTask = new Task(_description, _location, startDate, endDate);

	TextStorage::getInstance()->addTask(newTask);

	return ("Added " + newTask->toString());
}