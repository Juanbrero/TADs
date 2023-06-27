#include "Pilas.h"
#include <stdio.h>


//Cantidad maxima de elementos de la pila.
static const int TAM_MAX = 100;



// ---------------- ESTRUCTURA ----------------



/**
 * @brief Contiene el array de TipoElemento con los datos apilados y un indicador al tope de la pila.
 * 
 */
struct PilaRep{

    TipoElemento *datos;
    unsigned int tope;

};



// ---------------- FUNCIONALIDADES ----------------



Pila p_crear(){

    //Inicializa la pila asignando el espacio en memoria.
    Pila nueva_pila = (Pila)malloc(sizeof(struct PilaRep));

    //Inicializa el array de TipoElemento en 0 y posiciona el tope de la pila al inicio.
    nueva_pila->datos = calloc(TAM_MAX + 1, sizeof(TipoElemento));
    nueva_pila->tope = 0;

    return nueva_pila;

}


bool p_es_vacia(Pila pila){

    return (pila->tope <= 0);

}


bool p_es_llena(Pila pila){

    return (pila->tope == TAM_MAX);

}


void p_mostrar(Pila pila){

    //Verifica si la pila esta vacia.
    if(p_es_vacia(pila)){

        printf("\nError al mostrar. La pila esta vacia.\n");
        return;
    }

    Pila PilaAux = p_crear();
    TipoElemento teAux;

    printf("\nContenido:  ");

    while(!p_es_vacia(pila)){

        //Desapila el elemento del tope y lo apila en una pila auxiliar para no perderlo.
        teAux = p_desapilar(pila);
        p_apilar(PilaAux, teAux);

        printf("%d ", teAux->clave);    
    }

    printf("\n");

    //Reconstruye la pila original.
    while (!p_es_vacia(PilaAux)){

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

    //Desplaza el tope de la pila una posicion y apila el elemento en el tope.
    pila->tope++;
    pila->datos[pila->tope] = elemento;

}


TipoElemento p_desapilar(Pila pila){

    //Verifica si la pila esta vacia.
    if(p_es_vacia(pila)){

        printf("\nError al desapilar elemento. La pila esta vacia.\n");
        return NULL;
    }

    //Recupera el elemento del tope de la pila.
    TipoElemento te = pila->datos[pila->tope];
    //Desplaza el tope de la pila al siguiente elemento.
    pila->tope--;

    return te;

}


TipoElemento p_tope(Pila pila){

    //Verifica si la pila esta vacia.
    if(p_es_vacia(pila)){

        printf("\nError al recuperar elemento. La pila esta vacia.\n");
        return NULL;
    }

    //Retorna el elemento del tope sin desapilarlo.
    return pila->datos[pila->tope];

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////