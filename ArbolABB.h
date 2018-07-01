/*
   Arbol binario de búsqueda:
   Es un ABB que verifica que para cada nodo con clave x,
   toda clave del subárbol derecho de ese nodo es mayor que x y
   toda clave del subárbol izquierdo de ese nodo es menor que x.
 */

#ifndef SRC_ABB_H_
#define SRC_ABB_H_

#include "NodoABB.h"

#include <iostream>

template <class T>

class ArbolABB{

	private:

		NodoABB <T> * raiz;

	public:

		/*
		 * post: arbol con solo la raiz listo para su uso
		 */
		ArbolABB(T clave);

		/* pre: arbol con al menos altura 1
		 * post: remueve y devuelve la raiz del arbol
		 */
		T obtenerRaiz();

		/*
		 * post:busca clave en el arbol y devuelve si existe
		 */
		bool esta(T clave , NodoABB <T> *raiz);

		/*
		 * post : inserta la clave en el arbol, el mismo queda modificado
		 */
		void insertar(T clave);

		/*
		 * post: elimina la clave o dato del arbol, el mismo queda modificado
		 */
		void eliminarDato(T dato);

		/*
		 * post: devuelve impreso todos los nodos del arbol en orden creciente
		 */
		void obtenerArbol();

		/*
		 * post: a partir de la raiz muestra todos los elementos del arbol en orden
		 */
		void inOrden (NodoABB<T> *r);

		/*
		 * post: devuelve elemento por elemento del arbol, primero subarbol izquierdo
		 *       luego raiz y ultimo subarbol derecho
		 */
		T preOrden (NodoABB<T> *r);

		/*
		 * post: devuelve elemento por elemento del arbol, primero los dos subarboles
		 *       por ultimo la raiz.
		 */
		T postOrden(NodoABB<T> *r);

		/*
		 * post: el arbol queda arrancado, se elimina el mismo
		 */
		void arrancarArbol(NodoABB <T> * entrada);

		/*
		 * post: libera recursos asociados al arbol
		 */
		~ArbolABB();


	private:


		/* pre: hijo es 1 o 2 (izq. o der.), padre es NULL en principio
		 * post: inserta la clave, el arbol queda modificado
		 */
		NodoABB <T> * insertarRec(T clave, NodoABB <T> * raiz, NodoABB <T> * padre, short hijo);

		/*
		 * post: devuelve el nodo con la clave buscada
		 */
		NodoABB <T> * encontrarNodo(T claveBuscada, NodoABB <T> * entrada);

		/*
		 * post: devuelve el nodo de mayor clave del subarbol izquierdo de la entrada
		 */
		NodoABB <T> *  obtenerMayorDeMenores(NodoABB <T> * entrada);

		/*
		 * post: devuelve el padre del nodo que contiene la clave buscada
		 */
		NodoABB<T>*  encontrarPadre(T claveBuscada, NodoABB <T> * entrada);

		/*
		 * post: devuelve si aEliminar no tiene hijo alguno
		 */
		bool sinHijos(NodoABB <T> * aEliminar);

		/*
		 * post: devuelve si aEliminar posee solo un hijo
		 */
		bool conUnHijo(NodoABB <T> * aEliminar);

		//Este caso es cuando el 'hijoABorrar' no tiene hijos
		/*
		 * post: elimina el hijoABorrar
		 */
		void eliminarEnCaso1(NodoABB <T> * padre, NodoABB <T> * hijoABorrar);

		//Este caso es cuando el 'hijoABorrar' tiene un hijo
		/*
		 * post: el 'hijoABorrar' se elimina ahora el hijo de 'hijoABorrar'
		 *       es hijo de 'padre'.
		 */
		void eliminarEnCaso2(NodoABB <T> * padre, NodoABB <T> * hijoABorrar);

		//Este caso es cuando el 'hijoABorrar' tiene dos hijos
		/*
		 * post: en este caso, el mayor de los menores del hijoABorrar pisa el hijoABorrar
		 *       luego el mayor de los menores queda eliminado del arbol
		 */
		void eliminarEnCaso3( NodoABB <T> * hijoABorrar);

};

template <class T>

ArbolABB<T>::ArbolABB(T clave){

	this->raiz = new NodoABB <T> (clave);

}

