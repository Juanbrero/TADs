#include <stdio.h>
#include "Colas.h"


//Cantidad maxima de elementos de la cola.
static const int TAM_MAX = 100;



// ---------------- ESTRUCTURAS ----------------



/**
 * @brief Contiene un nodo apuntando al frente de la cola y otro apuntando al final.
 * 
 */
struct ColaRep{

    Nodo frente;
    Nodo final;

};


/**
 * @brief Contiene un TipoElemento con los datos y un nodo apuntando al siguiente elemento enlazado.
 * 
 */
struct NodoRep{

    TipoElemento datos;
    Nodo siguiente;

};



// ---------------- FUNCIONALIDADES ----------------



Cola c_crear(){

    //Inicializa la cola asignando el espacio en memoria.
    Cola nueva_cola = (Cola)malloc(sizeof(struct ColaRep));

    //Apunta el frente y final de la cola a NULL.
    nueva_cola->frente = NULL;
    nueva_cola->final = NULL;

    return nueva_cola;

}


bool c_es_vacia(Cola cola){

    return (cola->frente == NULL);

}


bool c_es_llena(Cola cola){

    Nodo actual = cola->frente;
    int i = 0;

    //Recorre los elemento de la cola incrementando el contador.
    while(actual != NULL){
        
        i++;
        actual = actual->siguiente;
    }

    //Verifica si el contador de elementos es igual a la cantidad maxima.
    return (i == TAM_MAX);

}


void c_mostrar(Cola cola){

    //Verifica si la cola esta vacia.
    if(c_es_vacia(cola)){

        printf("\nError al mostrar. La cola esta vacia.\n");
        return;
    }

    Cola colaAux = c_crear();
    TipoElemento actual;

    printf("\nContenido:  ");

    //Desencola los elemento y los guarda en una cola auxiliar para no perderlos.
    while(!c_es_vacia(cola)){

        actual = c_desencolar(cola);
        c_encolar(colaAux, actual);

        printf("%d ", actual->clave);
    }

    printf("\n");

    //Reconstruye la cola original.
    while(!c_es_vacia(colaAux)){

        actual = c_desencolar(colaAux);
        c_encolar(cola, actual);
    }

    //Libera el espacio en memoria de la cola auxiliar.
    free(colaAux);

}


void c_encolar(Cola cola, TipoElemento elemento){

    //Verifica si la cola esta llena.
    if(c_es_llena(cola)){

        printf("\nError al encolar elemento. La cola esta llena.\n");
        return;
    }

    //Crea un nuevo nodo asignando el espacio en memoria y lo carga con los datos del elemento.
    Nodo nuevo_nodo = (Nodo)malloc(sizeof(struct NodoRep));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;

    //Verifica si se encola al frente o en el resto de la cola.
    if(c_es_vacia(cola)){

        cola->frente = nuevo_nodo;
        cola->final = nuevo_nodo;
        
    }
    else{

        cola->final->siguiente = nuevo_nodo;
        cola->final = nuevo_nodo;
        
    }

}


TipoElemento c_desencolar(Cola cola){

    //Verifica si la cola esta vacia.
    if(c_es_vacia(cola)){

        printf("\nError al desencolar elemento. La cola esta vacia.\n");
        return NULL;
    }

    //Recupera el frente de la cola.
    Nodo actual = cola->frente;
    TipoElemento elemento = cola->frente->datos;
    //Desplaza el frente al siguiente elemento.
    cola->frente = cola->frente->siguiente;
    //Libera el espacio en memoria del nodo desencolado.
    free(actual);

    return elemento;

}


TipoElemento c_recuperar(Cola cola){

    if(c_es_vacia(cola)){

        printf("\nError al recuperar elemento. La cola esta vacia.\n");
        return NULL;
    }

    Nodo frente = cola->frente;

    return frente->datos;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////