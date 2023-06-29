#ifndef NODO_H
#define NODO_H

#include <stdlib.h>
#include "Tipo_elemento.h"



// ---------------- ESTRUCTURA ----------------



struct NodoArbolRep;
/**
 * @brief Puntero a la estructura NodoArbolRep.
 * 
 */
typedef struct NodoArbolRep *NodoArbol;


/**
 * @brief Contiene los datos del elemento, punteros a los nodos hijos (izquierdo y derecho), y el factor de equilibrio para el balanceo.
 * 
 */
struct NodoArbolRep{

    TipoElemento datos;
    NodoArbol hi;
    NodoArbol hd;
    int FE;

};



// ---------------- FUNCIONALIDADES ----------------



/**
 * @brief Crea un nodo con el elemento pasado por parametro y lo retorna.
 * 
 * @param elemento 
 * @return NodoArbol 
 */
NodoArbol n_crear(TipoElemento elemento);


/**
 * @brief Recibe un nodo padre y retorna su hijo izquierdo.
 * 
 * @param nodo 
 * @return NodoArbol 
 */
NodoArbol n_hijoizquierdo(NodoArbol nodo);


/**
 * @brief Recibe un nodo padre y retorna su hijo derecho.
 * 
 * @param nodo 
 * @return NodoArbol 
 */
NodoArbol n_hijoderecho(NodoArbol nodo);


/**
 * @brief Recibe un nodo y retorna el elemento que contiene.
 * 
 * @param nodo 
 * @return TipoElemento 
 */
TipoElemento n_recuperar(NodoArbol nodo);



#endif //NODO_H