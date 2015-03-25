#pragma once
#include <string>

//Command strings that a user can input
static const std::string COMMAND_ADD = "add";
static const std::string COMMAND_DELETE = "delete";
static const std::string COMMAND_EDIT = "edit";
static const std::string COMMAND_UNDO = "undo";
static const std::string COMMAND_REDO = "redo";
static const std::string COMMAND_SEARCH = "search";
static const std::string COMMAND_SHOW = "show";

// Strings for date input
static const std::string DATE_YESTERDAY = "yesterday";
static const std::string DATE_TODAY = "today";
static const std::string DATE_TOMORROW = "tomorrow";
static const std::string DATE_MONDAY = "Monday";
static const std::string DATE_TUESDAY = "Tuesday";
static const std::string DATE_WEDNESDAY = "Wednesday";
static const std::string DATE_THURSDAY = "Thursday";
static const std::string DATE_FRIDAY = "Friday";
static const std::string DATE_SATURDAY = "Saturday";
static const std::string DATE_SUNDAY = "Sunday";

//Default file names constant string declarations:
const std::string FILENAME_TODODEFAULT = "ComCal_todo.txt";
const std::string FILENAME_DONEDEFAULT = "ComCal_done.txt";

//Default log file name constant string declarations:
const std::string FILENAME_LOGDEFAULT = "ErrorLog.txt";

//Number of file name arguments constant int declarations:
const int NOFILENAMEENTERED = 0;
const int TODOFILENAMEENTERED = 1;

//Time and date info
const static int MAX_ASCTIME_S = 26;
const static int DAYS_IN_WEEK = 7;
const static int MONTHS_IN_YEAR = 12;
const static int MAX_DAYS_IN_MONTH = 31;

//keyboard shortcuts
const static std::string NEWLINE = "\n";
const static std::string INDEX_DESCRIPTION_SEPARATOR = ". ";

//Input error messages here
const std::string GET_MONTH_STR_ERROR = "Integer passed outside the boundaries of 0 and 11\n";
const std::string GUI_UPDATE_ERROR = "isShowMonth and/or isShowDayTaskSearch was not flagged\n";
const std::string NO_TASKS_IN_VECTOR = "No tasks contained in _todoTask vector\n";
const std::string INVALID_COMMAND = "This is not a valid command\n";
