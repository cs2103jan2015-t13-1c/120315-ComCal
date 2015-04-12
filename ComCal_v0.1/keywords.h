#pragma once
#include <string>

//Command strings that a user can input
static const std::string COMMAND_ADD = "add";
static const std::string COMMAND_DELETE = "delete";
static const std::string COMMAND_EDIT = "edit";
static const std::string COMMAND_LOAD = "load";
static const std::string COMMAND_REDO = "redo";
static const std::string COMMAND_SAVE = "save";
static const std::string COMMAND_SEARCH = "search";
static const std::string COMMAND_SHOW = "show";
static const std::string COMMAND_UNDO = "undo";
static const std::string COMMAND_DONE = "done";
static const std::string COMMAND_UNDONE = "undone";

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
static const std::string DATE_WEEK = "week";
static const std::string DATE_MONTH = "month";
static const std::string DATE_LAST = "last";
static const std::string DATE_NEXT = "next";
static const std::string WEEK = "week";

// Strings for possible user inputs
static const std::string INPUT_TODO = "todo";
static const int TODO_CODE = 1;
static const std::string INPUT_DONE = "done";
static const int DONE_CODE = 2;
static const std::string INPUT_TIMED = "timed";
static const std::string DEADLINED_TASK = "deadline";
static const std::string FLOATING_TASKS = "floating";
static const std::string INPUT_PARTIAL = "partial";
static const std::string ALL_TASKS = "all";
static const int ALL_CODE = 3;

//Attribute keywords constant string and index int declarations:
static const int ATTRIBUTEKEYWORDSARRAYSIZE = 4;
static const std::string ATTRIBUTEKEYWORDSARRAY[ATTRIBUTEKEYWORDSARRAYSIZE] = { " .d ", " .s ", " .e ", " .l " };
static const int INDEX_DESCRIPTION = 0;
static const int INDEX_STARTDATETIME = 1;
static const int INDEX_ENDDATETIME = 2;
static const int INDEX_LOCATION = 3;

//Attributes for toCalString
static const int CAL_DESC_LIMIT = 10;
static const int CAL_CHAR_LIMIT = 14;
static const std::string CAL_WHITE_SPACE = "  ";

//Delete before certain date/time command keywords:
static const int BEFOREKEYWORDSARRAYSIZE = 2;
static const std::string BEFOREKEYWORDSARRAY[BEFOREKEYWORDSARRAYSIZE] = { ".b ", "before " };
static const std::string ALLKEYWORD = "all";

//Integer string:
static const std::string INTS = "0123456789";

//Attribute constant string declarations:
static const std::string DESCRIPTION = "[D]";
static const std::string STARTDATETIME = "[S]";
static const std::string STARTDATE = "[S-D]";
static const std::string STARTTIME = "[S-T]";
static const std::string ENDDATETIME = "[E]";
static const std::string ENDDATE = "[E-D]";
static const std::string ENDTIME = "[E-T]";
static const std::string DEADLINE = "[DL]";
static const std::string DEADLINEDATE = "[DL-D]";
static const std::string DEADLINETIME = "[DL-T]";
static const std::string LOCATION = "[L]";

//Search-related constant declarations:
static const int SEARCHCONDITIONKEYWORDSARRAYSIZE = 3;
static const std::string SEARCHCONDITIONKEYWORDSARRAY[SEARCHCONDITIONKEYWORDSARRAYSIZE] = { " and ", " or ", " not " };
static const int INDEX_AND = 0;
static const int INDEX_OR = 1;
static const int INDEX_NOT = 2;
static const int INDEX_WILDCARD = -1;
static const std::string SEARCHDATETIMERANGESTART = "from ";
static const std::string SEARCHDATETIMERANGEEND = " to ";
static const std::string AND = "AND";
static const std::string OR = "OR";
static const std::string NOT = "EXCLUDING";

