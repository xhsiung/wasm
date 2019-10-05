__ATPOSTRUN__.push(() => {
	var xClass = new Module.MyClass(100);

	console.log(xClass.x);
	console.log(Module.passThrough(xClass));
	console.log(Module.passToUniquePtr(xClass));

	console.log(Module.getValue(Module.passToUniquePtr2(10), 'i8'));
});
