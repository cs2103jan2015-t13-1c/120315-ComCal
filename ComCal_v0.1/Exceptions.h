//@author A0085731A

#pragma once

#include <string>
#include <exception>

//Help message constant string declarations:
const std::string LINESPACING_SINGLE = "";
const std::string LINESPACING_DOUBLE = "";

//Help sheets constant string declarations:
const std::string INPUTHELP_COMMAND = "Commands: add; edit; del; done; undone; undo; redo; search. For input help on each command, pls enter \"help <command>\" - e.g. \"help add\"shows input help for add command.";
const std::string INPUTHELP_TIME = "Time Input: \"HHMM\" E.g.: \"0830\" represents 8:30 AM; \"1600\" represents 4:00 PM";
const std::string INPUTHELP_DATE = "Date Input: \"DD/MM/YYYY\" E.g.: \"31/04/14\" represents 31 April 2014; \"01/05/2014\" represents 1 May 2014";
const std::string INPUTHELP_DATETIMEADDEDIT = "Date/Day Inputs: 1. \"DD/MM/YYYY\": Specific date e.g. \"31/04/2014\" represents 31 April 2014; 2. \"yesterday\": Yesterday; 3. \"today\": Today; 4. \"tomorrow\": Tomorrow; 5. \"this <day>\": This coming occurence of the specified day e.g. \"this Wednesday\" represents this coming Wednesday; 6. \"next <day>\": Next occurrence of the specified day e.g. \"next Friday\" represents the Friday after this coming Friday; 7. \"last <day>\": Previous occurrence of the specified day e.g. \"last Sunday\" represents the Sunday that just passed; Time Input: \"HHMM\" e.g.: \"0830\" represents 8:30 AM; \"1600\" represents 4:00 PM";
const std::string INPUTHELP_DATETIMESHOWSEARCH = "Date/Day Inputs: 1. \"DD/MM/YYYY\": Specific date e.g. \"31/04/2014\" represents 31 April 2014; 2. \"yesterday\": Yesterday; 3. \"today\" : Today; 4. \"tomorrow\": Tomorrow; 5. \"this <day>\": This coming occurence of the specified day e.g. \"this Wednesday\" represents this coming Wednesday; 6. \"next <day>\": Next occurrence of the specified day e.g. \"next Friday\" represents the Friday after this coming Friday; 7. \"last <day>\": Previous occurrence of the specified day e.g. \"last Sunday\" represents the Sunday that just passed; 8. \"week DD/MM/YYYY\" OR \"DD/MM/YYYY week\": Week of Monday to Sunday containing thespecified date e.g. \"week 31/04/2014\" represents the week containing 31 April 2014; 9. \"this/next/last week\": This/Next/Last week of Monday to Sunday";
const std::string INPUTHELP_EDIT = "edit: A. To edit all attributes of a task, enter \"edit <task index> .d <new description> .s <new start date-time> .e <new end date/time> .l <new location>\" e.g.: edit 1 .d NewDescription .s 01/01/2014 1000 .e 02/01/2014 1100 .l NewLocation; Note: You may edit a single or multiple attributes in any order and combination.; B. To edit date/day but not time of a task, enter \"edit <task index>.s <new date/day>\" e.g.: edit 1 .s Sunday; C. To edit time but not date/day of a task, enter \"edit <task index>.e <new time>\" e.g.: edit 1 .e 1230";
const std::string INPUTHELP_ADD = "add: A. To add a timed task, enter either format I) or II): I) For tasks that start and end on the same date, enter a) or b): a) \"add .d <task description> .s <start date/day> <start time> .e <end time> .l <location>\" e.g.: add .d SampleTask .s today 1000 .e 1100 .l school; b) \"add <task description> on <start date/day> from <start time> to <end time> in <location>\" e.g.: add SampleTask on tomorrow from 1000 to 1100 in school; II) For tasks that start and end on different dates, enter a) or b): a) \"add .d <task description> .s <start date/day> <start time> .e <end date/day> <end time> .l <location>\" e.g.: add .d SampleTask .s Saturday 1000 .e Sunday 03/01/14 1000 .l school; b) \"add <task description> from <start date/Day> <start time> to <end date/day> <end time> in <location>\" e.g.: add SampleTask from next Friday 1000 to next Saturday 1000 in school; B. To add a partial timed task, enter a) or b): a) \"add .d <task description> .s <start date/day> <start time> .l <location>\" e.g.: add .d SampleTask .s 01/01/14 1000 .l school; (b) \"add <task description> on <start date/day> <start time> in <location>\" e.g.: add SampleTask on 02/01/14 1000 in school; C. To add a deadline task, enter a) or b): a) \"add .d <task description> .e <deadline date/day> <deadline time> .l <location>\" e.g.: add .d SampleTask .by 01/01/14 1000 .l school; b) \"add <task description> by <deadline date/Day> <deadline time> in <location>\" e.g.: add SampleTask by 01/01/14 1000 in school; D. To add a floating task, enter a) or b): a) \"add .d <task description> .l <location>\" e.g.: add .d SampleTask .l school; b) \"add <task description> in <location>\" e.g.: add SampleTask in schoolNote: Location attribute is optional for all task types.";
const std::string INPUTHELP_SHOW = "show: A. To show calendar for today, enter either a) or b): a) \"show\"; b) \"show today\"; B. To show calendar for a specific date/day, enter \"show <date/day>\" e.g.: show 01/01/14 show tomorrow show Friday show next Sunday; C. To show calendar for this week, enter either a) or b): a) \"show week\"; b) \"show this week\"; D. To show calendar for a specific week, enter either a) or b): a) \"show week <date>\"; b) \"show <date> week\" e.g.: show week 01/01/14 show next week; E. To show to-do tasks, enter \"show todo\"; F. To show all done tasks, enter \"show done\"; G. To show done tasks on a specific date/day, enter \"show done <date/day>\" e.g.: show done 01/01/14 show done yesterday show done last Tuesday; H. To show done tasks this week, enter \"show done this week\"; I. To show done tasks on a specific week, enter either a) or b): a) \"show done week <date>\"b) \"show done <date> week\" e.g.: show done week 01/01/14 show done last week";
const std::string INPUTHELP_DEL = "delete: A. To delete a task, enter \"delete <task index>\" e.g.: delete 1; B. To delete multiple tasks, enter \"delete <taskindex1 taskindex2 ...>\" e.g.: delete 1 2; C. To delete all tasks before a certain date, enter \"delete .b <date/day (time)>\" e.g.: delete .b 27/04/2014";
const std::string INPUTHELP_DONE = "done: A. To mark a single task done, enter \"done <task index>\" e.g.: done 1; B. To mark multiple tasks done, enter \"done <taskindex1 taskindex2 ...>\" e.g.: done 1 2; C. To mark done all tasks before a certain date, enter \"done .b <date/day (time)>\" e.g.: done .b 27/04/2014";
const std::string INPUTHELP_UNDONE = "undone: A. To mark a single done task undone, enter \"undone <task index>\" e.g.: undone 1; B. To mark multiple done tasks undone, enter \"undone <taskindex1 taskindex2>\" e.g.: undone 1 2; C. To mark undone all done tasks before a certain date, enter \"undone .b <date/day (time)>\" e.g.: undone .b 27/04/2014";
const std::string INPUTHELP_ATTRIBUTEKEYWORDS = "Attribute keywords: 1. \" .d \": Description; 2. \" .s \": Start date-time; 3. \" .e \": End date-time4. \" .l \": Location";
const std::string INPUTHELP_NATURALKEYWORDS = "Natural keywords: A. To add a timed task, enter either format I) or II): I) For tasks that start and end on the same date, enter \"add <task description> on <start date/day> from <start time> to <end time> in <location>\" e.g.: add SampleTask on 02/01/14 from 1000 to 1100 in school; II) For tasks that start and end on different dates, enter \"add <task description> from <start date/Day> <start time> to <end date/day> <end time> in <location>\" e.g.: add SampleTask from 02/01/14 1000 to 03/01/14 1000 in school; B. To add a partial timed task, enter \"add <task description> on <start date/day> <start time> in <location>\" e.g.: add SampleTask on 02/01/14 1000 in schoolC. To add a deadline task, enter \"add <task description> by <deadline date/Day> <deadline time> in <location>\" e.g.: add SampleTask by 01/01/14 1000 in schoolD. To add a floating task, enter \"add <task description> in <location>\" e.g.: add SampleTask in schoolNote: Location attribute is optional for all task types.";

