all: ExpressionTemplates.run



ExpressionTemplates.run: $(wildcard *.hpp) makefile ExpressionTemplates.cpp
	g++ -o ExpressionTemplates.run -I"./" ExpressionTemplates.cpp



clean:
	rm ExpressionTemplates.run || true