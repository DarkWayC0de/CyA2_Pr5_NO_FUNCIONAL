// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 20/10/2019
// Archivo ER2Tree.cpp: Funcion principal del programa, recoge los atributos
//                      los analiza y hace la gestion de ficheros  
//                     
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    20/10/2019 - Creación (primera versión) del código
//
#include <iostream>
#include <string>
#include "AnalizadorER.h"
int main(){
  std::string hi = "(a|b)*xz*";
  AnalizadorER hola(hi);
  hola.convertir_arbol();
  
  return 0;
}
