#include <fstream>
#include <iostream>

// new_cat is a utility which concatenates and lists the contents of files.
int main(int argc, char** argv) {
  // new_cat
  // No file is given.
  // Everything you type as input gets outputted as soon as you hit the
  // <enter> key.
  // Ctrl-D (UNIX) or CTRL-Z (Windows) will exit the program
  // Check if there is only ./new_cat being entered only
  if (argc == 1) {
    // Ask for input and print out input until user exits
    while (!std::cin.eof()) {
      // Create string variable
      std::string input;
      // Get user input
      std::cin >> input;
      // Display user input
      std::cout << input << "\n";
    }
    return 0;
  // Else any other arguments being passed
  } else {
    // new_cat filename1 filename2 [etc]
    // file(s) can be given
    // If at least one of the files doesn't exist exit your program with a
    // status code of
    // and inform the user that one of the filenames was not valid
    // DO NOT output any files if at least one file does not exist
    // If all files exist, output each file, one after another

    // Create var to hold file name.
    std::string file;
    // Loop through trying to see if there is any txt files to open
    for (int i = 1; i < argc; i++) {
      // Convert file name to string
      file = argv[i];
      // Open the file
      std::ifstream open(file);
      // If fail to open orfind a txt file, exit program & display message
      if (open.fail()) {
        std::cerr << "No such file or directory.\n";
        exit(1);
      }
    }
    // Loop through to output what is in text file(s)
    for (int i = 1; i < argc; i++) {
      // Convert file name to string
      file = argv[i];
      // Open the file
      std::ifstream read(file);
      // Create a string var to hold a line
      std::string line;
      // Loop through whole txt file to get line and display it's data
      while (!read.eof()) {
        // Get one line row in the file
        getline(read, line);
        // Display out the line
        std::cout << line << "\n";
      }
    }
  }
  return 0;
}
