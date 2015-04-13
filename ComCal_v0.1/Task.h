//@author A0119754X
// Task.h
// Contains the class that stores information about tasks

#pragma once

#include "Date.h"
#include "keywords.h"
#include "typeConversions.h"

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
	bool isBetween(const Date &date); //checks if a date is between the start and end date inclusive
	int getTaskTypeCode();

	// Setter methods
	void setDescription(std::string description);
	void setLocation(std::string location);
	void setStartDate(Date*);
	void setEndDate(Date*);
	void hide();
	void display();
	void done();
	void undone();

	std::string toString();
	std::string toGUIString();
	std::string toCalString();
};