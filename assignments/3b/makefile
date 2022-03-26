# Makefile for Assignment 3b
CXX = g++
ASSIGNMENT = 3
ASSIGNMENT_NAME = assignment_${ASSIGNMENT}
MAIN = ${ASSIGNMENT_NAME}_unit_test
CPP_FILES = todo_item.cpp todo_list.cpp
H_FILES = todo_item.h todo_list.h
CXXFLAGS = -Wall -Wextra -pedantic -g

options:
	@echo
	@echo Options
	@echo ----------------------------------------
	@echo 'make              - View these options'
	@echo 'make todo_list    - Compiles the unit test for TodoList'
	@echo 'make style        - Runs the class style check'
	@echo 'make clean        - Deletes your executable'
	@echo
	@echo
	@echo "Once you've created your executable use the following to test"
	@echo './${ASSIGNMENT_NAME}     - Run the Interactive Unit Test'
	@echo
	@echo

todo_list: ${MAIN}.cpp todo_list.h todo_list.cpp todo_item.h todo_item.cpp
	${CXX} ${CXXFLAGS} ${MAIN}.cpp todo_list.cpp todo_item.cpp -o ${ASSIGNMENT_NAME}
	@echo
	@echo 'Compiled! (Fix any warnings above)'

# Type 'make style' to check your code style
s style: ../../helpful_files/cpplint.py
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${H_FILES} ${CPP_FILES}

# Type 'make clean' to remove the executable
c clean:
	rm -rf ${ASSIGNMENT_NAME}
