Path=$(PWD)

Headers=$(wildcard ./*.hpp)

CC=g++
STD=-std=c++17
OPT=-O0



FLG=  $(STD)  -I "$(Path)"  -lm   $(OPT) -pthread

all:future_test.run 


future_test.run: makefile $(Headers) future_test.cpp
	$(CC) -o "$(Path)/future_test.run" "$(Path)/future_test.cpp" $(FLG) -Wall


clean:
	@[ -f "$(Path)/future_test.run" ] && rm "$(Path)/future_test.run" || true