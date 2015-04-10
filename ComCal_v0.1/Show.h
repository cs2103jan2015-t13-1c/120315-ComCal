// Show.h
// Subclass of Command; implements the show function
//@author A011954X

#pragma once

#include "Command.h"
#include "Date.h"
#include "TextStorage.h"
#include "ComCalManager.h"
#include "timeDateInfo.h"
#include "keywords.h"
#include "typeConversions.h"

class Show : public Command {
	
private:
	int getMonthInput(std::string argument);
	//2 overloaded functions of getDatesInWeek
	//Purpose: To return a vector of dates that corresponds to the week depending on which overload is used
	//Arguments: None
	//Returns: dates within the week of the current time
	std::vector<Date> getDatesInWeek();
	//Arguments: Date corresponding to the date specified by used
	//Returns:: Dates within the week that contains the argument
	std::vector<Date> getDatesInWeek(Date* specDate);

	std::vector<Date> getWeeklyDates(struct tm*);
public:
	Show();
	~Show();
	std::string execute(std::string argument);
};