//Input errors constant string declarations:
const std::string INPUTERROR_NOCOMMAND = "INPUT ERROR: No command entered - pls enter one of the following valid commands: " + INPUTHELP_COMMAND;
const std::string INPUTERROR_INVALIDCOMMAND = "INPUT ERROR: Invalid command - pls enter one of the following valid commands: " + INPUTHELP_COMMAND;
const std::string INPUTERROR_INVALIDTIME = "INPUT ERROR: Invalid time format - pls enter the following valid time format: " + INPUTHELP_TIME;
const std::string INPUTERROR_INVALIDDATE = "INPUT ERROR: Invalid date format - pls enter the following valid date format: " + INPUTHELP_DATE;
const std::string INPUTERROR_INVALIDDATETIMEADDEDIT = "INPUT ERROR: Invalid date-time format - pls enter one of the following valid date-time formats: " + INPUTHELP_DATETIMEADDEDIT;
const std::string INPUTERROR_INVALIDDATETIMESHOWSEARCH = "INPUT ERROR: Invalid date-time format - pls enter one of the following valid date-time formats: " + INPUTHELP_DATETIMESHOWSEARCH;
const std::string INPUTERROR_MISSINGADDPARAMS = "INPUT ERROR: Missing parameters following add command - pls see below for input help: " + INPUTHELP_ADD;
const std::string INPUTERROR_MISSINGEDITTASKINDEXANDPARAMS = "INPUT ERROR: Missing task index number, attribute keyword(s) and parameters - pls see below for input help: " + INPUTHELP_EDIT;
const std::string INPUTERROR_MISSINGEDITPARAMS = "INPUT ERROR: Missing attribute keyword(s) and parameters(s) - pls see below for input help: " + INPUTHELP_EDIT;
const std::string INPUTERROR_REPEATATTRIBUTEKEYWORDS = "INPUT ERROR: Repeat attribute keywords entered - pls enter each attribute keyword not more than once.";
const std::string INPUTERROR_REPEATNATURALKEYWORDS = "INPUT ERROR: Repeat natural keywords entered - pls enter each natural keyword not more than once.";
const std::string INPUTERROR_MISSINGATTRIBUTEPARAM = "INPUT ERROR: Missing parameter following attribute keyword - pls enter parameter after attribute keyword. " + INPUTHELP_ATTRIBUTEKEYWORDS;
const std::string INPUTERROR_MISSINGNATURALPARAM = "INPUT ERROR: Missing parameter following natural keyword - pls enter parameter after natural keyword. " + INPUTHELP_NATURALKEYWORDS;
const std::string INPUTERROR_MISSINGDESCRIPTION = "INPUT ERROR: Missing description - pls enter a description for the task.";
const std::string INPUTERROR_MISSINGATTRIBUTEKEYWORD = "INPUT ERROR: Missing attribute keyword - pls see below for input help: " + INPUTHELP_ATTRIBUTEKEYWORDS;
const std::string INPUTERROR_STARTLATERTHANENDTIME = "INPUT ERROR: Start time is later than end time - pls correct start time or end time such that end time is later than start time.";
const std::string INPUTERROR_MISSINGTASKINDEX = "INPUT ERROR: Missing task index(es) - pls enter number index(es) of desired task(s) from above task display. If there are no tasks displayed above, pls display tasks by entering show command. " + INPUTHELP_SHOW;
const std::string INPUTERROR_INVALIDTASKINDEX = "INPUT ERROR: Invalid task index format - pls enter number index of desired task.";
const std::string INPUTERROR_INVALIDDELPARAMS = "INPUT ERROR: Invalid delete parameters - pls see below for valid parameter formats: " + INPUTHELP_DEL;
const std::string INPUTERROR_INVALIDDONEPARAMS = "INPUT ERROR: Invalid done parameters - pls see below for valid parameter formats: " + INPUTHELP_DONE;
const std::string INPUTERROR_INVALIDUNDONEPARAMS = "INPUT ERROR: Invalid undone parameters - pls see below for valid parameter formats: " + INPUTHELP_UNDONE;
const std::string INPUTERROR_INVALIDATTRIBUTEKEYWORD = "INPUT ERROR: Invalid attribute keyword - pls see below for valid keywords: " + INPUTHELP_ATTRIBUTEKEYWORDS;
const std::string INPUTERROR_INVALIDEDITREMOVEDESCRIPTION = "INPUT ERROR: Cannot remove description - every task requires a description.";
const std::string INPUTERROR_NOEXISTINGDATE = "INPUT ERROR: No existing date - pls specify a date/day along with the time.";
const std::string INPUTERROR_INVALIDDONE = "INPUT ERROR: Invalid done - can only done TO-DO or DEADLINE.";
const std::string INPUTERROR_INVALIDUNDO = "INPUT ERROR: No further previous actions to undo.";
const std::string INPUTERROR_INVALIDREDO = "INPUT ERROR: No further previous undo actions to redo.";
const std::string INPUTERROR_INVALIDTIMERANGESTARTMISSING = "INPUT ERROR: Missing time range start keyword: \"from\"";
const std::string INPUTERROR_INVALIDTIMERANGEENDMISSING = "INPUT ERROR: Missing time range end keyword: \"to\"";
const std::string INPUTERROR_INVALIDSPACESONLY = "INPUT ERROR: A portion of the/Entire input contains spaces only, please revise.";
const std::string INPUTERROR_INVALIDCANNOTREMOVEDESCRIPTION = "INPUT ERROR: Cannot remove description of task.";

