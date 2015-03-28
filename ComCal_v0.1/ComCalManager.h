#pragma once

#include <string>
#include <vector>
#include <stack>

class ComCalManager
{
private:
	static ComCalManager* _instance;

	//side bar viewer vector: This vector is used for search and show functions
	//To use this vector, delete the content in the vector then add in the searh/show info into this vector
	//The display will be done in the MonthForm.cpp by first getting this vector then displaying it on GUI
	std::vector<std::string>* _sideBarView;

	//monthDetails will be initially set to the current time
	//Changes when the show command is called, MonthForm will call for this when an update is flagged
	struct tm* monthDetails;

	//Update flags:
	//To flag to MonthForm that search/show was successfully implemented hence needing update on GUI
	//When a search/show is successfully implemented->Change the appropriate flag to true->MonthForm 
	//will change it back to false when it successfully updates the GUI
	bool isShowMonth; //is flagged whenever user asks to show a specific month
	bool isShowDayTaskSearch; //is flagged whenever user asks to show a specific day or search function is called

public:
	ComCalManager();
	~ComCalManager();

	static ComCalManager* getInstance();

	void initialise(int, const char**);

	//1) This function will deduce the mainCom and call that specific main function
	//2) The String^ here will be converted to a std::string the passed to the mainCom functions
	//3) Argument: String^ user input
	//3) Returns: a String^ message for the UI feedback
	System::String^ deduceCommand(System::String^);

	// Getter methods
	std::vector<std::string>* getSideVec();
	struct tm* getMonthDetails();
	bool getIsShowMonth();
	bool getIsShowDayTaskSearch();

	//Setter methods 
	void setDefaultSideBar(); //Set sideBar to its default of TodoTasks of the current day
};
