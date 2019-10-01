#include  <iostream>
using std::cout;
using std::cin;
using std::endl;

extern "C"{
	#include "add.h"
}

int main(int argc, char** argv){
	cout << "hello world" << endl;
	return 0;
}

