//@author A0119754X
#include "TextStorage.h"
#include "keywords.h"
#include "typeConversions.h"
#include <fstream>

using namespace rapidxml;

template<class Ch>
inline std::basic_ostream<Ch> &print(std::basic_ostream<Ch> &out, const xml_node<Ch> &node, int flags = 0);

// Global static pointer used to ensure a single instance of the class
TextStorage* TextStorage::_instance = NULL;

TextStorage::TextStorage() {
	_todoTasks = new std::vector<Task*>();
}

TextStorage::~TextStorage() {
	delete _todoTasks;
}

TextStorage* TextStorage::getInstance() {
	if (_instance == NULL)
		_instance = new TextStorage();
	return _instance;
}

void TextStorage::initialize(std::string todoFileName) {
	_todoFileName = todoFileName;
	loadTasks(_todoFileName);
}

unsigned int TextStorage::getNumberOfTasks() {
	return _todoTasks->size();
}

Task* TextStorage::getTask(int index) {
	if ((index >= _todoTasks->size()) || (index < 0)) {
		return NULL;
	}
	return _todoTasks->at(index);
}

std::string TextStorage::getTodoFileName() {
	return _todoFileName;
}

void TextStorage::addTask(Task* newTask) {
	_todoTasks->push_back(newTask);
}

//@author A0085731A
void TextStorage::addTaskAtSpecificPosition(Task* newTask, int position) {
	_todoTasks->insert(_todoTasks->begin() + position - 1, newTask);
}

//@author A0119754X
bool TextStorage::deleteTask(int index) {
	if (index > _todoTasks->size())
		return false;
	if (index <= 0)
		return false;
	_todoTasks->erase(_todoTasks->begin() + index - 1);
	return true;
}


int TextStorage::displayAllTasks() {
	unsigned int size = _todoTasks->size();
	int count = 0;
	for (unsigned int i = 0; i < size; i++) {
		_todoTasks->at(i)->display();
		count++;
	}

	return count;
}

//@author A0110783L
int TextStorage::displayTodoTasks() {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);
		if (!tempTask->getIsDone()) {
			tempTask->display();
			count++;
		}
		else {
			tempTask->hide();
		}
	}
	return count;
}

int TextStorage::displayTodoTasks(const Date &date) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED && tempTask->isBetween(date) && !tempTask->getIsDone()) {
			tempTask->display();
			count++;
		}
		else {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && !tempTask->getIsDone()) {
				if (tempTask->getStartDate()->operator==(date)){
					tempTask->display();
					count++;
				}
				else {
					tempTask->hide();
				}
			}
			else {
				if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && !tempTask->getIsDone()){
					if (tempTask->getEndDate()->operator==(date)) {
						tempTask->display();
						count++;
					}
					else {
						tempTask->hide();
					}
				}
				else{
					tempTask->hide();
				}

			}
		}
	}
	return count;
}

int TextStorage::displayDoneTasks() {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);
		if (tempTask->getIsDone()) {
			tempTask->display();
			count++;
		}
		else {
			tempTask->hide();
		}
	}

	return count;
}

int TextStorage::displayDoneTasks(const Date &date) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED && tempTask->getIsDone()) {
			if (tempTask->isBetween(date)) {
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}
		else {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && tempTask->getIsDone()) {
				if (tempTask->getStartDate()->operator==(date)){
					tempTask->display();
					count++;
				}
				else {
					tempTask->hide();
				}
			}
			else {
				if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && tempTask->getIsDone()){
					if (tempTask->getEndDate()->operator==(date)) {
						tempTask->display();
						count++;
					}
					else {
						tempTask->hide();
					}
				}
				else{
					tempTask->hide();
				}
			}
		}
	}
	return count;
}

int TextStorage::displayFloatingTasks() {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (tempTask->getTaskTypeCode() == TASKTYPECODE_FLOATING) {
			tempTask->display();
			count++;
		}
		else {
			tempTask->hide();
		}
	}

	return count;
}

int TextStorage::displayFloatingTasks(bool isDone) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (tempTask->getIsDone() == isDone){
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_FLOATING) {
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}
	}

	return count;
}

int TextStorage::displayPartialTask() {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED) {
			tempTask->display();
			count++;
		}
		else {
			tempTask->hide();
		}
	}

	return count;
}

