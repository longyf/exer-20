#include <iostream>
#include "isNumeric.h"
using namespace std;

void test1() {
	cout<<"Test1:"<<endl;
	char str[] = "1e-10";
	if (isNumeric(str)) {
		cout<<"Yes."<<endl;
	}
	else {
		cout<<"No."<<endl;
	}
}

void test2() {
	cout<<"Test2:"<<endl;
	char str[] = "123.a";
	if (isNumeric(str)) {
		cout<<"Yes."<<endl;
	}
	else {
		cout<<"No."<<endl;
	}
}

int main() {
	test1();
	test2();
	return 0;
}
