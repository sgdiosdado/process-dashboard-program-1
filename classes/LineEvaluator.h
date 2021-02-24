/*
* Esta clase evalúa las líneas de un archivo de C++ 
* para checar que caigan dentro de un valor del enum: LineType
* 
* Autor: Sergio Gabriel Diosdado Castelazo A00516971
* Creación: febrero 23, 2021
* Actualización: febrero 24, 2021
*/
#ifndef LINEEVALUATOR_H
#define LINEEVALUATOR_H
#include <string.h>
#include <iostream>

class LineEvaluator
{
private:
  bool multiLineFlag;

  /*
  * Remueve los espacios iniciales y finales de un string
  * 
  * Parámetros:
  *   const string str: String al cual se le aplicará la operación
  * 
  * Retorno:
  *   Nuevo string sin espacios iniciales ni finales.
  *   
  */
  std::string _trim(const std::string &str) {
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

  /*
  * Cambia la bandera multiLineComment si encuentra el símbolo de 
  * fin de comentario multilinea.
  * 
  * Parámtros:
  *   const string line: Línea en la que buscará el símbolo
  * 
  * Retorno:
  *   No regresa nada.
  */
  void multiLineComment(const std::string& line) {
    if (line.find("*/") != std::string::npos ) {
      this->multiLineFlag = false;
    }
  }

public:
  enum LineType {Comment, Code, Blank};

  LineEvaluator() {
    this->multiLineFlag = false;
  }

  /*
  * Regresa el tipo de línea recibida, de acuerdo con el enum LineType
  * 
  * Parámtros:
  *   const string line: Línea a evaluar 
  * 
  * Retorno:
  *   Valor del enum LineType en el que cae la línea evaluada.  
  */
  LineType getLineType(const std::string& line) {
    std::string trimmedLine = this-> _trim(line);

    // Check for comments
    if(trimmedLine.find("/*") != std::string::npos) {
      this->multiLineFlag = true;
      this->multiLineComment(trimmedLine);
      return Comment;
    }
    if(this->multiLineFlag) {
      this->multiLineComment(trimmedLine);
      return Comment;
    }
    if(trimmedLine[0] == '/' && trimmedLine[1] == '/') return Comment;

    if(trimmedLine == "") return Blank;
    return Code;
  }

};

#endif