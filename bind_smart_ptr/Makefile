CC:=
LIBS:=
CFLAG:=

SOURCE:=libs/main.cc 
OBJS:=$(SOURCE:.cc=.o)
OUT:=js/main.js

all:env
	emcc  $(SOURCE) -Os -s WASM=1   \
		--bind \
		-s EXTRA_EXPORTED_RUNTIME_METHODS="['getValue']"  \
		--post-js  libs/postscript.js \
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

#--post-js  libs/postscript.js 
#--pre-js   libs/prescript.js 
