/*
* Realiza validaciones de archivos de texto.
* 
* Autor: Sergio Gabriel Diosdado Castelazo A00516971
* Creación: febrero 23, 2021
* Actualización: febrero 23, 2021
*/
#ifndef FILEVALIDATOR_H
#define FILEVALIDATOR_H
#include <iostream>
#include <string.h>
#include <fstream>

class FileValidator
{

public:
  /*
  * Revisa que el archivo exista y sea válido (no corrupto)
  * 
  * Parámetros:
  *   const string fileName: String que contiene el nombre del archivo a validar
  * 
  * Retorno:
  *   Regresa un bool dependiendo si el archivo existe o sea válido (true) o no (false). 
  *   
  */
  static bool doesFileExist(const std::string& fileName) {
    std::ifstream file(fileName);
    return !file.fail();
  }

  /*
  * Revisa que el archivo esté vacío 
  * 
  * Parámetros:
  *   const string fileName: String que contiene el nombre del archivo a validar
  * 
  * Retorno:
  *   Regresa un bool dependiendo si el archivo está vacío (true) o no (false). 
  *   
  */
  static bool isFileEmpty(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.peek() == std::ifstream::traits_type::eof();
  }

};

#endif