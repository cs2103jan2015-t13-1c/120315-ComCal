//@author A0085731A
// SearchCondition.cpp
// Implementation of functions in SearchCondition class

#include "SearchCondition.h"

SearchCondition::SearchCondition(int condition) {
	_attributeKeywords.assign(ATTRIBUTEKEYWORDSARRAY, ATTRIBUTEKEYWORDSARRAY + ATTRIBUTEKEYWORDSARRAYSIZE);

	_condition = condition;
}

SearchCondition::~SearchCondition() {
}

void SearchCondition::setContents(std::string contents) {
	contents = " " + contents;
	std::vector<std::vector<std::string>> keywordsAndParams = support::extractParamsForKeywords(contents, _attributeKeywords);

	if (contents != "") {
		_attributesToSearch.push_back(INDEX_WILDCARD);
		contents = contents.substr(1);
		std::vector<std::string> contentsToSearch;
		contentsToSearch.push_back(contents);
		_contentsToSearch.push_back(contentsToSearch);
	}
	for (unsigned int i = 0; i < keywordsAndParams.size(); i++) {
		if (!keywordsAndParams[i].empty()) {
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

			for (unsigned int j = 0; j < keywordsAndParams[i].size(); j++) {
				if (keywordsAndParams[i][j] == "") {
					throw exceptionInputMissingAttributeParam;
				}
			}
			_contentsToSearch.push_back(keywordsAndParams[i]);
		}
	}
}

int SearchCondition::getCondition() {
	return _condition;
}

std::vector<int> SearchCondition::getAttributesToSearch() {
	return _attributesToSearch;
}

std::vector<std::vector<std::string>> SearchCondition::getContentsToSearch() {
	return _contentsToSearch;
}