#include <iostream>
#include <string.h>
#include <fstream>
#include "classes/LineEvaluator.h"
#include "classes/FileValidator.h"

using namespace std;

int main(int argc, char const *argv[])
{
  string fileName;
  cout << "Nombre del archivo: ";
  cin >> fileName;

  if (!FileValidator::doesFileExist(fileName)) {
    cout << "The file does not exist." << endl;
    return -1;
  }

  if(FileValidator::isFileEmpty(fileName)) {
    cout << "The file is empty." << endl;
    return -2;
  }

  ifstream file(fileName);
  string line;
  int commentLines = 0;
  int codeLines = 0;
  int blankLines = 0;

  while(!file.eof()){
    getline(file, line);
    LineEvaluator::LineType type = LineEvaluator::getLineType(line);

    switch (type) {
      case LineEvaluator::LineType::Comment:
        commentLines++;
        break;
      case LineEvaluator::LineType::Blank:
        blankLines++;
        break;
      default:
        codeLines++;
        break;
    }
  }
  cout << commentLines << " " << blankLines  << " " << codeLines << endl;

  return 0;
}
