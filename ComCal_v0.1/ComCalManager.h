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
	std::string _sideBarTitle;

	//monthDetails will be initially set to the current time
	//Changes when the show command is called, MonthForm will call for this when an update is flagged
	struct tm* _monthDetails;

	//Update flags:
	//To flag to MonthForm that add/delete/search/edit/redo/undo was successfully implemented hence needing update on GUI
	//When a search/show is successfully implemented->Change the appropriate flag to true->MonthForm 
	//will change it back to false when it successfully updates the GUI

	//Month Flags: Only 1 flag allowed to be true at one time
	//These flags will update only the calendar
	bool _isShowMonth; //is flagged whenever user asks to show a specific month

	//Sidebar Flags: Only 1 flag is allowed to be true at one time
	//These flags will cause changes to the _sideBarView vector and hence to the sideBar in GUI
	bool _isAllTodo;
	bool _isShowDayTaskSearch; //is flagged whenever user asks to show a specific day
	bool _isSearchResults; //is flagged whenever user commands a search result

public:
	ComCalManager();
	~ComCalManager();

	static ComCalManager* getInstance();

	void initialise(int, const char**);

	//1) This function will deduce the mainCom and call that specific main function
	//2) The String^ here will be converted to a std::string the passed to the mainCom functions
	//3) Argument: std::string user input
	//3) Returns: std::string message for the UI feedback
	std::string deduceCommand(std::string);

	// Getter methods
	std::vector<std::string>* getSideVec();
	struct tm* getMonthDetails();

	bool getIsShowMonth();
	bool getIsShowDayTaskSearch();
	bool getIsAllTodo();

	std::string getSideBarTitle();

	//Setter methods 
	void setDefaultSideBar(); //Set sideBar to its default of TodoTasks of the current day

	void setIsShowMonth(bool);
	void setIsShowDayTaskSearch(bool);
	void setIsAllTodo(bool);

	void setMonthDetails(struct tm*);
	void setSideBarTitle(std::string);
};
