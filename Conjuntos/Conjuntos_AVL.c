#include <stdio.h>
#include "Conjuntos.h"
#include "../Arboles/Arboles_AVL.h"
#include "../Listas/Listas.h"



// ---------------- ESTRUCTURA ----------------



/**
 * @brief Contiene el arbol AVL con el que operara.
 * 
 */
struct ConjuntoRep{

    ArbolAVL avl;

};



// ---------------- FUNCIONALIDADES ----------------



Conjunto cto_crear(){

    //Inicializa el conjunto asignando el espacio en memoria.
    Conjunto nuevo_cto = (Conjunto)malloc(sizeof(struct ConjuntoRep));

    //Inicializa el arbol como vacio.
    nuevo_cto->avl = avl_crear();

    return nuevo_cto;

}


bool cto_es_vacio(Conjunto conjunto){

    return avl_es_vacio(conjunto->avl);

}


bool cto_es_lleno(Conjunto conjunto){

    return avl_es_lleno(conjunto->avl);

}


int cto_cantidad_elementos(Conjunto conjunto){

    return avl_cantidad_elementos(conjunto->avl);

}


void cto_agregar(Conjunto conjunto, TipoElemento elemento){

    avl_insertar(conjunto->avl, elemento);

}


void cto_borrar(Conjunto conjunto, int clave){

    avl_eliminar(conjunto->avl, clave);

}


bool cto_pertenece(Conjunto conjunto, int clave){

    return (avl_buscar(conjunto->avl, clave) != NULL);

}


/**
 * @brief Funcion interna para realizar union con el conjunto A.
 * 
 * @param nodo 
 * @param rta 
 */
void unioninta(NodoArbol nodo, Conjunto rta){

    //Mientras la rama del subarbol no sea nula (caso de corte) agrega los elementos en In-Orden.
    if(!avl_rama_nula(nodo)){

        unioninta(n_hijoizquierdo(nodo), rta);
        cto_agregar(rta, n_recuperar(nodo));
        unioninta(n_hijoderecho(nodo), rta);
    }

}


/**
 * @brief Funcion interna para realizar union con el conjunto B.
 * 
 * @param nodo 
 * @param rta 
 */
void unionintb(NodoArbol nodo, Conjunto rta){

    //Mientras la rama del subarbol no sea nula (caso de corte) agrega los elementos en In-Orden.
    if(!avl_rama_nula(nodo)){

        unionintb(n_hijoizquierdo(nodo), rta);
        
        //Si el elemento no esta en el conjunto lo agrega.
        if(!cto_pertenece(rta, n_recuperar(nodo)->clave)){

            cto_agregar(rta, n_recuperar(nodo));
        
        }
        
        unionintb(n_hijoderecho(nodo), rta);
    }

}


Conjunto cto_union(Conjunto conjuntoA, Conjunto conjuntoB){

    Conjunto resultado = cto_crear();

    //Llama a las dos funciones internas para realizar la union.
    unioninta(avl_raiz(conjuntoA->avl), resultado);
    unionintb(avl_raiz(conjuntoB->avl), resultado);

    return resultado;
}


/**
 * @brief Rutina interna encargada de realizar la interseccion de A con B.
 * 
 * @param nodo 
 * @param B 
 * @param rta 
 */
void interseccionInt(NodoArbol nodo, Conjunto B, Conjunto rta){

    //Mientras la rama del subarbol no sea nula (caso de corte) recorre el arbol.
    if(!avl_rama_nula(nodo)){

        //Si el elemento pertenece al conjunto B, lo agrega.
        if(cto_pertenece(B, n_recuperar(nodo)->clave)){

            cto_agregar(rta, n_recuperar(nodo));
        }

        interseccionInt(n_hijoizquierdo(nodo), B, rta);
        interseccionInt(n_hijoderecho(nodo), B, rta);
    }

}


Conjunto cto_interseccion(Conjunto conjuntoA, Conjunto conjuntoB){

    Conjunto resultado = cto_crear();

    //Llama a la rutina que se encarga de realizar la interseccion.
    interseccionInt(avl_raiz(conjuntoA->avl), conjuntoB, resultado);

    return resultado;

}


/**
 * @brief Rutina interna encargada de realizar la union de A con B.
 * 
 * @param nodo 
 * @param B 
 * @param rta 
 */
void diferenciaInt(NodoArbol nodo, Conjunto B, Conjunto rta){

    if(!avl_rama_nula(nodo)){

        if(!cto_pertenece(B, n_recuperar(nodo)->clave)){

            cto_agregar(rta, n_recuperar(nodo));
        }

        diferenciaInt(n_hijoizquierdo(nodo), B, rta);
        diferenciaInt(n_hijoderecho(nodo), B, rta);
    }

}


Conjunto cto_diferencia(Conjunto conjuntoA, Conjunto conjuntoB){

    Conjunto resultado = cto_crear();

    //Llama a la rutina encargada de realizar la diferencia.
    diferenciaInt(avl_raiz(conjuntoA->avl), conjuntoB, resultado);

    return resultado;

}


/**
 * @brief Rutina interna para transferir elementos del arbol a una lista en recorrido In-Orden.
 * 
 * @param nodo 
 * @param L 
 */
void recuperarInt(NodoArbol nodo, Lista L){

    if(!avl_rama_nula(nodo)){

        recuperarInt(n_hijoizquierdo(nodo), L);
        l_agregar(L, n_recuperar(nodo));
        recuperarInt(n_hijoderecho(nodo), L);
    }

}


TipoElemento cto_recuperar(Conjunto conjunto, int posicion){

    if(cto_cantidad_elementos(conjunto) < posicion){

        return NULL;
    }

    //Agrega elementos del arbol a una lista en In-Orden en una rutina aparte para determinar la posicion.
    Lista L = l_crear();

    recuperarInt(avl_raiz(conjunto->avl), L);

    return l_recuperar(L, posicion);

}


/**
 * @brief Rutina interna que muestra los elementos del arbol en In-Orden.
 * 
 * @param nodo 
 */
void InOrden(NodoArbol nodo){

    if(!avl_rama_nula(nodo)){

        InOrden(n_hijoizquierdo(nodo));
        printf("%d ", n_recuperar(nodo)->clave);
        InOrden(n_hijoderecho(nodo));
    }

}


void cto_mostrar(Conjunto conjunto){

    if(cto_es_vacio(conjunto)){

        printf("\nConjunto vacio!\n");
        return;
    }
    printf("\nContenido: ");

    //Llama a una rutina interna que muestra el contenido In-Orden.
    InOrden(avl_raiz(conjunto->avl));
    printf("\n");
    return;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////