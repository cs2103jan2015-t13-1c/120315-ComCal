// Task.h
// Contains the class that stores information about tasks
//@author A0119754X

#pragma once

#include <string>
#include "Date.h"

class Task {
private:
	std::string _description;
	std::string _location;
	Date* _startDate;			// Could be null, as some tasks do not have a start date and time
	Date* _endDate;				// Could be null, as some tasks do not have a end date and time
	bool _isDone;
	bool _isHidden;				// If true, won't display in sidebar. To be manipulated with Show and Search
public:
	Task();
	Task(std::string description, std::string location, int startDay, int startMonth, int startYear, int startTime, int endDay, int endMonth, int endYear, int endTime);
	Task(std::string description, std::string location, Date* startDate, Date* endDate);
	~Task();

	// Getter methods
	std::string getDescription();
	std::string getLocation();
	Date* getStartDate();
	Date* getEndDate();
	bool getIsDone();
	bool hasStartDate();
	bool hasEndDate();
	bool isHidden();

	// Setter methods
	void hide();
	void display();

	std::string toString();
	std::string toGUIString();
};