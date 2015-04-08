// SearchCondition.cpp
// Implementation of functions in SearchCondition class
//@author A0085731A

#include "SearchCondition.h"

SearchCondition::SearchCondition(int condition) {
	_attributeKeywords.assign(ATTRIBUTEKEYWORDSARRAY, ATTRIBUTEKEYWORDSARRAY + ATTRIBUTEKEYWORDSARRAYSIZE);

	_condition = condition;
}

SearchCondition::~SearchCondition() {
}

void SearchCondition::setContents(std::string contents) {
	std::vector<std::vector<std::string>> keywordsAndParams = support::extractParamsForKeywords(contents, _attributeKeywords);

	if (contents != "") {
		_attributesToSearch.push_back(INDEX_WILDCARD);
		_contentsToSearch.push_back(contents);
	}
	for (unsigned int i = 0; i < keywordsAndParams.size(); i++) {
		if (!keywordsAndParams[i].empty()) {
			if (keywordsAndParams[i][0] == "") {
				throw exceptionInputMissingAttributeParam;
			}

			switch (i) {
			case INDEX_DESCRIPTION:
				_attributesToSearch.push_back(INDEX_DESCRIPTION);
				break;
			case INDEX_STARTDATETIME:
				_attributesToSearch.push_back(INDEX_STARTDATETIME);
				break;
			case INDEX_ENDDATETIME:
				_attributesToSearch.push_back(INDEX_ENDDATETIME);
				break;
			case INDEX_LOCATION:
				_attributesToSearch.push_back(INDEX_LOCATION);
				break;
			}

			_contentsToSearch.push_back(keywordsAndParams[i][0]);
		}
	}
}

int SearchCondition::getCondition() {
	return _condition;
}

std::vector<int> SearchCondition::getAttributesToSearch() {
	return _attributesToSearch;
}

std::vector<std::string> SearchCondition::getContentsToSearch() {
	return _contentsToSearch;
}