int TextStorage::displayPartialTask(int code, const Date &date) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (code == TODO_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && tempTask->getStartDate()->operator==(date) && !tempTask->getIsDone()){
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}

		if (code == DONE_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && tempTask->getStartDate()->operator==(date) && tempTask->getIsDone()){
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}

		if (code == ALL_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && tempTask->getStartDate()->operator==(date)){
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}
	}

	return count;
}

int TextStorage::displayTimedTasks() {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED) {
			tempTask->display();
			count++;
		}
		else {
			tempTask->hide();
		}
	}

	return count;
}

int TextStorage::displayTimedTasks(int code, const Date &date) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (code == TODO_CODE) {
			if ((tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED) && tempTask->isBetween(date) && !tempTask->getIsDone()) {
				count++;
				tempTask->display();
			}
			else {
				tempTask->hide();
			}
		}

		if (code == DONE_CODE) {
			if ((tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED) && tempTask->isBetween(date) && tempTask->getIsDone()) {
				count++;
				tempTask->display();
			}
			else {
				tempTask->hide();
			}
		}

		if (code == ALL_CODE) {
			if ((tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED) && tempTask->isBetween(date)) {
				count++;
				tempTask->display();
			}
			else {
				tempTask->hide();
			}
		}

	}

	return count;
}

int TextStorage::displayMonthTasks(int code, int year, int month) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;
	year -= 1900;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (code == TODOFILENAMEENTERED) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED && !tempTask->getIsDone()) {

				if ((tempTask->getStartDate()->getYear() <= year) && (tempTask->getEndDate()->getYear() >= year)) {

					if ((tempTask->getStartDate()->getYear() == year) && (tempTask->getStartDate()->getYear() == tempTask->getEndDate()->getYear()) && (tempTask->getStartDate()->getMonth() <= month) && (tempTask->getEndDate()->getMonth() >= month)) {
						tempTask->display();
						count++;
					}
					else {
						if (tempTask->getStartDate()->getYear() < year && tempTask->getEndDate()->getYear() > year) {
							tempTask->display();
							count++;
						}
						else {
							if (tempTask->getEndDate()->getYear() > year && tempTask->getStartDate()->getYear() == year && tempTask->getStartDate()->getMonth() <= month){
								tempTask->display();
								count++;
							}
							else {
								if (tempTask->getEndDate()->getYear() == year && month <= tempTask->getEndDate()->getMonth() && tempTask->getStartDate()->getYear() != tempTask->getEndDate()->getYear() && tempTask->getStartDate()->getYear() != tempTask->getEndDate()->getYear()) {
									tempTask->display();
									count++;
								}
								else {
									tempTask->hide();
								}
							}
						}
					}
				}
				else {
					tempTask->hide();
				}

			}//end tasktypecode_timed
			else {
				if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && !tempTask->getIsDone()) {
					if ((tempTask->getStartDate()->getMonth() == month) && (tempTask->getStartDate()->getYear() == year)) {
						tempTask->display();
						count++;
					}
					else {
						tempTask->hide();
					}
				}
				else {
					if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && !tempTask->getIsDone()) {
						if ((tempTask->getEndDate()->getMonth() == month) && (tempTask->getEndDate()->getYear() == year)) {
							tempTask->display();
							count++;
						}
						else {
							tempTask->hide();
						}
					}
					else {
						tempTask->hide();
					}
				}
			}
		}

		if (code == DONE_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED && tempTask->getIsDone()) {

				if ((tempTask->getStartDate()->getYear() <= year) && (tempTask->getEndDate()->getYear() >= year)) {

					if ((tempTask->getStartDate()->getYear() == year) && (tempTask->getStartDate()->getYear() == tempTask->getEndDate()->getYear()) && (tempTask->getStartDate()->getMonth() <= month) && (tempTask->getEndDate()->getMonth() >= month)) {
						tempTask->display();
						count++;
					}
					else {
						if (tempTask->getStartDate()->getYear() < year && tempTask->getEndDate()->getYear() > year) {
							tempTask->display();
							count++;
						}
						else {
							if (tempTask->getEndDate()->getYear() > year && tempTask->getStartDate()->getYear() == year && tempTask->getStartDate()->getMonth() <= month){
								tempTask->display();
								count++;
							}
							else {
								if (tempTask->getEndDate()->getYear() == year && month <= tempTask->getEndDate()->getMonth() && tempTask->getStartDate()->getYear() != tempTask->getEndDate()->getYear() && tempTask->getStartDate()->getYear() != tempTask->getEndDate()->getYear()) {
									tempTask->display();
									count++;
								}
								else {
									tempTask->hide();
								}
							}
						}
					}
				}
				else {
					tempTask->hide();
				}

			}//end tasktypecode_timed
			else {
				if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && tempTask->getIsDone()) {
					if ((tempTask->getStartDate()->getMonth() == month) && (tempTask->getStartDate()->getYear() == year)) {
						tempTask->display();
						count++;
					}
					else {
						tempTask->hide();
					}
				}
				else {
					if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && tempTask->getIsDone()) {
						if ((tempTask->getEndDate()->getMonth() == month) && (tempTask->getEndDate()->getYear() == year)) {
							tempTask->display();
							count++;
						}
						else {
							tempTask->hide();
						}
					}
					else {
						tempTask->hide();
					}
				}
			}
		}

		if (code == ALL_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED) {

				if ((tempTask->getStartDate()->getYear() <= year) && (tempTask->getEndDate()->getYear() >= year)) {

					if (tempTask->getStartDate()->getYear() == year && tempTask->getStartDate()->getYear() == tempTask->getEndDate()->getYear() && tempTask->getStartDate()->getMonth() <= month && tempTask->getEndDate()->getMonth() >= month) {
						tempTask->display();
						count++;
					}
					else {
						if (tempTask->getStartDate()->getYear() < year && tempTask->getEndDate()->getYear() > year) {
							tempTask->display();
							count++;
						}
						else {
							if (tempTask->getEndDate()->getYear() > year && tempTask->getStartDate()->getYear() == year && tempTask->getStartDate()->getMonth() <= month){
								tempTask->display();
								count++;
							}
							else {
								if (tempTask->getEndDate()->getYear() == year && month <= tempTask->getEndDate()->getMonth() && tempTask->getStartDate()->getYear() != tempTask->getEndDate()->getYear() && tempTask->getStartDate()->getYear() != tempTask->getEndDate()->getYear()) {
									tempTask->display();
									count++;
								}
								else {
									tempTask->hide();
								}
							}
						}
					}
				}
				else {
					tempTask->hide();
				}

			}//end tasktypecode_timed
			else {
				if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED) {
					if ((tempTask->getStartDate()->getMonth() == month) && (tempTask->getStartDate()->getYear() == year)) {
						tempTask->display();
						count++;
					}
					else {
						tempTask->hide();
					}
				}
				else {
					if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE) {
						if ((tempTask->getEndDate()->getMonth() == month) && (tempTask->getEndDate()->getYear() == year)) {
							tempTask->display();
							count++;
						}
						else {
							tempTask->hide();
						}
					}
					else {
						tempTask->hide();
					}
				}
			}
		}
	}
	return count;
} //end of displayMonth

