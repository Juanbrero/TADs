#include <stdio.h>
#include "Listas.h"


//Cantidad maxima de elementos de la lista.
static const int TAM_MAX = 100;
//Variable que simula el NULL.
static const int NULO = -1;


// ---------------- ESTRUCTURAS ----------------



/**
 * @brief Contiene el elemento y el indice del nodo siguiente en el array de nodos.
 * 
 */
struct NodoRep{

    TipoElemento datos;
    int siguiente;

};


/**
 * @brief Contiene el array de nodos que simula el cursor, el indice inicial del array, el indice del primer nodo disponible y la cantidad de nodos ocupados (longitud).
 * 
 */
struct ListaRep{

    Nodo cursor;
    int inicio;
    int libres;
    int longitud;

};


/**
 * @brief Contiene la lista sobre la que opera y el indice en el que se encuentra.
 * 
 */
struct IteradorRep{

    Lista lista;
    int PosActual;
};



// ---------------- FUNCIONALIDADES ----------------



Lista l_crear(){

    //Inicializa la lista asignandole el espacio en memoria.
    Lista nueva_lista = (Lista)malloc(sizeof(struct ListaRep));
    
    //Inicializa el array de nodos cursor poniendo los valores en 0 por defecto.
    nueva_lista->cursor = calloc(TAM_MAX, sizeof(struct NodoRep));
    //Posiciona el inicio de la lista en NULL.
    nueva_lista->inicio = NULO;
    nueva_lista->longitud = 0;

    //Encadena los nodos libres.
    for(int i = 0; i < TAM_MAX - 2; i++){

        //Asigna a cada nodo el indice del siguiente para realizar el encadenamiento.
        nueva_lista->cursor[i].siguiente = i + 1;
    }

    //Asigna el indice a partir del cual los nodos estan disponibles (vacios).
    nueva_lista->libres = 0;
    //Asigna indice nulo al final de la lista.
    nueva_lista->cursor[TAM_MAX - 1].siguiente = NULO;

    return nueva_lista;

}


bool l_es_vacia(Lista lista){

    return (lista->longitud == 0);
}


bool l_es_llena(Lista lista){

    return (lista->longitud == TAM_MAX);
}


int l_longitud(Lista lista){

    return lista->longitud;
}


void l_mostrar(Lista lista){

    //Verifica si la lista esta vacia.
    if(l_es_vacia(lista)){

        printf("\nError al mostrar. La lista esta vacia.\n");
        return;
    }

    printf("\nContenido:  ");

    //Crea un indice para recorrer la lista y lo inica al inicio de esta.
    int posActual = lista->inicio;

    while(posActual != NULO){

        printf("%d ", lista->cursor[posActual].datos->clave);

        //Se desplaza hacia la siguiente posicion.
        posActual = lista->cursor[posActual].siguiente;
    }

    printf("\n");

}


void l_agregar(Lista lista, TipoElemento elemento){

    //Verifica que la lista no esta llena.
    if(l_es_llena(lista)){

        printf("\nError al agregar elemento. La lista se encuentra llena.\n");
        return;
    }
    
    //Se posiciona en el primer espacio libre de la lista.
    int p = lista->libres;
    //Desplazo el indice de los nodos libres a la derecha.
    lista->libres = lista->cursor[p].siguiente;

    //Le asigna los datos agregados en dicha posicion.
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;

    if(lista->inicio == NULO){

        //Posiciona el inicio de la lista en el primer elemento.
        lista->inicio = p;
    }
    else{

        int q = lista->inicio;
        //Recorre la lista hasta el ultimo elemento enlazado.
        while(lista->cursor[q].siguiente != NULO){

            q = lista->cursor[q].siguiente;

        }
        //Enlaza al nuevo nodo al final de la lista.
        lista->cursor[q].siguiente = p;

    }

    lista->longitud++;

}


void l_borrar(Lista lista, int clave){

    //Verifica si la lista esta vacia.
    if(l_es_vacia(lista)){

        printf("\nError al borrar elemento. La lista esta vacia.\n");
        return;
    }

    int p = lista->inicio;
    //Borra los elementos coincidentes al inicio de la lista.
    while((lista->inicio != NULO) && (lista->cursor[lista->inicio].datos->clave == clave)){
        
        //Libera al nodo a borrar encadenandolo al principio de los nodos libres.
        lista->cursor[lista->inicio].siguiente = lista->libres;
        
        //Desplaza el indice inicial de nodos libres al nodo que se libero.
        lista->libres = lista->inicio;
        
        //Desplaza el nuevo inicio de lista al siguiente elemento.
        lista->inicio = lista->cursor[p].siguiente;
    }

    int q = lista->inicio;
    //Borra los elementos coincidentes en el resto de la lista.
    while((lista->inicio != NULO) && (lista->cursor[q].siguiente != NULO)){

        p = lista->cursor[q].siguiente;

        if(lista->cursor[p].datos->clave == clave){

            //Puentea el elemento a borrar.
            lista->cursor[q].siguiente = lista->cursor[p].siguiente;

            //Libera al nodo a borrar encadenandolo al principio de los nodos libres.
            lista->cursor[p].siguiente = lista->libres;

            //Desplaza el indice inicial de nodos libres al nodo que se libero.
            lista->libres = p;

            lista->longitud--;
        }

        q = lista->cursor[q].siguiente;

    }

}


