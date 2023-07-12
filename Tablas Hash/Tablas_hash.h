#ifndef TABLAS_HASH_H
#define TABLAS_HASH_H

#include <stdlib.h>
#include <stdbool.h>
#include "../Tipo_elemento.h"



// ---------------- ESTRUCTURAS ----------------



struct TablaHashRep;
/**
 * @brief Puntero a la estructura TablaHashRep.
 * 
 */
typedef struct TablaHashRep *TablaHash;


struct TipoRegistroTablaRep;
/**
 * @brief Puntero a la estructura TipoRegistroTablaRep.
 * 
 */
typedef struct TipoRegistroTablaRep *TipoRegistroTabla;



// ---------------- FUNCIONALIDADES ----------------



/**
 * @brief Crear una tabla hash con un tamaño inicial y una funcion hash especificada.
 * 
 * @param capacidad Tamaño inicial de la tabla.
 * @param hash_function Puntero a una funcion que se utilizara para calcular el hash de las claves.
 * @return TablaHash 
 */
TablaHash th_crear(int capacidad, int (*hash_function)(int));


/**
 * @brief Inserta un elemento en la tabla.
 * 
 * @param th 
 * @param elemento 
 */
void th_insertar(TablaHash th, TipoElemento elemento);


/**
 * @brief Elimina un elemento de la tabla
 * 
 * @param th 
 * @param clave 
 */
void th_eliminar(TablaHash th, int clave);


/**
 * @brief Recupera el elemento con la clave especificada en la tabla.
 * 
 * @param th 
 * @param clave 
 * @return TipoElemento 
 */
TipoElemento th_recuperar(TablaHash th, int clave);


/**
 * @brief Muestra todos los elementos de la tabla, incluyendo espacios vacios.
 * 
 * @param th 
 */
void th_mostrar(TablaHash th);


/**
 * @brief Muestra solo los elementos ocupados en la tabla, omitiendo los espacios vacios.
 * 
 * @param th 
 */
void th_mostrar_solo_ocupados(TablaHash th);



#endif //TABLAS_HASH_H