//Task type constant declarations:
static const int TASKTYPECODE_FLOATING = 1;
static const int TASKTYPECODE_DEADLINE = 2;
static const int TASKTYPECODE_PARTIALTIMED = 3;
static const int TASKTYPECODE_TIMED = 4;
static const std::string TASKTYPE_FLOATING = "FLOATING";
static const std::string TASKTYPE_PARTIALTIMED = "PARTIAL-TIMED";
static const std::string TASKTYPE_TIMED = "TIMED";

//Task type constant string declarations:
static const std::string TASKTYPE_EVENT = "EVENT";
static const std::string TASKTYPE_DEADLINE = "DEADLINE";
static const std::string TASKTYPE_TODO = "TO-DO";
static const std::string TASKS = "Tasks";

//Default file names constant string declarations:
static const std::string FILENAME_TODODEFAULT = "ComCal_todo.xml";

//Default log file name constant string declarations:
static const std::string FILENAME_LOGDEFAULT = "ErrorLog.txt";

//Number of file name arguments constant int declarations:
static const int NOFILENAMEENTERED = 0;
static const int TODOFILENAMEENTERED = 1;

//Time and date info
static const int MAX_ASCTIME_S = 26;
static const int DAYS_IN_WEEK = 7;
static const int MONTHS_IN_YEAR = 12;
static const int MAX_DAYS_IN_MONTH = 31;
static const int NUM_BLOCKS_IN_CALENDAR = 42;
static const int SECONDS_IN_DAY = 24 * 60 * 60;
static const int SECONDS_IN_WEEK = 7 * SECONDS_IN_DAY;

//keyboard shortcuts
static const std::string NEWLINE = " \n";
static const std::string INDEX_DESCRIPTION_SEPARATOR = ") ";
static const std::string SHOW_COUNT_START = "(Show count: ";
static const std::string SHOW_COUNT_END = ")";

//SideBar titles
static const std::string ALL_TODO_TITLE = "All Todo Tasks";
static const std::string ALL_DONE_TITLE = "All Done Tasks";
static const std::string SEARCH_RESULTS_TITLE = "Search Results";
static const std::string TODAY_TASKS_TITLE = "Today's Tasks";
static const std::string ALL_TASKS_TITLE = "All tasks";

static const std::string ALL_TASKS_WITH_DEADLINE_TITLE = "Deadlined Tasks\n";
static const std::string ALL_TODO_TASKS_WITH_DEADLINE_TITLE = "Todo Deadlined Tasks";
static const std::string ALL_DONE_TASKS_WITH_DEADLINE_TITLE = "Done Deadlined Tasks";

static const std::string ALL_FLOATING_TASKS_TITLE = "Floating Tasks";
static const std::string ALL_TODO_FLOATING_TASKS_TITLE = "Todo Floating Tasks";
static const std::string ALL_DONE_FLOATING_TASKS_TITLE = "Done Floating Tasks";

static const std::string ALL_PARTIAL_TASKS_TITLE = "Partial-timed Tasks";
static const std::string ALL_TODO_PARTIAL_TASKS_TITLE = "Todo Partial-timed Tasks";
static const std::string ALL_DONE_PARTIAL_TASKS_TITLE = "Done Partial-timed Tasks";

static const std::string ALL_TIMED_TASKS_TITLE = "Timed Tasks";
static const std::string ALL_TODO_TIMED_TASKS_TITLE = "Todo Timed Tasks";
static const std::string ALL_DONE_TIMED_TASKS_TITLE = "Done Timed Tasks";

static const std::string THIS_WEEK_ALL_TASK = "This Week's Task";
static const std::string THIS_WEEK_TODO_TASK_TITLE = "This Week's Todo Task";
static const std::string THIS_WEEK_DONE_TASK_TITLE = "This Week's Done Task";

static const std::string NEXT_WEEK_TITLE = "Next Week's Tasks";
static const std::string NEXT_MONTH_TITLE = "Next Month's Tasks";

