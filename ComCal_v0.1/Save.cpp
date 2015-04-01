// Save.cpp
// Implementation of functions in the Save class
//@author A0119754X

#include "Save.h"
#include "TextStorage.h"
#include "keywords.h"

std::string Save::execute(std::string argument) {
	if (argument.compare("") == 0) {
		argument = FILENAME_TODODEFAULT;
	}
	TextStorage::getInstance()->saveTasks(argument);
	return ("Tasks saved to " + argument + " successfully.");
}