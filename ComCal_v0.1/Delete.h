//@author A0085731A
// Delete.h
// Subclass of Command; implements the delete function
#pragma once

#include "Command.h"
#include "typeConversions.h"
#include "TextStorage.h"
#include "Exceptions.h"
#include "support.h"

#include <vector>
#include <algorithm>

class Delete : public Command {
private:
	std::vector<int> _deletedTasksIndexes;
	std::vector<Task*> _deletedTasks;
	int _deletedCount;

	void process(std::string);

public:
	Delete();
	~Delete();
	std::string execute(std::string argument);
	std::string undo();
	std::string redo();
};