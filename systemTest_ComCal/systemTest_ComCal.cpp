//@author A0110783L
#include <gtest\gtest.h>
#include "ComCalManager.h"
#include "TextStorage.h"
#include <queue>
#include <string>
#define TESTMODE

class ComCalManagerTest : public ::testing::Test {
protected:
	//this is the setup method
	virtual void SetUp() {
		ComCalManager::getInstance()->deduceCommand("delete all");

		actual.push(ComCalManager::getInstance()->deduceCommand("add archery .s 10/04/2015"));
		expected.push("Added: PARTIAL-TIMED task - [D]: \"archery\"; [S]: 10/04/2015");

		actual.push(ComCalManager::getInstance()->deduceCommand("add testTask .s 10/05/2015 1500"));
		expected.push("Added: PARTIAL-TIMED task - [D]: \"testTask\"; [S]: 10/05/2015 1500");

		actual.push(ComCalManager::getInstance()->deduceCommand("add soccer .s 21/04/2015 .e 22/05/2015 .l loc"));
		expected.push("Added: TIMED task - [D]: \"soccer\"; [S]: 21/04/2015; [E]: 22/05/2015; [L]: \"loc\"");

		actual.push(ComCalManager::getInstance()->deduceCommand("show may 2015"));
		expected.push("may 2015 (Show count: 2)");

		actual.push(ComCalManager::getInstance()->deduceCommand("edit 2 .s 15/04/2015"));
		expected.push("Edited [S] of EVENT (2):[D]: \"testTask\"; [S]: 15/04/2015");

		actual.push(ComCalManager::getInstance()->deduceCommand("add play .s 10/12/2018 1500 .e 21/06/2020 .l nus"));
		expected.push("Added: TIMED task - [D]: \"play\"; [S]: 10/12/2018 1500; [E]: 21/06/2020; [L]: \"nus\"");

		actual.push(ComCalManager::getInstance()->deduceCommand("show 15/04/2015"));
		expected.push("15/04/2015 tasks (Show count: 1)");

		actual.push(ComCalManager::getInstance()->deduceCommand("edit 2 .s -"));
		expected.push("Edited [S-D] of EVENT to TO-DO (2): [D]: \"testTask\"");

		actual.push(ComCalManager::getInstance()->deduceCommand("show 15/04/2015"));
		expected.push("There are zero show results");

		actual.push(ComCalManager::getInstance()->deduceCommand("show week 19/02/2019"));
		expected.push("19/02/2019 weekTasks (Show count: 1)");

		actual.push(ComCalManager::getInstance()->deduceCommand("search nus"));
		expected.push("Executed search of: (nus )");

		actual.push(ComCalManager::getInstance()->deduceCommand("delete 1 3"));
		expected.push("Deleted task(s): (1), (3).");

		actual.push(ComCalManager::getInstance()->deduceCommand("show"));
		expected.push("There are zero show results");

		actual.push(ComCalManager::getInstance()->deduceCommand("add some old war .s 10/14/1890 1500 .e 04/07/1700 .l nus"));
		expected.push("Invalid add command: Invalid start date and time format (please enter: DD/MM/YYYY HHMM)");

		actual.push(ComCalManager::getInstance()->deduceCommand("add freedom day .s 04/07/2015 20000 .e 04/07/2015   1900 .l nus"));
		expected.push("Invalid add command: Invalid start date and time format (please enter: DD/MM/YYYY HHMM)");

		actual.push(ComCalManager::getInstance()->deduceCommand("done 2"));
		expected.push("Marked completed task(s): (2).");

		actual.push(ComCalManager::getInstance()->deduceCommand("show done"));
		expected.push("All done tasks shown in sideBar (Show count: 1)");

		actual.push(ComCalManager::getInstance()->deduceCommand("show todo"));
		expected.push("All todo tasks shown in sideBar (Show count: 1)");

		actual.push(ComCalManager::getInstance()->deduceCommand("add april's fool .s 01/04/2015 1500"));
		expected.push("Added: PARTIAL-TIMED task - [D]: \"april's fool\"; [S]: 01/04/2015 1500");

		actual.push(ComCalManager::getInstance()->deduceCommand("add april may die .s 01/04/2015 1500 .e 05/04/2015 1600 .l waterpark"));
		expected.push("Added: TIMED task - [D]: \"april may die\"; [S]: 01/04/2015 1500; [E]: 05/04/2015 1600; [L]: \"waterpark\"");

		actual.push(ComCalManager::getInstance()->deduceCommand("add apr...on .e 26/04/2015 1500"));
		expected.push("Added: DEADLINE task - [D]: \"apr...on\"; [E]: 26/04/2015 1500");

		actual.push(ComCalManager::getInstance()->deduceCommand("add exe. .d scorpion from 10/04/2015 1500 to 13/04/2015 1600 .l waterpark"));
		expected.push("Added: TIMED task - [D]: \"scorpion\"; [S]: 10/04/2015 1500; [E]: 13/04/2015 1600; [L]: \"waterpark\"");

		actual.push(ComCalManager::getInstance()->deduceCommand("show week 08/04/2015"));
		expected.push("08/04/2015 weekTasks (Show count: 2)");

		actual.push(ComCalManager::getInstance()->deduceCommand("add C'mon april baby .s 15/04/2015 1500"));
		expected.push("Added: PARTIAL-TIMED task - [D]: \"C'mon april baby\"; [S]: 15/04/2015 1500");

		actual.push(ComCalManager::getInstance()->deduceCommand("redo"));
		expected.push("Error: No previous undo actions to redo.");

		actual.push(ComCalManager::getInstance()->deduceCommand("done 6"));
		expected.push("Marked completed task(s): (6).");
	}