int TextStorage::displayDatedTasks(int code, const Date &date) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (code == TODO_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED && !tempTask->getIsDone()){
				if (tempTask->isBetween(date)){
					tempTask->display();
					count++;
				}
				else {
					tempTask->hide();
				}
			}
			else {
				if ((tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED) && (tempTask->getStartDate()->operator==(date)) && !tempTask->getIsDone()) {
					tempTask->display();
					count++;
				}
				else {
					if ((tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE) && (tempTask->getEndDate()->operator==(date)) && !tempTask->getIsDone()) {
						tempTask->display();
						count++;
					}
					else{
						tempTask->hide();
					}
				}
			}
		}

		if (code == DONE_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED && tempTask->getIsDone()){
				if (tempTask->isBetween(date)){
					tempTask->display();
					count++;
				}
				else {
					tempTask->hide();
				}
			}
			else {
				if ((tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED) && (tempTask->getStartDate()->operator==(date)) && tempTask->getIsDone()) {
					tempTask->display();
					count++;
				}
				else {
					if ((tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE) && (tempTask->getEndDate()->operator==(date)) && tempTask->getIsDone()) {
						tempTask->display();
						count++;
					}
					else{
						tempTask->hide();
					}
				}
			}
		}

		if (code == ALL_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED){
				if (tempTask->isBetween(date)){
					tempTask->display();
					count++;
				}
				else {
					tempTask->hide();
				}
			}
			else {
				if ((tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED) && (tempTask->getStartDate()->operator==(date))) {
					tempTask->display();
					count++;
				}
				else {
					if ((tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE) && (tempTask->getEndDate()->operator==(date))) {
						tempTask->display();
						count++;
					}
					else{
						tempTask->hide();
					}
				}
			}
		}
	}
	return count;
}

