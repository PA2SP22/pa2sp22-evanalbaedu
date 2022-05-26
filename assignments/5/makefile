# Makefile for Assignment 5
CXX = g++
ASSIGNMENT = 5
ASSIGNMENT_NAME = assignment_${ASSIGNMENT}
MAIN = ${ASSIGNMENT_NAME}_unit_test
CPP_FILES =
H_FILES = bst_nodet.h bs_treet.h
CXXFLAGS = -Wall -Wextra -pedantic -g

# Type 'make' to create the executable
${MAIN}: ${H_FILES} ${CPP_FILES}
	${CXX} ${CXXFLAGS} ${MAIN}.cpp ${CPP_FILES} -o ${ASSIGNMENT_NAME}
	@echo 'Compiled! (Fix any warnings above)'

# Type 'make style' to check your code style
style: ../../helpful_files/cpplint.py
	python2 $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${H_FILES} ${CPP_FILES}

# Type 'make clean' to remove the executable
clean:
	rm -rf ${ASSIGNMENT_NAME}
