// Delete.h
// Subclass of Command; implements the delete function
//@author A011954X

#pragma once

#include "Command.h"
#include <vector>

class Delete : public Command {
private:
	std::vector<int> deletedTaskIndexes;
	std::vector<Task*> _deletedTasks;
	int deletedCount;
	
	void deleteMultipleTasks(std::string argument);
public:
	Delete();
	~Delete();
	std::string execute(std::string argument);
	std::string undo();
	std::string redo();
};