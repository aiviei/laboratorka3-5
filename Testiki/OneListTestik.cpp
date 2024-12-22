
#define CATCH_CONFIG_MAIN
#include "OneList.cpp"
#include "catch.hpp"



TEST_CASE("Check Constructor") {
	OneList<int> TestList;
	REQUIRE(TestList.back() == nullptr);
	REQUIRE(TestList.front() == nullptr);
}

TEST_CASE("Check CopyConstr") {
	OneList<int> TestList;
	OneList<int> TwoList = TestList;
	REQUIRE(TestList.front() == TwoList.front());
	REQUIRE(TestList.back() == TwoList.back());
}

TEST_CASE("push front") {
	OneList<int> TestList;
	TestList.push_front(2);
	REQUIRE(TestList.front()->element == 2);
	REQUIRE(TestList.front()->NextEl == nullptr);
	TestList.push_front(3);
	REQUIRE(TestList.front()->element == 3);
	REQUIRE(TestList.front()->NextEl->element == 2);
}

TEST_CASE("push back") {
	OneList<int> TestList;
	TestList.push_back(2);
	REQUIRE(TestList.back()->element == 2);
	REQUIRE(TestList.back()->NextEl == nullptr);
	TestList.push_back(3);
	REQUIRE(TestList.back()->element == 3);
	REQUIRE(TestList.front()->element == 2);
}

TEST_CASE("insert") {
	OneList<int> TestList;
	TestList.insert(0, 2);
	REQUIRE(TestList.front()->element == 2);
	TestList.insert(TestList.size(), 4);
	REQUIRE(TestList.back()->element == 4);
	TestList.insert(1, 5);
	REQUIRE(TestList[1] == 5);
}

TEST_CASE("front") {
	OneList<int> TestList;
	REQUIRE(TestList.front() == nullptr);
	TestList.push_front(2);
	REQUIRE(TestList.front()->element == 2);
}

TEST_CASE("back") {
	OneList<int> TestList;
	REQUIRE(TestList.back() == nullptr);
	TestList.push_back(2);
	REQUIRE(TestList.back()->element == 2);
}

TEST_CASE("size") {
	OneList<int> TestList;
	REQUIRE(TestList.size() == 0);
	TestList.push_back(3);
	TestList.push_back(2);
	TestList.push_back(4);
	REQUIRE(TestList.size() == 3);
}

TEST_CASE("[]") {
	OneList<int> TestList;
	bool flag = 0;
	try {
		TestList[0];
	}
	catch (...) {
		flag = 1;
	}
	REQUIRE(flag);
	TestList.push_back(3);
	TestList.push_back(2);
	TestList.push_back(4);
	REQUIRE(TestList[1] == 2);
}

TEST_CASE("empty") {
	OneList<int> TestList;
	REQUIRE(TestList.empty() == 1);
	TestList.push_back(2);
	REQUIRE(TestList.empty() == 0);
}

TEST_CASE("pop front") {
	OneList<int> TestList;
	bool flag = 0;
	try {
		TestList.pop_front();
	}
	catch (...) {
		flag = 1;
	}
	REQUIRE(flag);
	TestList.push_front(2);
	TestList.push_front(3);
	TestList.pop_front();
	REQUIRE(TestList.front()->element == 2);
}

TEST_CASE("pop back") {
	OneList<int> TestList;
	bool flag = 0;
	try {
		TestList.pop_back();
	}
	catch (...) {
		flag = 1;
	}
	REQUIRE(flag);
	TestList.push_back(2);
	TestList.push_back(3);
	TestList.pop_back();
	REQUIRE(TestList.back()->element == 2);
}

TEST_CASE("remove") {
	OneList<int> TestList;
	TestList.push_back(2);
	TestList.push_back(3);
	TestList.push_back(4);
	TestList.remove(2);
	REQUIRE(TestList.front()->element == 3);
	TestList.remove(4);
	REQUIRE(TestList.back()->element == 3);
	TestList.push_front(2);
	TestList.push_back(3);
	TestList.push_back(4);
	TestList.remove(3);
	REQUIRE(TestList.front()->NextEl->element == 4);

}