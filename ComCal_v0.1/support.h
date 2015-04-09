//@author A0085731A

#pragma once

#include "Date.h"
#include "keywords.h"
#include "Task.h"

#include <string>
#include <vector>
#include <algorithm>

namespace support {
	/*************************************************************************************************************
	Name: extractParamsForKeywords
	Type: support namespace method
	Purpose: Processes input string with given vector of keywords and extracts parameters for each keyword,
	Returns the parameters extracted as a vector of vector of strings, with the parameters extracted for each 
	keyword as a vector of strings assigned to its corresponding index element.
	**************************************************************************************************************/
	std::vector<std::vector<std::string>> extractParamsForKeywords(std::string&, std::vector<std::string>);
	
	/*************************************************************************************************************
	Name: prepareTaskDisplayAttributeBreakdown
	Type: support namespace method
	Purpose: Returns task type string according to:
	"TO-DO": Floating task type code - 1
	"DEADLINE": Deadline task type code - 2
	"EVENT": Partial-timed and Timed task type code - 3,4
	**************************************************************************************************************/
	std::string getTaskType(int taskTypeCode);
	
	/*************************************************************************************************************
	Name: checkStartEndTimeValidity
	Type: support namespace method
	Purpose: Checks and returns true of 2nd Date object time is bigger than 1st Date object time, false otherwise.
	**************************************************************************************************************/
	bool checkStartEndTimeValidity(Date*, Date*);
	
	/*************************************************************************************************************
	Name: prepareTaskDisplayAttributeBreakdown
	Type: support namespace method
	Purpose: Processes input task into task display string of the following format:
	Description: ...
	Start date/time: ...
	End date/time OR Deadline: ...
	Location: ...
	**************************************************************************************************************/
	std::string prepareTaskDisplayAttributeBreakdown(Task*);

	/*************************************************************************************************************
	Name: isTaskWithinTimeRange
	Type: support namespace method
	Purpose: Checks and returns true if input Task pointer is within specified start and end Date objects time 
	range, returns false otherwise.
	**************************************************************************************************************/
	bool isDateWithinTimeRange(Date*, Date*, Date*);
	
	/*************************************************************************************************************
	Name: isSpacesOnly
	Type: support namespace method
	Purpose: Checks and returns true if input reference string contains only spaces, returns false otherwise. Also
	trims any leading and ending spaces of input reference string. 
	**************************************************************************************************************/
	bool isSpacesOnly(std::string&);
}