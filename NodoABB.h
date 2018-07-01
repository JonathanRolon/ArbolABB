/*
 * NodoABB.h
 *
 *  Created on: 29 jun. 2018
 *      Author: jonathan
 */

#ifndef NODOABB_H_
#define NODOABB_H_



#include <cstdlib>

template <class T>

class NodoABB{

	private:

		T clave;

		NodoABB <T> * hijoIzquierdo;

		NodoABB <T> * hijoDerecho;

	public:

		/*
		 *post: deja el nodo del arbol creado con la clave guardada o un valor,
		 *		 y sin hijos
		 */
		NodoABB(T clave){

			this->clave=clave;

			hijoIzquierdo = NULL;

			hijoDerecho = NULL;
		}

		/*
		 * post: devuelve la clave
		 */
		T obtenerClave(){
			return this->clave;
		}

		/*
		 * post:
		 */
		void cambiarClave(T clave){
			this->clave =clave;
		}

		/*
		 * post: cambia el hijo derecho
		 */
		void cambiarHijoDerecho(NodoABB <T>* nuevoHijoDerecho){
			this->hijoDerecho = nuevoHijoDerecho;
		}

		/*
		 * post: cambia el hijo izquierdo
		 */
		void cambiarHijoIzquierdo(NodoABB <T>* nuevoHijoIzquierdo){
			this->hijoIzquierdo = nuevoHijoIzquierdo;
		}

		/*
		 * post: devuelve el hijo izquierdo
		 */
		NodoABB <T> * obtenerHijoIzquierdo(){
			return this->hijoIzquierdo;
		}

		/*
		 * post: devuelve el hijo derecho
		 */
		NodoABB <T> * obtenerHijoDerecho(){
			return this->hijoDerecho;
		}
};


#endif /* SRC_NODOABB_H_ */