int TextStorage::displayWeekTasks(int code, std::vector<Date> weekDate) {
	int count = 0;
	unsigned int todoSize = _todoTasks->size();
	unsigned int weekSize = weekDate.size();
	Task * tempTask;

	//loops through todo task
	for (int i = 0; i < todoSize; i++) {

		tempTask = _todoTasks->at(i);
		//loops through weekdate to see if the task at i corresponds to any of the dates in weekdate
		for (int j = 0; j < weekSize; j++) {

			if (code == TODO_CODE) {
				if (!tempTask->getIsDone() && tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED && tempTask->isBetween(weekDate[j])) {
					tempTask->display();
					count++;
					break;
				}
				else {
					if (!tempTask->getIsDone() && tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && tempTask->getStartDate()->operator==(weekDate[j])) {
						tempTask->display();
						count++;
						break;
					}
					else {
						if (!tempTask->getIsDone() && tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && tempTask->getEndDate()->operator==(weekDate[j])) {
							tempTask->display();
							count++;
							break;
						}
						else {
							tempTask->hide();
						}
					}
				}
			}//end of TODO_CODE

			if (code == DONE_CODE) {
				if (tempTask->getIsDone() && tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED && tempTask->isBetween(weekDate[j])) {
					tempTask->display();
					count++;
					break;
				}
				else {
					if (tempTask->getIsDone() && tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && tempTask->getStartDate()->operator==(weekDate[j])) {
						tempTask->display();
						count++;
						break;
					}
					else {
						if (tempTask->getIsDone() && tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && tempTask->getEndDate()->operator==(weekDate[j])) {
							tempTask->display();
							count++;
							break;
						}
						else {
							tempTask->hide();
						}
					}
				}
			}//end of DONE_CODE

			if (code == ALL_CODE) {
				if (tempTask->getTaskTypeCode() == TASKTYPECODE_TIMED && tempTask->isBetween(weekDate[j])) {
					tempTask->display();
					count++;
					break;
				}
				else {
					if (tempTask->getTaskTypeCode() == TASKTYPECODE_PARTIALTIMED && tempTask->getStartDate()->operator==(weekDate[j])) {
						tempTask->display();
						count++;
						break;
					}
					else {
						if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && tempTask->getEndDate()->operator==(weekDate[j])) {
							tempTask->display();
							count++;
							break;
						}
						else {
							tempTask->hide();
						}
					}
				}
			}//end of ALL_CODE

		}
	}
	return count;
}

int TextStorage::displayDeadlinedTasks() {
	int count = 0;
	unsigned int todoSize = _todoTasks->size();

	for (int i = 0; i < todoSize; i++) {
		Task* tempTask = _todoTasks->at(i);
		if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE) {
			tempTask->display();
			count++;
		}
		else {
			tempTask->hide();
		}
	}
	return count;
}

