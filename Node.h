/*
   File Node.h

   Class Node

   Class Node stores integer values for a linked list.
   
   This file has the Node's interface (header file).

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/
#ifndef NODE
#define NODE
#include "headers.h"

class Node {

    string val;
    Node* next;

  public:
         
    Node(string dat, Node* nxt);
    string getVal();
    Node* getNext();
    void setVal(string dat);
    void setNext(Node* nxt);
};

#endif
