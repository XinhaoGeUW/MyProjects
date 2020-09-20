CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
OBJECTS = main.o Expr.o
EXEC = a4q2

${EXEC}: main.o Expr.o
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

Expr.o: Expr.cc Expr.h

main.o: main.cc Expr.h

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC}
