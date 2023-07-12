#include <stdio.h>
#include "Conjuntos.h"
#include "../Listas/Listas.h"



// ---------------- ESTRUCTURA ----------------



/**
 * @brief Contiene la lista con la que operara.
 * 
 */
struct ConjuntoRep{

    Lista lista;

};



// ---------------- FUNCIONALIDADES ----------------



Conjunto cto_crear(){

    //Inicializa el conjunto asignando el espacio en memoria.
    Conjunto nuevo_cto = (Conjunto)malloc(sizeof(struct ConjuntoRep));

    //Inicializa la lista.
    nuevo_cto->lista = l_crear();

    return nuevo_cto;

}


bool cto_es_vacio(Conjunto conjunto){

    return l_es_vacia(conjunto->lista);

}


bool cto_es_lleno(Conjunto conjunto){

    return l_es_llena(conjunto->lista);

}


int cto_cantidad_elementos(Conjunto conjunto){

    return l_longitud(conjunto->lista);

}


void cto_agregar(Conjunto conjunto, TipoElemento elemento){

    if(l_buscar(conjunto->lista, elemento->clave) == NULL){

        l_agregar(conjunto->lista, elemento);
    }

}


void cto_borrar(Conjunto conjunto, int clave){

    l_borrar(conjunto->lista, clave);

}


bool cto_pertenece(Conjunto conjunto, int clave){

    //Recorre la lista buscando el elemento.
    Iterador ite = iterador(conjunto->lista);
    TipoElemento te;

    while(hay_siguiente(ite)){

        te = siguiente(ite);
        
        if(te->clave == clave){

            break;
        }

    }
    free(ite);

    return (te->clave == clave);
}


Conjunto cto_union(Conjunto conjuntoA, Conjunto conjuntoB){

    Conjunto resultado = cto_crear();

    Iterador ite = iterador(conjuntoA->lista);
    //Agrega los elementos del conjunto A.
    while(hay_siguiente(ite)){

        cto_agregar(resultado, siguiente(ite));
    }
    
    ite = iterador(conjuntoB->lista);
    //Agrega los elementos del conjunto B.
    while(hay_siguiente(ite)){

        cto_agregar(resultado, siguiente(ite));
    }
    free(ite);

    return resultado;

}


Conjunto cto_interseccion(Conjunto conjuntoA, Conjunto conjuntoB){

    Conjunto resultado = cto_crear();

    Iterador ite = iterador(conjuntoA->lista);

    while(hay_siguiente(ite)){

        TipoElemento te = siguiente(ite);

        //Por cada elemento del conjunto A, verifica si pertenece al conjunto B, de ser verdadero lo agrega al conjunto resultado.
        if(cto_pertenece(conjuntoB, te->clave)){

            cto_agregar(resultado, te);
        }
    }
    free(ite);

    return resultado;

}


Conjunto cto_diferencia(Conjunto conjuntoA, Conjunto conjuntoB){

    Conjunto resultado = cto_crear();

    Iterador ite = iterador(conjuntoA->lista);

    while(hay_siguiente(ite)){

        TipoElemento te = siguiente(ite);

        //Por cada elemento del conjunto A, verifica si pertenece al conjunto B, de ser verdadero lo agrega al conjunto resultado.
        if(!cto_pertenece(conjuntoB, te->clave)){

            cto_agregar(resultado, te);
        }
    }
    free(ite);

    return resultado;

}


TipoElemento cto_recuperar(Conjunto conjunto, int posicion){

    return l_recuperar(conjunto->lista, posicion);

}


void cto_mostrar(Conjunto conjunto){

    l_mostrar(conjunto->lista);

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////