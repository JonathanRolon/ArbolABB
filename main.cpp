
#include "ArbolABB.h"
#include <iostream>

using namespace std;

int main(){

		/*
		 *       2
		 *        \
		 *         5
		 *        / \
		 *       4  10
		 */

		ArbolABB<int> arbol(2);

		arbol.insertar(5);
		arbol.insertar(10);
		arbol.insertar(4);

		arbol.eliminarDato(5);

		cout<<"Arbol ordenado"<<endl;
		arbol.obtenerArbol();

	return 0;
}



