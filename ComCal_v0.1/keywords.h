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

//Default file names constant string declarations:
const std::string FILENAME_TODODEFAULT = "ComCal_todo.txt";
const std::string FILENAME_DONEDEFAULT = "ComCal_done.txt";

//Default log file name constant string declarations:
const std::string FILENAME_LOGDEFAULT = "ActivityLog.txt";

//Number of file name arguments constant int declarations:
const int NOFILENAMEENTERED = 0;
const int TODOFILENAMEENTERED = 1;