//@author A0085731A
//Search.cpp
//Implementation of functions in the Search class

#include "Search.h"

static const std::string SYSTEMERROR_UNRECOGNIZEDSEARCHATTRIBUTEPASSED = "System error: Unrecognized search attribute code stored in _attributeToSearch private attribute of SearchCondition object. Search attribute code read = ";
static const std::string SYSTEMERROR_UNRECOGNIZEDSEARCHCONDITIONPASSED = "System error: Unrecognized search condition code stored in SearchCondition object in _searchConditions private attribute of Search class. Search condition code read = ";

Search::Search() : Command() {
}

Search::~Search() {
}

bool Search::isResultWildcardSearch(Task* taskUnderExam, std::string searchContents) {
	searchContents = searchContents.substr(1);
	if (taskUnderExam->getDescription().find(searchContents) == std::string::npos && taskUnderExam->getLocation().find(searchContents) == std::string::npos) {
		return false;
	}
	else {
		return true;
	}
}

bool Search::isResultDescriptionSearch(Task* taskUnderExam, std::string searchContents) {
	if (taskUnderExam->getDescription().find(searchContents) == std::string::npos) {
		return false;
	}
	else {
		return true;
	}
}

bool Search::isResultLocationSearch(Task* taskUnderExam, std::string searchContents) {
	if (taskUnderExam->getLocation().find(searchContents) == std::string::npos) {
		return false;
	}
	else {
		return true;
	}
}

bool Search::isResultDateSearch(Date* taskDate, std::string searchContents) {
	Date* timeRangeStart = new Date();
	Date* timeRangeEnd = new Date();
	//Check for from and to specification
	int timeRangeStartPos = searchContents.find(SEARCHDATETIMERANGESTART);
	int timeRangeEndPos = searchContents.find(SEARCHDATETIMERANGEEND);
	if (timeRangeStartPos > 0) {
		throw exceptionInputInvalidDateTimeShowSearch;
	}
	else if (timeRangeStartPos != std::string::npos&&timeRangeEndPos == std::string::npos) {
		throw exceptionInputInvalidTimeRangeEndMissing;
	}
	else if (timeRangeStartPos == std::string::npos&&timeRangeEndPos != std::string::npos) {
		throw exceptionInputInvalidTimeRangeStartMissing;
	}
	else if (timeRangeStartPos != std::string::npos&&timeRangeEndPos != std::string::npos) {
		std::string timeRangeStartString = searchContents.substr(SEARCHDATETIMERANGESTART.size(), timeRangeEndPos - SEARCHDATETIMERANGESTART.size());
		if (!timeRangeStart->setDate(timeRangeStartString)) {
			throw exceptionInputInvalidDateTimeShowSearch;
		}
		if (timeRangeStart->getTime() == NULL) {
			timeRangeStart->setTime(0);
		}
		std::string timeRangeEndString = searchContents.substr(timeRangeEndPos + SEARCHDATETIMERANGEEND.size());
		if (!timeRangeEnd->setDate(timeRangeEndString)) {
			throw exceptionInputInvalidDateTimeShowSearch;
		}
		if (timeRangeEnd->getTime() == NULL) {
			timeRangeEnd->setTime(2359);
		}
	}
	else {
		//No from and to specification
		if (searchContents.find(DATE_WEEK) != std::string::npos) {
			if (!timeRangeStart->setDate(searchContents)) {
				throw exceptionInputInvalidDateTimeShowSearch;
			}
			timeRangeEnd->setDate(searchContents);
			timeRangeEnd->setEndOfWeek();
		}
		else {
			if (!timeRangeStart->setDate(searchContents)) {
				throw exceptionInputInvalidDateTimeShowSearch;
			}
			timeRangeEnd->setDate(searchContents);
			timeRangeEnd->setEndOfDay();
		}
	}
	
	bool isResult = support::isDateWithinTimeRange(taskDate, timeRangeStart, timeRangeEnd);

	return isResult;
}

