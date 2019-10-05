CC:=
LIBS:=
CFLAG:=

SOURCE:=libs/main.cc  libs/add.c
OBJS:=$(SOURCE:.cc=.o)
OUT:=js/main.js

all:env
	emcc  $(SOURCE) -Os -s WASM=1   \
		-s  EXTRA_EXPORTED_RUNTIME_METHODS="['ccall','cwrap']"  \
		-s  EXPORTED_FUNCTIONS="['_main']" \
		-o $(OUT)

run: 
	emrun --port 8888 index.html

env:
	$(source)  ~/emsdk/emsdk_env.sh

init:
	mkdir -p  libs
	mkdir -p  js
	
test:
	echo "test"
