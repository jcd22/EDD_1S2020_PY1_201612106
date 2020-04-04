#pragma once
#include <iostream>
#include <fstream>
#include <iomanip> //para stw
#include <nlohmann\json.hpp>
#include <cstdlib> 

using json = nlohmann::json;
using namespace std;

class Menu
{

private:

public:

	Menu()
	{


	}

	void insertarArchivo();

};

void Menu::insertarArchivo() {
	ifstream i("Test.json");
	json j;
	i >> j; // paso todo el archivo a el json

	json j2, j3, j4, j5, j6, j7;

	//**********************Comandos**************************
	//it.key() obtiene la llave en el json
	// it.value() obtiene el valor que apunta esa llave
	//*it apunta al contenido del arreglo

	// special iterator member functions for objects
	for (json::iterator it = j.begin(); it != j.end(); ++it)  //obtengo contenido de Test
		{

			j2 = it.value();
			
			cout<<"/" << endl;
			if (it.key() == "dimension")//verifico llave e y cuardo contenido
			{
			//	cout <<""<<it.value()<<"dimension----"<<endl;//imprimo contenido de dimension
			}
			else if (it.key() == "casillas")
			{

				for (json::iterator it = j2.begin(); it != j2.end(); ++it) // recorro json de las casillas
				{
					if (it.key() == "dobles")
					{
						cout << "dobles" << endl;
						j3 = it.value();
						for (json::iterator it = j3.begin(); it != j3.end(); ++it) //itero el arreglo de coordenadas
						{
							int contador = 0;
							j4 = *it;//consigo cada coordenada en json;
							cout << j4<<endl;
							cout << "coordenada" << contador << endl;
							for (json::iterator it = j4.begin(); it != j4.end(); ++it)
							{
								cout << it.key() << "::" << it.value()<<endl;
							}
							contador++;
						}//fin for coordenadas dobles
					} 
					else if (it.key() == "triples")
					{
						cout << "triples" << endl;
						j3 = it.value();
						for (json::iterator it = j3.begin(); it != j3.end(); ++it) //itero el arreglo de coordenadas
						{
							int contador = 0;
							j4 = *it;//consigo cada coordenada en json;
							cout << j4 << endl;
							cout << "coordenada" << contador << endl;
							for (json::iterator it = j4.begin(); it != j4.end(); ++it)
							{
								cout << it.key() << "::" << it.value() << endl;
							}
							contador++;
						}//fin for coordenadas triples
					}

				} //fin for para casillas

			}
			else if (it.key() == "diccionario")
			{
				cout << "contenido diccionario:" << endl;
				for (json::iterator it = j2.begin(); it != j2.end(); ++it) //itero el arreglo de coordenadas
				{
					j5 = *it;
						for (json::iterator it = j5.begin(); it != j5.end(); ++it) //for recoore c/u de las palabras obtengo key() palabra y valor() palabra
						{
							cout << it.key() << "::" << it.value() << endl;
						}
						
				}//fin for palabras
				
				}


			}//fin for recorre archivo;
	
		


	} //fin insertarArchivo

int main()
{

	Menu *menu = new Menu();
	menu->insertarArchivo();
	std::cin.get();
	return 0;
	
}


