#include <iostream>
#include <fstream>
#include "Test.h"
#include "Judge.h"

using namespace std;

int main()
{
	//Test *t=new TestSet(12);
	//Test *t=new TestVector(12);
	//Test *t=new TestList(12);
	Test *t=new TestMap(12);
	Judge j(t);
	j.start();

	cout << "oK";
}
