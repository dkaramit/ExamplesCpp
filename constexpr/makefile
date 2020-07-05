

all: test.out

#slow compilation time
test.out: test_class.hpp main.cpp makefile
	g++ main.cpp -I./ -fconstexpr-loop-limit=10000000 -o test.out
