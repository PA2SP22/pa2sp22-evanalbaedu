# Makefile for Assignment 3a
CXX = g++
ASSIGNMENT = 3a
ASSIGNMENT_NAME = assignment_${ASSIGNMENT}
MAIN = ${ASSIGNMENT_NAME}_unit_test
CPP_FILES = todo_item.cpp
H_FILES = todo_item.h
CXXFLAGS = -Wall -Wextra -pedantic -g

options:
	@echo
	@echo Options
	@echo ----------------------------------------
	@echo 'make              - View these options'
	@echo 'make todo_item    - Compiles the unit test for TodoItem'
	@echo 'make style        - Runs the class style check'
	@echo 'make clean        - Deletes your executable'
	@echo
	@echo
	@echo "Once you've created your executable use the following to test"
	@echo './${ASSIGNMENT_NAME}     - Run the Interactive Unit Test'
	@echo
	@echo

todo_item: ${MAIN}.cpp todo_item.h todo_item.cpp
	${CXX} ${CXXFLAGS} ${MAIN}.cpp todo_item.cpp -o ${ASSIGNMENT_NAME}
	@echo
	@echo 'Compiled! (Fix any warnings above)'

# Type 'make style' to check your code style
s style: ../../helpful_files/cpplint.py
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${H_FILES} ${CPP_FILES}

# Type 'make clean' to remove the executable
c clean:
	rm -rf ${ASSIGNMENT_NAME}