int TextStorage::displayDeadlinedTasks(int code, const Date &date) {
	int count = 0;
	unsigned int todoSize = _todoTasks->size();

	for (int i = 0; i < todoSize; i++) {
		Task* tempTask = _todoTasks->at(i);

		if (code == TODO_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && !tempTask->getIsDone() && tempTask->getEndDate()->operator==(date)) {
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}

		if (code == DONE_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && tempTask->getIsDone() && tempTask->getEndDate()->operator==(date)) {
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}

		if (code == ALL_CODE) {
			if (tempTask->getTaskTypeCode() == TASKTYPECODE_DEADLINE && tempTask->getEndDate()->operator==(date)) {
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}
	}

	return count;
}

//@author A0116683B
bool TextStorage::saveTasks(std::string fileName)
{
	xml_document<> xmlDocument;
	std::ofstream saveFile(fileName);
	if (!saveFile.is_open()) {
		return false;
	}

	xml_node<>* xmlDeclarationNode = xmlDocument.allocate_node(node_declaration);
	xmlDeclarationNode->append_attribute(xmlDocument.allocate_attribute("version", "1.0"));
	xmlDeclarationNode->append_attribute(xmlDocument.allocate_attribute("encoding", "utf-8"));
	xmlDocument.append_node(xmlDeclarationNode);

	Task* tempTask;
	Date* tempDate;
	xml_node<>* taskNode;
	xml_node<>* detailsNode;
	xml_node<>* dateNode;

	for (unsigned int i = 0; i < _todoTasks->size(); i++) {
		tempTask = _todoTasks->at(i);
		taskNode = xmlDocument.allocate_node(node_element, "task");
		xmlDocument.append_node(taskNode);

		detailsNode = xmlDocument.allocate_node(node_element, "description");
		detailsNode->value(xmlDocument.allocate_string(tempTask->getDescription().c_str()));
		taskNode->append_node(detailsNode);

		detailsNode = xmlDocument.allocate_node(node_element, "location");
		detailsNode->value(xmlDocument.allocate_string(tempTask->getLocation().c_str()));
		taskNode->append_node(detailsNode);

		for (int i = 0; i < 2; i++)
		{
			if (((i == 0) && tempTask->hasStartDate()) || ((i == 1) && tempTask->hasEndDate()))
			{
				tempDate = (i == 0) ? tempTask->getStartDate() : tempTask->getEndDate();

				detailsNode = xmlDocument.allocate_node(node_element, (i == 0) ? "startDate" : "endDate");
				detailsNode->value(tempTask->getLocation().c_str());
				taskNode->append_node(detailsNode);

				dateNode = xmlDocument.allocate_node(node_element, "day");
				dateNode->value(xmlDocument.allocate_string(typeConversions::intToString(tempDate->getDay()).c_str()));
				detailsNode->append_node(dateNode);

				dateNode = xmlDocument.allocate_node(node_element, "month");
				dateNode->value(xmlDocument.allocate_string(typeConversions::intToString(tempDate->getMonth()).c_str()));
				detailsNode->append_node(dateNode);

				dateNode = xmlDocument.allocate_node(node_element, "year");
				dateNode->value(xmlDocument.allocate_string(typeConversions::intToString(tempDate->getYear()+1900).c_str()));
				detailsNode->append_node(dateNode);

				dateNode = xmlDocument.allocate_node(node_element, "time");
				dateNode->value(xmlDocument.allocate_string(typeConversions::intToString(tempDate->getTime()).c_str()));
				detailsNode->append_node(dateNode);
			}
		}

		detailsNode = xmlDocument.allocate_node(node_element, "isDone");
		detailsNode->value(tempTask->getIsDone() ? "true" : "false");
		taskNode->append_node(detailsNode);
	}

	std::string sXml;
	print(back_inserter(sXml), xmlDocument);
 
	saveFile << sXml;
	saveFile.close();

	return true;
}

bool TextStorage::loadTasks(std::string fileName)
{
	_todoTasks->clear();

	xml_document<> xmlDocument;

	std::ifstream loadFile(fileName);
	if (!loadFile.is_open()) {
		return false;
	}

	std::vector<char> buffer((std::istreambuf_iterator<char>(loadFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');

	xmlDocument.parse<0>(&buffer[0]);

	std::string description;
	std::string location;
	std::string isDone;
	Date* startDate;
	Date* endDate;
	int day;
	int month;
	int year;
	int time;
	Task* task;
	xml_node<>* dateNode;

	for (xml_node<>* taskNode = xmlDocument.first_node("task"); taskNode != NULL; taskNode = taskNode->next_sibling()) {
		description = taskNode->first_node("description")->value();
		location = taskNode->first_node("location")->value();
		isDone = taskNode->first_node("isDone")->value();

		startDate = NULL;
		endDate = NULL;
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				dateNode = taskNode->first_node("startDate");
			}
			else {
				dateNode = taskNode->first_node("endDate");
			}
			if (dateNode != NULL) {
				day = typeConversions::stringToInt(dateNode->first_node("day")->value());
				month = typeConversions::stringToInt(dateNode->first_node("month")->value());
				year = typeConversions::stringToInt(dateNode->first_node("year")->value());
				time = typeConversions::stringToInt(dateNode->first_node("time")->value());
				if (i == 0) {
					startDate = new Date(day, month, year-1900, time);
				}
				else {
					endDate = new Date(day, month, year-1900, time);
				}
			}
		}
		
		task = new Task(description, location, startDate, endDate);
		if (isDone.compare("true") == 0) {
			task->done();
		}
		_todoTasks->push_back(task);
	}

	return true;
}