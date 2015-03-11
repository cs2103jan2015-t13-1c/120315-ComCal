#pragma once

#include <string>
#include <vector>
#include "Task.h"

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
	std::vector<Task*>* _tasks;

	int _numOfFiles;
	std::string _todoFileName;
	std::string _doneFileName;

	std::string convertStrTostr(System::String^); // Converts System::String^ into std::string
	System::String^ convertstrToStr(std::string); // Converts std::string into System::String^

	//------------------------------------Standalone Functions------------------------------------------
	//1) Standalone functions that might be useful to other mainComs
	//   probably some bool function to check some stuff
	bool isDateValid(std::string);
	bool isTimeValid(std::string);
	bool isDayValid(std::string);
	bool isClashing(std::string);
	bool isIndexValid(std::string);

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