std::string Search::execute(std::string argument) {
	process(argument);

	int numOfTasks = TextStorage::getInstance()->getNumberOfTasks();
	for (unsigned int i = 0; i < _searchConditions.size(); i++) {
		std::vector<int> attributesToSearch = _searchConditions[i].getAttributesToSearch();
		std::vector<std::vector<std::string>> contentsToSearch = _searchConditions[i].getContentsToSearch();
		switch (_searchConditions[i].getCondition()) {
		case INDEX_AND:
			if (!_searchResults.empty()) {
				unsigned int j = 0;
				while (j < _searchResults.size()) {
					Task* taskUnderExam = _searchResults[j];
					for (unsigned int k = 0; k < attributesToSearch.size(); k++) {
						switch (attributesToSearch[k]) {
						case INDEX_WILDCARD:
							for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
								if (!isResultWildcardSearch(taskUnderExam, contentsToSearch[k][l])) {
									_searchResults.erase(_searchResults.begin() + j);
								}
								else {
									j++;
								}
							}
							break;
						case INDEX_DESCRIPTION:
							for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
								if (!isResultDescriptionSearch(taskUnderExam, contentsToSearch[k][l])) {
									_searchResults.erase(_searchResults.begin() + j);
								}
								else {
									j++;
								}
							}
							break;
						case INDEX_STARTDATETIME:
							if (taskUnderExam->hasStartDate()) {
								for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
									if (!isResultDateSearch(taskUnderExam->getStartDate(), contentsToSearch[k][l])) {
										_searchResults.erase(_searchResults.begin() + j);
									}
									else {
										j++;
									}
								}
							}
							else {
								_searchResults.erase(_searchResults.begin() + j);
							}
							break;
						case INDEX_ENDDATETIME:
							if (taskUnderExam->hasEndDate()) {
								for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
									if (!isResultDateSearch(taskUnderExam->getEndDate(), contentsToSearch[k][l])) {
										_searchResults.erase(_searchResults.begin() + j);
									}
									else {
										j++;
									}
								}
							}
							else {
								_searchResults.erase(_searchResults.begin() + j);
							}
							break;
						case INDEX_LOCATION:
							for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
								if (!isResultLocationSearch(taskUnderExam, contentsToSearch[k][l])) {
									_searchResults.erase(_searchResults.begin() + j);
								}
								else {
									j++;
								}
							}
							break;
						default:
							ErrorLog::inputErrorLog(SYSTEMERROR_UNRECOGNIZEDSEARCHATTRIBUTEPASSED + typeConversions::intToString(attributesToSearch[j]));
						}
					}
				}
			}
			break;
		case INDEX_OR:
			for (int j = 0; j < numOfTasks; j++) {
				bool isInResults = false;
				if (!_searchResults.empty()) {
					for (unsigned int k = 0; k < _searchResults.size(); k++) {
						if (_searchResults[k] == TextStorage::getInstance()->getTask(j)) {
							isInResults = true;
						}
					}
				}
				if (!isInResults) {
					Task* taskUnderExam = TextStorage::getInstance()->getTask(j);
					bool satisfySearch = true;
					for (unsigned int k = 0; k < attributesToSearch.size() && satisfySearch; k++) {
						switch (attributesToSearch[k]) {
						case INDEX_WILDCARD:
							for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
								if (!isResultWildcardSearch(taskUnderExam, contentsToSearch[k][l])) {
									satisfySearch = false;
								}
							}
							break;
						case INDEX_DESCRIPTION:
							for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
								if (!isResultDescriptionSearch(taskUnderExam, contentsToSearch[k][l])) {
									satisfySearch = false;
								}
							}
							break;
						case INDEX_STARTDATETIME:
							if (taskUnderExam->hasStartDate()) {
								for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
									if (!isResultDateSearch(taskUnderExam->getStartDate(), contentsToSearch[k][l])) {
										satisfySearch = false;
									}
								}
							}
							else {
								satisfySearch = false;
							}
							break;
						case INDEX_ENDDATETIME:
							if (taskUnderExam->hasEndDate()) {
								for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
									if (!isResultDateSearch(taskUnderExam->getEndDate(), contentsToSearch[k][l])) {
										satisfySearch = false;
									}
								}
							}
							else {
								satisfySearch = false;
							}
							break;
						case INDEX_LOCATION:
							for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
								if (!isResultLocationSearch(taskUnderExam, contentsToSearch[k][l])) {
									satisfySearch = false;
								}
							}
							break;
						default:
							ErrorLog::inputErrorLog(SYSTEMERROR_UNRECOGNIZEDSEARCHATTRIBUTEPASSED + typeConversions::intToString(attributesToSearch[k]));
						}
					}

					if (satisfySearch) {
						_searchResults.push_back(taskUnderExam);
					}
				}
			}
			break;
		case INDEX_NOT:
			if (!_searchResults.empty()) {
				unsigned int j = 0;
				while (j < _searchResults.size()) {
					Task* taskUnderExam = _searchResults[j];
					for (unsigned int k = 0; k < attributesToSearch.size(); k++) {
						switch (attributesToSearch[k]) {
						case INDEX_WILDCARD:
							for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
								if (isResultWildcardSearch(taskUnderExam, contentsToSearch[k][l])) {
									_searchResults.erase(_searchResults.begin() + j);
								}
								else {
									j++;
								}
							}
							break;
						case INDEX_DESCRIPTION:
							for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
								if (isResultDescriptionSearch(taskUnderExam, contentsToSearch[k][l])) {
									_searchResults.erase(_searchResults.begin() + j);
								}
								else {
									j++;
								}
							}
							break;
						case INDEX_STARTDATETIME:
							if (taskUnderExam->hasStartDate()) {
								for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
									if (isResultDateSearch(taskUnderExam->getStartDate(), contentsToSearch[k][l])) {
										_searchResults.erase(_searchResults.begin() + j);
									}
									else {
										j++;
									}
								}
							}
							else {
								j++;
							}
							break;
						case INDEX_ENDDATETIME:
							if (taskUnderExam->hasEndDate()) {
								for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
									if (isResultDateSearch(taskUnderExam->getEndDate(), contentsToSearch[k][l])) {
										_searchResults.erase(_searchResults.begin() + j);
									}
									else {
										j++;
									}
								}
							}
							else {
								j++;
							}
							break;
						case INDEX_LOCATION:
							for (unsigned int l = 0; l < contentsToSearch[k].size(); l++) {
								if (isResultLocationSearch(taskUnderExam, contentsToSearch[k][l])) {
									_searchResults.erase(_searchResults.begin() + j);
								}
								else {
									j++;
								}
							}
							break;
						default:
							ErrorLog::inputErrorLog(SYSTEMERROR_UNRECOGNIZEDSEARCHATTRIBUTEPASSED + typeConversions::intToString(attributesToSearch[j]));
						}
					}
				}
			}
			break;
		default:
			ErrorLog::inputErrorLog(SYSTEMERROR_UNRECOGNIZEDSEARCHCONDITIONPASSED + typeConversions::intToString(_searchConditions[i].getCondition()));
		}
	}

	for (int i = 0; i < numOfTasks; i++) {
		TextStorage::getInstance()->getTask(i)->hide();
	}

	for (unsigned int i = 0; i < _searchResults.size(); i++) {
		_searchResults[i]->display();
	}

	std::string feedback = prepareFeedback();

	return feedback;
}

