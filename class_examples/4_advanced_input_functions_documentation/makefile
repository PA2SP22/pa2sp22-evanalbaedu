# Makefile for Lecture 4
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = advanced_input
TWO = stringstream
THREE = functions
FOUR = call_by
FIVE = overloading_default
SIX = overloading_concepts

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} ${FOUR} ${FIVE} ${SIX}

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
	
${SIX}: ${SIX}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
