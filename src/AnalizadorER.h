// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 20/10/2019
// Archivo AnalizadorER.h: Declaracion de la clase AnalizadorER que apartir de
//                         una expresion regular en formato infijo la tranforma
//                         a formato posfijo y forma el arbol de la expresion 
//                         regular con el cual optendra la salida prefija,
//                         infija y posfija.  
//                     
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    21/10/2019 - Creación (primera versión) del código
//

#ifndef ANALIZADORER_H
#define ANALIZADORER_H

#include <memory>
#include <string>
#include <stack>
#include "NodoB.h"

class AnalizadorER{
 public:
  explicit AnalizadorER(std::string expresionregular);
  ~AnalizadorER();
  void convertir_arbol();
  std::string lectura_infija(); //TODO
  std::string lectura_posfija();//TODO
  std::string lectura_prefija();//TODO
  unsigned numero_nodos_arbol();//TODO:

 private:
  void tranformar_formato_postfijo();
  void expandirconcatenacion();
  void evaluayconstrullearbol(char ,std::stack<std::unique_ptr<NodoB<char>>> &);
  std::string Expresion_Regular_;
  std::unique_ptr<NodoB<char>> ArbolER_;
    char ESTRELLA =  '*';
    char DISYUNCION = '|';
    char PARENTESIS_APERTURA = '(';
    char PARENTESIS_CIERRE = ')';
    char CONCATENACION = '&';

};

#endif //ANALIZADORER_H