static const std::string DATED_TODO_TASKS = " Todo Tasks";
static const std::string DATED_DONE_TASKS = " Done Tasks";

//Feedbacks
static const std::string ALL_TASKS_FEEDBACK = "All tasks shown in sideBar";
static const std::string ALL_TODO_FEEDBACK = "All todo tasks shown in sideBar";
static const std::string ALL_DONE_FEEDBACK = "All done tasks shown in sideBar";
static const std::string SHOW_TODAY_FEEDBACK = "All tasks today shown in sideBar";
static const std::string ZERO_SHOW_RESULTS = "There are zero show results";
static const std::string CURRENT_MONTH_TASKS = "All current month tasks in sideBar and calendar";

static const std::string ALL_DEADLINED_FEEDBACK = "All tasks with deadlines in sideBar";
static const std::string ALL_TODO_DEADLINED_FEEDBACK = "All todo tasks with deadlines in sideBar";
static const std::string ALL_DONE_DEADLINED_FEEDBACK = "All done tasks with deadlines in sideBar";

static const std::string ALL_PARTIAL_FEEDBACK = "All partial-timed tasks in sideBar";
static const std::string ALL_TODO_PARTIAL_FEEDBACK = "All todo partial-timed tasks in sideBar";
static const std::string ALL_DONE_PARTIAL_FEEDBACK = "All done partial-timed tasks in sideBar";

static const std::string ALL_FLOATING_TASKS_FEEDBACK = "All floating tasks in sideBar";
static const std::string ALL_TODO_FLOATING_TASKS_FEEDBACK = "All todo floating tasks in sideBar";
static const std::string ALL_DONE_FLOATING_TASKS_FEEDBACK = "All done floating tasks in sideBar";

static const std::string ALL_TIMED_TASKS_FEEDBACK = "All timed tasks in sideBar";
static const std::string ALL_TODO_TIMED_TASKS_FEEDBACK = "All todo timed tasks in sideBar";
static const std::string ALL_DONE_TIMED_TASKS_FEEDBACK = "All done timed tasks in sideBar";

static const std::string NEXT_MONTH_TASKS_FEEDBACK = "Next month's tasks shown in sideBar";
static const std::string NEXT_WEEK_TASKS_FEEDBACK = "Next week's tasks shown in sideBar";
static const std::string THIS_WEEK_TASKS_FEEDBACK = "This week's tasks shown in sideBar";
static const std::string THIS_WEEK_TODO_TASKS_FEEDBACK = "This week's todo tasks shown in sideBar";
static const std::string THIS_WEEK_DONE_TASKS_FEEDBACK = "This week's done tasks shown in sideBar";

//Input error messages here
static const std::string GET_MONTH_STR_ERROR = "Integer passed outside the boundaries of 0 and 11\n";
static const std::string TODO_DONE_INPUT_ERROR = "Invalid todo/done input: Please input either 'todo' or 'done'";
static const std::string GUI_UPDATE_ERROR = "isShowMonth and/or isShowDayTaskSearch was not flagged\n";
static const std::string NO_TASKS_IN_VECTOR = "No tasks contained in _todoTask vector\n";
static const std::string INVALID_COMMAND = "This is not a valid command\n";
static const std::string INVALID_MONTH_INPUT = "Invalid month input";
static const std::string INVALID_SHOW_INPUT = "Input arguments invalid for show command";
static const std::string INVALID_DATE_INPUT = "Invalid date input. Proper format: 'dd/mm/yy' , 'today', 'yesterday' , 'tomorrow' , 'monday' , tuesday' etc.";
static const std::string INVALID_NEXT_INPUT = "Please input in the format 'next month' or 'next week'";
static const std::string INVALID_YEAR_ERROR = "Please input a year above 1900";
static const std::string INVALID_WEEK_INPUT = "Please input in the format: 'show week' or 'show week todo' or 'show week done' or 'show next week' or 'show week DD/MM/YYYY' or 'show week monday/tuesday/etc'";
