// Edit.cpp
// Implementation of functions in the Edit class
//@author A0085731A

#include "Edit.h"

Edit::Edit() : Command() {
	_attributeKeywords.assign(ATTRIBUTEKEYWORDSARRAY, ATTRIBUTEKEYWORDSARRAY + ATTRIBUTEKEYWORDSARRAYSIZE);
}

Edit::~Edit() {
}

std::string Edit::execute(std::string userInput) {
	process(userInput);

	for (unsigned int i = 0; i < _attributesToBeEdited.size(); i++) {
		if (_attributesToBeEdited[i] == DESCRIPTION) {
			if (_attributesToBeEdited[i] == "") {
				throw exceptionInputInvalidEditRemoveDescription;
			}
			if (_contentsToBeEdited[i] == "") {
				throw exceptionInputInvalidCannotRemoveDescription;
			}
			_editedTask->setDescription(_contentsToBeEdited[i]);
		}
		else if (_attributesToBeEdited[i] == STARTDATETIME) {
			Date* editTaskStartDateTime = new Date();
			if (!editTaskStartDateTime->setDate(_contentsToBeEdited[i])) {
				throw exceptionInputInvalidDateTimeAddEdit;
			}
			if (_editedTask->getEndDate() != NULL) {
				if (!support::checkStartEndTimeValidity(editTaskStartDateTime, _editedTask->getEndDate())) {
					throw exceptionInputStartLaterThanEndTime;
				}
			}
			_editedTask->setStartDate(editTaskStartDateTime);
		}
		else if (_attributesToBeEdited[i] == STARTDATE) {
			if (_contentsToBeEdited[i] == "") {
				_editedTask->setStartDate(NULL);
			}
			else {
				Date* editTaskStartDateTime = new Date();
				if (!editTaskStartDateTime->setDate(_contentsToBeEdited[i])) {
					throw exceptionInputInvalidDate;
				}
				if (_editedTask->getStartDate() != NULL) {
					int existingTime = _editedTask->getStartDate()->getTime();
					editTaskStartDateTime->setTime(existingTime);
				}
				if (editTaskStartDateTime->getTime() == NULL){
					editTaskStartDateTime->setTime(0);
				}
				if (_editedTask->getEndDate() != NULL) {
					if (!support::checkStartEndTimeValidity(editTaskStartDateTime, _editedTask->getEndDate())) {
						throw exceptionInputStartLaterThanEndTime;
					}
				}
				_editedTask->setStartDate(editTaskStartDateTime);
			}
		}
		else if (_attributesToBeEdited[i] == STARTTIME) {
			if (_editedTask->getStartDate() != NULL && _editedTask->getEndDate() != NULL) {
				int editTime = typeConversions::stringToInt(_contentsToBeEdited[i]);
				Date* editTaskStartDateTime = new Date();
				if (_editedTask->getStartDate() != NULL) {
					*editTaskStartDateTime = *_editedTask->getStartDate();
				}
				else {
					*editTaskStartDateTime = *_editedTask->getEndDate();
				}
				if (!editTaskStartDateTime->setTime(editTime)) {
					throw exceptionInputInvalidTime;
				}
				if (_editedTask->getEndDate() != NULL) {
					if (!support::checkStartEndTimeValidity(editTaskStartDateTime, _editedTask->getEndDate())) {
						throw exceptionInputStartLaterThanEndTime;
					}
				}
				_editedTask->setStartDate(editTaskStartDateTime);
			}
			else {
				throw exceptionInputNoExistingDate;
			}
		}
		else if (_attributesToBeEdited[i] == ENDDATETIME) {
			Date* editTaskEndDateTime = new Date();
			if (!editTaskEndDateTime->setDate(_contentsToBeEdited[i])) {
				throw exceptionInputInvalidDateTimeAddEdit;
			}
			if (_editedTask->getStartDate() != NULL) {
				if (!support::checkStartEndTimeValidity(_editedTask->getStartDate(), editTaskEndDateTime)) {
					throw exceptionInputStartLaterThanEndTime;
				}
			}
			_editedTask->setEndDate(editTaskEndDateTime);
		}
		else if (_attributesToBeEdited[i] == ENDDATE) {
			if (_contentsToBeEdited[i] == "") {
				_editedTask->setEndDate(NULL);
			}
			else {
				Date* editTaskEndDateTime = new Date();
				if (!editTaskEndDateTime->setDate(_contentsToBeEdited[i])) {
					throw exceptionInputInvalidDate;
				}
				if (_editedTask->getEndDate() != NULL) {
					int existingTime = _editedTask->getEndDate()->getTime();
					editTaskEndDateTime->setTime(existingTime);
				}
				if (editTaskEndDateTime->getTime() == NULL){
					editTaskEndDateTime->setTime(2359);
				}
				if (_editedTask->getStartDate() != NULL) {
					if (!support::checkStartEndTimeValidity(_editedTask->getStartDate(), editTaskEndDateTime)) {
						throw exceptionInputStartLaterThanEndTime;
					}
				}
				_editedTask->setEndDate(editTaskEndDateTime);
			}
		}
		else if (_attributesToBeEdited[i] == ENDTIME) {
			if (_editedTask->getStartDate() != NULL && _editedTask->getEndDate() != NULL) {
				int editTime = typeConversions::stringToInt(_contentsToBeEdited[i]);
				Date* editTaskEndDateTime = new Date();
				if (_editedTask->getEndDate() != NULL) {
					*editTaskEndDateTime = *_editedTask->getEndDate();
				}
				else {
					*editTaskEndDateTime = *_editedTask->getStartDate();
				}
				if (!editTaskEndDateTime->setTime(editTime)) {
					throw exceptionInputInvalidTime;
				}
				if (_editedTask->getStartDate() != NULL) {
					if (!support::checkStartEndTimeValidity(_editedTask->getStartDate(), editTaskEndDateTime)) {
						throw exceptionInputStartLaterThanEndTime;
					}
				}
				_editedTask->setEndDate(editTaskEndDateTime);
			}
			else {
				throw exceptionInputNoExistingDate;
			}
		}
		else {
			_editedTask->setLocation(_contentsToBeEdited[i]);
		}
	}

	std::string feedback = prepareFeedback();

	return feedback;
}

