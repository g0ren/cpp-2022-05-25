#include "Judge.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

Judge::Judge(Test *test) {
	this->test = test;
}

void Judge::start() {
	clock_t start { };
	clock_t end { };
	double seconds { };
	FILE *output = fopen(this->test->fileName().c_str(), "w+");
	string text;
	text="N,create(),addValue(),delValue(),push_front(),pop_front(),find(),sort()\n";
	fwrite(text.c_str(), 1, text.size(), output);
	setlocale(LC_ALL, "Russian");
	for (int i = 10000; i <= 1000000; i += 10000) {
		text = to_string(i) + ",";
		cout << text << endl;
		fwrite(text.c_str(), 1, text.size(), output);

		start = clock();
		this->test->create(i);
		end = clock();
		seconds = (double) (end - start) / CLOCKS_PER_SEC;
		text = to_string(seconds) + ",";
		cout << text << endl;
		fwrite(text.c_str(), 1, text.size(), output);

		int testvalue=rand();
		start = clock();
		this->test->addValue(testvalue, rand() % i);
		end = clock();
		seconds = (double) (end - start) / CLOCKS_PER_SEC;
		text = to_string(seconds) + ",";
		cout << text << endl;
		fwrite(text.c_str(), 1, text.size(), output);

		start = clock();
		this->test->delValue(testvalue, 0);
		end = clock();
		seconds = (double) (end - start) / CLOCKS_PER_SEC;
		text = to_string(seconds) + ",";
		cout << text << endl;
		fwrite(text.c_str(), 1, text.size(), output);

		start = clock();
		this->test->push_front(rand());
		end = clock();
		seconds = (double) (end - start) / CLOCKS_PER_SEC;
		text = to_string(seconds) + ",";
		cout << text << endl;
		fwrite(text.c_str(), 1, text.size(), output);

		start = clock();
		this->test->pop_front();
		end = clock();
		seconds = (double) (end - start) / CLOCKS_PER_SEC;
		text = to_string(seconds) + ",";
		cout << text << endl;
		fwrite(text.c_str(), 1, text.size(), output);

		start = clock();
		this->test->findValue(testvalue);
		end = clock();
		seconds = (double) (end - start) / CLOCKS_PER_SEC;
		text = to_string(seconds) + ",";
		cout << text << endl;
		fwrite(text.c_str(), 1, text.size(), output);

		start = clock();
		this->test->sort();
		end = clock();
		seconds = (double) (end - start) / CLOCKS_PER_SEC;
		text = to_string(seconds) + "\n";
		cout << text << endl;
		fwrite(text.c_str(), 1, text.size(), output);
	}
	fclose(output);
}
