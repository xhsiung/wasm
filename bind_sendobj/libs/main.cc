#include  <emscripten/bind.h>
#include <iostream>
using namespace emscripten;

struct Pack
{
	/* data */
	std::string name;
	std::string mobile;	
};


Pack sendMsg(std::string action,Pack &p){
	Pack pp;
	std::cout << p.name   << std::endl;
	std::cout << p.mobile << std::endl;
	pp = {"david","000"};
	return  pp ;
}

EMSCRIPTEN_BINDINGS(module){
	value_object<Pack>("Send")
		.field("name", &Pack::name)
		.field("mobile", &Pack::mobile);
	
	function("sendMsg" ,  sendMsg);
}
