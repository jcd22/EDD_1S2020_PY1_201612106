#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <iostream>
using namespace std;

class Pila
{

class NodoPila
{

private:

    NodoPila *before;
    string cancion;

public:

    NodoPila(string cancion_)
    {

    before = 0;
    cancion = cancion_;

    }

    NodoPila *getBefore(){return before;}
    NodoPila *setBefore(NodoPila *before_){ before = before_;}
    string getCancion(){return cancion;};


};

private:
    int size;
    NodoPila *last;
    bool isEmpty(){ return size == 0;};

public:
    Pila()
    {
        size = 0;
        last = 0;

    }

    void push(string cancion);
    void pop();
    void printPila();

};

void Pila::push(string cancion)
{

    if(isEmpty())
    {
         NodoPila *aux = new NodoPila(cancion);
        this->last = aux;
        size++;

    } else
    {
        NodoPila *aux = new NodoPila(cancion);
        aux->setBefore(this->last);
        this->last = aux;
        size++;

    }

}

void Pila::pop()
{
    if(isEmpty())
    {

    } else
    {
        NodoPila *aux = this->last;
        this->last = this->last->getBefore();
        aux->setBefore(0);
        delete aux;
        size--;
    }


}

void Pila::printPila()
{

        NodoPila *aux = this->last; //apunta al ultimo par recorrer desde el final
        int x = 0;

        while(aux != 0){ //recorre alrevez 1 vez

        cout<<x<<":"<<aux->getCancion()<<endl;// imprime
        aux = aux -> getBefore();// apunta al anterior para recorrer
        x++;
        }


}

#endif // PILA_H_INCLUDED