class ExceptionInputNoCommand : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_NOCOMMAND.c_str();
	}
} static exceptionInputNoCommand;

class ExceptionInputInvalidCommand : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDCOMMAND.c_str();
	}
} static exceptionInputInvalidCommand;

class ExceptionInputInvalidCannotRemoveDescription : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDCANNOTREMOVEDESCRIPTION.c_str();
	}
} static exceptionInputInvalidCannotRemoveDescription;

class ExceptionInputInvalidSpacesOnly : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDSPACESONLY.c_str();
	}
} static exceptionInputInvalidSpacesOnly;

class ExceptionInputInvalidTimeRangeStartMissing : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDTIMERANGESTARTMISSING.c_str();
	}
} static exceptionInputInvalidTimeRangeStartMissing;

class ExceptionInputInvalidTimeRangeEndMissing : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDTIMERANGEENDMISSING.c_str();
	}
} static exceptionInputInvalidTimeRangeEndMissing;

class ExceptionInputInvalidDelParams : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDDELPARAMS.c_str();
	}
} static exceptionInputInvalidDelParams;

class ExceptionInputInvalidDoneParams : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDDONEPARAMS.c_str();
	}
} static exceptionInputInvalidDoneParams;

class ExceptionInputInvalidUndoneParams : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDUNDONEPARAMS.c_str();
	}
} static exceptionInputInvalidUndoneParams;

