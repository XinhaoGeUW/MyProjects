CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
OBJECTS = main.o cell.o grid.o textdisplay.o
EXEC = a4q4

${EXEC}: main.o cell.o grid.o textdisplay.o 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

cell.o: cell.cc cell.h

grid.o: grid.cc grid.h textdisplay.h

textdisplay.o: textdisplay.cc textdisplay.h subject.h

main.o: main.cc grid.h state.h

.PHONY: clean

clean:	
	rm ${OBJECTS} ${EXEC}