	//this functions acts like a dsetructor
	virtual void TearDown() {

	}

	std::queue<std::string> expected;
	std::queue<std::string> actual;
};

class ShowFunctionTest : public ::testing::Test{
protected:
	//this is the setup method
	virtual void SetUp() {
		ComCalManager::getInstance()->deduceCommand("delete all");

		ComCalManager::getInstance()->deduceCommand("add archery .s 10/04/2015");
		ComCalManager::getInstance()->deduceCommand("add testTask .s 10/05/2015 1500");
		ComCalManager::getInstance()->deduceCommand("add soccer .s 21/04/2015 .e 22/05/2015 .l loc");
		ComCalManager::getInstance()->deduceCommand("add play .s 10/12/2018 1500 .e 21/06/2020 .l nus");
		ComCalManager::getInstance()->deduceCommand("add freedom   day .s   04/07/2015 20000 .e 04/07/2015   2300 .l nus");
		ComCalManager::getInstance()->deduceCommand("add april's fool .s 01/04/2015 1500");
		ComCalManager::getInstance()->deduceCommand("add I wanna watch GoT .s 03/04/2015 1500");
		ComCalManager::getInstance()->deduceCommand("add april may die .s 01/04/2015 1500 .e 05/04/2015 1600 .l waterpark");
		ComCalManager::getInstance()->deduceCommand("add apr...on .e 26/04/2015 1500");
		ComCalManager::getInstance()->deduceCommand("add exe. .d scorpion from 10/04/2015 1500 to 13/04/2015 1600 .l waterpark");
		ComCalManager::getInstance()->deduceCommand("add C'mon april baby .s 15/04/2015 1500");
		ComCalManager::getInstance()->deduceCommand("done 6");
	}

	virtual void TearDown() {

	}
};

class SearchFunctionTest : public ::testing::Test{
protected:
	//this is the setup method
	virtual void SetUp() {
		ComCalManager::getInstance()->deduceCommand("delete all");

		ComCalManager::getInstance()->deduceCommand("add archery .s 10/04/2015");
		ComCalManager::getInstance()->deduceCommand("add testTask .s 10/05/2015 1500");
		ComCalManager::getInstance()->deduceCommand("add soccer .s 21/04/2015 .e 22/05/2015 .l loc");
		ComCalManager::getInstance()->deduceCommand("add play .s 10/12/2018 1500 .e 21/06/2020 .l nus");
		ComCalManager::getInstance()->deduceCommand("add freedom   day .s   04/07/2015 2000 .e 04/07/2015   2300 .l nus");
		ComCalManager::getInstance()->deduceCommand("add april's fool .s 01/04/2015 1500");
		ComCalManager::getInstance()->deduceCommand("add I wanna watch GoT .s 03/04/2015 1500");
		ComCalManager::getInstance()->deduceCommand("add april may die .s 01/04/2015 1500 .e 05/04/2015 1600 .l waterpark");
		ComCalManager::getInstance()->deduceCommand("add apr...on .e 26/04/2015 1500");
		ComCalManager::getInstance()->deduceCommand("add exe. .d scorpion from 10/04/2015 1500 to 13/04/2015 1600 .l waterpark");
		ComCalManager::getInstance()->deduceCommand("add C'mon april baby .s 15/04/2015 1500");
		ComCalManager::getInstance()->deduceCommand("done 6");
	}

