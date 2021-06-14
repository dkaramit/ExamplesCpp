all: example.run



example.run: $(wildcard *.hpp) makefile example.cpp
	g++ -o example.run -I"./" example.cpp



clean:
	rm example.run || true