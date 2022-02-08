/*
<<<<<<< HEAD
 * Name        : Coding Assignment #1
 * Author      : Evan Alba
 * Description : Caesar Cipher Encryption & Decryption lab with Data Manipulation functions.
 * Sources     :
 
 https://stackoverflow.com/questions/4743564/c-string-variable-declaration#4743586
 https://www.tutorialspoint.com/cplusplus/cpp_for_loop.htm
 https://www.cplusplus.com/reference/cctype/isalpha/
 https://en.wikipedia.org/wiki/Caesar_cipher
 https://www.techonthenet.com/ascii/chart.php
 https://stackoverflow.com/questions/21832886/converting-letters-to-numbers-in-c
 https://www.cplusplus.com/reference/cctype/islower/
 https://www.cplusplus.com/reference/cctype/isupper/
 https://www.geeksforgeeks.org/character-arithmetic-c-c/
 */

#include "assignment_1.h"
#include <bits/stdc++.h>
#include <ctype.h>
#include <iostream>
#include <string>

// Write Function Definitions Here (What goes below main)
bool CheckAlphabetic(const std::string &word) {
  // Check if string has no characters.
  if (word.length() == 0) {
    return false;
  }
  // Loop through the word
  for (unsigned int i = 0; i < word.length(); i++) {
    // Check if word character has non-alpha character.
    if (!isalpha(word[i])) {
      return false;
    }
  }
  // Return true word if valid alpha.
  return true;
}

bool EncryptString(std::string &secret, int shift) {
  // Check if string has a non-alpha character.
  if (!CheckAlphabetic(secret)) {
    return false;
  }
  // Create variable to hold encrypted word.
  std::string cipher;
  // Hold shifted value
  unsigned char shifted;
  // Make clean value to shift by.
  shift %= 26;
  // Loop through word
  for (unsigned int i = 0; i < secret.length(); i++) {
    //  Check if letter lower
    if (islower(secret[i])) {
      // Shift the letter and add it to the encrypted phrase.
      shifted = static_cast<char>((static_cast<int>(secret[i])-97) +shift+ 97);
      // Check if shifted number is out ASCII range to put it back in Alpha
      if (shifted < 'a') {
        shifted += 26;
      } else if (shifted > 'z') {
        shifted -= 26;
      }
      // Hold new encrypted letter
      cipher += shifted;
      // Check if letter upper
    } else {
      // Shift the letter and add it to the encrypted phrase.
      shifted = static_cast<char>((static_cast<int>(secret[i])-65) +shift+ 65);
      // Check if shifted number is out ASCII range to put it back in Alpha
      if (shifted < 'A') {
        shifted += 26;
      } else if (shifted > 'Z') {
        shifted -= 26;
      }
      // Hold new encrypted letter
      cipher += shifted;
    }
  }
  // Store encrypted word back to original variable of uncrypted word.
  secret = cipher;
  return true;
}

bool DecryptString(std::string &unlock, int reverse) {
  EncryptString(unlock, -reverse);
  return false;
}

double ComputeAverage(double data[], unsigned int size) {
  // Create a variable to hold the sum of array
  double sum = 0;
  // Loop through each umber data in array
  for (unsigned int i = 0; i < size; i++) {
    // Add to sum of data
    sum += data[i];
  }
  // return the mean of data
  return (sum / size);
}

double FindMinValue(double low[], unsigned int size) {
  // Create a variable to hold the min number in array
  double min = low[0];
  // Loop through each umber data in array
  for (unsigned int i = 0; i < size; i++) {
    // Check if number is smaller compared to the previous min value
    if (low[i] < min) {
      min = low[i];
    }
  }
  // return the min value
  return min;
}

double FindMaxValue(double high[], unsigned int size) {
  // Create a variable to hold the max number in array
  double max = high[0];
  // Loop through each umber data in array
  for (unsigned int i = 0; i < size; i++) {
    // Check if number is bigger compared to the previous max value
    if (high[i] > max) {
      max = high[i];
    }
  }
  // return the max value
  return max;
}
=======
 * Name        : FILL IN
 * Author      : FILL IN
 * Description : FILL IN
 * Sources     : FILL IN
 */

#include "assignment_1.h"

// Write Function Definitions Here (What goes below main)
>>>>>>> 1c0d4ab2759781cf0a510c5de4fa21346a844549
