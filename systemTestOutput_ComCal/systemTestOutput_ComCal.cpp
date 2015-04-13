//@author A0110783L
#include <gtest\gtest.h>
#include "ComCalManager.h"
#include <queue>
#include <string>

class ComCalManagerTest : public ::testing::Test {
protected:
	//this is the setup method
	virtual void SetUp() {
		actual.push(ComCalManager::getInstance()->deduceCommand("add testTask .s 10/04/2015"));
		expected.push("Added: PARTIAL-TIMED task - [D]: testTask; [S]: 10/4/15 0000; ");

		actual.push(ComCalManager::getInstance()->deduceCommand("add testTask .s 10/04/2015 1500"));
		expected.push("Added: PARTIAL-TIMED task - [D]: testTask; [S]: 10/4/15 1500; ");

		actual.push(ComCalManager::getInstance()->deduceCommand("add testTask .s 21/04/2015 .e 22/04/2015 .l loc"));
		expected.push("Added: TIMED task - [D]: testTask; [S]: 21/4/15 0000; [E]: 22/4/15 0000; [L]: loc");

		actual.push(ComCalManager::getInstance()->deduceCommand("show may 2015"));
		expected.push("may 2015 shown");
	}

	//this functions acts like a dsetructor
	virtual void TearDown() {

	}

	std::queue<std::string> expected;
	std::queue<std::string> actual;
};

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

	actual.push(ComCalManager::getInstance()->deduceCommand("add testTask .s 10/04/2015"));
	expected.push("Added: PARTIAL-TIMED task - [D]: testTask; [S]: 10/4/15 0000; ");

	ASSERT_EQ(expected.front(), actual.front());
}

TEST(addTest, test2) {
	std::queue<std::string> expected;
	std::queue<std::string> actual;

	actual.push(ComCalManager::getInstance()->deduceCommand("add testTask .s 10/04/2015 1500"));
	expected.push("Added: PARTIAL-TIMED task - [D]: testTask; [S]: 10/4/15 1500; ");

	ASSERT_EQ(expected.front(), actual.front());
}

TEST(addTest, test3) {
	std::queue<std::string> expected;
	std::queue<std::string> actual;

	actual.push(ComCalManager::getInstance()->deduceCommand("add testTask .s 21/04/2015 .e 22/04/2015 .l loc"));
	expected.push("Added: TIMED task - [D]: testTask; [S]: 21/4/15 0000; [E]: 22/4/15 0000; [L]: loc");

	ASSERT_EQ(expected.front(), actual.front());
}

TEST(showTest, test4) {
	std::queue<std::string> expected;
	std::queue<std::string> actual;

	actual.push(ComCalManager::getInstance()->deduceCommand("show may 2015"));
	expected.push("may 2015 shown");

	ASSERT_EQ(expected.front(), actual.front());
}

TEST(showTest, test5) {
	std::queue<std::string> expected;
	std::queue<std::string> actual;

	actual.push(ComCalManager::getInstance()->deduceCommand("show week"));
	expected.push("Current week shown");

	ASSERT_EQ(expected.front(), actual.front());
}

TEST(showTest, test6) {
	std::queue<std::string> expected;
	std::queue<std::string> actual;

	actual.push(ComCalManager::getInstance()->deduceCommand("show week 22/04/2015"));
	expected.push("22/4/15 week tasks shown");

	ASSERT_EQ(expected.front(), actual.front());
}