#ifndef LISTAS_H
#define LISTAS_H

#include <stdlib.h>
#include <stdbool.h>
#include "../Tipo_elemento.h"



// ---------------- ESTRUCTURAS ----------------



struct NodoRep;
/**
 * @brief Puntero a la estructura NodoRep.
 * 
 */
typedef struct NodoRep *Nodo;


struct ListaRep;
/**
 * @brief Puntero a la estructura ListaRep.
 * 
 */
typedef struct ListaRep *Lista;


struct IteradorRep;
/**
 * @brief Puntero a la estructura IteradorRep.
 * 
 */
typedef struct IteradorRep *Iterador;



// ---------------- FUNCIONALIDADES ----------------



/**
 * @brief Crea un nueva lista y la devuelve vacia.
 * 
 * @return Lista 
 */
Lista l_crear();


/**
 * @brief Recibe una lista por parametro y verifica si es vacia.
 * 
 * @param lista 
 * @return true 
 * @return false
 */
bool l_es_vacia(Lista lista);


/**
 * @brief Recibe una lista por parametro y verifica si es llena.
 * 
 * @param lista 
 * @return true 
 * @return false 
 */
bool l_es_llena(Lista lista);


/**
 * @brief Recibe una lista por parametro y retorna la cantidad de elementos que contiene (longitud).
 * 
 * @param lista 
 * @return int 
 */
int l_longitud(Lista lista);


/**
 * @brief Recibe una lista por parametro y la muestra en pantalla.
 * 
 * @param lista 
 */
void l_mostrar(Lista lista);


/**
 * @brief Recibe una lista y el elemento a agregar por parametros. Verifica si la lista se encuentra llena.
 * 
 * @param lista 
 * @param elemento 
 * @return TipoElemento 
 */
void l_agregar(Lista lista, TipoElemento elemento);


/**
 * @brief Recibe una lista y la clave a borrar por parametros. Verifica que el elemento se encuentre en la lista.
 * 
 * @param lista 
 * @param clave 
 */
void l_borrar(Lista lista, int clave);


/**
 * @brief Recibe una lista y la clave buscada por parametros. Retorna el TipoElemento o NULL si no se encuentra. 
 * 
 * @param lista 
 * @param clave 
 * @return TipoElemento 
 */
TipoElemento l_buscar(Lista lista, int clave);


/**
 * @brief Recibe una lista, el elemento y la posicion ordinal a insertar. Verifica si la lista se encuentra llena.
 * 
 * @param lista 
 * @param elemento 
 * @param posicion 
 */
void l_insertar(Lista lista, TipoElemento elemento, int posicion);


/**
 * @brief Recibe una lista y la posicion ordinal del elemento a eliminar. Verifica si es una posicion valida.
 * 
 * @param lista 
 * @param posicion 
 */
void l_eliminar(Lista lista, int posicion);


/**
 * @brief Recibe una lista y la posicion ordinal del elemento a recuperar.
 * 
 * @param lista 
 * @param posicion 
 * @return TipoElemento 
 */
TipoElemento l_recuperar(Lista lista, int posicion);



// ---------------- FUNCIONALIDADES DEL ITERADOR ----------------



/**
 * @brief Inicializa el iterador en la lista recibida por parametro.
 * 
 * @param lista 
 * @return Iterador 
 */
Iterador iterador(Lista lista);


/**
 * @brief Recibe un iterador y verifica si la lista contiene un elemento en la posicion siguiente.
 * 
 * @param iterador 
 * @return true 
 * @return false 
 */
bool hay_siguiente(Iterador iterador);


/**
 * @brief Avanzo el iterador hacia la siguiente posicion en la lista.
 * 
 * @param iterador 
 * @return TipoElemento 
 */
TipoElemento siguiente(Iterador iterador);



#endif //LISTAS_H