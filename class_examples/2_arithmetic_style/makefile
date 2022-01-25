# Makefile for Lecture 2
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = arithmetic
TWO = inc_dec_type_cast
THREE = escape_constant
FOUR = style

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