void Search::process(std::string argument) {
	std::string previousContents;
	int nextConditionCode;
	int nextConditionPos = getNextConditionAndPosAndPreviousContents(argument, nextConditionCode, previousContents);
	int conditionIndex = 1;
	SearchCondition firstSearchCondition(INDEX_OR);
	_searchConditions.push_back(firstSearchCondition);
	while (nextConditionPos!=std::string::npos) {
		SearchCondition nextSearchCondition(nextConditionCode);
		_searchConditions.push_back(nextSearchCondition);
		_searchConditions[conditionIndex-1].setContents(previousContents);
		nextConditionPos = getNextConditionAndPosAndPreviousContents(argument, nextConditionCode, previousContents);
		conditionIndex++;
	}
	_searchConditions[conditionIndex - 1].setContents(argument);

	return;
}

int Search::getNextConditionAndPosAndPreviousContents(std::string& input, int& conditionCode, std::string& previousContents) {
	std::vector<int> conditionPosVect;
	std::vector<int> conditionCodeVect;
	std::string inputLowerCase = typeConversions::toLowerCase(input);

	for (int i = 0; i < SEARCHCONDITIONKEYWORDSARRAYSIZE; i++) {
		int conditionPos = inputLowerCase.find(SEARCHCONDITIONKEYWORDSARRAY[i]);
		if (conditionPos != std::string::npos) {
			conditionPosVect.push_back(conditionPos);
			conditionCodeVect.push_back(i);
		}
	}

	if (conditionPosVect.empty()) {
		return std::string::npos;
	}

	int conditionPos = conditionPosVect[0];
	conditionCode = conditionCodeVect[0];
	for (unsigned int i = 1; i < conditionPosVect.size(); i++) {
		if (conditionPosVect[i] < conditionPos) {
			conditionPos = conditionPosVect[i];
			conditionCode = conditionCodeVect[i];
		}
	}

	previousContents = input.substr(0,conditionPos);
	if (support::isSpacesOnly(previousContents)){
		throw exceptionInputInvalidSpacesOnly;
	}
	input = input.substr(conditionPos + SEARCHCONDITIONKEYWORDSARRAY[conditionCode].size());

	return conditionPos;
}

