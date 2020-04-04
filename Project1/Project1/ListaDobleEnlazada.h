#ifndef LISTAARTISTA_H_INCLUDED
#define LISTAARTISTA_H_INCLUDED

#include <iostream>

using namespace std;


class ListaDoble
{
	class Nodo {

	public:
		Nodo(string name_)
		{

			next = 0;
			before = 0;
			name = name_;

		}

		Nodo *getNext() { return next; }
		Nodo *getBefore() { return before; }
		void setNext(Nodo *n) { next = n; }
		void setBefore(Nodo *n) { before = n; }
		Nodo *getDato() { return this; }
		string getName() { return name; };


	private:
		Nodo *next;
		Nodo *before;
		Nodo *dato;
		string name;

	};

private:
	int size;
	Nodo *first;
	Nodo *last;
	bool isEmpty() { return size == 0; }

public:
	ListaDoble() {

		first = 0;
		last = 0;
		size = 0;

	}

	int getsize() { return size; }
	void add_first( string name);
	void add_last( string name);
	void add_at( string name, int index);
	void get_element_at(int index);

	void remove_first();
	void remove_last();
	void remove_at(int index);
	void print_front_back();

	void addOrder( string name);
	int ordenAlfabetico(string name);

};


int ListaDoble::ordenAlfabetico(string name)
{

	char stringsep[90];
	strcpy(stringsep, name.c_str());

	if (stringsep[0] == 'a' || stringsep[0] == 'A') {
		return 0;

	}
	else if (stringsep[0] == 'b' || stringsep[0] == 'B') {

		return 1;

	}
	else if (stringsep[0] == 'c' || stringsep[0] == 'C') {

		return 2;

	}
	else if (stringsep[0] == 'd' || stringsep[0] == 'D') {

		return 3;

	}
	else if (stringsep[0] == 'e' || stringsep[0] == 'E') {

		return 4;

	}
	else if (stringsep[0] == 'f' || stringsep[0] == 'F') {

		return 5;

	}
	else if (stringsep[0] == 'g' || stringsep[0] == 'G') {

		return 6;

	}
	else if (stringsep[0] == 'h' || stringsep[0] == 'H') {

		return 7;

	}
	else if (stringsep[0] == 'i' || stringsep[0] == 'I') {

		return 8;

	}
	else if (stringsep[0] == 'j' || stringsep[0] == 'J') {

		return 9;

	}
	else if (stringsep[0] == 'k' || stringsep[0] == 'K') {

		return 10;

	}
	else if (stringsep[0] == 'l' || stringsep[0] == 'L') {

		return 11;

	}
	else if (stringsep[0] == 'm' || stringsep[0] == 'M') {

		return 12;

	}
	else if (stringsep[0] == 'n' || stringsep[0] == 'N') {

		return 13;

	}
	else if (stringsep[0] == 'ñ' || stringsep[0] == 'Ñ') {

		return 14;

	}

}


void ListaDoble::addOrder( string name)
{

	if (this->isEmpty()) {

		this->add_first( name);

	}
	else {

		if (ordenAlfabetico(name) > ordenAlfabetico(this->last->getName())) {


			this->add_last( name);

		}
		else if (ordenAlfabetico(name) < ordenAlfabetico(this->first->getName())) {

			this->add_first( name);

		}
		else {

			Nodo *temp = this->first;

			while (temp != 0) {

				if (this->ordenAlfabetico(temp->getNext()->getName()) >= this->ordenAlfabetico(name)) {

					Nodo *nuevo = new Nodo( name);
					nuevo->setNext(temp->getNext());
					nuevo->setBefore(temp);
					temp->getNext()->setBefore(nuevo);
					temp->setNext(nuevo);
					break;

				}
				temp = temp->getNext();


			}

			this->size++;

		}

	}

}


void ListaDoble::add_first( string name)
{
	Nodo *n = new Nodo( name);
	if (isEmpty())
	{
		this->first = n;
		this->last = n;
		this->size++;

	}
	else
	{

		n->setNext(this->first);
		this->first->setBefore(n);
		this->first = n;
		this->size++;

	}
}

void ListaDoble::add_last( string name)
{
	if (isEmpty())
	{
		this->add_first( name);
	}
	else {

		Nodo *n = new Nodo( name);
		this->last->setNext(n);
		n->setBefore(this->last);
		this->last = n;
		this->size++;

	}

}


void ListaDoble::add_at( string name, int index)
{
	if (index >= 0 && index <= this->size)
	{
		if (index == 0) { this->add_first(name); return; }
		if (index == this->size) { this->add_last( name); return; }

		Nodo *aux = this->first;
		int x = 0;
		while (aux != 0) {

			if (x == index) { break; }
			aux = aux->getNext();
			x++;
		}
		Nodo *n = new Nodo( name);
		aux->getBefore()->setNext(n);
		n->setBefore(aux->getBefore());
		n->setNext(aux);
		aux->setBefore(n);
		this->size++;

	}

}

//Metodos para remover Nodos


void ListaDoble::remove_first()
{

	if (!isEmpty())
	{

		if (this->size == 1) {

			this->first = 0;
			this->last = 0;
			size--;

		}
		else {

			Nodo *aux = this->first;
			this->first = this->first->getNext();
			aux->getNext()->setBefore(0);
			aux->setNext(0);
			delete aux;
			cout << aux->getDato() << endl;
			size--;

		}

	}

}



void ListaDoble::remove_last()
{

	if (!isEmpty())
	{

		if (this->size == 1) {

			this->first = 0;
			this->last = 0;
			size--;

		}
		else {

			Nodo *aux = this->last;
			this->last = this->last->getBefore();
			aux->getBefore()->setNext(0);
			aux->setBefore(0);
			delete aux;

			cout << aux->getDato() << endl;
			size--;

		}

	}

}



void ListaDoble::remove_at(int index)
{

	if (index >= 0 && index <= this->size)
	{
		if (index == 0)
		{
			this->remove_first();
		}
		else if (index == this->size - 1)
		{
			this->remove_last();
		}
		else
		{

			Nodo *aux = this->first;
			int x = 0;
			while (aux != 0)
			{ //aqui cambiar a x != sife

				if (x == index) { break; }
				aux = aux->getNext();
				x++;
			}

			aux->getBefore()->setNext(aux->getNext());
			aux->getNext()->setBefore(aux->getBefore());
			delete aux;
			cout << aux->getDato() << endl;
			this->size--;
		}

	}

}


void ListaDoble::get_element_at(int index)
{

	if (index >= 0 && index< size)
	{
		Nodo *iterador = this->first;
		int x = 0;
		while (iterador != 0)
		{
			if (index == x) { /*return iterador->getDato();*/ }
			iterador = iterador->getNext();
			x++;
		}
	}

}

void ListaDoble::print_front_back()
{

	Nodo *aux = this->first;
	int x = 0;
	while (x != this->size) {

		if (x == this->size) { break; }
		cout << aux->getName() << endl;
		aux = aux->getNext();
		x++;
	}


}


#endif // LISTAARTISTA_H_INCLUDED
