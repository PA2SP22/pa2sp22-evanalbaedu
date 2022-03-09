# Makefile for Lecture 11
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = binary_unary_overload
TWO = member_overload
THREE = friend_functions

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run ${THREE}.cpp
	
# Clean-Up the executables
clean:
	rm -rf *.run
