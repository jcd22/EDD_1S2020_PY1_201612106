#ifndef ListaCircular_H_INCLUDED
#define ListaCircular_H_INCLUDED
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

template <class T>
class ListaCircular
{
    class Nodo{

public:
    Nodo(T *x)
    {

        next = 0;
        before = 0;
        dato = x;

    }

    Nodo *getNext(){ return next;}
    Nodo *getBefore(){return before;}
    void setNext(Nodo *n){next = n;}
    void setBefore(Nodo *n){before = n;}
    T *getDato(){ return dato;}

private:
    Nodo *next;
    Nodo *before;
    T *dato;

    };

private:
    int size;
    Nodo *first;
    Nodo *last;
    bool isEmpty(){return size == 0;}

public:
    ListaCircular(){

        first = 0;
        last = 0;
        size = 0;

    }

    int getsize(){return size;}
    /*aqui se inicializan los metodos que usaremos
      para  la Hoja de trabajo1*/
    void add_first(T *dato);
    void add_last(T *dato);
    void add_at(T *dato, int index);
    T *get_element_at(int index);
    T print_front_back();
    T print_back_front();
    T graph();
};


template <class T>
void ListaCircular<T>::add_first(T *dato)
{
Nodo *n = new Nodo(dato);
//En el siguiente if else is esta vacia la lista agregamos el nodo y sera el primero y el ultimo
if (isEmpty())
{
    this ->first = n;
    this ->last = n;
    this ->size++;

} else
{

    n->setNext(this->first); //al nuevo nodo crado, le desimos que su siguiente apunte al primero
    this->first->setBefore(n);//el anterior del primero apunta al nuevo
    this->first = n;//ahora el primero sera el nuevo

    //Para crear de tipo circular
    n->setBefore(this->last);//el anterior del nuevo apunta al ultimo
    this->last->setBefore(this->first);// el anterior del ultimo apunta al nuevo
    this ->size++;

}
}
template <class T >
void ListaCircular<T>::add_last(T *dato)
{
    Nodo *n = new Nodo(dato);

    if(isEmpty())
    { //si esta vacia los dos apuntadores primero y ultimo apuntan al nuevo
        this ->first = n;
        this ->last = n;
        this ->size++;

    } else{

    this -> last ->setNext(n); // el siguiente del ultimo apunta al nuevo
    n->setBefore(this->last);// el anterior del nuevo apunta al ultimo
    this -> last = n;// el ultimo apunta al nuevo

    //para que sea doble circular
    n->setNext(this->first);//el siguiente del nuevo apunta al primero
    first->setBefore(this->last);// el anterior del primero apunta al ultimo
    this -> size++;

    }

}

template <class T>
void ListaCircular<T>::add_at(T *dato, int index)
{
    if(index > 0 && index <= this-> size)
    {
        if(index == 0){this ->add_first(dato); return;} // si agrega al inicio
        if(index == this->size){this -> add_list(dato); return;} //para agregar al final

        Nodo *aux = this->first;
        int x = 0;
        while(x != this->size){

            if(x == index){ break;}
            aux = aux -> getNext(); // el auxiliar apuntara al siuiente para moverse en la lista hasta encontrar el indice
            x++;
        }
        Nodo *n = new Nodo(dato);
        aux -> getBefore()->setNext(n);// el siguiente del anterior del auxiliar apuntara al nuevo
        n -> setBefore(aux->getBefore()); // el anterior del nuevo apuntara al anterior del aux
        n -> setNext(aux); // el siguiente del nuevo apuntara al aux
        aux -> setBefore(n); //el anterior del aux apuntara al nuevo
        this -> size++;

    }

}

template <class T>
T *ListaCircular<T>::get_element_at(int index)
{

    if(index >= 0 && index< this->getsize())
    {
        Nodo *iterador = this->first; // nos ayudara a recorrer la lista
        int x = 0;
        while(iterador != 0)
        {
            if(index == x){ return iterador->getDato();} //al encontrar el dato de ese nodo
            iterador = iterador->getNext();// continua hasta que se cumpla la condicion o con un break
            x++;
        }
    }

}

template <class T>
T ListaCircular <T>::print_front_back()
{

        Nodo *aux = this->first; //empieza apuntando al primero par recorrer
        int x = 0;
        while(x != this->size){ // para hasta que se recorra toda la lista 1 vez

            if(x == this->size){ break;}
            cout<<aux->getDato()<<endl; // obtiene e imprime los datos
            aux = aux -> getNext(); // apunta al siguiente para recorrer
            x++;
        }


}

template <class T>
T ListaCircular <T>::print_back_front()
{
           Nodo *aux = this->last; //apunta al ultimo par recorrer desde el final
        int x = 0;

        while(x != this->size){ //recorre alrevez 1 vez

            if(x == this->size){ break;}
            cout<<aux->getDato()<<endl;// imprime
            aux = aux -> getBefore();// apunta al anterior para recorrer
            x++;
        }

}

template <class T>
T ListaCircular <T>::graph()
{
     T graf =  "digraph { \n";
     graf = graf + "node[shape=box, width = 2.5, height = .75 ]; \n";

        cout<< " digraph {"<<endl;
        cout<<"node[shape=box, width = 2.5, height = .75 ];"<<endl;
        Nodo *aux = this->first; //empieza apuntando al primero par recorrer
        int x = 0;
        while(x != this->size){ // para hasta que se recorra toda la lista 1 vez

            if(x == this->size){ break;}
            cout<<aux->getDato()<<"->"<<aux->getNext()->getDato()<<endl; // obtiene e imprime los datos
            graf = graf + aux->getDato();
            graf = graf + "->";
            graf = graf + aux->getNext()->getDato();
            graf = graf + "\n";

            aux = aux -> getNext(); // apunta al siguiente para recorrer
            x++;
        }
         x = 0;
         aux = this->first;
         cout<<endl;
         while(x != this->size){ //recorre alrevez 1 vez

            if(x == this->size){ break;}
            cout<<aux->getDato()<<"->"<<aux->getBefore()->getDato()<<endl;// imprime
            graf = graf + aux->getDato();
            graf = graf + "->";
            graf = graf + aux->getBefore()->getDato();
            graf = graf + "\n";

            aux = aux -> getBefore();// apunta al anterior para recorrer
            x++;
        }
        cout<<endl;
        cout<<"}"<<endl; //el final del dot
        graf = graf + "\n";
        graf = graf + "}";

         ofstream g("grafica.dot");
          cout<<graf<<endl;
          g<<graf;
          g.close();
          system("dot -Tpng grafica.dot -o grafCircular.png");
          system("grafCircular.png");


}


#endif // ListaCircular_H_INCLUDED

