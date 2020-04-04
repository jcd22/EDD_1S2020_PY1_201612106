#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

class Cola
{

	class NodoCola
	{

	private:

		NodoCola *before;
		string nombre; //nombre ficha
		int puntaje; //puntaje de esa ficha
		int cantidad; // cantidad del mismo tipo de ficha

	public:

		NodoCola(string nombre_,int puntaje_, int cantidad_)
		{

			before = 0;
			nombre = nombre_;
			puntaje = puntaje_;
			cantidad = cantidad_;
		}

		NodoCola *getbefore() { return before; }
		NodoCola *setbefore(NodoCola *before_) { before = before_; }
		NodoCola *getNodo() { return this; };


	};

private:
	int size;
	NodoCola *last;
	NodoCola *first;
	bool isEmpty() { return size == 0; };

public:
	Cola()
	{
		size = 0;
		last = 0;
		first = 0;
		llenarCola();
	}

	void enqueue(string nombre, int puntaje, int cantidad);
	void dequeue();
	void printCola();
	void llenarCola();

};

void Cola::enqueue(string nombre, int puntaje , int cantidad)
{

	if (isEmpty())
	{
		NodoCola *aux = new NodoCola(nombre,puntaje,cantidad);
		this->first = aux;
		this->last = aux;
		size++;

	}
	else
	{
		NodoCola *aux = new NodoCola(nombre,puntaje,cantidad);
		this->last->setbefore(aux);
		this->last = aux;
		size++;

	}

}

void Cola::dequeue()
{
	if (isEmpty())
	{

	}
	else
	{
		NodoCola *aux = this->first;
		this->first = this->first->getbefore();
		aux->setbefore(0);
		delete aux;
		size--;
	}


}

void Cola::printCola()
{

	NodoCola *aux = this->first; //apunta al ultimo par recorrer desde el final
	int x = 0;

	while (aux != 0) { //recorre alrevez 1 vez

		cout << x << ":"  << endl;// imprime
		aux = aux->getbefore();// apunta al anterior para recorrer
		x++;
	}


}

void Cola::llenarCola() {
		
	enqueue("a",1,12);
	enqueue("b", 3, 2);
	enqueue("c", 3, 4);
	enqueue("d", 2, 5);
	enqueue("e", 1, 12);
	enqueue("f", 4, 1);
	enqueue("g", 2, 2);
	enqueue("h", 4, 2);
	enqueue("i", 1, 6);
	enqueue("j", 8, 1);
	enqueue("l", 1, 4);
	enqueue("m", 3, 2);
	enqueue("n", 1, 5);
	enqueue("ñ", 8, 1);
	enqueue("o", 1, 9);
	enqueue("p", 3, 2);
	enqueue("q", 5, 1);
	enqueue("r", 1, 5);
	enqueue("s", 1, 6);
	enqueue("t", 1, 4);
	enqueue("u", 1, 5);
	enqueue("v", 4, 1);
	enqueue("x", 8, 1);
	enqueue("y", 4, 1);
	enqueue("z", 10, 1);

}

#endif // COLA_H_INCLUDED

