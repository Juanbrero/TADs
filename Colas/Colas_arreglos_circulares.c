#include <stdio.h>
#include "Colas.h"


//Cantidad maxima de elementos de la cola.
static const int TAM_MAX = 101;



// ---------------- ESTRUCTURA ----------------



struct ColaRep{

    TipoElemento *array;
    unsigned int frente;
    unsigned int final;

};



// ---------------- FUNCIONALIDADES ----------------



// -----------------------------------------------------------------------------------------------------


/**
 * @brief Funcion interna que desplaza el frente y el final a la siguiente posicion. Retorna la siguiente posicion.
 * 
 * @param posicion 
 * @return int 
 */
int paso(int posicion){

    return ((posicion % TAM_MAX) + 1);

}


// -----------------------------------------------------------------------------------------------------


Cola c_crear(){

    //Inicializa la cola como vacia asignando el espacio en memoria.
    Cola nueva_cola = (Cola)malloc(sizeof(struct ColaRep));

    //Inicializa el array de elementos en 0 por defecto. Inica 1 elemento extra por la condicion que produce la ranura.
    nueva_cola->array = calloc((TAM_MAX + 1), sizeof(TipoElemento));

    //La lista esta vacia si al hacer un paso con el final llego al frente (paso((TAM_MAXIMO) + 1) retorna 1.).
    nueva_cola->frente = 1;
    nueva_cola->final = TAM_MAX;

    return nueva_cola;

}


bool c_es_vacia(Cola cola){

    //Verifica si la siguiente posicion al final es el frente de la cola.
    return (paso(cola->final) == cola->frente);

}


bool c_es_llena(Cola cola){

    /*Si la cola esta llena, paso(cola->final) se posiciona en la ranura generada por la condicion de paso entre el final y el frente.
    Por lo que realiza un nuevo paso para verificar si llega al frente, en dicho caso la cola estara llena y retornara true.*/
    return (paso(paso(cola->final)) == cola->frente);

}


void c_mostrar(Cola cola){

    //Verifica si la cola esta vacia.
    if(c_es_vacia(cola)){

        printf("\nError al mostrar. La cola esta vacia.\n");
        return;
    }

    TipoElemento actual;
    Cola colaAux = c_crear();

    printf("\nContenido:  ");

    //Recorre la cola desencolando el frente para mostrarlo y lo encola en una cola auxiliar para no perderlo.
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

    //Realiza un paso con el final para desplazarlo a la siguiente posicion y encola al final el nuevo elemento.
    cola->final = paso(cola->final);
    cola->array[cola->final] = elemento;

}


TipoElemento c_desencolar(Cola cola){

    //Verifica si la cola esta vacia.
    if(c_es_vacia(cola)){

        printf("\nError al desencolar elemento. La cola esta vacia.\n");
        return NULL;
    }

    //Salva el elemento del frente de la cola.
    TipoElemento frente = cola->array[cola->frente];

    //Desplaza el frente de la cola al siguiente elemento.
    cola->frente = paso(cola->frente);

    return frente;

}


TipoElemento c_recuperar(Cola cola){

    //Verifica si la cola esta vacia.
    if(c_es_vacia(cola)){

        printf("\nError al recuperar elemento. La cola esta vacia.\n");
        return NULL;
    }

    //Retorna el elemento del frente de la cola sin desencolarlo.
    return cola->array[cola->frente];

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////