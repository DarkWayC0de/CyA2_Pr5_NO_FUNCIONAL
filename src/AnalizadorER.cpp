// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Autor: Diego Cruz Rodriguez
// Correo: alu0101105802@ull.edu.es
// Fecha: 20/10/2019
// Archivo AnalizadorER.h: Implementacion de la clase AnalizadorER que apartir 
//                         de una expresion regular en formato infijo la 
//                         tranforma a formato posfijo y forma el arbol de la
//                         expresion regular con el cual optendra la salida 
//                         prefija, infija y postfija.  
//                     
//
// Referencias: 
//  Enunciado de la práctica: https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
//
//
// Historial de revisiones
//                    21/10/2019 - Creación (primera versión) del código
//
#include <iostream>
#include <stack>
#include <utility>
#include "AnalizadorER.h"

AnalizadorER::AnalizadorER(std::string expresionregular) :
                          Expresion_Regular_(std::move(expresionregular)), ArbolER_(std::make_unique<NodoB<char>>()){
}

AnalizadorER::~AnalizadorER(){
}

void AnalizadorER::tranformar_formato_postfijo(){
  std::stack<char> pila;
  expandirconcatenacion();
  std::string expresion_regular_infija = this -> Expresion_Regular_;
  std::string expresion_regular_postfija;
  for (int i = 0; i < expresion_regular_infija.size(); i++) {
    if ( expresion_regular_infija[i] != ESTRELLA &&
         expresion_regular_infija[i] != DISYUNCION &&
         expresion_regular_infija[i] != PARENTESIS_APERTURA &&
         expresion_regular_infija[i] != PARENTESIS_CIERRE &&
         expresion_regular_infija[i] != CONCATENACION) {
      expresion_regular_postfija += expresion_regular_infija[i];
    } else {
      if ( pila.empty() ||pila.top() == PARENTESIS_APERTURA ||
           expresion_regular_infija[i] == PARENTESIS_APERTURA) {
        pila.push(expresion_regular_infija[i]);
      } else if ( expresion_regular_infija[i] == PARENTESIS_CIERRE){
        while (pila.top() != PARENTESIS_APERTURA){
          expresion_regular_postfija += pila.top();
          pila.pop();
        }
        pila.pop();
      } else if ((expresion_regular_infija[i] == ESTRELLA && pila.top() != ESTRELLA) ||
                 (expresion_regular_infija[i] == CONCATENACION && pila.top() == DISYUNCION)) {
        pila.push(expresion_regular_infija[i]); // entra de mayor presedencia
      } else if ((expresion_regular_infija[i] == CONCATENACION && pila.top() == CONCATENACION )||
                 (expresion_regular_infija[i] == DISYUNCION && pila.top() == DISYUNCION )||
                 (expresion_regular_infija[i] == ESTRELLA && pila.top() == ESTRELLA )){
        expresion_regular_postfija += pila.top();
        pila.pop();
        pila.push(expresion_regular_infija[i]); 
      } else if ( expresion_regular_infija[i] != ESTRELLA){
        expresion_regular_postfija += pila.top();
        pila.pop();
       i--;   
      }
    }
  }
  while (!pila.empty()){
        expresion_regular_postfija += pila.top();
        pila.pop();
  }
  

  this -> Expresion_Regular_ = expresion_regular_postfija;


}

void AnalizadorER::expandirconcatenacion() {
 std::string expresionbase =this -> Expresion_Regular_;
 std::string expresionexpandida;
 expresionexpandida += expresionbase[0];
    for (int i = 1, j = 0; i < expresionbase.size() ; ++i, j++) {
      if ( (expresionbase[j] == PARENTESIS_CIERRE &&
            (expresionbase[i] != ESTRELLA))&&
            (expresionbase[j] == PARENTESIS_CIERRE &&
            expresionbase[i] == DISYUNCION)){
          expresionexpandida += '&';
      } else if ((expresionbase[j] == ESTRELLA &&
                 expresionbase[i] != ESTRELLA) ||
                 (expresionbase[j] == ESTRELLA &&
                 expresionbase[i] !=DISYUNCION)) {
          expresionexpandida += '&';
      } else if ( expresionbase[j] != ESTRELLA &&
                  expresionbase[j] != DISYUNCION &&
                  expresionbase[j] != PARENTESIS_APERTURA &&
                  expresionbase[j] != PARENTESIS_CIERRE &&
                  expresionbase[i] != ESTRELLA &&
                  expresionbase[i] != DISYUNCION &&
                  expresionbase[i] != PARENTESIS_APERTURA &&
                  expresionbase[i] != PARENTESIS_CIERRE){
          expresionexpandida += '&';
      }
        expresionexpandida += expresionbase[i];
    }

 this -> Expresion_Regular_ = expresionexpandida;
}

void AnalizadorER::convertir_arbol() {
  tranformar_formato_postfijo();
  std::stack<std::unique_ptr<NodoB<char>>> pila;
  for (int i = 0; i < this -> Expresion_Regular_.size(); ++i) {
    this -> evaluayconstrullearbol(this -> Expresion_Regular_[i],pila);
  }
  this -> ArbolER_ = std::move( pila.top());
}

void AnalizadorER::evaluayconstrullearbol(char simbolo,
                      std::stack<std::unique_ptr<NodoB<char>>> &pila) {
  if ( simbolo == ESTRELLA ) {
     std::unique_ptr<NodoB<char>> nodoestrella = std::make_unique<NodoB<char>>();
     std::unique_ptr<NodoB<char>> nodosubarbol = std::make_unique<NodoB<char>>();
     std::cout<<"fallo"<<&nodoestrella;
     nodosubarbol = std::move( pila.top());
     nodoestrella -> setDato(ESTRELLA);
     nodoestrella -> setIzq(nodosubarbol.get());
     pila.pop();
     pila.push(std::move(nodoestrella));
  } else if (simbolo == DISYUNCION) {
     std::unique_ptr<NodoB<char>> nododisyuncion = std::make_unique<NodoB<char>>();
     std::unique_ptr<NodoB<char>> nodosubarbolizq = std::make_unique<NodoB<char>>();
     std::unique_ptr<NodoB<char>> nodosubarbolder = std::make_unique<NodoB<char>>();
     nodosubarbolder = std::move( pila.top());
     pila.pop();
     nodosubarbolizq = std::move( pila.top());
     pila.pop();
     nododisyuncion -> setDato(DISYUNCION);
     nododisyuncion -> setIzq(nodosubarbolizq.get());
     nododisyuncion -> setDer(nodosubarbolder.get());
     pila.push(std::move(nododisyuncion));
  } else if (simbolo == CONCATENACION) {
     std::unique_ptr<NodoB<char>> nododconcatenacion = std::make_unique<NodoB<char>>();
     std::unique_ptr<NodoB<char>> nodosubarbolizq = std::make_unique<NodoB<char>>();
     std::unique_ptr<NodoB<char>> nodosubarbolder = std::make_unique<NodoB<char>>();
     nodosubarbolder = std::move( pila.top());
     pila.pop();
     nodosubarbolizq = std::move( pila.top());
     pila.pop();
     nododconcatenacion -> setDato(CONCATENACION);
     nododconcatenacion -> setIzq(nodosubarbolizq.get());
     nododconcatenacion -> setDer(nodosubarbolder.get());
     pila.push(std::move(nododconcatenacion));
  } else {
     std::unique_ptr<NodoB<char>> nodosimbolo = std::make_unique<NodoB<char>>();
     nodosimbolo -> setDato(simbolo);
     pila.push(std::move(nodosimbolo));
  }
}
