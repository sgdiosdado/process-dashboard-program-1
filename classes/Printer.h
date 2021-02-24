/*
* Esta clase imprime el tipo de reporte solicitado. 
* 
* Autor: Sergio Gabriel Diosdado Castelazo A00516971
* Creación: febrero 24, 2021
* Actualización: febrero 24, 2021
*/
#ifndef PRINTER_H
#define PRINTER_H
#include <iostream>

using namespace std;
class Printer {

public:
  /*
  * Imprime el reporte de conteo de líneas
  * 
  * Parámetros:
  *   int code: Cantidad de líneas con código
  *   int blank: Cantidad de líneas en blanco
  *   int comment: Cantidad de líneas con comentario
  * 
  * Retorno:
  *   No regresa nada.
  */
  static void lineTypeCountReport(int code, int blank, int comment) {
    cout << "--------------------------------------------" << endl;
    cout << "Cantidad de líneas en blanco: " << blank << endl;
    cout << "Cantidad de líneas con comentarios: " << comment << endl; 
    cout << "Cantidad de líneas con código: " << code << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Cantidad total de líneas: " << code + blank + comment << endl;
  }
};

#endif