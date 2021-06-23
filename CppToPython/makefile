CC=g++
STD=c++17

FLG=-std=$(STD) -O3

all: Example.so



Example.so: $(wildcard Cpp/*.hpp) makefile $(wildcard Cpp/Example-py.cpp) 
	$(CC) -fPIC $(FLG) -shared -o  Example.so -I"Cpp" Cpp/Example-py.cpp -Wall



clean:
	rm Example.run || true