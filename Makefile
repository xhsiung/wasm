CC:=
LIBS:=
CFLAG:=

SOURCE:=libs/main.cc  libs/add.c
OBJS:=$(SOURCE:.cc=.o)
OUT:=js/main.js

all:
	emcc  $(SOURCE) -Os -s WASM=1 -s EXPORTED_FUNCTIONS="['_main','_add']" -o   $(OUT)

run: 
	emrun --port 8888 index.html

init:
	mkdir -p  libs
	mkdir -p  js
	source emsdk/emsdk_env.sh

test:
	echo "test"