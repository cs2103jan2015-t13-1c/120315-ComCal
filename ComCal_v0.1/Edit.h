// Edit.h
// Subclass of Command; implements the edit function
//@author: A0085731A

/**********************************************************************************************************
Name: Edit
Type: Class
Purpose: Child class of Command parent class.
Responsible for executing editing of task in tasks database text file, when its execute API
is called by ComCalManager class.
**********************************************************************************************************/

#pragma once

#include "Command.h"
#include "keywords.h"
#include "timeDateInfo.h"
#include "support.h"
#include "TextStorage.h"
#include "typeConversions.h"
#include "Exceptions.h"

class Edit : public Command {
private:
	/****************************************************************************************************
	Name: _attributeKeywords
	Type: Vector of strings attribute
	Purpose: Holds recognised attribute keywords
	****************************************************************************************************/
	std::vector<std::string> _attributeKeywords;
	
	/****************************************************************************************************
	Type: Private attributes
	Purpose: Hold characteristics of edit object, including task index to be edited, attributes and contents to be edited,
	the original task object and the task object after editing.
	****************************************************************************************************/
	int _taskIndexToBeEdited;
	std::vector<std::string> _attributesToBeEdited;
	std::vector<std::string> _contentsToBeEdited;
	Task* _originalTask;
	Task* _editedTask;

	/****************************************************************************************************
	Name: extractTaskIndex
	Type: Method
	Purpose: Extracts and returns task index to be edited from input reference string. Throws missing 
	edit parameters exception if no space is read in input reference string. Removes task index read from
	input reference string.
	****************************************************************************************************/
	int extractTaskIndex(std::string&);
	
	/****************************************************************************************************
	Name: process
	Type: Method
	Purpose: Processes input string to obtain specified task index to be edited, attribute codes and 
	new content for each attribute to be edited and furnishes the respect vector of string private
	attributes.
	****************************************************************************************************/
	void process(std::string);

	/****************************************************************************************************
	Name: furnishTaskToBeEdited
	Type: Method
	Purpose: Furnishes _orignalTask and _editedTask private attributes with specified task index to be 
	edited from input reference string, and removes the this task index from the input reference string.
	****************************************************************************************************/
	void furnishTaskToBeEdited(std::string&);
	
	/****************************************************************************************************
	Name: furnishEditContents
	Type: Method
	Purpose: Furnishes remaining private attributes with specifications from input reference string, and
	removes these from the input reference string.
	****************************************************************************************************/
	void furnishEditContents(std::string&);
	
	/****************************************************************************************************
	Name: checkDateTimeInputIsTime
	Type: Method
	Purpose: Checks and returns true if input string is a time input of 4 integers, false otherwise.
	****************************************************************************************************/
	bool checkDateTimeInputIsTime(std::string);

	/****************************************************************************************************
	Name: checkDateTimeInputIsTime
	Type: Method
	Purpose: Checks and returns true if input string is a date time input with last 4 characters being
	integers, false otherwise.
	****************************************************************************************************/
	bool checkDateTimeInputIsDateTime(std::string);

	/****************************************************************************************************
	Name: prepareFeedback
	Type: Method
	Purpose: Prepares and returns edit feedback string upon successful edit execution.
	****************************************************************************************************/
	std::string prepareFeedback();
public:
	Edit();
	~Edit();

	/****************************************************************************************************
	Name: execute
	Type: Method
	Purpose: Public API for ComCalManager class to call to execute edit action.
	****************************************************************************************************/
	std::string execute(std::string argument);

	/****************************************************************************************************
	Name: undo
	Type: Method
	Purpose: Public API for ComCalManager class to call to undo edit action.
	****************************************************************************************************/
	std::string undo();

	/****************************************************************************************************
	Name: redo
	Type: Method
	Purpose: Public API for ComCalManager class to call to redo edit action.
	****************************************************************************************************/
	std::string redo();

	/****************************************************************************************************
	Name: getEditedTaskIndex
	Type: Method
	Purpose: (for unit tests to call) Returns edited task's index.
	****************************************************************************************************/
	int getEditedTaskIndex();
};