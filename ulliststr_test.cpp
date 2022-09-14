/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
	ULListStr dat;
	//normal tests of push functions
	dat.push_back("7");
	dat.push_front("6");
	dat.push_back("8");
	dat.push_front("9");
	//testing size
	cout << "Size: " << dat.size() << endl;
	//testing get in normal cases
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << endl; 
	//testing front and back, 1 line only test needed for these
	cout << dat.front() << " " << dat.back() << endl;
	//testing set
	dat.set(2, "3");
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << endl;
	dat.pop_back();
	dat.pop_back();
	dat.pop_front();
	cout << dat.size() << endl;
	//testing get() when size is one
	cout << dat.get(0) << endl;
	dat.clear();

	ULListStr test2;
	//testing push front on empty, both push functions fully tested
	test2.push_front("2");
	test2.push_front("1");
	test2.push_back("3");
	cout << test2.get(0) << " " << test2.get(1) << " " << test2.get(2) << endl;
	test2.clear();

	ULListStr test3;
	//testing pop functions on empty lists, should just continue through the code without problems
	test3.pop_back();
	test3.pop_front();
	test3.clear();
	//all code has been run through
	//invalid loc in get() throws, so can't test cleanly, works though
	return 0;
}
