#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include <stdlib.h>
#include <stdbool.h>
#include "../Tipo_elemento.h"



// ---------------- ESTRUCTURA ----------------



struct ConjuntoRep;
/**
 * @brief Puntero a la estructura ConjuntoRep.
 * 
 */
typedef struct ConjuntoRep *Conjunto;



// ---------------- FUNCIONALIDADES ----------------



/**
 * @brief Crea un conjunto vacio y lo retorna.
 * 
 * @return Conjunto 
 */
Conjunto cto_crear();


/**
 * @brief Indica si el conjunto esta vacio.
 * 
 * @param conjunto 
 * @return true 
 * @return false 
 */
bool cto_es_vacio(Conjunto conjunto);


/**
 * @brief Indica si el conjunto esta lleno.
 * 
 * @param conjunto 
 * @return true 
 * @return false 
 */
bool cto_es_lleno(Conjunto conjunto);


/**
 * @brief Retorna la cantidad de elementos del conjunto.
 * 
 * @param conjunto 
 * @return int 
 */
int cto_cantidad_elementos(Conjunto conjunto);


/**
 * @brief Agrega un elemento al conjunto. Verifica que el elemento no este repetido.
 * 
 * @param conjunto 
 * @param elemento 
 */
void cto_agregar(Conjunto conjunto, TipoElemento elemento);


/**
 * @brief Borra un elemento del conjunto. Verifica que no este vacio.
 * 
 * @param conjunto 
 * @param clave 
 */
void cto_borrar(Conjunto conjunto, int clave);


/**
 * @brief Busca una clave en el conjunto, retorna true si la encuentra.
 * 
 * @param conjunto 
 * @param clave 
 * @return true 
 * @return false 
 */
bool cto_pertenece(Conjunto conjunto, int clave);


/**
 * @brief Retorna el conjunto union entre A y B.
 * 
 * @param conjuntoA 
 * @param conjuntoB 
 * @return Conjunto 
 */
Conjunto cto_union(Conjunto conjuntoA, Conjunto conjuntoB);


/**
 * @brief Retorna el conjunto interseccion entre A y B.
 * 
 * @param conjuntoA 
 * @param conjuntoB 
 * @return Conjunto 
 */
Conjunto cto_interseccion(Conjunto conjuntoA, Conjunto conjuntoB);


/**
 * @brief Retorna el conjunto diferencia entre A y B.
 * 
 * @param conjuntoA 
 * @param conjuntoB 
 * @return Conjunto 
 */
Conjunto cto_diferencia(Conjunto conjuntoA, Conjunto conjuntoB);


/**
 * @brief Recupera el elemento de una posicion ordinal.
 * 
 * @param conjunto 
 * @param posicion 
 * @return TipoElemento 
 */
TipoElemento cto_recuperar(Conjunto conjunto, int posicion);


/**
 * @brief Muestra las claves de los elementos del conjunto.
 * 
 * @param conjunto 
 */
void cto_mostrar(Conjunto conjunto);



#endif //CONJUNTOS_H