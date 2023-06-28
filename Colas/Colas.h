#ifndef COLAS_H
#define COLAS_H

#include <stdlib.h>
#include <stdbool.h>
#include "../Tipo_elemento.h"



// ---------------- ESTRUCTURAS ----------------



struct ColaRep;
/**
 * @brief Puntero a la estructura ColaRep.
 * 
 */
typedef struct ColaRep *Cola;


struct NodoRep;
/**
 * @brief Puntero a la estructura NodoRep.
 * 
 */
typedef struct NodoRep *Nodo;



// ---------------- FUNCIONALIDADES ----------------



/**
 * @brief Crea una cola vacia y la retorna.
 * 
 * @return Cola 
 */
Cola c_crear();


/**
 * @brief Recibe una cola y verifica si es vacia (true) o no.
 * 
 * @param cola 
 * @return true 
 * @return false 
 */
bool c_es_vacia(Cola cola);


/**
 * @brief Recibe una cola y verifica si esta llena (true) o no.
 * 
 * @param cola 
 * @return true 
 * @return false 
 */
bool c_es_llena(Cola cola);


/**
 * @brief Recibe una cola y muestra su contenido sin perderla.
 * 
 * @param cola 
 */
void c_mostrar(Cola cola);


/**
 * @brief Recibe una cola y el dato a encolar. Verifica si la cola no esta llena y lo agrega al final.
 * 
 * @param cola 
 * @param elemento 
 */
void c_encolar(Cola cola, TipoElemento elemento);


/**
 * @brief Recibe una cola y verifica que no este vacia, luego desencola el elemento del frente y lo retorna.
 * 
 * @param cola 
 * @return TipoElemento 
 */
TipoElemento c_desencolar(Cola cola);


/**
 * @brief Recibe una cola y retorna el elemento del frente sin desencolarlo.
 * 
 * @param cola 
 * @return TipoElemento 
 */
TipoElemento c_recuperar(Cola cola);



#endif // COLAS_H