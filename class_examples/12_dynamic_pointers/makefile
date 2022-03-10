# Makefile for Lecture 12
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = pointer_operators
TWO = dynamic
THREE = dynamic_arrays
FOUR = functions_and_pointers

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} ${FOUR}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${FOUR}: ${FOUR}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
