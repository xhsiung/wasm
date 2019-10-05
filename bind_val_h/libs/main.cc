#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <iostream>
using namespace emscripten;

void getDateTime(){
	//first
	double now = val::global("DD").call<double>("getTime");
	std::cout << now << std::endl;

	//second
	val dt = val::global("Date").new_();
	double nn = dt.call<double>("getTime");
	std::cout << nn << std::endl;

	//third
	val mc = val::global("MyClass").new_();
	mc.set("name",val("alex"));
	std::cout << mc["name"].as<std::string>()   << std::endl;

	//aaa.bbb.ccc.ddd.Open(p1,p2)
	//aaa["bbb"]["ccc"]["ddd"].call<returnType>("Open",p1,p2)
	
	//aaa.bbb.ccc.ddd.X1 = 100
	//aaa["bbb"]["ccc"]["ddd"].set("X1", 100);
}

EMSCRIPTEN_BINDINGS(module){
	function("getDateTime",&getDateTime);
}