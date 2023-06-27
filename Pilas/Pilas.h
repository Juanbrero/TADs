#ifndef PILAS_H
#define PILAS_H

#include <stdlib.h>
#include <stdbool.h>
#include "../Tipo_elemento.h"



// ---------------- ESTRUCTURA ----------------



struct PilaRep;
/**
 * @brief Puntero a la estructura PilaRep.
 * 
 */
typedef struct PilaRep *Pila;


struct NodoRep;
/**
 * @brief Puntero a la estructura NodoRep.
 * 
 */
typedef struct NodoRep *Nodo;



// ---------------- FUNCIONALIDADES ----------------


/**
 * @brief Crea una pila vacia y la retorna.
 * 
 * @return Pila 
 */
Pila p_crear();


/**
 * @brief Recibe una pila y verifica si es vacia (true), caso contrario retorna false.
 * 
 * @param pila 
 * @return true 
 * @return false 
 */
bool p_es_vacia(Pila pila);


/**
 * @brief Recibe una pila y verifica si esta llena (true), caso contrario retorna false.
 * 
 * @param pila 
 * @return true 
 * @return false 
 */
bool p_es_llena(Pila pila);


/**
 * @brief Recibe una pila y la imprime en pantalla sin perderla.
 * 
 * @param pila 
 */
void p_mostrar(Pila pila);


/**
 * @brief Recibe una pila y un elemento a apilar. Verifica si la pila esta llena.
 * 
 * @param pila 
 * @param elemento 
 */
void p_apilar(Pila pila, TipoElemento elemento);


/**
 * @brief Recibe una pila y retorna el elemento del tope (lo desapila).
 * 
 * @param pila 
 * @return TipoElemento 
 */
TipoElemento p_desapilar(Pila pila);


/**
 * @brief Recibe una pila y recupera el elemento del tope sin desapilarlo.
 * 
 * @param pila 
 * @return TipoElemento 
 */
TipoElemento p_tope(Pila pila);



#endif //PILAS_H