void Edit::process(std::string userInput) {
	if (support::isSpacesOnly(userInput)) {
		throw exceptionInputInvalidSpacesOnly;
	}

	furnishTaskToBeEdited(userInput);

	furnishEditContents(userInput);
}

void Edit::furnishTaskToBeEdited(std::string &userInput) {
	if (userInput == "") {
		throw exceptionInputMissingEditTaskIndexAndParams;
	}

	_taskIndexToBeEdited = extractTaskIndex(userInput);

	Task* originalTask = TextStorage::getInstance()->getTask(_taskIndexToBeEdited-1);

	if(originalTask == NULL) {
		throw exceptionInputInvalidTaskIndex;
	}

	_originalTask = new Task;
	_originalTask->setDescription(originalTask->getDescription());
	if (originalTask->getStartDate() != NULL) {
		Date* originalStartDate = new Date(originalTask->getStartDate()->getDay(), originalTask->getStartDate()->getMonth(), originalTask->getStartDate()->getYear(), originalTask->getStartDate()->getTime());
		_originalTask->setStartDate(originalStartDate);
	}	
	if (originalTask->getEndDate() != NULL) {
		Date* originalEndDate = new Date(originalTask->getEndDate()->getDay(), originalTask->getEndDate()->getMonth(), originalTask->getEndDate()->getYear(), originalTask->getEndDate()->getTime());
		_originalTask->setEndDate(originalEndDate);
	}
	_originalTask->setLocation(originalTask->getLocation());

	_editedTask = originalTask;

	return;
}

int Edit::extractTaskIndex(std::string &userInput){
	int spacePosition = userInput.find(" ");

	if (spacePosition == std::string::npos) {
		throw exceptionInputMissingEditParams;
	}

	if (!typeConversions::isNumber(userInput.substr(0,spacePosition))) {
		throw exceptionInputInvalidTaskIndex;
	}

	std::string taskIndexToBeEditedString = userInput.substr(0, spacePosition);

	userInput = userInput.substr(spacePosition + 1);

	int taskIndexToBeEdited = typeConversions::stringToInt(taskIndexToBeEditedString);

	return taskIndexToBeEdited;
}

