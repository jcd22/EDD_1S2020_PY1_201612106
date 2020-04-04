#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include <iostream>
#include "Cancion.h"

using namespace std;

class ListaSimple
{

    class NodoSimple
    {

private:
    Cancion *dato;
    NodoSimple *next;

public:
    NodoSimple(Cancion *dato_)
    {

    next = 0;
    dato = dato_;

    }

    Cancion *getCancion(){ return dato;}
    NodoSimple *getNext(){return next;}
    NodoSimple *setNext(NodoSimple *n){ next = n;}


    };

private:
    NodoSimple *first;
    NodoSimple *last;
    int size;
    bool isEmpty(){return size == 0;};
    int getSize(){return size;};

public:

    ListaSimple()
    {

    size = 0;
    first = 0;
    last = 0;

    }

    void push(Cancion *dato);
    void print_front_back();

};

void ListaSimple::push(Cancion *dato)
{

if(isEmpty())
    {
        NodoSimple *aux = new NodoSimple(dato);
        this->first = aux;
        this->last = aux;
        size++;

    } else
    {
        NodoSimple *aux = new NodoSimple(dato);
        this->last->setNext(aux);
        this->last = aux;
        size++;

    }

}

void ListaSimple::print_front_back()
{

        NodoSimple *aux = this->first; //empieza apuntando al primero par recorrer
        int x = 0;
        while(x != this->size){ // para hasta que se recorra toda la lista 1 vez

            if(x == this->size){ break;}
            cout<<aux->getCancion()->getName()<<endl; // obtiene e imprime los datos
            aux = aux ->getNext(); // apunta al siguiente para recorrer
            x++;
        }


}

#endif // LISTASIMPLE_H_INCLUDED
