//@author A0085731A

#include "support.h"

//If keyword is not found, its associated vector element will be empty.
//If keyword is found but there is no associated param, its associated vector element will have 1 element of empty string
//Passed by reference input string will be modified to remaining string after extraction.
std::vector<std::vector<std::string>> support::extractParamsForKeywords(std::string& input, std::vector<std::string> keywords) {
	//Check for dangling keyword at end of string, if true, append ending space to string
	bool isFound = false;
	for (unsigned int i = 0; i < keywords.size() && !isFound; i++) {
		std::string danglingKeyword;
		danglingKeyword = keywords[i].substr(0, keywords[i].size() - 1);
		if (input.find(danglingKeyword, input.size() - danglingKeyword.size()) != std::string::npos) {
			isFound = true;
			input += " ";
		}
	}

	std::vector<std::vector<std::string>> keywordsAndParams;
	std::vector<std::vector<int>> keywordsStartPos;
	std::vector<int> allStartPos;

	//Get start position of each occurrence of each keyword
	for (unsigned int i = 0; i < keywords.size(); i++) {
		int startSearchPos = 0;
		std::vector<int> startPos;
		int pos;

		pos = input.find(keywords[i].c_str(), startSearchPos, keywords[i].size());
		startPos.push_back(pos);
		startSearchPos = pos + 1;
		if (pos != std::string::npos) {
			allStartPos.push_back(pos);
		}

		while ((pos != std::string::npos) && ((unsigned int)startSearchPos < input.size())) {
			pos = input.find(keywords[i].c_str(), startSearchPos, keywords[i].size());
			if (pos != std::string::npos) {
				startPos.push_back(pos);
				allStartPos.push_back(pos);
				startSearchPos = pos + 1;
			}
		}

		keywordsStartPos.push_back(startPos);
	}

	//Extract param for each keyword by substr from start position of keyword + size of keyword +1 to start position of next keyword
	for (unsigned int i = 0; i < keywordsStartPos.size(); i++) {
		std::vector<std::string> params;
		for (unsigned int j = 0; j < keywordsStartPos[i].size(); j++) {
			if (keywordsStartPos[i][j] != std::string::npos) {
				int nextKeywordPos = input.size();
				for (unsigned int k = 0; k < allStartPos.size(); k++) {
					if (allStartPos[k] > keywordsStartPos[i][j] && allStartPos[k] < nextKeywordPos) {
						nextKeywordPos = allStartPos[k];
					}
				}

				std::string param;
				int paramLength;
				paramLength = nextKeywordPos - (keywordsStartPos[i][j] + keywords[i].size());
				if (paramLength > 0) {
					param = input.substr(keywordsStartPos[i][j] + keywords[i].size(), paramLength);
					if (support::isSpacesOnly(param)) {
						throw exceptionInputInvalidSpacesOnly;
					}
					params.push_back(param);
				}
				else {
					params.push_back("");
				}
			}
		}

		keywordsAndParams.push_back(params);
	}

	//Modify input string to remaining string after extraction
	if (!allStartPos.empty()) {
		std::sort(allStartPos.begin(), allStartPos.end());
		input = input.substr(0, allStartPos[0]);
	}

	return keywordsAndParams;
}

std::string support::getTaskType(int taskTypeCode) {
	if (taskTypeCode == TASKTYPECODE_TIMED || taskTypeCode == TASKTYPECODE_PARTIALTIMED) {
		return TASKTYPE_EVENT;
	}
	else if (taskTypeCode == TASKTYPECODE_DEADLINE) {
		return TASKTYPE_DEADLINE;
	}
	else {
		return TASKTYPE_TODO;
	}
}

bool support::checkStartEndTimeValidity(Date* startDate, Date* endDate) {
	if (startDate->getTimeT() > endDate->getTimeT()) {
		return false;
	}
	else {
		return true;
	}
	
	/*
	bool startEndTimeValidity = true;

	if (startDate->getYear() > endDate->getYear()) {
		startEndTimeValidity = false;
	} else if (startDate->getMonth() > endDate->getMonth()) {
		startEndTimeValidity = false;
	} else if (startDate->getDay() > endDate->getYear()) {
		startEndTimeValidity = false;
	} else if (startDate->getTime() > endDate->getTime()) {
		startEndTimeValidity = false;
	}

	return startEndTimeValidity;
	*/
}

std::string support::prepareTaskDisplayAttributeBreakdown(Task* task) {
	std::string taskDisplay = "";

	taskDisplay += DESCRIPTION + ": \"" + task->getDescription() + "\"";

	if (task->getStartDate() != NULL) {
		taskDisplay += "; " + STARTDATETIME + ": " + task->getStartDate()->toString();
	}

	if (task->getEndDate() != NULL) {
		if (task->getTaskTypeCode() == TASKTYPECODE_DEADLINE) {
			taskDisplay += "; " + DEADLINE + ": ";
		}
		else {
			taskDisplay += "; " + ENDDATETIME + ": ";
		}	
		taskDisplay += task->getEndDate()->toString();
	}

	if (task->getLocation() != "") {
		taskDisplay += "; " + LOCATION + ": \"" + task->getLocation() + "\"";
	}

	return taskDisplay;
}

bool support::isDateWithinTimeRange(Date* dateUnderExam, Date* timeRangeStart, Date* timeRangeEnd) {
	if (dateUnderExam->getTimeT() < timeRangeStart->getTimeT() || dateUnderExam->getTimeT() > timeRangeEnd->getTimeT()) {
		return false;
	}
	else {
		return true;
	}
}

bool support::isSpacesOnly(std::string& input) {
	while (input.substr(0,1)==" ") {
		if (input.size() <= 1) {
			return true;
		}
		input = input.substr(1);	
	}

	while (input.substr(input.size() - 1) == " ") {
		input = input.substr(0, input.size() - 1);
	}

	return false;
}

bool support::checkDateBefore(Date* dateToBeChecked, Date* dateToCheckWith) {
	if (dateToBeChecked->getTimeT() < dateToCheckWith->getTimeT()) {
		return true;
	}
	else {
		return false;
	}
}