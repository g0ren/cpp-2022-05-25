#include "Test.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * Set
 */

TestSet::TestSet(int size) {

}

void TestSet::create(int size) {
	this->container.erase(this->container.begin(), this->container.end());
	for (int i = 0; i < size; i++) {
		this->container.insert(rand());
	}
}

void TestSet::addValue(int value, int pos) {
	this->container.insert(value);
}

void TestSet::push_front(int value) {
	cout << "Method not applicable" << endl;
}

void TestSet::pop_front() {
	this->container.erase(this->container.begin());
}

void TestSet::delValue(int value, int pos) {
	this->container.erase(this->container.find(value));
}

void TestSet::sort() {
	cout << "Method not applicable" << endl;
}

void TestSet::findValue(int value) {
	this->container.find(value);
}

/*
 * Vector
 */

TestVector::TestVector(int size) {

}

void TestVector::create(int size) {
	this->container.clear();
	for (int i = 0; i < size; i++) {
		this->container.push_back(rand());
	}
}

void TestVector::addValue(int value, int pos) {
	std::vector<int>::iterator it = this->container.begin() + pos;
	this->container.insert(it, value);
}

void TestVector::push_front(int value) {
	this->container.insert(this->container.begin(), value);
}

void TestVector::pop_front() {
	this->container.erase(this->container.begin());
}

void TestVector::delValue(int value, int pos) {
	std::vector<int>::iterator it = std::find(this->container.begin(),
			this->container.end(), value);
	this->container.erase(it);
}

void TestVector::sort() {
	std::sort(this->container.begin(), this->container.end());
}

void TestVector::findValue(int value) {
	std::vector<int>::iterator it = std::find(this->container.begin(),
			this->container.end(), value);
}

/*
 * List
 */

TestList::TestList(int size) {

}

void TestList::create(int size) {
	for (int i = 0; i < size; i++)
		this->container.push_back(rand());
}

void TestList::addValue(int value, int pos) {
	std::list<int>::iterator it = this->container.begin();
	std::advance(it, pos);
	this->container.insert(it, value);
}

void TestList::push_front(int value) {
	this->container.push_front(value);
}

void TestList::pop_front() {
	this->container.pop_front();
}

void TestList::delValue(int value, int pos) {
	std::list<int>::iterator it = std::find(this->container.begin(),
			this->container.end(), value);
	this->container.erase(it);
}

void TestList::sort() {
	this->container.sort();
}

void TestList::findValue(int value) {
	std::list<int>::iterator it = std::find(this->container.begin(),
			this->container.end(), value);
}

/*
 * Map
 */

TestMap::TestMap(int size) {

}

void TestMap::create(int size) {
	this->container.erase(this->container.begin(), this->container.end());
	for (int i = 0; i < size; ++i) {
		this->container.insert(make_pair(i, rand()));
	}
}

void TestMap::addValue(int value, int pos) {

}

void TestMap::push_front(int value) {
	this->container.insert(
			make_pair(this->container.begin()->first - 1, value));
}

void TestMap::pop_front() {
	this->container.erase(this->container.begin());
}

void TestMap::delValue(int value, int pos) {
	for (size_t i = 0; i < this->container.size(); ++i) {
		if (this->container.at(i) == value) {
			this->container.erase(this->container.at(i));
		}
	}
}

void TestMap::sort() {
	for (size_t i = 0; i < this->container.size(); ++i) {
		for (size_t j = i + 1; j < this->container.size(); ++j) {
			if (this->container.at(i) > this->container.at(j)) {
				int tmp = this->container.find(i)->second;
				this->container.find(i)->second =
						this->container.find(j)->second;
				this->container.find(j)->second = tmp;
			}
		}
	}
}

void TestMap::findValue(int value) {

}

string TestSet::fileName() {
	return "Set.csv";
}

string TestVector::fileName() {
	return "Vector.csv";
}

string TestList::fileName() {
	return "List.csv";
}

string TestMap::fileName() {
	return "Map.csv";
}
