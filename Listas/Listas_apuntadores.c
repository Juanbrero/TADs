#include "Listas.h"
#include <stdio.h>

//Cantidad maxima de elementos de la lista
static const int TAM_MAX = 100;



// ---------------- ESTRUCTURAS ----------------



/**
 * @brief Contiene los datos del TipoElemento y el puntero al nodo siguiente.
 * 
 */
struct NodoRep{

    TipoElemento datos;
    Nodo siguiente;
};


/**
 * @brief Contiene el nodo inicial por el cual se accede a la lista y la cantidad de nodos existentes (longitud).
 * 
 */
struct ListaRep{

    Nodo inicio;
    int longitud;

};

/**
 * @brief Contiene el nodo en el que se encuentra.
 * 
 */
struct IteradorRep{

    Nodo PosActual;
};



// ---------------- FUNCIONALIDADES ----------------



Lista l_crear(){

    //Inicializa la estructura lista asignando el espacio en memoria.
    Lista nueva_lista = (Lista)malloc(sizeof(struct ListaRep));

    //Nodo inicio de la lista apunta a NULL.
    nueva_lista->inicio = NULL;
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

    //Crea un nodo auxiliar y le asigna el contenido del nodo inicio.
    Nodo nodoActual = lista->inicio;

    printf("\nContenido:  ");

    while(nodoActual != NULL){

        //Muestra la clave del nodo y le asigna el contenido del siguiente nodo enlazado.
        printf("%d ", nodoActual->datos->clave);
        nodoActual = nodoActual->siguiente;

    }

    printf("\n");

}


void l_agregar(Lista lista, TipoElemento elemento){

    //Verifica si la lista esta llena.
    if(l_es_llena(lista)){

        printf("\nError al agregar elemento. La lista se encuentra llena.\n");
        return;
    }

    //Crea un nuevo nodo asignandole el espacio en memoria, luego lo carga con los datos del elemento a agregar en la lista.
    Nodo nuevo_nodo = (Nodo)malloc(sizeof(struct NodoRep));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;

    //Verifica si el inicio de la lista es NULL, de ser verdadero asigna el nuevo nodo como inico de lista.
    if(lista->inicio == NULL){

        lista->inicio = nuevo_nodo;
    }
    else{

        //Crea un nodo auxiliar para recorrer la lista, cuando llega al final, enlaza el nuevo nodo.
        Nodo nodoAux = lista->inicio;

        while (nodoAux->siguiente != NULL){

            nodoAux = nodoAux->siguiente;

        }

        nodoAux->siguiente = nuevo_nodo;

    }

    lista->longitud++;
    
}


void l_borrar(Lista lista, int clave){

    //Verifica que la lista no este vacia.
    if(l_es_vacia(lista)){

        printf("\nError al borrar elemento. La lista esta vacia.\n");
        return;
    }

    Nodo nodoActual = lista->inicio;
    
    //Borra las claves coincidentes si se encuentran al inicio de la lista.
    while(nodoActual != NULL && nodoActual->datos->clave == clave){

        //Desplaza el nodo inicio a la siguiente posicion para hacer una eliminacion logica del nodo.
        lista->inicio = nodoActual->siguiente;
        
        //Libera el espacio de memoria del nodo y decrementa la longitud reflejando la eliminacion de un elemento.
        free(nodoActual);
        lista->longitud--;
        
        //Se posiciona en el nuevo inicio para verificar si vuelve a coincidir la clave y seguir borrando.
        nodoActual = lista->inicio;

    }

    //Borra las claves coincidentes del resto de la lista.
    while(nodoActual != NULL && nodoActual->siguiente != NULL){

        //Verifica siempre si el siguiente es el nodo a borrar, dado que si llega a la posicion no puede volver atras para enlazar los nodos puenteando el elemento a borrar.
        if(nodoActual->siguiente->datos->clave == clave){

            //Puentea el nodo a borrar (eliminacion logica del nodo).
            Nodo nodoAux = nodoActual->siguiente;
            nodoActual->siguiente = nodoAux->siguiente;

            //Libera el espacio en memoria del nodo borrado y decrementa la longitud reflejando la eliminacion de un elemento.
            free(nodoAux);
            lista->longitud--;

        }
        //Sigue recorriendo la lista.
        nodoActual = nodoActual->siguiente;

    }    

}


TipoElemento l_buscar(Lista lista, int clave){

    //Verifica que la lista no este vacia.
    if(l_es_vacia(lista)){

        printf("\nError al buscar elemento. La lista esta vacia.\n");
        return NULL;
    }

    Nodo nodoActual = lista->inicio;

    //Recorre la lista mientras hasta llegar al final o hasta que coincida con la clave buscada.
    while(nodoActual != NULL){

        if(nodoActual->datos->clave == clave){

            return nodoActual->datos;

        }

        nodoActual = nodoActual->siguiente;
    
    }

    return NULL;

}


