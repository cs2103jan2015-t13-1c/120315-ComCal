#include "TextStorage.h"

TextStorage::TextStorage(std::string todoFileName, std::string doneFileName){
	_todoFileName = todoFileName;
	_doneFileName = doneFileName;

	_todoVec = new std::vector<Task*>();
	_doneVec = new std::vector<Task*>();
	_passedDeadline = new std::vector<Task>();
}

TextStorage::~TextStorage(){
	delete _todoVec;
	delete _doneVec;
	delete _passedDeadline;
}

std::vector<Task*>* TextStorage::getSortedVec(std::string fileName){

		if (fileName == _todoFileName){
			return _todoVec;
		}

		if (fileName == _doneFileName){
			return _doneVec;
		}

}