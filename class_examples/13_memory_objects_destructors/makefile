# Makefile for Lecture 13
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = dynamic_multi_array
TWO = dynamic_objects
THREE = dynamic_objects_arrays
FOUR = delete
FIVE = destructor
SIX = dynamic_objects_in_dynamic_array
SEVEN = more_pointers

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} ${FOUR} ${FIVE} ${SIX} ${SEVEN}

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

${SEVEN}: ${SEVEN}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