template <class T>

T ArbolABB<T>::obtenerRaiz(){

	return this->raiz->obtenerClave();
	eliminarDato(raiz->obtenerClave());
}

template <class T>
bool ArbolABB<T>::esta(T claveBuscada, NodoABB<T> *raiz){ // Buscar Dato

	if (raiz == NULL){
		return false;
	}else{
		if(raiz->obtenerClave()==claveBuscada){
			return true;
		}else
			if(claveBuscada > raiz->obtenerClave()){
				esta(claveBuscada,raiz->obtenerHijoDerecho());
			}else{
				esta(claveBuscada,raiz->obtenerHijoIzquierdo());
			}
	}
}

template <class T>
void ArbolABB<T>:: insertar(T clave){
	insertarRec(clave, raiz, NULL, 1);
}

template <class T>
NodoABB <T> * ArbolABB<T>::insertarRec(T dato, NodoABB <T> * entrada,
		                               NodoABB <T> * padre, short hijo){

	if (entrada == NULL){

		NodoABB<T> * nuevo = new NodoABB<T> (dato);

		if(hijo == 1){
			padre->cambiarHijoIzquierdo(nuevo);//padre nunca es NULL porque el arbol se crea con
			                                    // un nodo al menos
		}else{
			padre->cambiarHijoDerecho(nuevo);
		}

	}else
		if(dato == entrada->obtenerClave()){
			throw std::string("El nodo ya existe") ;
		}else
			if(dato > entrada->obtenerClave()){
				insertarRec(dato,entrada->obtenerHijoDerecho(),entrada,2);
			}else{
				insertarRec(dato,entrada->obtenerHijoIzquierdo(),entrada,1);
			}

	return entrada;
}

template <class T>
NodoABB <T> * ArbolABB<T> :: encontrarNodo(T claveBuscada, NodoABB <T> * entrada){

	bool esta = false;
	NodoABB <T> * nuevo = NULL;
	if (entrada != NULL){
		nuevo = entrada;
	}
	while(nuevo!=NULL && !esta){
		if(nuevo->obtenerClave() == claveBuscada){
			esta=true;
		}else
			if( claveBuscada > nuevo->obtenerClave()){
				nuevo = nuevo->obtenerHijoDerecho();
			}else{
				nuevo = nuevo->obtenerHijoIzquierdo();
			}
	}
	return nuevo;
}

template <class T>
NodoABB <T> *  ArbolABB<T>::obtenerMayorDeMenores(NodoABB <T> * entrada){
	if(entrada==NULL){
		return  NULL;
	}else
		if(entrada->obtenerHijoDerecho()==NULL){
			return entrada;
		}else{
			return obtenerMayorDeMenores(entrada->obtenerHijoDerecho());
		}
}

template <class T>
NodoABB<T>*  ArbolABB<T>:: encontrarPadre(T claveBuscada, NodoABB <T> * raiz){

	bool esta = false;
	NodoABB <T> * entrada = raiz;
	NodoABB <T> * padre = NULL;

	if (entrada == NULL){
		padre = entrada;
	}
	while(entrada!=NULL && !esta){

		if(entrada->obtenerClave() == claveBuscada){

			esta=true;
		}else{

			padre  = entrada;

			if( claveBuscada > entrada->obtenerClave()){

				entrada = entrada->obtenerHijoDerecho();
			}else{

				entrada = entrada->obtenerHijoIzquierdo();
			}
		}

	}

	return padre;
}

template <class T>
bool ArbolABB<T>::sinHijos(NodoABB <T> * aEliminar){
	return (aEliminar->obtenerHijoDerecho()==NULL && aEliminar->obtenerHijoIzquierdo()==NULL);
}

template <class T>
bool ArbolABB<T>::conUnHijo(NodoABB <T> * aEliminar){
	bool unicoHijo = false;
	if(aEliminar->obtenerHijoDerecho()==NULL && aEliminar->obtenerHijoIzquierdo()!=NULL){
		unicoHijo=true;
	}else
		if(aEliminar->obtenerHijoDerecho()!=NULL && aEliminar->obtenerHijoIzquierdo()==NULL){
			unicoHijo=true;
		}
	return unicoHijo;
}