	virtual void TearDown() {

	}
};

TEST_F(ShowFunctionTest, showDone) {
	int expected = 1;
	int actual = 0;
	Task* tempTask;
	TextStorage::getInstance()->displayDoneTasks();
	unsigned int size = TextStorage::getInstance()->getNumberOfTasks();

	for (int i = 0; i < size; i++) {
		tempTask = TextStorage::getInstance()->getTask(i);
		if (!tempTask->isHidden()) {
			actual++;
		}
	}

	ASSERT_EQ(expected, actual);
}

TEST_F(ShowFunctionTest, showTodo) {
	int expected = 1;
	int actual = 0;
	Task* tempTask;
	TextStorage::getInstance()->displayTodoTasks();
	unsigned int size = TextStorage::getInstance()->getNumberOfTasks();

	for (int i = 0; i < size; i++) {
		tempTask = TextStorage::getInstance()->getTask(i);
		if (tempTask->isHidden()) {
			actual++;
		}
	}

	ASSERT_EQ(expected, actual);
}

TEST_F(ShowFunctionTest, showDate) {
	Date * testDate = new Date();
	testDate->setDate("03/04/2015");
	Task * tempTask;
	int actual = 0;
	int expected = 2;

	TextStorage::getInstance()->displayDatedTasks(ALL_CODE, *testDate);
	unsigned int size = TextStorage::getInstance()->getNumberOfTasks();

	for (int i = 0; i < size; i++) {
		tempTask = TextStorage::getInstance()->getTask(i);
		
		if (!tempTask->isHidden()) {
			actual++;
		}
	}

	ASSERT_EQ(expected, actual);

	delete testDate;
	testDate = nullptr;
}

TEST_F(ComCalManagerTest, feedBackTest){
	int actualStage = 0;
	int expectedStage = expected.size();

	while (!expected.empty() && !actual.empty()) {

		if (expected.front() == actual.front()) {
			actualStage++;
		}
		actual.pop();
		expected.pop();
	}

	ASSERT_EQ(expectedStage, actualStage);
}

TEST(addTest, test1) {
	std::queue<std::string> expected;
	std::queue<std::string> actual;

	ComCalManager::getInstance()->deduceCommand("delete all");

	actual.push(ComCalManager::getInstance()->deduceCommand("add archery .s 10/04/2015"));
	expected.push("Added: PARTIAL-TIMED task - [D]: \"archery\"; [S]: 10/04/2015");
	

	ASSERT_EQ(expected.front(), actual.front());
}

TEST(addTest, test2) {
	std::queue<std::string> expected;
	std::queue<std::string> actual;

	ComCalManager::getInstance()->deduceCommand("delete all");

	actual.push(ComCalManager::getInstance()->deduceCommand("add testTask .s 10/05/2015 1500"));
	expected.push("Added: PARTIAL-TIMED task - [D]: \"testTask\"; [S]: 10/05/2015 1500");

	ASSERT_EQ(expected.front(), actual.front());
}

TEST(addTest, test3) {
	std::queue<std::string> expected;
	std::queue<std::string> actual;

	ComCalManager::getInstance()->deduceCommand("delete all");

	actual.push(ComCalManager::getInstance()->deduceCommand("add soccer .s 21/04/2015 .e 22/05/2015 .l loc"));
	expected.push("Added: TIMED task - [D]: \"soccer\"; [S]: 21/04/2015; [E]: 22/05/2015; [L]: \"loc\"");

	ASSERT_EQ(expected.front(), actual.front());
}

TEST(addTest, test4) {
	std::queue<std::string> expected;
	std::queue<std::string> actual;

	ComCalManager::getInstance()->deduceCommand("delete all");

	actual.push(ComCalManager::getInstance()->deduceCommand("add play .s 10/12/2018 1500 .e 21/06/2020 .l nus"));
	expected.push("Added: TIMED task - [D]: \"play\"; [S]: 10/12/2018 1500; [E]: 21/06/2020; [L]: \"nus\"");

	ASSERT_EQ(expected.front(), actual.front());
}
