XX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
OBJECTS = main.o transform.o Decorator.o ppm.o basic.o exception.o image.o 
EXEC = a4q3

${EXEC}: main.o transform.o Decorator.o ppm.o basic.o exception.o image.o
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
basic.o: basic.cc basic.h 

exception.o: exception.cc exception.h

image.o: image.cc image.h

Decorator.o: Decorator.cc Decorator.h

transform.o: transform.cc transform.h

main.o: main.cc transform.h image.h basic.h exception.h ppm.h

.PHONY: clean

clean:
	 rm ${OBJECTS} ${EXEC}
