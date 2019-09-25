# Author: Lauren Work
# Date: 7 June 2019
# Description: Basic makefile to compile the final files

#adapted from lecture on makefiles in CS162 canvas week 1
#adapted from ftp://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_2.html
#adapted from my submission from Lab1

CXX = g++
CXXFLAGS = -std=c++11

SOURCES = main.cpp africa.cpp antarctica.cpp asia.cpp checkIfRangedInt.cpp europe.cpp game.cpp northAmerica.cpp oceania.cpp southAmerica.cpp space.cpp

HEADERS = africa.hpp antarctica.hpp asia.hpp checkIfRangedInt.hpp europe.hpp game.hpp northAmerica.hpp oceania.hpp southAmerica.hpp space.hpp

OBJS = ${SOURCES:.cpp=.o}

# exe file made if objects are updated
travel: ${OBJS}
	${CXX} ${OBJS} -o travel

# object files updated if sources or headers are updated using implicit rule
main.o: game.hpp
space.o: space.hpp
africa.o: africa.hpp space.hpp checkIfRangedInt.hpp
northAmerica.o: northAmerica.hpp space.hpp checkIfRangedInt.hpp
southAmerica.o: southAmerica.hpp space.hpp checkIfRangedInt.hpp
asia.o: asia.hpp space.hpp checkIfRangedInt.hpp
oceania.o: oceania.hpp space.hpp checkIfRangedInt.hpp
antarctica.o: antarctica.hpp space.hpp checkIfRangedInt.hpp
europe.o: europe.hpp space.hpp checkIfRangedInt.hpp
game.o: europe.hpp northAmerica.hpp southAmerica.hpp africa.hpp oceania.hpp asia.hpp antarctica.hpp space.hpp checkIfRangedInt.hpp
checkIfRangedInt.o: checkIfRangedInt.hpp

.PHONY: clean

clean:
	-rm travel ${OBJS}

zip:
	zip -D Final_Work_Lauren.zip ${SOURCES} ${HEADERS} reflection.pdf Makefile 

valgrind:
	valgrind --leak-check=full ./travel
