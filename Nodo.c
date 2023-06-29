#include "Nodo.h"
#include <stdio.h>



// ---------------- FUNCIONALIDADES ----------------



NodoArbol n_crear(TipoElemento elemento){

    //Inicializa el nodo asignando el espacio en memoria.
    NodoArbol nuevo_nodo = (NodoArbol)malloc(sizeof(struct NodoArbolRep));

    //Carga el nodo con los datos del elemento.
    nuevo_nodo->datos = elemento;
    nuevo_nodo->hd = NULL;
    nuevo_nodo->hi = NULL;
    nuevo_nodo->FE = 0;

    return nuevo_nodo;

}


NodoArbol n_hijoizquierdo(NodoArbol nodo){

    //Verifica que el nodo padre sea valido.
    if(nodo == NULL){

        printf("\nError al recuperar hijo izquierdo. El nodo padre es nulo.\n");
        return NULL;
    }
    
    //Si el hijo izquierdo es valido lo retorna, caso contrario retorna NULL.

    return nodo->hi;

}


NodoArbol n_hijoderecho(NodoArbol nodo){

    //Verifica que el nodo padre sea valido.
    if(nodo == NULL){

        printf("\nError al recuperar hijo derecho. El nodo padre es nulo.\n");
        return NULL;
    }

    //Si el hijo derecho es valido lo retorna, caso contrario retorna NULL.
    return nodo->hd;

}


TipoElemento n_recuperar(NodoArbol nodo){

    //Verifica que el nodo sea valido.
    if(nodo == NULL){

        printf("\nError al recuperar elemento. El nodo es nulo.\n");
        return NULL;
    }

    //Retorna el elemento contenido en el nodo.
    return nodo->datos;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////