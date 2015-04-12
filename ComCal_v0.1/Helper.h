#include <string>
#include <vector>

const std::string INPUTHELP_1 = "User commands: add; edit; delete; done; undone; undo; redo; search";
const std::string INPUTHELP_2 = "Time Input: \"HHMM\" E.g.: \"0830\" represents 8:30 AM; \"1600\" represents 4:00 PM";
const std::string INPUTHELP_3 = "Date Input: \"DD/MM/YYYY\" E.g.: \"31/04/2015\" represents 31 April 2015; \"01/05/2015\" represents 1 May 2015";
const std::string INPUTHELP_4 = "Acceptable Day Input: monday, tuesday, wednesday, thursday, friday, saturday, sunday, today, tomorrow, yesterday";

const std::string INPUTHELP_5 = "Token Format:";
const std::string INPUTHELP_6 = "TOKENS meaning: .d - <Descripton> , .s - <start date & time> , .e - <end date & time> , .l - <location>";
const std::string INPUTHELP_7 = "These tokens are used to specify the relevant information information of the task";
const std::string INPUTHELP_8 = " '.s' & 'from' are interchangeable(<->) , '.e' <-> 'to' , '.l' <-> 'at'";

const std::string INPUTHELP_9 = "Add Command Format: The only necessary attribute is <description>, the rest are optional";
const std::string INPUTHELP_10 = "\"add .d <task description> .s <start date/day> <start time> .e <end date/day> <end time> .l <location>\"";
const std::string INPUTHELP_11 = "e.g.: add .d SampleTask .s 14/04/2015 1000 .e 29/06/2016 1100 .l school";
const std::string INPUTHELP_12 = "The token .d is unnecessary for adding but will be used in the edit command";

const std::string INPUTHELP_13 = "Edit Command Format: Only the token(s) you would like to change need to be specified";
const std::string INPUTHELP_14 = "To edit, simply specify the index of the task, type a token, followed by the content you would like to change it to";
const std::string INPUTHELP_15 = "edit <index> .d <new description> .s <new start date and/or time> .e <new end date and/or time> .l <new location>";
const std::string INPUTHELP_16 = "eg. edit 26 .d Going to school .s 13/04/2015 1600 .e 3/04/2015 1800";

const std::string INPUTHELP_17 = "Show Command Format:";
const std::string INPUTHELP_18 = "show <date/day> , show <date/day> <todo/done> , show <date/day> <floating/timed/partial/deadline> , show <floating/timed/partial/deadline>";
const std::string INPUTHELP_19 = "show <week> , show <week> <specified date in week> , show <week> <todo/done> , show <week> <date/day> <todo/done>";
const std::string INPUTHELP_20 = "show <month> , show <month> <year> , show <month> <year> <todo/done> , show <next> <week/month> , show <todo/done>";

const std::string INPUTHELP_21 = "Delete/Done/Undon Command Format: Delete/Done/Undone using index seen on the left on the task";
const std::string INPUTHELP_22 = "delete <index> eg. delete 4 , delete <multiple> eg. delete 1 4 2 8 , delete <all>";
const std::string INPUTHELP_23 = "done/undone <index> eg. done/undone 2 , done/undone <multiple> eg. done/undone 2 3 5 1 , done <all> eg. done/undone all";
const std::string INPUTHELP_24 = "Search <word>";

namespace helper {
	std::vector<std::string> getHelp();
}