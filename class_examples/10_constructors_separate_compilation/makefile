# Makefile for Lecture 10
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = constructor
TWO = initial_overload
THREE = separate_compilation

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} ${FOUR} ${FIVE}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${THREE}: ${THREE}.cpp my_class.h my_class.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run ${THREE}.cpp my_class.cpp
	
# Clean-Up the executables
clean:
	rm -rf *.run
