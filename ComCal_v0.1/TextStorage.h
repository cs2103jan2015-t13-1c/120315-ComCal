//Prasoon handles this whole part of the code

#pragma once
#include <string>
#include <vector>
#include "Task.h"
#include "keywords.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//store, sort and updates the textfile
class TextStorage
{
private:
	std::string _todoFileName;
	std::string _doneFileName;

	std::vector<Task*>* _todoVec;
	std::vector<Task*>* _doneVec;


	//used to store tasks that pass deadline during sortAndUpdate() then Tasks in the vector will be stored into
	//_doneFileName textFile in storeDeadlines()
	std::vector<Task>* _passedDeadline;


	//Function: used to store _passedDeadline into _doneFileName text file before storeUpdateSortTasks
	void storeDeadlines();


	//**Just think storing->updating->sorting at the same time would be more efficient?? Cant be too sure but its
	//up to whoever does this if he wants to change it as long as a sorted vec is passed when needed in getSortedVec
	//Function: Sort text file according to date and start time. If string passed in argument is _todoFileName
	//          then update function will be called inside to remove any task in todo that has passed deadline
	//          and store those tasks in _passDeadlineVec to be stored in todo
	//This function will only be called **ONCE** straight after the application runs and before initialising
	//std::vector<Task*>* _todoTasks and std::vector<Task*>* _doneTasks in ComCalManger.h
	//Arguement: either _todofileName or _doneFileName
	void storeUpdateSortTasksInVec(std::string);

public:

	//Arguments: 1st - todo file name, 2nd - done file name
	TextStorage(std::string, std::string);
	~TextStorage();


	//Use to return all Tasks within the Todo or done files
	//Argument: either todo or done text file name specified
	//Returns: vector of Tasks, either _todoVec or _doneVec depending what string arg is passed
	std::vector<Task*>* getSortedVec(std::string);


	//Function: use to update _todoVec or _doneVec whenever add, edit, delete is called
	//Argument: 1st - vector either _todoTasks* or _doneTasks* from ComCalManager 2nd - string either todoFileName 
	//or doneFileName
	//Return: void
	void updateTodoVec(std::vector<Task>*, std::string);
};

