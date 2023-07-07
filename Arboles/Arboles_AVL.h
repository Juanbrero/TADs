#ifndef ARBOLES_AVL_H
#define ARBOLE_AVL_H

#include "../Nodo.h"
#include "../Tipo_elemento.h"
#include <stdlib.h>
#include <stdbool.h>



// ---------------- ESTRUCTURA ----------------



struct ArbolAVLRep;
/**
 * @brief Puntero a la estructura ArbolAVLRep.
 * 
 */
typedef struct ArbolAVLRep *ArbolAVL;



// ---------------- FUNCIONALIDADES ----------------



// FUNCIONES INTERNAS PROPIAS DEL BALANCEO


/**
 * @brief Realiza una rotacion hacia la derecha.
 * 
 * @param nodo 
 * @return NodoArbol 
 */
NodoArbol avl_rotar_derecha(NodoArbol nodo);


/**
 * @brief Realiza una rotacion hacia la izquierda.
 * 
 * @param nodo 
 * @return NodoArbol 
 */
NodoArbol avl_rotar_izquierda(NodoArbol nodo);


/**
 * @brief Retorna la altura del subarbol izquierdo.
 * 
 * @param nodo 
 * @return int 
 */
int avl_altura_izq(NodoArbol nodo);


/**
 * @brief Retorna la altura del subarbol derecho.
 * 
 * @param nodo 
 * @return int 
 */
int avl_altura_der(NodoArbol nodo);


/**
 * @brief Retorna la altura mayor.
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int avl_max(int a, int b);


/**
 * @brief Calcula la condicion de balanceo del nodo.
 * 
 * @param nodo 
 * @return enum Balanceo 
 */
enum Balanceo avl_calcular_balanceo(NodoArbol nodo);


// --------------------------------------------------------------------------------------------------------------------


/**
 * @brief Crea un arbol AVL como vacio y lo retorna.
 * 
 * @return ArbolAVL 
 */
ArbolAVL avl_crear();


/**
 * @brief Verifica si el arbol es vacio (true), caso contrario retorna false.
 * 
 * @param avl 
 * @return true 
 * @return false 
 */
bool avl_es_vacio(ArbolAVL avl);


/**
 * @brief Verifica si el arbol esta lleno (true), caso contrario retorna false.
 * 
 * @param avl 
 * @return true 
 * @return false 
 */
bool avl_es_lleno(ArbolAVL avl);


/**
 * @brief Verifica si el subarbol es nulo (true), caso contrario retorna false.
 * 
 * @param subArbol 
 * @return true 
 * @return false 
 */
bool avl_rama_nula(NodoArbol subArbol);


/**
 * @brief Retorna la cantidad de nodos del arbol.
 * 
 * @param avl 
 * @return int 
 */
int avl_cantidad_elementos(ArbolAVL avl);


/**
 * @brief Retorna el nodo raiz del arbol.
 * 
 * @param avl 
 * @return NodoArbol 
 */
NodoArbol avl_raiz(ArbolAVL avl);


/**
 * @brief Crea un nuevo nodo con los datos del elemento y lo inserta. Verifica si el arbol esta lleno, condicion de balanceo y claves repetidas.
 * 
 * @param avl 
 * @param elemento 
 */
void avl_insertar(ArbolAVL avl, TipoElemento elemento);


/**
 * @brief Elimina el nodo que coincide con la clave. Verifica que el arbol no este vacio, que la clave se encuentre en el arbol y la condicion de balanceo.
 * 
 * @param avl 
 * @param clave 
 */
void avl_eliminar(ArbolAVL avl, int clave);


/**
 * @brief Busca el elemento y lo retorna, si no se encuentra retorna NULL. Verifica que el arbol no este vacio.
 * 
 * @param avl 
 * @param clave 
 * @return TipoElemento 
 */
TipoElemento avl_buscar(ArbolAVL avl, int clave);



#endif //ARBOLES_AVL_H