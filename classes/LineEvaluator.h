#ifndef LINEEVALUATOR_H
#define LINEEVALUATOR_H
#include <string.h>
#include <iostream>

class LineEvaluator
{
private:
  static std::string trim(const std::string &str) {
      auto start = str.begin();
      auto end = str.end();

      while (start != str.end() && std::isspace(*start)) {
          start++;
      }
  
      do {
          end--;
      } while (std::distance(start, end) > 0 && std::isspace(*end));
  
      return std::string(start, end + 1);
  }

public:
  enum LineType {Comment, Code, Blank, EndOfFile};

  static LineType getLineType(const std::string& line) {
    std::string trimmedLine = trim(line);
    if(trimmedLine == "") return Blank;
    if(trimmedLine[0] == '/' && trimmedLine[1] == '/') return Comment;
    return Code;
  }

};

#endif