#ifndef FILEVALIDATOR_H
#define FILEVALIDATOR_H
#include <iostream>
#include <string.h>
#include <fstream>

class FileValidator
{

public:

  static bool doesFileExist(const std::string& fileName) {
    std::ifstream file(fileName);
    return !file.fail();
  }

  static bool isFileEmpty(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.peek() == std::ifstream::traits_type::eof();
  }

};

#endif