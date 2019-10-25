// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 20/10/2019
// Archivo NodoB.h: Template para la creacion de nodos de un arbol
//                   
//                     
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    22/10/2019 - Creación (primera versión) del código
//
#ifndef NODOB_H
#define NODOB_H

template <class T>
class NodoB {

 private:

  NodoB<T> *izq_;
  NodoB<T> *der_;
  T Dato_;

 public:

  NodoB() : izq_(nullptr), der_(nullptr) {
  }

  explicit NodoB(T dato) : izq_(nullptr), der_(nullptr), Dato_(dato) {
  }

  virtual ~NodoB()= default;


  NodoB<T> **getIzq()  {
    return &izq_;
  }
  NodoB<T> *getIzqcop()  {
    return izq_;
  }

  void setIzq(NodoB<T> *izq) {
    izq_ = izq;
  }

  NodoB<T> **getDer() {
    return &der_;
  }
  NodoB<T> *getDercop() {
    return der_;
  }

  void setDer(NodoB<T> *der) {
    der_ = der;
  }

  T getDato() const {
    return Dato_;
  }

  void setDato(T dato) {
    Dato_ = dato;
  }

};

#endif //NODOB_H
