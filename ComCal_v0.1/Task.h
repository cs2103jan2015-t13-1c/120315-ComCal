// Task.h
// Contains the class that stores information about tasks
//@author A0119754X

#pragma once

#include <string>
#include "Date.h"

class Task {
private:
	int _index;
	std::string _description;
	std::string _location;
	Date* _startDate;
	Date* _endDate;
	bool _isDone;
public:
	Task();
	Task(int index, std::string description, std::string location, int startDay, int startMonth, int startYear, int startTime, int endDay, int endMonth, int endYear, int endTime);
	Task(int index, std::string description, std::string location, Date* startDate, Date* endDate);
	~Task();

	int getIndex();
	std::string getDescription();
	Date* getStartDate();
	bool isDone();

	std::string toString();
};