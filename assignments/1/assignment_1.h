/*
 * Name        : Caesar Cipher Encryption & Decryption Lab Header file
 * Author      : Evan Alba
 * Description : Function Prototypes
 * Sources     : https://www.learncpp.com/cpp-tutorial/header-files/
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H
#include <string>

// Add any includes and using statements Here

// Declare Function Prototypes Here (What goes above main)
bool CheckAlphabetic(const std::string &word);
bool EncryptString(std::string &secret, int shift);
bool DecryptString(std::string &unlock, int reverse);
double ComputeAverage(double data[], unsigned int size);
double FindMinValue(double low[], unsigned int size);
double FindMaxValue(double i[], unsigned int j);
#endif /* ASSIGNMENT_1_H */
