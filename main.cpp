/*
* Este programa lee un archivo de texto con sintáxis de C++ e
* imprime la cantidad de líneas blancas, con comentarios, con
* código y totales.
* 
* Autor: Sergio Gabriel Diosdado Castelazo A00516971
* Creación: febrero 23, 2021
* Actualización: febrero 24, 2021
*
* Nota importante:
* Este programa usa características de C++ 11, por lo que se
* recomienda compilar usando la bandera -std=c++11.
* De lo contrario se desplegarán "Warnings" recomendando la
* configuración de la bandera std
*/
#include <iostream>
#include <string.h>
#include <fstream>
#include "classes/LineEvaluator.h"
#include "classes/FileValidator.h"
#include "classes/Printer.h"

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
  LineEvaluator lineEvaluator;
  int commentLines = 0;
  int codeLines = 0;
  int blankLines = 0;

  while(!file.eof()){
    getline(file, line);
    LineEvaluator::LineType type = lineEvaluator.getLineType(line);

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

  Printer::lineTypeCountReport(codeLines, blankLines, commentLines);

  return 0;
}
