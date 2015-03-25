// Add.cpp
// Implementation of functions in the Add class
//@author A0119754X

// TODO Command will interpret the "to" in "today" as the delimiter for end date/time. Please fix.

#include "Add.h"
#include "Task.h"
#include "TextStorage.h"
#include "typeConversions.h"

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

	bool usesFrom = false; // Used because all the delimiters are of length 2,
						// other than _ for description which is 0,
						// and from for start date and time, which is 4

	int d = argument.find(".d");
	int s = argument.find(".s");
	if (s == std::string::npos) {
		s = argument.find("from");
		usesFrom = true;
	}
	if (s == std::string::npos) {
		s = argument.find("on");
	}
	int e = argument.find(".e");
	if (e == std::string::npos) {
		e = argument.find("to");
	}
	if (e == std::string::npos) {
		e = argument.find("by");
	}
	int l = argument.find(".l");
	if (l == std::string::npos) {
		l = argument.find("in");
	}

	// Check if argument is valid
	bool hasStartDate = true;
	bool hasEndDate = true;
	if (l == std::string::npos) {
		return "Invalid add command: No location given";
	}
	if (s == std::string::npos) {
		hasStartDate = false;
	}
	if (e == std::string::npos) {
		hasEndDate = false;
	}
	if ((hasStartDate) && (d > s)) {
		return "Invalid add command: Description should be given before start date/time";
	}
	if ((hasEndDate) && (d > e)) {
		return "Invalid add command: Description should be given before end date/time";
	}
	if (d > l) {
		return "Invalid add command: Description should be given before location";
	}
	if ((hasStartDate) && (s > e)) {
		return "Invalid add command: Start date/time should be given before end date/time";
	}
	if ((hasStartDate) && (s > l)) {
		return "Invalid add command: Start date/time (" + typeConversions::intToString(s) + ") should be given before location (" + typeConversions::intToString(l) + ")";
	}
	if ((hasEndDate) && (e > l)) {
		return "Invalid add command: End date/time should be given before location";
	}

	std::string description;
	std::string startDate;
	std::string endDate;
	std::string location;
	int position;
	int length;

	if (d == std::string::npos) {
		position = 0;
	}
	else {
		position = d + 3;
	}

	if (hasStartDate) {
		length = s - position - 1;
	}
	else if (hasEndDate) {
		length = e - position - 1;
	}
	else {
		length = l - position - 1;
	}

	description = argument.substr(position, length);

	if (hasStartDate) {
		if (usesFrom) {
			position = s + 5;
		}
		else {
			position = s + 3;
		}

		if (hasEndDate) {
			length = e - position - 1;
		}
		else {
			length = l - position - 1;
		}

		startDate = argument.substr(position, length);
	}

	if (hasEndDate) {
		position = e + 3;
		length = l - position - 1;
		endDate = argument.substr(position, length);
	}

	position = l + 3;
	length = argument.length() - position;
	location = argument.substr(position, length);

	// TODO Make sure the two strings for dates are valid
	// TODO Make sure Date can handle whatever string arguments you give it
	// TODO Implement "no end date, only end time" so that end date = start date

	Date* objStartDate = NULL;
	Date* objEndDate = NULL;
	if (hasStartDate) {
		objStartDate = new Date();
		if (!objStartDate->setDate(startDate)) {
			delete objStartDate;
			return "Invalid add command: Invalid start date and time format";
		}
	}
	if (hasEndDate) {
		objEndDate = new Date();
		if (!objEndDate->setDate(endDate)) {
			delete objEndDate;
			return "Invalid add command: Invalid end date and time format";
		}
	}
	Task* newTask = new Task(description, location, objStartDate, objEndDate);
	TextStorage::getInstance()->getTodoTask()->push_back(newTask);

	return ("Added " + newTask->toString());
}