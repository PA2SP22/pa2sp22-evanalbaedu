# Makefile for Lecture 3
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = basic_branching
TWO = switch
THREE = loops
FOUR = strings
FIVE = character_functions

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} ${FOUR} ${FIVE}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${FOUR}: ${FOUR}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${FIVE}: ${FIVE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