void l_insertar(Lista lista, TipoElemento elemento, int posicion){

    //Verifica si la lista esta llena.
    if(l_es_llena(lista)){

        printf("\nError al insertar elemento. La lista se encuentra llena.\n");
        
    }
    //Verifica que sea una posicion de insercion valida.
    else if(posicion <= 0 || posicion > lista->longitud){

        printf("\nError al insertar elemento. La posicion no es valida.\n");
        
    }
    else{

        Nodo nodoActual = lista->inicio;
        
        //Crea el nuevo nodo con el elemento a insertar.
        Nodo nuevo_nodo = (Nodo)malloc(sizeof(struct NodoRep));
        nuevo_nodo->datos = elemento;
        nuevo_nodo->siguiente = NULL;

        //Si la posicion de insercion es igual a 1, reasigna el inicio de la lista al nuevo nodo.
        if(posicion == 1){

            nuevo_nodo->siguiente = nodoActual;
            lista->inicio = nuevo_nodo;

        }
        else{

            //Se posiciona en el nodo anterior a la posicion de insercion.
            for(int i = 1; i < posicion - 1; i++){

                nodoActual = nodoActual->siguiente;    

            }

            //Salva el nodo existente en la posicion de insercion.
            Nodo nodoAux = nodoActual->siguiente;

            //Enlaza el nodo que estaba antes en la posicion a continuacion del nuevo nodo.
            nuevo_nodo->siguiente = nodoAux;
            //Inserta el nuevo nodo en la posicion.
            nodoActual->siguiente = nuevo_nodo;
        }

        lista->longitud++;

    }

}


void l_eliminar(Lista lista, int posicion){

    //Verifica que la lista no esta vacia.
    if(l_es_vacia(lista)){

        printf("\nError al eliminar elemento. La lista esta vacia.\n");

    }
    //Verifica que la posicion sea valida.
    else if(posicion <=0 || posicion > lista->longitud){

        printf("\nError al eliminar elemento. La posicion no es valida.\n");

    }
    else{

        Nodo nodoActual = lista->inicio;      

        //Verifica si la posicion a eliminar es la primera, de ser verdadero desplaza el inicio de la lista al siguiente elemento.
        if(posicion == 1){

            lista->inicio = nodoActual->siguiente;
            //Libera el espacio en memoria del nodo.
            free(nodoActual);
        }
        else{

            //Se posiciona en el nodo anterior a la posicion de eliminacion para poder enlazar (puentear) los nodos anteriores con los posteriores al nodo eliminado.
            for(int i = 1; i < posicion - 1; i++){

                nodoActual = nodoActual->siguiente;

            }

            //Salva el elemento a eliminar.
            Nodo nodoAux = nodoActual->siguiente;
            //Puentea el nodo anterior con el posterior.
            nodoActual->siguiente = nodoAux->siguiente;
            //Libera el espacio en memoria del nodo eliminado.
            free(nodoAux);

        }

        lista->longitud--;

    }

}


TipoElemento l_recuperar(Lista lista, int posicion){

    //Verifica que la lista no esta vacia.
    if(l_es_vacia(lista)){

        printf("\nError al recuperar elemento. La lista esta vacia.\n");
        return NULL;
    }
    //Verifica que la posicion sea valida.
    else if(posicion <= 0 || posicion > lista->longitud){

        printf("\nError al recuperar elemento. La posicion no es valida.\n");
        return NULL;
    }
    
    Nodo nodoActual = lista->inicio;
    //Se posiciona en el elemento a recuperar.
    for(int i = 0; i < posicion - 1; i++){

        nodoActual = nodoActual->siguiente;

    }

    return nodoActual->datos;

}



// ---------------- FUNCIONALIDADES DEL ITERADOR ----------------



Iterador iterador(Lista lista){

    //Inicializa el iterador asignandole el espacio en memoria.
    Iterador iterador = (Iterador)malloc(sizeof(struct IteradorRep));

    //Posiciona al iterador al inicio de la lista en la que va a operar.
    iterador->PosActual = lista->inicio;

    return iterador;

}


bool hay_siguiente(Iterador iterador){

    return (iterador->PosActual != NULL);
}


TipoElemento siguiente(Iterador iterador){

    //Recupera el elemento de la posicion actual.
    TipoElemento actual = iterador->PosActual->datos;
    //Avanza el iterador hacia la siguiente posicion.
    iterador->PosActual = iterador->PosActual->siguiente;

    return actual;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////