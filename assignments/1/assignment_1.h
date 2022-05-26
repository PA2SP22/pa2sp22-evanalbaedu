/*
 * Name        : Caesar Cipher Encryption & Decryption Lab Header file
 * Author      : Evan Alba
 * Description : Function Prototypes
 * Sources     : https://www.learncpp.com/cpp-tutorial/header-files/
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H
#include <string>

// This function will check to make sure all characters in a given string
// are alphabetic. It returns true if the string is all alphabetic,
// otherwise it returns false. An empty string should also return false.
bool CheckAlphabetic(const std::string &word);

// This function will perform a Caesar Cipher shift
// If the string contains any non-alpha characters do not perform the
// encryption and return false. Otherwise perform the encryption
// and return true.
bool EncryptString(std::string &secret, int shift);

// This function decrypts a Caesar Cipher shift. If the string contains
// any non-alpha characters do not perform the decryption and return
// false. Otherwise perform the encryption and return true.
bool DecryptString(std::string &unlock, int reverse);

// This function will compute the mean average of the values in the
// array. The array will always be at least of size 1.
double ComputeAverage(double data[], unsigned int size);

// This function will find and return the smallest value in an array. The
// array will always be at least of size 1.
double FindMinValue(double low[], unsigned int size);

// This function will find and return the largest value in an array. The
// array will always be at least of size 1.
double FindMaxValue(double i[], unsigned int j);
#endif /* ASSIGNMENT_1_H */
