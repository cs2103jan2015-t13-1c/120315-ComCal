// Delete.h
// Subclass of Command; implements the delete function
//@author A011954X

#pragma once

#include "Command.h"
#include <vector>

class Delete : public Command {
private:
	std::vector<int>* deletedTasks;
	int deletedCount;
	
	void deleteMultipleTasks(std::string argument);
public:
	std::string execute(std::string argument);
};