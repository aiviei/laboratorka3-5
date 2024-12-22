
#include "DoubleList.cpp"
#include "catch.hpp"



TEST_CASE("Check_Constructor") {
	DoubleList<int> TestList;
	REQUIRE(TestList.back() == nullptr);
	REQUIRE(TestList.front() == nullptr);
}

TEST_CASE("Check_CopyConstr") {
	DoubleList<int> TestList;
	DoubleList<int> TwoList = TestList;
	REQUIRE(TestList.front() == TwoList.front());
	REQUIRE(TestList.back() == TwoList.back());
}

TEST_CASE("push_front") {
	DoubleList<int> TestList;
	TestList.push_front(2);
	REQUIRE(TestList.front()->element == 2);
	REQUIRE(TestList.front()->NextEl == nullptr);
	TestList.push_front(3);
	REQUIRE(TestList.front()->element == 3);
	REQUIRE(TestList.front()->NextEl->element == 2);
}

TEST_CASE("push_back") {
	DoubleList<int> TestList;
	TestList.push_back(2);
	REQUIRE(TestList.back()->element == 2);
	REQUIRE(TestList.back()->NextEl == nullptr);
	TestList.push_back(3);
	REQUIRE(TestList.back()->element == 3);
	REQUIRE(TestList.front()->element == 2);
}

TEST_CASE("insert_") {
	DoubleList<int> TestList;
	TestList.insert(0, 2);
	REQUIRE(TestList.front()->element == 2);
	TestList.insert(TestList.size(), 4);
	REQUIRE(TestList.back()->element == 4);
	TestList.insert(1, 5);
	REQUIRE(TestList[1] == 5);
}

TEST_CASE("front_") {
	DoubleList<int> TestList;
	REQUIRE(TestList.front() == nullptr);
	TestList.push_front(2);
	REQUIRE(TestList.front()->element == 2);
}

TEST_CASE("back_") {
	DoubleList<int> TestList;
	REQUIRE(TestList.back() == nullptr);
	TestList.push_back(2);
	REQUIRE(TestList.back()->element == 2);
}

TEST_CASE("size_") {
	DoubleList<int> TestList;
	REQUIRE(TestList.size() == 0);
	TestList.push_back(3);
	TestList.push_back(2);
	TestList.push_back(4);
	REQUIRE(TestList.size() == 3);
}

TEST_CASE("[]_") {
	DoubleList<int> TestList;
	bool flag = 0;
	try {
		TestList[0];
	}
	catch (...) {
		flag = 1;
	}
	REQUIRE(!flag);
	TestList.push_back(3);
	TestList.push_back(2);
	TestList.push_back(4);
	REQUIRE(TestList[1] == 2);
}

TEST_CASE("empty_") {
	DoubleList<int> TestList;
	REQUIRE(TestList.empty() == 1);
	TestList.push_back(2);
	REQUIRE(TestList.empty() == 0);
}

TEST_CASE("pop_front") {
	DoubleList<int> TestList;
	TestList.push_front(2);
	TestList.push_front(3);
	TestList.pop_front();
	REQUIRE(TestList.front()->element == 2);
}

TEST_CASE("pop_back") {
	DoubleList<int> TestList;
	TestList.push_back(2);
	TestList.push_back(3);
	TestList.pop_back();
	REQUIRE(TestList.back()->element == 2);
}

TEST_CASE("remove_") {
	DoubleList<int> TestList;
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