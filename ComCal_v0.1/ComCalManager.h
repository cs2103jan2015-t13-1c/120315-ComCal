#pragma once

#include <string>
#include <vector>
#include <stack>
#include "comAndTask.h"
#include "Task.h"
#include "typeConversions.h"
#include "keywords.h"
#include "TextStorage.h"

class ComCalManager
{
public:
	ComCalManager(int, const char**);
	~ComCalManager();

	//1) This function will deduce the mainCom and call that specific function
	//2) The String^ here will be converted to a normal c++ string the passed to the mainCom functions
	//3) A String^ class as a message that will be reflected on the feedback.
	System::String^ deduceCommand(System::String^); 

private:
	TextStorage* textEditor;
	//Whenever add, delete or edit function is successfully implemented, the opposite command and Task is stored here
	//comAndTask are only pushed into undo when a successful add/delete/edit is called
	//comAndTask are only pushed into redo when an undo is done
	std::vector<comAndTask*>* _undoHistory;
	std::vector<comAndTask*>* _redoHistory;


	// These are 2 most important vectors in the application, at the start of the application, it will initialise the
	// 2 vectors with what is in the text file from TextStorage::getTextFileInfo. All add, delete, edit, undo, redo 
	// will affect these vectors. Right after add,delete,edit is executed, these vectors will pass its information 
	// to TextStorage for storing
	std::vector<Task*>* _todoTasks;
	std::vector<Task*>* _doneTasks;

	int _numOfFiles;
	std::string _todoFileName;
	std::string _doneFileName;

	//------------------------------------Standalone Functions------------------------------------------
	//1) Standalone functions that might be useful to other mainComs
	//   probably some bool function to check some stuff


	void saveTasks(std::string fileName);
	void loadTasks(std::string fileName);


	//------------------------------------Main Functions------------------------------------------------
	//1) All the main functions with string should return to the UI a message for the feedback history
	//   so that it can be binded to the "FeedBack" textblock in the UI, a simple 'cout' from the function
	//   class itself isn't possible to my knowledge
	//2) The public deduceCommand fx will pass the input string to these main commands below
	//3) The arguments passed in the mainComs will be without the command itself eg. "add stuff" -> "stuff"

	std::string addMainCom(std::string);
	std::string showMainCom(std::string);
	
	//remark: default delete will only delete indexes from the todo file unless specifed
	//eg:"delete done 2" or "delete done 3,5,6,14,20"(deletes a number of taks) 
	//   or "delete done"(deletes all done tasks)
	std::string deleteMainCom(std::string); 
	std::string editMainCom(std::string);
	std::string undoMainCom(std::string);
	std::string redoMainCom(std::string);
	std::string searchMainCom(std::string);


	//---------------------------------Main Sub-Functions-----------------------------------------------
	//1) Below will be all the sub-functions that will be used by the MainCom functions
	//2) Add whatever function you want but it should only deal with that specific mainCom you want to handle

	//sub-functions for addMainCom
	bool isAddFormatValid(std::string);

	//sub-functions for showMainCom
	bool isShowFormatValid(std::string);

	//sub-functions for deleteMainCom
	bool isDeleteFormatValid(std::string);

	//sub-functions for editMainCom
	bool isEditFormatValid(std::string);

	//sub-functions for undoMainCom

	//sub-functions for redoMainCom

};
