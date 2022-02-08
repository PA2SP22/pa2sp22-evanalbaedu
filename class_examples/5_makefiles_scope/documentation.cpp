/*
 * Name        : documentation.cpp
 * Author      : Luke Sathrum
 * Description : Example of documentation. A good file to start your code with.
 * Sources     : List any sources used
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*
 * This is function one. This is a description of what function one does.
 */
void FunctionOne();

/*
 * This is function two. This is a description of what function two does.
 * @param int number - This describes how the function uses this parameter.
 *                     Continuing comments of the parameter should be lined up.
 */
void FunctionTwo(int number);

/*
 * This is function three. This is a description
 * of what function three does.
 * @param int number_one - This describes how the function uses this parameter
 * @param int number_two - This describes how the function uses this parameter
 */
void FunctionThree(int number_one, int number_two);

/*
 * This is function four. This is a description
 * of what function four does.
 * @return int - A description of what the int contains when returned
 */
int function_four();

/*
 * This is function five. This is a description
 * of what function five does.
 * @param int number - This describes how the function uses this parameter
 * @return int - A description of what the int contains when returned
 */
int function_five(int number);

/*
 * This is the program's main function/entry point.
 */
int main() {

  // Print a welcome message to the screen
  cout << "Welcome to the program!\n\n";

  // This ends the program
  return 0;

}
