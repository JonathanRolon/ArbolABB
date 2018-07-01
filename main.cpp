
#include "ArbolABB.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

		/*
		 *       2
		 *        \
		 *         5
		 *        / \
		 *       4  10
		 */

		ArbolABB<string> arbol("MENDOZA");

		arbol.insertar("SAN JUAN");
		arbol.insertar("CORDOBA");
		arbol.insertar("SAN LUIS");
		cout<<"existe?"<<arbol.esta("LA PAMPA")<<endl;

		//arbol.eliminarDato(5);

		cout<<"Arbol ordenado"<<endl;
		arbol.obtenerArbol();

	return 0;
}



