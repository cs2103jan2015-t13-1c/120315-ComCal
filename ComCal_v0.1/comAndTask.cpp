#include "comAndTask.h"

comAndTask::comAndTask(std::string command, Task task) {
	_task = task;
	_command = command;
}

comAndTask::~comAndTask() {

}

std::string comAndTask::getCommand() {
	return _command;
}

Task comAndTask::getTask() {
	return _task;
}

