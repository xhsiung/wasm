#include <emscripten.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

extern "C"
{
	#include "add.h"	
}

// EM_JS(void, call_alert, (), {
// 	console.log('hello world!');
// 	throw 'all done';
// });


int main(int argc, char **argv)
{
	//call_alert();
	//emscripten_run_script("console.log('hello world')");
	
	// EM_ASM(
	// 	console.log("hello world");
	// 	throw 'all done';
	// );

	// EM_ASM_({
	//   	console.log('I received: ' + $0);
	// }, 100);

	int x = EM_ASM_INT({
  		console.log('I received: ' + $0);
  		return $0 + 1;
	}, 100);

	cout << "hello world" << x << endl;
	return 0;
}
