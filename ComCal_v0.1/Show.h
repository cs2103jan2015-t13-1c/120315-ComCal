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
	std::vector<Date> getDatesInWeek(Date specDate);

	//Arguments: 1)time Details of the week
	std::vector<Date> getWeeklyDates(struct tm*);

	//Arguments: 1) int year - years after 1900, month, day of the month, day of the week
	std::vector<Date> getWeeklyDates(int year, int month, int mday, int wday);

	Date getNextWeekDate(int year, int month, int mday, int wday);

	std::string prepShowFeedback(std::string feedback,int count);
	int countWhiteSpace(std::string argument);
	
public:
	Show();
	~Show();
	std::string execute(std::string argument);
};