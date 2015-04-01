// Edit.cpp
// Implementation of functions in the Edit class
//@author A0119754X

#include <string>
#include <vector>
#include "Edit.h"
#include "TextStorage.h"
#include "typeConversions.h"

enum DSEL {
	DSEL_DESCRIPTION,
	DSEL_START_DATE,
	DSEL_END_DATE,
	DSEL_LOCATION
};

struct dselStruct {
	DSEL name;
	unsigned int find;
};

bool Edit::canFind(int index) {
	return ((index != std::string::npos) && (index != -1));
}

std::string Edit::execute(std::string argument) {
	dselStruct dsel[4];
	dsel[0].name = DSEL_DESCRIPTION;
	dsel[0].find = argument.find(".d");
	dsel[1].name = DSEL_START_DATE;
	dsel[1].find = argument.find(".s");
	dsel[2].name = DSEL_END_DATE;
	dsel[2].find = argument.find(".e");
	dsel[3].name = DSEL_LOCATION;
	dsel[3].find = argument.find(".l");

	for (int i = 0; i < 4; i++) {
		if (dsel[i].find == -1) {
			dsel[i].find = std::string::npos;
		}
	}

	// Sorts according to where they are found in the argument
	int minimum;
	dselStruct toSwap;
	for (int x = 0; x < 3; x++) {
		minimum = x;
		for (int y = x + 1; y < 4; y++) {
			if (dsel[y].find < dsel[minimum].find) {
				minimum = y;
			}
		}
		if (minimum != x) {
			toSwap = dsel[minimum];
			dsel[minimum] = dsel[x];
			dsel[x] = toSwap;
		}
	}

	if (!canFind(dsel[0].find)) {
		return "Invalid Edit command: No arguments entered";
	}

	std::string strEditEntryIndex = argument.substr(0, dsel[0].find - 1);
	if (!typeConversions::isNumber(strEditEntryIndex)) {
		return "Invalid Edit command: Index of entry to be edited is not an integer";
	}

	int nEditEntryIndex = typeConversions::stringToInt(strEditEntryIndex);
	Task* editEntryTask = TextStorage::getInstance()->getTask(nEditEntryIndex - 1);
	if (editEntryTask == NULL) {
		return "Invalid Edit command: No entry with index " + strEditEntryIndex + " found";
	}
	
	int startPosition;
	int length;
	std::vector<DSEL> whatHasBeenEdited;
	bool hasStartDateError = false;
	bool hasEndDateError = false;

	for (int i = 0; i < 4; i++) {
		if (!canFind(dsel[i].find)) {
			i = 4;
		}
		else {
			startPosition = dsel[i].find + 3;
			if ((i == 4) || (!canFind(dsel[i + 1].find))) {
				length = argument.length() - startPosition;
			}
			else {
				length = dsel[i + 1].find - startPosition - 1;
			}
			switch (dsel[i].name) {
			case DSEL_DESCRIPTION:
				whatHasBeenEdited.push_back(DSEL_DESCRIPTION);
				editEntryTask->setDescription(argument.substr(startPosition, length));
				break;
			case DSEL_START_DATE:
				whatHasBeenEdited.push_back(DSEL_START_DATE);
				if (!editEntryTask->getStartDate()->setDate(argument.substr(startPosition, length))) {
					hasStartDateError = true;
				}
				break;
			case DSEL_END_DATE:
				whatHasBeenEdited.push_back(DSEL_END_DATE);
				if (!editEntryTask->getEndDate()->setDate(argument.substr(startPosition, length))) {
					hasEndDateError = true;
				}
				break;
			case DSEL_LOCATION:
				whatHasBeenEdited.push_back(DSEL_LOCATION);
				editEntryTask->setLocation(argument.substr(startPosition, length));
				break;
			}
		}
	}

	std::string strWhatHasBeenEdited = "";
	unsigned int size = whatHasBeenEdited.size();
	for (unsigned int i = 0; i < size; i++) {
		switch (whatHasBeenEdited[i]) {
			case DSEL_DESCRIPTION:
				strWhatHasBeenEdited += "description";
				break;
			case DSEL_START_DATE:
				if (!hasStartDateError) {
					strWhatHasBeenEdited += "start date";
				}
				break;
			case DSEL_END_DATE:
				if (!hasEndDateError) {
					strWhatHasBeenEdited += "end date";
				}
				break;
			case DSEL_LOCATION:
				strWhatHasBeenEdited += "location";
				break;
		}
		if (i < size - 1) {
			strWhatHasBeenEdited += ", ";
		}
	}

	std::string errorMessage = "";
	if (hasStartDateError) {
	}

	if ((hasStartDateError) || (hasEndDateError)) {
		errorMessage += " (error with setting ";
		if (hasStartDateError) {
			errorMessage += "start date";
			if (hasEndDateError) {
				errorMessage += " and ";
			}
		}
		if (hasEndDateError) {
			errorMessage += "end date";
		}
		errorMessage += ")";
	}


	return ("Task " + strEditEntryIndex + "\'s attributes (" + strWhatHasBeenEdited + ") edited" + errorMessage);
}