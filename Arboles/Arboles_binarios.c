#include "Arboles_binarios.h"
#include <stdio.h>


//Cantidad maxima de nodos del arbol.
static const int TAM_MAX = 100;



// ---------------- ESTRUCTURA ----------------



/**
 * @brief Contiene el nodo raiz con el que se accede a la estructura del arbol y la cantidad de elementos.
 * 
 */
struct ArbolBinarioRep{

    NodoArbol raiz;
    int cantidad;

};



// ---------------- FUNCIONALIDADES ----------------



/**
 * @brief Funcion recursiva auxiliar para recorrer el arbol en busca del nodo a eliminar.
 * 
 * @param raiz 
 * @param nodo 
 */
void a_eliminar_nodo_recursivo(ArbolBinario arbol, NodoArbol raiz, NodoArbol nodo);



ArbolBinario a_crear(){

    //Inicializa el arbol asignando el espacio en memoria.
    ArbolBinario nuevo_arbol = (ArbolBinario)malloc(sizeof(struct ArbolBinarioRep));

    //Lo establece como arbol vacio.
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad = 0;

    return nuevo_arbol;

}


bool a_es_vacio(ArbolBinario arbol){

    return (arbol->cantidad == 0);

}


bool a_es_lleno(ArbolBinario arbol){

    return (arbol->cantidad == TAM_MAX);

}


int a_cantidad_elementos(ArbolBinario arbol){

    return arbol->cantidad;

}


bool a_rama_nula(NodoArbol nodo){

    return (nodo == NULL);

}


NodoArbol a_raiz(ArbolBinario arbol){

    //Verifica si el arbol esta vacio.
    if(a_es_vacio(arbol)){

        printf("\nError al recuperar la raiz del arbol. El arbol esta vacio.\n");
        return NULL;
    }

    return arbol->raiz;

}


NodoArbol a_establecer_raiz(ArbolBinario arbol, TipoElemento elemento){

    //Verifica si el arbol ya tiene una raiz establecida.
    if(arbol->raiz != NULL){

        printf("\nError al establecer raiz. El arbol ya tiene una raiz establecida.\n");

    }
    else{

        //Crea un nodo con los datos del elemento y lo asigna como raiz.
        NodoArbol nodo = n_crear(elemento);
        arbol->raiz = nodo;
        arbol->cantidad++;

    }

    return arbol->raiz;

}


NodoArbol a_conectar_hi(ArbolBinario arbol, NodoArbol padre, TipoElemento elemento){

    //Verifica si el arbol esta vacio.
    if(a_es_vacio(arbol)){

        printf("\nError al conectar hijo izquierdo. El arbol no tiene raiz.\n");
    }
    //Verifica si el nodo padre es valido.
    else if(padre == NULL){

        printf("\nError al conectar hijo izquierdo. El nodo padre no es valido.\n");
    }
    else{

        //Crea un nuevo nodo con los datos del elemento y lo conecta como hijo izquierdo del nodo padre.
        NodoArbol nodo = n_crear(elemento);
        padre->hi = nodo;
        arbol->cantidad++;

        return padre->hi;

    }

    return NULL;

}


NodoArbol a_conectar_hd(ArbolBinario arbol, NodoArbol padre, TipoElemento elemento){

    //Verifica si el arbol esta vacio.
    if(a_es_vacio(arbol)){

        printf("\nError al conectar hijo derecho. El arbol no tiene raiz.\n");
    }
    //Verifica si el nodo padre es valido.
    else if(padre == NULL){

        printf("\nError al conectar hijo derecho. El nodo padre no es valido.\n");
    }
    else{

        //Crea un nuevo nodo con los datos del elemento y lo conecta como hijo derecho del nodo padre.
        NodoArbol nodo = n_crear(elemento);
        padre->hd = nodo;
        arbol->cantidad++;

        return padre->hd;

    }

    return NULL;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////