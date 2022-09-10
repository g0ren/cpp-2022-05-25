#pragma once
#include "Test.h"

class Judge{
	Test* test;
public:
	Judge(Test* test);
	void start();
};