TipoElemento l_buscar(Lista lista, int clave){

    //Verifica que la lista no esta vacia.
    if(l_es_vacia(lista)){

        printf("\nError al buscar elemento. La lista esta vacia.\n");

    }
    else{

        int p = lista->inicio;

        //Recorre la lista completa buscando la clave.
        while(p != NULO){

            if(lista->cursor[p].datos->clave == clave){

                return lista->cursor[p].datos;
            }

            p = lista->cursor[p].siguiente;
        }
    }

    //Si no encuentra la clave retorna NULL.
    return NULL;
}


void l_insertar(Lista lista, TipoElemento elemento, int posicion){

    //Verifica si la lista esta llena.
    if(l_es_llena(lista)){

        printf("\nError al insertar elemento. La lista esta llena.\n");
        return;
    }
    //Verifica que la posicion de insercion sea valida.
    else if(posicion <= 0 || posicion > lista->longitud){

        printf("\nError al insertar elemento. La posicion no es valida.\n");
        return;
    }
    
    int p = lista->libres;
    //Desplaza el indice inical de nodos libres al siguiente elemento.
    lista->libres = lista->cursor[p].siguiente;
    //Carga los datos del nodo.
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;

    //Verifica si la posicion a insertar es el inicio de la lista.
    if(posicion == 1){
            
        lista->cursor[p].siguiente = lista->inicio;
        //Desplaza el inicio al nuevo nodo.
        lista->inicio = p;

    }
    else{

        int q = lista->inicio;

        //Se posicion en el elemento anterior a la posicion de insercion.
        for(int i = 0; i < posicion - 2; i++){

            q = lista->cursor[q].siguiente;
        }

        //Desplaza el nodo existente en la posicion a la derecha y enlaza el nuevo nodo.
        lista->cursor[p].siguiente = lista->cursor[q].siguiente;
        lista->cursor[q].siguiente = p;
    }

        lista->longitud++;

}


void l_eliminar(Lista lista, int posicion){

    //Verifica que la lista no esta vacia.
    if(l_es_vacia(lista)){

        printf("\nError al eliminar elemento. La lista se encuentra vacia.\n");
        return;
    }
    //Verifica que la posicion sea valida.
    else if(posicion <= 0 || posicion > lista->longitud){

        printf("\nError al eliminar elemento. La posicion no es valida.\n");
        return;
    }

    int p = lista->inicio, q;

    //Verifica si la posicion a eliminar es el inicio de la lista.
    if(posicion == 1){

        //Salva la posicion a eliminar y desplaza el inicio a la siguiente posicion.
        q = lista->cursor[p].siguiente;
        lista->inicio = q;

        //Libera el nodo encadenandolo al comienzo de los libres.
        lista->cursor[p].siguiente = lista->libres;
        lista->libres = p;

    }
    else{

        //Se posiciona en la posicion anterior a la de eliminacion.
        for(int i = 0; i < posicion - 2; i++){

            p = lista->cursor[p].siguiente;

        }
        //Salva la posicion a eliminar.
        q = lista->cursor[p].siguiente;

        //Puentea el elemento a eliminar con su siguiente.
        lista->cursor[p].siguiente = lista->cursor[q].siguiente;

        //Libera el nodo eliminado encadenandolo al principio de los nodos libres.
        lista->cursor[q].siguiente = lista->libres;
        //Desplaza el indice inicial de los nodos libres al elemento liberado.
        lista->libres = q;

    }

    lista->longitud--;

}


TipoElemento l_recuperar(Lista lista, int posicion){

    //Verifica que la lista no esta vacia.
    if(l_es_vacia(lista)){

        printf("\nError al recuperar elemento. La lista se encuentra vacia.\n");
        
    }
    //Verifica que la posicion sea valida.
    else if(posicion <= 0 || posicion > lista->longitud){

        printf("\nError al recuperar elemento. La posicion no es valida.\n");
        
    }
    else{

        int p = lista->inicio;
        //Busca el elemento de la posicion ordinal pasada por parametro.
        for(int i = 0; i < posicion - 1; i++){

            p = lista->cursor[p].siguiente;
        }
        
        return lista->cursor[p].datos;
    
    }

    return NULL;
}



// ---------------- FUNCIONALIDADES DEL ITERADOR ----------------



Iterador iterador(Lista lista){

    //Inicializa el iterador asignando el espacio en memoria.
    Iterador iterador = (Iterador)malloc(sizeof(struct IteradorRep));

    //Asigna la lista sobre la que va a iterar y lo posiciona al inicio de esta.
    iterador->lista = lista;
    iterador->PosActual = 0;

    return iterador;

}


bool hay_siguiente(Iterador iterador){

    //Verifica si llego al ultimo elemento de la lista.
    return (iterador->PosActual < iterador->lista->longitud);

}


TipoElemento siguiente(Iterador iterador){
    
    int p = iterador->lista->inicio;
    //Avanza hasta el elemento en la posicion ordinal marcada por el iterador.
    for(int i = 0; i < iterador->PosActual; i++){
            
        p = iterador->lista->cursor[p].siguiente;
    }

    //Incrementa la posicion actual.
    iterador->PosActual++;
    
    return (iterador->lista->cursor[p].datos);

    
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////