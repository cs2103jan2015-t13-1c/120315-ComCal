//@author A0119754X

#pragma once

#include <string>
#include <vector>
#include "Task.h"
#include "keywords.h"
#include "typeConversions.h"
#include <fstream>
#include <vector>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

//store, sort and updates the textfile
class TextStorage {
private:
	static TextStorage* _instance;
	TextStorage();
	~TextStorage();
	TextStorage(TextStorage const&);
	TextStorage& operator=(TextStorage const&);

	std::string _todoFileName;

	// These are 2 most important vectors in the application, at the start of the application, it will initialise the
	// 2 vectors with what is in the text file from TextStorage::getTextFileInfo. All add, delete, edit, undo, redo 
	// will affect these vectors. Right after add,delete,edit is executed, these vectors will pass its information 
	// to TextStorage for storing
	std::vector<Task*>* _todoTasks;

public:
	static TextStorage* getInstance();

	void initialize(std::string todoFileName);

	unsigned int getNumberOfTasks();
	Task* getTask(int index);
	std::string getTodoFileName();

	void addTask(Task* newTask);
	void addTaskAtSpecificPosition(Task* newTask, int position);
	bool deleteTask(int index);

	int displayAllTasks();

	int displayTodoTasks();
	int displayTodoTasks(const Date &date);

	int displayDoneTasks();
	int displayDoneTasks(const Date &date);

	int displayTimedTasks();
	int displayTimedTasks(int code, const Date &date);

	int displayPartialTask();
	int displayPartialTask(int code, const Date &date);

	int displayFloatingTasks();
	int displayFloatingTasks(bool isDone);

	int displayDeadlinedTasks();
	int displayDeadlinedTasks(int code,const Date &date);

	int displayMonthTasks(int code, int year, int month);

	int displayDatedTasks(int code, const Date &date);

	int displayWeekTasks(int code, std::vector<Date>);

	

	bool saveTasks(std::string fileName);
	bool loadTasks(std::string fileName);
};
