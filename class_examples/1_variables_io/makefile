# Makefile for Lecture 1
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = variables
TWO = type_min_max
THREE = input_output

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