std::string Search::prepareFeedback() {
	std::string feedback = "Executed search of: ";

	for (unsigned int i = 0; i < _searchConditions.size(); i++) {
		if (i != 0) {
			switch (_searchConditions[i].getCondition()) {
			case INDEX_AND:
				feedback += " " + AND + " (";
				break;
			case INDEX_OR:
				feedback += " " + OR + " (";
				break;
			case INDEX_NOT:
				feedback += " " + NOT + " (";
			}
		}
		else {
			feedback += "(";
		}
		for (unsigned int j = 0; j < _searchConditions[i].getAttributesToSearch().size(); j++) {
			switch (_searchConditions[i].getAttributesToSearch()[j]) {
			case INDEX_DESCRIPTION:
				feedback += " " + DESCRIPTION + ": ";
				break;
			case INDEX_STARTDATETIME:
				feedback += " " + STARTDATETIME + ": ";
				break;
			case INDEX_ENDDATETIME:
				feedback += " " + ENDDATETIME + ": ";
				break;
			case INDEX_LOCATION:
				feedback += " " + LOCATION + ": ";
				break;
			}
			for (unsigned int k = 0; k < _searchConditions[i].getContentsToSearch()[j].size(); k++) {
				switch (_searchConditions[i].getAttributesToSearch()[j]) {
				case INDEX_DESCRIPTION:
					feedback += "\"";
					break;
				case INDEX_LOCATION:
					feedback += "\"";
					break;
				}
				feedback += _searchConditions[i].getContentsToSearch()[j][k];
				switch (_searchConditions[i].getAttributesToSearch()[j]) {
				case INDEX_DESCRIPTION:
					feedback += "\"";
					break;
				case INDEX_LOCATION:
					feedback += "\"";
					break;
				}
				if (k < _searchConditions[i].getContentsToSearch()[j].size() - 1) {
					feedback += ", ";
				}
			}
			if (j < _searchConditions[i].getAttributesToSearch().size() - 1) {
				feedback += ";";
			}
		}
		feedback += " )";
	}

	return feedback;
}
