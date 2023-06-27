#include "Pilas.h"
#include <stdio.h>


//Cantidad maxima de elementos de la pila
static const int TAM_MAX = 100;



// ---------------- ESTRUCTURA ----------------



/**
 * @brief Contiene los datos de TipoElemento y el nodo siguiente enlazado.
 * 
 */
struct NodoRep{

    TipoElemento datos;
    Nodo siguiente;

};


/**
 * @brief Contiene el nodo tope de pila.
 * 
 */
struct PilaRep{

    Nodo tope;

};



// ---------------- FUNCIONALIDADES ----------------



Pila p_crear(){

    //Inicializa la pila asignando el espacio en memoria.
    Pila nueva_pila = (Pila)malloc(sizeof(struct PilaRep));

    nueva_pila->tope = NULL;

    return nueva_pila;

}


bool p_es_vacia(Pila pila){

    return (pila->tope == NULL);

}


bool p_es_llena(Pila pila){

    //Crea una variable contador y un nodo auxiliar asignandole el tope de la pila.
    int i = 0;
    Nodo nodoAux = pila->tope;

    //Avanza el nodo hasta llegar a la base de la pila contando la cantidad de elementos.
    while(nodoAux != NULL){

        nodoAux = nodoAux->siguiente;
        i++;
    }

    //Verifica si el contador de nodos es igual a la cantidad maxima de la pila.
    return (i == TAM_MAX);

}


void p_mostrar(Pila pila){

    //Verifica si la pila esta vacia.
    if(p_es_vacia(pila)){

        printf("\nError al mostrar. La pila esta vacia.\n");
        return;
    }

    printf("\nContenido:  ");

    TipoElemento teAux;
    Pila PilaAux = p_crear();

    //Recorre la pila desapilando el elemento del tope y apilandolo en una pila auxiliar para no perderlo.
    while(!p_es_vacia(pila)){

        teAux = p_desapilar(pila);
        p_apilar(PilaAux, teAux);

        printf("%d ", teAux->clave);

    }

    printf("\n");

    //Reconstruye la pila original.
    while(!p_es_vacia(PilaAux)){

        teAux = p_desapilar(PilaAux);
        p_apilar(pila, teAux);

    }

    //Libera el espacio en memoria de la pila auxiliar.
    free(PilaAux);

}


void p_apilar(Pila pila, TipoElemento elemento){

    //Verifica si la pila esta llena.
    if(p_es_llena(pila)){

        printf("\nError al apilar elemento. La pila esta llena.\n");
        return;
    }

    //Crea un nuevo nodo asignando el espacio en memoria.
    Nodo nuevo_nodo = (Nodo)malloc(sizeof(struct NodoRep));
    //Cargar el nodo con los datos del elemento y lo enlaza al tope de la pila.
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = pila->tope;
    //Desplaza el tope de la pila al nuevo nodo.
    pila->tope = nuevo_nodo;

}


TipoElemento p_desapilar(Pila pila){

    //Verifica si la pila esta vacia.
    if(p_es_vacia(pila)){

        printf("\nError al desapilar elemento. La pila esta vacia.\n");
        return NULL;
    }

    //Salva el tope actual de la pila.
    Nodo nodoActual = pila->tope;
    TipoElemento te = nodoActual->datos;
    //Desplaza el tope hacia el siguiente elemento.
    pila->tope = nodoActual->siguiente;
    //Libera el espacio en memoria del nodo desapilado.
    free(nodoActual);

    return te;

}


TipoElemento p_tope(Pila pila){

    //Verifica si la pila esta vacia.
    if(p_es_vacia(pila)){

        printf("\nError al recuperar elemento. La pila esta vacia.\n");
        return NULL;
    }

    //Recupera el nodo del tope de la pila sin desapilarlo.
    Nodo topeActual = pila->tope;

    return topeActual->datos;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////