CC=g++
STD=c++17

FLG=-std=$(STD) -O3

all: example.run



example.run: $(wildcard *.hpp) makefile example.cpp
	$(CC) $(FLG) -o example.run -I"./" example.cpp



clean:
	rm example.run || true