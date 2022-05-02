# Makefile for Assignment 4
CXX = g++
ASSIGNMENT = 4
ASSIGNMENT_NAME = assignment_${ASSIGNMENT}
MAIN = ${ASSIGNMENT_NAME}_unit_test
CPP_FILES = dl_list.cpp dl_node.cpp
H_FILES = dl_list.h dl_node.h
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
