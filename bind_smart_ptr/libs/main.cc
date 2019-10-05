#include <emscripten/bind.h>
#include <memory>
#include <iostream>

using namespace emscripten;

class MyClass
{
public:
	MyClass(int x) : x(x) {}

	inline int getX() const
	{
		return x;
	}
	inline void setX(int val)
	{
		x = val;
	}

private:
	int x;
};

std::shared_ptr<MyClass> passThrough(MyClass *ptr)
{
	return std::shared_ptr<MyClass>(ptr);
}

std::unique_ptr<MyClass> passToUniquePtr(MyClass *ptr)
{
	return std::unique_ptr<MyClass>( ptr );
}

std::unique_ptr<int> passToUniquePtr2(int v)
{
	return std::unique_ptr<int>(new int(v));
}

EMSCRIPTEN_BINDINGS(module)
{
	class_<MyClass>("MyClass")
	    .constructor<int>()
	    .smart_ptr<std::shared_ptr<MyClass>>("shared_ptr<MyClass>")	    	    
	    .property("x", &MyClass::getX, &MyClass::setX);

	function("passThrough", &passThrough, allow_raw_pointers());
	function("passToUniquePtr", &passToUniquePtr,  allow_raw_pointers());
	function("passToUniquePtr2", &passToUniquePtr2);
}
