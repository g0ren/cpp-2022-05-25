#pragma once

#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Test
{
public:
	string virtual fileName() = 0;
	void virtual create(int) = 0;
	void virtual push_front(int value) = 0;
	void virtual pop_front() = 0;
	void virtual addValue(int value, int pos) = 0;
	void virtual delValue(int value, int pos) = 0;
	void virtual sort() = 0;
	void virtual findValue(int value) = 0;
};

class TestSet : public Test {
	set<int> container;
public:
	TestSet(int size);
	string fileName() override;
	void create(int)override;
	void addValue(int value, int pos) override;
	void push_front(int value) override;
	void pop_front() override;
	void delValue(int value, int pos) override;
	void sort()  override;
	void findValue(int value) override;
};

class TestVector : public Test {
	vector<int> container;
public:
	TestVector(int size);
	string fileName() override;
	void create(int)override;
	void addValue(int value, int pos) override;
	void push_front(int value) override;
	void pop_front() override;
	void delValue(int value, int pos) override;
	void sort()  override;
	void findValue(int value) override;
};

class TestList : public Test {
	list<int> container;
public:
	TestList(int size);
	string fileName() override;
	void create(int)override;
	void addValue(int value, int pos) override;
	void push_front(int value) override;
	void pop_front() override;
	void delValue(int value, int pos) override;
	void sort()  override;
	void findValue(int value) override;
};

class TestMap :public Test {
	map<int, int> container;
public:
	TestMap(int size);
	string fileName() override;
	void create(int) override;
	void addValue(int value, int pos) override;
	void push_front(int value) override;
	void pop_front() override;
	void delValue(int value, int pos) override;
	void sort()  override;
	void findValue(int value) override;
};
