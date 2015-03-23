#pragma once

#include <string>
#include <vector>
#include <stack>

#include "comAndTask.h"
#include "Task.h"
#include "typeConversions.h"
#include "keywords.h"
#include "TextStorage.h"
#include "ErrorLog.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class ComCalManager
{
public:
	ComCalManager(int, const char**);
	~ComCalManager();

	//1) This function will deduce the mainCom and call that specific main function
	//2) The String^ here will be converted to a std::string the passed to the mainCom functions
	//3) Argument: String^ user input
	//3) Returns: a String^ message for the UI feedback
	System::String^ deduceCommand(System::String^);

	//Update flags:
	//To flag to MonthForm that search/show was successfully implemented hence needing update on GUI
	//When a search/show is successfully implemented->Change the appropriate flag to true->MonthForm 
	//will change it back to false when it successfully updates the GUI
	bool isShowMonth; //is flagged whenever user asks to show a specific month
	bool isShowDayTaskSearch; //is flagged whenever user asks to show a specific day or search function is called

	//returns _sideBarVec*
	std::vector<std::string>* getSideVec();

	//gets monthDetails
	struct tm* getMonthDetails();

protected:
	//monthDetails will be initially set to the current time
	//Changes when the show command is called, MonthForm will call for this when an update is flagged
	struct tm* monthDetails;

private:

	//side bar viewer vector: This vector is used for search and show functions
	//To use this vector, delete the content in the vector then add in the searh/show info into this vector
	//The display will be done in the MonthForm.cpp by first getting this vector then displaying it on GUI
	std::vector<std::string>* _sideBarView;

	//------------------------------------Main Functions------------------------------------------------
	//1) All the main functions with string should return to the UI a message for the feedback history
	//   so that it can be binded to the "FeedBack" textblock in the UI, a simple 'cout' from the function
	//   class itself isn't possible to my knowledge
	//2) The public deduceCommand fx will pass the input string to these main commands below
	//3) The arguments passed in the mainComs will be without the command itself eg. "add stuff" -> "stuff"
	//4) We should make classes for each mainCom i guess, to adhere to SE principles but it should still pass
	//	 back a string as feedback for the UI

	std::string showMainCom(std::string); //Hamzah
	
	//remark: default delete will only delete indexes from the todo file unless specifed
	//eg:"delete done 2" or "delete done 3,5,6,14,20"(deletes a number of taks) 
	//   or "delete done"(deletes all done tasks)
	std::string deleteMainCom(std::string); //weiliang
	std::string editMainCom(std::string); //huangqin
	std::string undoMainCom(std::string); //huangqin
	std::string redoMainCom(std::string); //huangqin
	std::string searchMainCom(std::string); //weiliang
};
