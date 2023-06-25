#include <stdio.h>
#include "Listas.h"

//Cantidad maxima de elementos de la lista
static const int TAM_MAX = 100;



// ---------------- ESTRUCTURAS ----------------


/**
 * @brief Contiene un array de TipoElemento con los datos y la cantidad de elementos.
 * 
 */
struct ListaRep{

    TipoElemento *array;
    int longitud;

};

/**
 * @brief Contiene la lista sobre la cual itera y el indice en el que se encuentra.
 * 
 */
struct IteradorRep{

    Lista lista;
    int PosActual;

};



// ---------------- FUNCIONALIDADES ----------------



Lista l_crear(){

    //Asigna el espacio en memoria para la lista
    Lista nueva_lista = (Lista)malloc(sizeof(struct ListaRep));

    //Asigna el espacio en memoria del array de elementos y los inicializa en 0 por defecto.
    nueva_lista->array = calloc(TAM_MAX, sizeof(TipoElemento));
    nueva_lista->longitud = 0;

    return nueva_lista;
}


bool l_es_vacia(Lista lista){

    //Si longitud es igual a 0, entonces la lista es vacia y retorna true.
    return (lista->longitud == 0);

}


bool l_es_llena(Lista lista){

    //Si longitud es igual a la cantidad maxima, entonces la lista es llena y retorna true.
    return (lista->longitud == TAM_MAX);

}


int l_longitud(Lista lista){

    return lista->longitud;

}


void l_mostrar(Lista lista){

    printf("\nContenido de lista:  ");

    //Recorre el array hasta el ultimo elemento cargado.
    for(int i = 0; i < lista->longitud; i++){

        printf("%d ", lista->array[i]->clave);

    }
    printf("\n");

}


void l_agregar(Lista lista, TipoElemento elemento){

    //Si la lista tiene espacio disponible, agrega el elemento e incrementa la longitud.
    if(!l_es_llena(lista)){

        lista->array[lista->longitud] = elemento;
        lista->longitud++;

    }
    else{

        printf("\nError al agregar elemento. La lista se encuentra llena.\n\n");
        
    }

}


void l_borrar(Lista lista, int clave){

    //Verifica si la lista es vacia, de ser verdadero, corta el programa.
    if(l_es_vacia(lista)){

        printf("\nNo hay elementos en la lista para borrar.\n");
        return;
    }

    TipoElemento teActual;

    //Recorra el array hasta el ultimo elemento valido.
    for(int i = 0; i < lista->longitud; i++){

        teActual = lista->array[i];

        //Verifica si la clave actual es la clave a borrar.
        if(teActual->clave == clave){

            //Eliminacion logica del elemento corriendo un lugar a la izquierda los elementos subsiguientes.
            for(int j = i; j < lista->longitud; j++){

                lista->array[j] = lista->array[j+1];
            }
            //Decrementa la longitud y corta el programa.
            lista->longitud--;
            break;
        }
    }

}


TipoElemento l_buscar(Lista lista, int clave){

    //Verifica si la lista no esta vacia.
    if(!l_es_vacia(lista)){

        //Recorre el array hasta el ultimo elemento valido.
        for(int i = 0; i < lista->longitud; i++){

            //Comprueba si el elemento actual es el buscado, de ser verdadero lo retorna.
            if(lista->array[i]->clave == clave){

                return lista->array[i];
            }

        }

        //Si no se encuentra el elemento retorna NULL.
        printf("\nElemento no encontrado\n");
        return NULL;

    }
    else{

        printf("\nError al buscar elemento. La lista esta vacia.\n");
        return NULL;
        
    }

}


void l_insertar(Lista lista, TipoElemento elemento, int posicion){

    //Verifica que la lista no se encuentre llena.
    if(l_es_llena(lista)){

        printf("\nError al insertar elemento. La lista esta llena.\n");
        return;
    }
    //Verifica que la posicion pasada por parametro sea valida.
    else if(posicion <= 0 || posicion > lista->longitud){

        printf("\nError al insertar elemento. Posicion invalida.\n");
        return;
    }

    //Realiza un corrimiento de los elementos hacia la derecha desde el final hasta la posicion para "abrir" un espacio para la insercion del elemento.
    for(int i = lista->longitud; i >= posicion; i--){

        lista->array[i] = lista->array[i - 1];

    }
    lista->array[posicion - 1] = elemento;
    lista->longitud++;

}


void l_eliminar(Lista lista, int posicion){

    //Verifica que la lista no esta vacia.
    if(l_es_vacia(lista)){

        printf("\nError al eliminar elemento. La lista se encuentra vacia.\n");
        return;
    }
    //Verifica que la posicion pasada por parametro sea valida.
    else if(posicion <= 0 || posicion > lista->longitud){

        printf("\nError al eliminar elemento. Posicion invalida.\n");
        return;
    }

    //Eliminacion logica del elemento desplazando los elementos subsiguientes hacia la izquierda.
    for(int i = posicion - 1; i < lista->longitud; i++){

        lista->array[i] = lista->array[i + 1];

    }
    lista->longitud--;

}

TipoElemento l_recuperar(Lista lista, int posicion){

    //Verifica que la lista no esta vacia.
    if(l_es_vacia(lista)){

        printf("\nError al recuperar elemento. La lista se encuentra vacia.\n");
        return NULL;
    }
    //Verifica que la posicion pasada por parametro sea valida.
    else if(posicion <= 0 || posicion > lista->longitud){

        printf("\nError al recuperar elemento. Posicion invalida.\n");
        return NULL;
    }
    else{

        return lista->array[posicion - 1];

    }

}



// ---------------- FUNCIONALIDADES DEL ITERADOR ----------------



Iterador iterador(Lista lista){

    //Inicializa la estructura iterador asignando el espacio en memoria.
    Iterador nuevo_iterador = (Iterador)malloc(sizeof(struct IteradorRep));
    //Asigna el iterador a la lista pasada por parametro y pone el indice en 0.
    nuevo_iterador->lista = lista;
    nuevo_iterador->PosActual = 0;

    return nuevo_iterador;

}


bool hay_siguiente(Iterador iterador){

    //Verifica si el iterador llego a la ultima posicion valida del array.
    return (iterador->PosActual < iterador->lista->longitud);

}


TipoElemento siguiente(Iterador iterador){

    //Avanza el iterador hacia la siguiente posicion y retorna el elemento.
    return iterador->lista->array[iterador->PosActual++];

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////