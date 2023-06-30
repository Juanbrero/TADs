#ifndef ARBOLES_BINARIOS_BUSQUEDA_H
#define ARBOLES_BINARIOS_BUSQUEDA_H

#include "../Nodo.h"
#include "../Tipo_elemento.h"
#include <stdlib.h>
#include <stdbool.h>



// ---------------- ESTRUCTURA ----------------



struct ArbolBinarioBusquedaRep;
/**
 * @brief Puntero a la estructura ArbolBinarioBusquedaRep.
 * 
 */
typedef struct ArbolBinarioBusquedaRep *ArbolBinarioBusqueda;



// ---------------- FUNCIONALIDADES ----------------



/**
 * @brief Crear un arbol binario de busqueda como vacio y lo retorna.
 * 
 * @return ArbolBinarioBusqueda 
 */
ArbolBinarioBusqueda abb_crear();


/**
 * @brief Verifica si el arbol esta vacio (true), de lo contrario retorna false.
 * 
 * @param arbolBB 
 * @return true 
 * @return false 
 */
bool abb_es_vacio(ArbolBinarioBusqueda arbolBB);


/**
 * @brief Verifica si el arbol esta lleno (true), de lo contrario retorna false.
 * 
 * @param arbolBB 
 * @return true 
 * @return false 
 */
bool abb_es_lleno(ArbolBinarioBusqueda arbolBB);


/**
 * @brief Retorna la cantidad de elementos del arbol.
 * 
 * @param arbolBB 
 * @return int 
 */
int abb_cantidad_elementos(ArbolBinarioBusqueda arbolBB);


/**
 * @brief Verifica si la rama del subarbol es nula.
 * 
 * @param subArbol 
 * @return true 
 * @return false 
 */
bool abb_rama_nula(NodoArbol subArbol);


/**
 * @brief Retorna el nodo raiz del arbol pasado por parametro.
 * 
 * @param arbolBB 
 * @return NodoArbol 
 */
NodoArbol abb_raiz(ArbolBinarioBusqueda arbolBB);


/**
 * @brief Crea un NodoArbol con el elemento y lo inserta segun el criterio de orden. Debe verificar que el arbol no este lleno y que el elemento no sea repetido.
 * 
 * @param arbolBB 
 * @param elemento 
 */
void abb_insertar(ArbolBinarioBusqueda arbolBB, TipoElemento elemento);


/**
 * @brief Elimina el nodo que coincide con la clave pasada por parametro. Debe verificar que el arbol no esta vacio y que el nodo se encuentra en el arbol.
 * 
 * @param arbolBB 
 * @param clave 
 */
void abb_eliminar(ArbolBinarioBusqueda arbolBB, int clave);


/**
 * @brief Busca un elemento en el arbol y lo retorna, en caso de no hallarlo retorna NULL.
 * 
 * @param arbolBB 
 * @param clave 
 * @return TipoElemento 
 */
TipoElemento abb_buscar(ArbolBinarioBusqueda arbolBB, int clave);



#endif //ARBOLES_BINARIOS_BUSQUEDA_H