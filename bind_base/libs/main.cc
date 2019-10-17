#include <emscripten/bind.h>
#include <iostream>
#include "utils.h"

using namespace emscripten;

class MyClass
{
private:
	/* data */
public:
	MyClass(int a, std::string m):x(a),msg(m) {}
	~MyClass() {}

	int sum(int a,int b){
		return a+b;
	}
	
	static std::string  getMsg(const MyClass& instance){
		return instance.msg;
	}

	int x=0;
	std::string msg="";
};	

MyClass* getMyClassInstance(int a, std::string m){
	return new MyClass(a, m);
}

EM_PORT_API(int) add(int a,int b){
	return a+b;
}

EMSCRIPTEN_BINDINGS(module){
	class_<MyClass>("MyClass")
	.constructor<int,std::string>()
	.property("x", &MyClass::x)
	.function("sum", &MyClass::sum)
	.class_function("getMsg",&MyClass::getMsg);

	function("getMyClassInstance", &getMyClassInstance, allow_raw_pointers());
}