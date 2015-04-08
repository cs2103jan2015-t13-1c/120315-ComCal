// SearchCondition.h
// Class to hold search condition information
//@author A0085731A

#pragma once

#include "support.h"

#include <vector>
#include <string>

class SearchCondition {
private:
	/****************************************************************************************************
	Name: _condition
	Type: int
	Purpose: Holds condition int code of this object.
	****************************************************************************************************/
	int _condition;
	
	/****************************************************************************************************
	Name: _attributeKeywords
	Type: Vector of strings attribute
	Purpose: Holds recognised attribute keywords.
	****************************************************************************************************/
	std::vector<std::string> _attributeKeywords;

	/****************************************************************************************************
	Name: _attributesToSearch
	Type: Vector of strings attribute
	Purpose: Holds attributes to search.
	****************************************************************************************************/
	std::vector<int> _attributesToSearch;

	/****************************************************************************************************
	Name: _contentsToSearch
	Type: Vector of strings attribute
	Purpose: Holds contents of each corresponding index attribute to search.
	****************************************************************************************************/
	std::vector<std::string> _contentsToSearch;

public:
	/****************************************************************************************************
	Name: SearchCondition
	Type: Constructor
	Purpose: Constructs search condition object with associated condition int code.
	****************************************************************************************************/
	SearchCondition(int);
	~SearchCondition();

	/****************************************************************************************************
	Name: setContents
	Type: Method
	Purpose: Furnish attributes and contents to search with input string.
	****************************************************************************************************/
	void setContents(std::string);

	/****************************************************************************************************
	Name: getCondition
	Type: Method
	Purpose: Returns condition int code.
	****************************************************************************************************/
	int getCondition();

	/****************************************************************************************************
	Name: getAttributesToSearch
	Type: Method
	Purpose: Returns vector of strings of attributes to search.
	****************************************************************************************************/
	std::vector<int> getAttributesToSearch();

	/****************************************************************************************************
	Name: getContentsToSearch
	Type: Method
	Purpose: Returns vector of strings of corresponding contents to search.
	****************************************************************************************************/
	std::vector<std::string> getContentsToSearch();
};