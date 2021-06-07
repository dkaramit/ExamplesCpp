all: SimpleExpressionTemplates.run GeneralExpressionTemplates.run

SimpleExpressionTemplates.run: $(wildcard *.hpp) makefile SimpleExpressionTemplates.cpp
	g++ -o SimpleExpressionTemplates.run -I"./" SimpleExpressionTemplates.cpp


GeneralExpressionTemplates.run: $(wildcard *.hpp) makefile GeneralExpressionTemplates.cpp
	g++ -o GeneralExpressionTemplates.run -I"./" GeneralExpressionTemplates.cpp



clean:
	rm GeneralExpressionTemplates.run || true
	rm SimpleExpressionTemplates.run || true