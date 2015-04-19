//@author A0085731A
//Search.h
//Subclass of Command; implements the search function

#pragma once

#include "Command.h"
#include "SearchCondition.h"
#include "TextStorage.h"
#include "Task.h"
#include "Date.h"
#include "support.h"

#include <algorithm>

class Search : public Command {
private:
	/****************************************************************************************************
	Name: _searchConditions
	Type: Vector of SearchCondition objects attribute
	Purpose: Holds search contents in the form of SearchCondition objects containing their associated
	search condition int code, attributes and contents.
	****************************************************************************************************/
	std::vector<SearchCondition>_searchConditions;

	/****************************************************************************************************
	Name: _searchResults
	Type: Vector of Task object pointers attribute
	Purpose: Holds search results.
	****************************************************************************************************/
	std::vector<Task*>_searchResults;

	/****************************************************************************************************
	Name: process
	Type: Method
	Purpose: Processes input string to furnish _searchConditions private attribute.
	****************************************************************************************************/
	void process(std::string);

	/****************************************************************************************************
	Name: getNextConditionAndPos
	Type: Method
	Purpose: Processes first input reference string to obtain next condition's position and index code,
	as well as previous condition's contents, returning the position as int, assigning the index code 
	to second input reference int and previous condition's contents to third input reference string, and 
	removing portion of the first input reference string from its start to the end of the condition read.
	****************************************************************************************************/
	int getNextConditionAndPosAndPreviousContents(std::string&, int&, std::string&);

	/****************************************************************************************************
	Name: prepareFeedback
	Type: Method
	Purpose: Prepares and returns feedback string for successful search execution.
	****************************************************************************************************/
	std::string prepareFeedback();

	/****************************************************************************************************
	Name: isResultDescriptionSearch
	Type: Method
	Purpose: Checks and returns true if Task pointer satisfies input string description search, false
	otherwise.
	****************************************************************************************************/
	bool isResultDescriptionSearch(Task*, std::string);

	/****************************************************************************************************
	Name: isResultDateSearch
	Type: Method
	Purpose: Checks and returns true if Date pointer satisfies input string start date/time search, false
	otherwise.
	****************************************************************************************************/
	bool isResultDateSearch(Date*, std::string);

	/****************************************************************************************************
	Name: isResultLocationSearch
	Type: Method
	Purpose: Checks and returns true if Task pointer satisfies input string location search, false
	otherwise.
	****************************************************************************************************/
	bool isResultLocationSearch(Task*, std::string);

	/****************************************************************************************************
	Name: isResultWildcardSearch
	Type: Method
	Purpose: Checks and returns true if Task pointer satisfies input string wildcard (description and 
	location) search, false otherwise.
	****************************************************************************************************/
	bool isResultWildcardSearch(Task*, std::string);

public:
	Search();
	~Search();

	/****************************************************************************************************
	Name: execute
	Type: Method
	Purpose: Executes search command with input string and returns feedback string.
	****************************************************************************************************/
	std::string execute(std::string argument);
};