template <class T>
NodoABB<T> * obtenerUnicoHijo(NodoABB <T> * hijoABorrar){
	NodoABB<T> * unicoHijo = NULL;
	if(hijoABorrar->obtenerHijoDerecho()!=NULL){
		unicoHijo=hijoABorrar->obtenerHijoDerecho();
	}else{
		unicoHijo=hijoABorrar->obtenerHijoIzquierdo();
	}
	return unicoHijo;
}

template <class T>
void ArbolABB<T>::eliminarDato(T claveEliminar){

		NodoABB <T> * aEliminar = encontrarNodo(claveEliminar,raiz);

		NodoABB <T> * padre = encontrarPadre(claveEliminar, raiz);

		if(sinHijos(aEliminar)){
			eliminarEnCaso1(padre,aEliminar);
		}else
			if(conUnHijo(aEliminar)){
				eliminarEnCaso2(padre,aEliminar);
			}else{
				eliminarEnCaso3(aEliminar);
			}
}

template <class T>
void ArbolABB<T>::eliminarEnCaso1(NodoABB <T> * padre, NodoABB <T> * hijoABorrar){

	if(padre->obtenerHijoDerecho()->obtenerClave() == hijoABorrar->obtenerClave()){
		padre->cambiarHijoDerecho(NULL);
	}else{
		padre->cambiarHijoIzquierdo(NULL);
	}
	delete hijoABorrar;
}

template <class T>
void ArbolABB<T>::eliminarEnCaso2(NodoABB <T> * padre, NodoABB <T> * hijoABorrar){
	if(padre != NULL){
		if(padre->obtenerHijoDerecho()->obtenerClave() == hijoABorrar->obtenerClave()){
			padre->cambiarHijoDerecho(obtenerUnicoHijo(hijoABorrar));
		}else{
			padre->cambiarHijoIzquierdo(obtenerUnicoHijo(hijoABorrar));
		}
	}else{
		raiz = obtenerUnicoHijo(hijoABorrar);
	}
	delete hijoABorrar;
}

template <class T>
void ArbolABB<T>::eliminarEnCaso3( NodoABB <T> * hijoABorrar){

	NodoABB <T> * mayorMenores = obtenerMayorDeMenores(hijoABorrar->obtenerHijoIzquierdo());

	NodoABB <T> * padreMayorMenores = encontrarPadre(mayorMenores->obtenerClave(),raiz);

	hijoABorrar->cambiarClave(mayorMenores->obtenerClave());

	hijoABorrar = mayorMenores;

	if(sinHijos(hijoABorrar)){
		eliminarEnCaso1(padreMayorMenores,hijoABorrar);
	}else{
		eliminarEnCaso2(padreMayorMenores,hijoABorrar);
	}
}

template <class T>
void ArbolABB<T>::inOrden (NodoABB<T> *entrada){

	if (entrada!=NULL){

		inOrden(entrada->obtenerHijoIzquierdo());

		std::cout<<entrada->obtenerClave()<<std::endl;

		inOrden(entrada->obtenerHijoDerecho());
	}
}

template <class T>
void ArbolABB<T>::obtenerArbol(){
	inOrden(raiz);
}

template <class T>
T ArbolABB<T>::preOrden (NodoABB<T> *entrada){

	if (entrada!=NULL){

		return entrada->obtenerClave();
		preorden(entrada->obtenerHijoIzquierdo());
		preorden(entrada->obtenerHijoDerecho());
	}
}

template <class T>
T ArbolABB<T>::postOrden(NodoABB<T> *entrada){

	if (entrada!=NULL){

		postorden(entrada->obtenerHijoIzquierdo());
		postorden(entrada->obtenerHijoDerecho());
		return entrada->obtenerClave();
	}

}

template <class T>
void ArbolABB<T>::arrancarArbol(NodoABB <T> * entrada){
	if (entrada!=NULL){

		arrancarArbol(entrada->obtenerHijoIzquierdo());
		arrancarArbol(entrada->obtenerHijoDerecho());
		delete entrada;
		}
}

template <class T>
ArbolABB<T>::~ArbolABB(){

	arrancarArbol(raiz);
}

#endif /* SRC_ABB_H_ */