class ExceptionInputInvalidTime : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDTIME.c_str();
	}
} static exceptionInputInvalidTime;

class ExceptionInputInvalidDate : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDDATE.c_str();
	}
} static exceptionInputInvalidDate;

class ExceptionInputInvalidDateTimeAddEdit : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDDATETIMEADDEDIT.c_str();
	}
} static exceptionInputInvalidDateTimeAddEdit;

class ExceptionInputInvalidDateTimeShowSearch : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDDATETIMESHOWSEARCH.c_str();
	}
} static exceptionInputInvalidDateTimeShowSearch;

class ExceptionInputMissingAddParams : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_MISSINGADDPARAMS.c_str();
	}
} static exceptionInputMissingAddParams;

class ExceptionInputMissingEditTaskIndexAndParams : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_MISSINGEDITTASKINDEXANDPARAMS.c_str();
	}
} static exceptionInputMissingEditTaskIndexAndParams;

class ExceptionInputMissingEditParams : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_MISSINGEDITPARAMS.c_str();
	}
} static exceptionInputMissingEditParams;

class ExceptionInputRepeatAttributeKeywords : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_REPEATATTRIBUTEKEYWORDS.c_str();
	}
} static exceptionInputRepeatAttributeKeywords;

class ExceptionInputRepeatNaturalKeywords : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_REPEATNATURALKEYWORDS.c_str();
	}
} static exceptionInputRepeatNaturalKeywords;

class ExceptionInputMissingAttributeParam : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_MISSINGATTRIBUTEPARAM.c_str();
	}
} static exceptionInputMissingAttributeParam;

class ExceptionInputMissingNaturalParam : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_MISSINGNATURALPARAM.c_str();
	}
} static exceptionInputMissingNaturalParam;

class ExceptionInputMissingDescription : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_MISSINGDESCRIPTION.c_str();
	}
} static exceptionInputMissingDescription;

class ExceptionInputMissingAttributeKeyword : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_MISSINGATTRIBUTEKEYWORD.c_str();
	}
} static exceptionInputMissingAttributeKeyword;

class ExceptionInputStartLaterThanEndTime : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_STARTLATERTHANENDTIME.c_str();
	}
} static exceptionInputStartLaterThanEndTime;

class ExceptionInputMissingTaskIndex : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_MISSINGTASKINDEX.c_str();
	}
} static exceptionInputMissingTaskIndex;

class ExceptionInputInvalidTaskIndex : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDTASKINDEX.c_str();
	}
} static exceptionInputInvalidTaskIndex;

class ExceptionInputInvalidAttributeKeyword : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDATTRIBUTEKEYWORD.c_str();
	}
} static exceptionInputInvalidAttributeKeyword;

class ExceptionInputInvalidEditRemoveDescription : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDEDITREMOVEDESCRIPTION.c_str();
	}
} static exceptionInputInvalidEditRemoveDescription;

class ExceptionInputNoExistingDate : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_NOEXISTINGDATE.c_str();
	}
} static exceptionInputNoExistingDate;

class ExceptionInputInvalidDone : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDDONE.c_str();
	}
} static exceptionInputInvalidDone;

class ExceptionInputInvalidUndo : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDUNDO.c_str();
	}
} static exceptionInputInvalidUndo;

class ExceptionInputInvalidRedo : public std::exception {
	const char* what() const throw()
	{
		return INPUTERROR_INVALIDREDO.c_str();
	}
} static exceptionInputInvalidRedo;