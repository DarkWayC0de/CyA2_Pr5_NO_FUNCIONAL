# Práctica 5 Computabilidad y Algoritmia 2019-2020
### Objetivos
Consolidar los conocimientos adquiridos sobre Expresiones Regulares, sus 
operadores y significado.
Conocer las diferentes formas de una expresión: infija, posfija, prefija.
Implentar en C++ estructuras de datos tales como pilas o árboles.
Practicar en c++ el uso de clases genéricas a través de platillas (templates).
Profundizar en las capacidades de diseñar y desarrollar programas orientados
a objetos.

### Algoritmos
# Paso de expresión regular infija a postfija
El Algoritmo 1 permite convertir una expresión de infija a postfija utilizando
una pila.
1. Los operandos se imprimen conforme se leen en la entrada;
2. Si la pila está vacı́a o contiene un paréntesis abierto en el tope, apilar 
el operador entrante;
3. Si el sı́mbolo entrante es un paréntesis abierto, apilarlo;
4. Si el sı́mbolo entrante es un paréntesis cerrado, desapilar e imprimir los 
operadores hasta hallar un paréntesis abierto. Descartar el par de paréntesis;
5. Si el sı́mbolo entrante tiene mayor precedencia que el que se encuentra en 
el tope de la pila, apilarlo;
6. Si el sı́mbolo que se lee tiene la misma precedencia que el que se 
encuentra en el tope de la pila, usar asociación. Si la asociaciación es de
izquiera a derecha,desapilar e imprimir el elemento desapilado y apilar el 
operador que acaba de leerse. Si la asociatividad es de derecha a izquierda, 
apilar el operador que acaba de leerse.;
7. Si el sı́mbolo entrante tiene menor precedencia que el del tope de la 
pila, desapilar e imprimir el operador desapilado. Comprobar el operador 
entrante con el nuevo top de la pila;
8. Al final de la expresión, sacar de la pila todos los operadores e 
imprimirlos (no deberı́an quedar paréntesis);

# Paso de expresiónn postfija a árbol de expresión regular
El Algoritmo 2 permite construir el árbol de la expresión postfija usando 
nuevamente una pila, pero en este caso una pila de árboles (nodos).
1. Crear una pila;
2. Leer el siguiente sı́mbolo de la expresión postfija;
3. Si el sı́mbolo es un operando, cree un nuevo nodo del árbol que 
represente a ese operando y apile (push) ese nodo;
4. Si el sı́mbolo es un operador, saque (pop) de la pila dos árboles (A1 y
A2). Cree un nuevo árbol con el operador como raı́z y A1 y A2 como hijos. 
Apile este nuevo árbol en la pila;
5. Repita este proceso hasta que se complete la lectura de la expresión 
postfija;
6. Al final del proceso la pila contendrá un único árbol correspondiente a 
la expresión;

### Enunciado
Desarollar programa ER2Tree.cpp que lea un fichero de texto en el que figura
una relación de expresiones regulares escritasen notación infija y que usan 
el alfabeto Σ = {a,b,c,...,z,*,|,(,),}(la concatenación es un operando
implícito) El fichero de entrada contendrá una única espresión regular en 
cada línea. 
El progrma utilizara un archivo como entrada y un archivo de salida, su 
ejecusión se realizara de la siguiente forma:

'''bash
./ER2Tree filein.txt fileout.txt
'''

En el fichero de salido se imprimira una línea por cada espresión regular
del fichero de  entrada. En cada lı́nea del fichero de salida se deberá 
imprimir, separadas por tabuladores, las 3 formas de notación de la ER en 
el orden: infija, postfija, prefija y cada lı́nea finalizará con un número
natural que corresponde con el número de nodos del árbol de la expresión.
Como muestra la siguiente tabla:

'''bash
------------------------------------------------------
Infija		Postfija	Prefija		Nodos
------------------------------------------------------
a|b		ab|		|ab		3
a|bc		abc&|		|ab&c		5
(a|b)(c|d)	ab|cd|&		&|ab|cd		7
'''

En la primera columna de la tabla(Infija) no se explicita el operador de 
concatenación, deñ mismo modo que no se hace en las espreciones regulares
del fichero de entrada. 

### Rúbrica de evaluación del ejercicio
El programa debe ajustarse a lo solicitado.
Capacidad del programador de introducir cabios en el programa desarollado.
El programa ha de seguir el paradigma de orientacion a objetos.
El programa ha de ser modular.
El programa ha de ceñirse forzozamente al formato de escritura de programas
adoptado en las práticas de la asignatura.



