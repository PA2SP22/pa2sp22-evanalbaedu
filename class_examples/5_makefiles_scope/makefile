# Makefile for Lecture 5
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = scope
TWO = documentation

# Type 'make' to create the executables
all: ${ONE} ${TWO}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
