#ifndef ARBOLES_BINARIOS_H
#define ARBOLES_BINARIOS_H

#include <stdlib.h>
#include <stdbool.h>
#include "../Nodo.h"



// ---------------- ESTRUCTURA ----------------



struct ArbolBinarioRep;
/**
 * @brief Puntero a la estructura ArbolBinarioRep.
 * 
 */
typedef struct ArbolBinarioRep *ArbolBinario;



// ---------------- FUNCIONALIDADES ----------------



/**
 * @brief Crea el arbol vacio asignando el espacio en memoria.
 * 
 * @return ArbolBinario 
 */
ArbolBinario a_crear();


/**
 * @brief Recibe un arbol y verifica si esta vacio (true), caso contrario retorna false.
 * 
 * @param arbol 
 * @return true 
 * @return false 
 */
bool a_es_vacio(ArbolBinario arbol);


/**
 * @brief Recibe un arbol y verifica si esta lleno (true), caso contrario retorna false.
 * 
 * @param arbol 
 * @return true 
 * @return false 
 */
bool a_es_lleno(ArbolBinario arbol);


/**
 * @brief Recibe un arbol y retorna la cantidad de nodos que contiene.
 * 
 * @param arbol 
 */
int a_cantidad_elementos(ArbolBinario arbol);


/**
 * @brief Recibe un nodo del arbol (subarbol) y verifica si dicha rama es nula (true), caso contrario retorna false. 
 * 
 * @param nodo 
 * @return true 
 * @return false 
 */
bool a_rama_nula(NodoArbol nodo);


/**
 * @brief Recibe un arbol y retorna el nodo raiz.
 * 
 * @param arbol 
 * @return NodoArbol 
 */
NodoArbol a_raiz(ArbolBinario arbol);


/**
 * @brief Crea un nuevo nodo con el elemento, lo establece en la raiz del arbol y lo retorna. Incrementa la cantidad de elementos del arbol. 
 * 
 * @param arbol 
 * @param elemento 
 * @return NodoArbol 
 */
NodoArbol a_establecer_raiz(ArbolBinario arbol, TipoElemento elemento);


/**
 * @brief Crea un nuevo nodo con el elemento, lo conecta como hijo izquierdo del nodo padre y lo retorna. Incrementa la cantidad de elementos del arbol.
 * 
 * @param arbol 
 * @param padre 
 * @param elemento 
 * @return NodoArbol 
 */
NodoArbol a_conectar_hi(ArbolBinario arbol, NodoArbol padre, TipoElemento elemento);


/**
 * @brief  Crea un nuevo nodo con el elemento, lo conecta como hijo derecho del nodo padre y lo retorna. Incrementa la cantidad de elementos del arbol.
 * 
 * @param arbol 
 * @param padre 
 * @param elemento 
 * @return NodoArbol 
 */
NodoArbol a_conectar_hd(ArbolBinario arbol, NodoArbol padre, TipoElemento elemento);


/**
 * @brief Verifica que el nodo se encuentra en el arbol y lo elimina. Decrementa la cantidad de elementos del arbol.
 * 
 * @param arbol 
 * @param nodo 
 */
void a_eliminar_nodo(ArbolBinario arbol, NodoArbol nodo);



#endif //ARBOLES_BINARIOS_H