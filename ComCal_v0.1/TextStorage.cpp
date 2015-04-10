#include "TextStorage.h"

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

bool TextStorage::deleteTask(int index) {
	if (index > _todoTasks->size())
		return false;
	if (index <= 0)
		return false;
	_todoTasks->erase(_todoTasks->begin() + index - 1);
	return true;
}

void TextStorage::displayAllTasks() {
	unsigned int size = _todoTasks->size();
	for (unsigned int i = 0; i < size; i++) {
		_todoTasks->at(i)->display();
	}
}

int TextStorage::displayTodoTasks() {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);
		if (!tempTask->getIsDone()) {
			tempTask->display();
			count ++;
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

		if (tempTask->hasStartDate() && !tempTask->getIsDone()) {
			if (tempTask->getStartDate()->operator==(date)){
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}
		else {
			if (tempTask->hasEndDate() && !tempTask->getIsDone()){
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

		if (tempTask->hasStartDate() && tempTask->getIsDone()) {
			if (tempTask->getStartDate()->operator==(date)){
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}
		else {
			if (tempTask->hasEndDate() && tempTask->getIsDone()){
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
	return count;
}

int TextStorage::displayFloatingTasks() {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (!tempTask->hasStartDate() && !tempTask->hasEndDate()) {
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
			if (!tempTask->hasStartDate() && !tempTask->hasEndDate()) {
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

//1 = January, 2 = February, etc.
int TextStorage::displayMonthTasks(int month) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);
		if (tempTask->hasStartDate()) {
			if (tempTask->getStartDate()->getMonth() == month) {
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}
		else {
			if (tempTask->hasEndDate()) {
				if (tempTask->getStartDate()->getMonth() == month) {
					tempTask->display();
				count++;
				}
				else {
					tempTask->hide();
				}
			}
		}
	}
	return count;
}

int TextStorage::displayMonthTasks(int year, int month) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);

		if (tempTask->hasStartDate()) {
			if ((tempTask->getStartDate()->getMonth() == month) && (tempTask->getStartDate()->getYear()+1900 == year)) {
				tempTask->display();
				count++;
			}
			else {
				tempTask->hide();
			}
		}
		else {
			if (tempTask->hasEndDate()) {
				if ((tempTask->getEndDate()->getMonth() == month) && (tempTask->getEndDate()->getYear()+1900 == year)) {
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
	return count;
}

int TextStorage::displayDatedTasks(const Date &date) {
	int count = 0;
	unsigned int size = _todoTasks->size();
	Task* tempTask;

	for (unsigned int i = 0; i < size; i++) {
		tempTask = _todoTasks->at(i);
		if ((tempTask->hasStartDate()) && (tempTask->getStartDate()->operator==(date))) {
			tempTask->display();
			count++;
		}
		else {
			tempTask->hide();
		}
	}
	return count;
}

int TextStorage::displayWeekTasks(std::vector<Date> weekDate) {
	int count = 0;
	unsigned int todoSize = _todoTasks->size();
	unsigned int weekSize = weekDate.size();

	//loops through todo task
	for (int i = 0; i < todoSize; i++) {
		//loops through weekdate to see if the task at i corresponds to any of the dates in weekdate
		for (int j = 0; j < weekSize; j++) {

			if (_todoTasks->at(i)->hasStartDate()) {
				if (_todoTasks->at(i)->getStartDate()->getDay() == weekDate[j].getDay() && _todoTasks->at(i)->getStartDate()->getMonth() == weekDate[j].getMonth() && _todoTasks->at(i)->getStartDate()->getYear() == weekDate[j].getYear()) {
					_todoTasks->at(i)->display();
					count++;
					break;
				}
				else {
					_todoTasks->at(i)->hide();
				}
			}
			else if (_todoTasks->at(i)->hasEndDate()) {
				if (_todoTasks->at(i)->getEndDate()->getDay() == weekDate[j].getDay() && _todoTasks->at(i)->getEndDate()->getMonth() == weekDate[j].getMonth() && _todoTasks->at(i)->getEndDate()->getYear() == weekDate[j].getYear()) {
					_todoTasks->at(i)->display();
					count++;
					break;
				}
				else {
					_todoTasks->at(i)->hide();
				}

			}
		}
	}
	return count;
}

int TextStorage::displayDeadlinedTasks() {
	int count = 0;
	unsigned int todoSize = _todoTasks->size();

	for (int i = 0; i < todoSize; i++) {
		Task* tempTask = _todoTasks->at(i);
		if (tempTask->hasEndDate()) {
			tempTask->display();
			count++;
		}
		else {
			tempTask->hide();
		}
	}
	return count;
}

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