# Makefile for Lecture 16
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = assert

# Type 'make' to create the executables
all: ${ONE}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