void Edit::furnishEditContents(std::string &userInput) {
	if (userInput == "") {
		throw exceptionInputMissingEditParams;
	}

	if (support::isSpacesOnly(userInput)) {
		throw exceptionInputInvalidSpacesOnly;
	}

	userInput = " " + userInput;

	std::vector<std::vector<std::string>> keywordsAndParams = support::extractParamsForKeywords(userInput, _attributeKeywords);

	for (unsigned int i = 0; i < keywordsAndParams.size(); i++) {
		if (!keywordsAndParams[i].empty()) {
			if (keywordsAndParams[i].size() > 1) {
				throw exceptionInputRepeatAttributeKeywords;
			}

			if (keywordsAndParams[i][0] == "") {
				throw exceptionInputMissingAttributeParam;
			}

			switch (i) {
			case INDEX_DESCRIPTION:
				_attributesToBeEdited.push_back(DESCRIPTION);
				break;
			case INDEX_STARTDATETIME:
				if (checkDateTimeInputIsTime(keywordsAndParams[i][0])) {
					_attributesToBeEdited.push_back(STARTTIME);
				}
				else if (checkDateTimeInputIsDateTime(keywordsAndParams[i][0])) {
					_attributesToBeEdited.push_back(STARTDATETIME);
				}
				else {
					_attributesToBeEdited.push_back(STARTDATE);
				}
				break;
			case INDEX_ENDDATETIME:
				if (checkDateTimeInputIsTime(keywordsAndParams[i][0])) {
					_attributesToBeEdited.push_back(ENDTIME);
				}
				else if (checkDateTimeInputIsDateTime(keywordsAndParams[i][0])) {
					_attributesToBeEdited.push_back(ENDDATETIME);
				}
				else {
					_attributesToBeEdited.push_back(ENDDATE);
				}
				break;
			case INDEX_LOCATION:
				_attributesToBeEdited.push_back(LOCATION);
				break;
			}

			if (keywordsAndParams[i][0] == "-") {
				keywordsAndParams[i][0] = "";
			}
			_contentsToBeEdited.push_back(keywordsAndParams[i][0]);
		}
	}

	if (_attributesToBeEdited.empty()) {
		throw exceptionInputInvalidAttributeKeyword;
	}

	if (userInput != "") {
		throw exceptionInputMissingAttributeKeyword;
	}

	return;
}

bool Edit::checkDateTimeInputIsTime(std::string input) {
	if (input.size() == LENGTH_TIMEINPUT) {
		return true;
	}
	else {
		return false;
	}
}

bool Edit::checkDateTimeInputIsDateTime(std::string input) {
	if (input.size()>LENGTH_TIMEINPUT && input.substr(input.size() - LENGTH_TIMEINPUT).find_first_not_of(INTS) == std::string::npos) {
		return true;
	}
	else {
		return false;
	}
}

std::string Edit::prepareFeedback(){
	std::string feedback = "Edited ";
	std::string taskDisplay;
	
	std::string originalType;
	originalType = support::getTaskType(_originalTask->getTaskTypeCode());

	std::string editedType;
	editedType = support::getTaskType(_editedTask->getTaskTypeCode());

	for (unsigned int i = 0; i < _attributesToBeEdited.size(); i++) {
		if (editedType == TASKTYPE_DEADLINE) {
			if (_attributesToBeEdited[i] == ENDDATE) {
				_attributesToBeEdited[i] = DEADLINEDATE;
			}
			else if (_attributesToBeEdited[i] == ENDDATETIME) {
				_attributesToBeEdited[i] = DEADLINE;
			}
			else if (_attributesToBeEdited[i] == ENDTIME) {
				_attributesToBeEdited[i] = DEADLINETIME;
			}
		}

		feedback += _attributesToBeEdited[i];

		if (i == _attributesToBeEdited.size() - 2) {
			feedback += " and ";
		}
		else if (i == _attributesToBeEdited.size() - 1) {
			feedback += " ";
		}
		else {
			feedback += ", ";
		}
	}

	if (editedType == originalType) {
		feedback += "of " + editedType + " (" + std::to_string(_taskIndexToBeEdited) + "):";
	}
	else {
		feedback += "of " + originalType + " to " + editedType + " (" + std::to_string(_taskIndexToBeEdited) + "): ";
	}

	taskDisplay = support::prepareTaskDisplayAttributeBreakdown(_editedTask);

	feedback += taskDisplay;

	return feedback;
}

int Edit::getEditedTaskIndex() {
	return _taskIndexToBeEdited;
}

std::string Edit::undo() {
	std::string feedback;

	Task* temp = new Task();
	
	*temp = *_editedTask;

	*_editedTask = *_originalTask;

	*_originalTask = *temp;

	feedback = prepareFeedback();

	return feedback;
}

std::string Edit::redo() {
	std::string feedback;

	Task* temp = new Task();

	*temp = *_editedTask;

	*_editedTask = *_originalTask;

	*_originalTask = *temp;

	feedback = prepareFeedback();

	return feedback;
}
