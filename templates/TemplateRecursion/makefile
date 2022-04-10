CC=g++
STD=c++17

FLG = -std=$(STD) -O3 





all: test.run

test.run: test.cpp $(wildcard *.hpp) makefile 
	g++ -o $@ $< $(FLG) -I./   

clean:
	rm test.run || true