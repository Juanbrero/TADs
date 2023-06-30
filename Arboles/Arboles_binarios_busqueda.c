#include "Arboles_binarios_busqueda.h"
#include <stdio.h>


//Cantidad maxima de nodos del arbol.
static const int TAM_MAX = 100;



// ---------------- ESTRUCTURA ----------------



/**
 * @brief Contiene el nodo raiz del arbol y la cantidad de elementos.
 * 
 */
struct ArbolBinarioBusquedaRep{

    NodoArbol raiz;
    int cantidad;

};



// ---------------- FUNCIONALIDADES ----------------



ArbolBinarioBusqueda abb_crear(){

    //Inicializa el arbol asignando el espacio en memoria.
    ArbolBinarioBusqueda nuevo_arbol = (ArbolBinarioBusqueda)malloc(sizeof(struct ArbolBinarioBusquedaRep));

    //Lo pone en condicion de arbol vacio.
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad = 0;

    return nuevo_arbol;

}


bool abb_es_vacio(ArbolBinarioBusqueda arbolBB){

    return (arbolBB->cantidad == 0);

}


bool abb_es_lleno(ArbolBinarioBusqueda arbolBB){

    return (arbolBB->cantidad == TAM_MAX);

}


int abb_cantidad_elementos(ArbolBinarioBusqueda arbolBB){

    return arbolBB->cantidad;

}


bool abb_rama_nula(NodoArbol subArbol){

    return (subArbol == NULL);

}


NodoArbol abb_raiz(ArbolBinarioBusqueda arbolBB){

    return arbolBB->raiz;

}


void abb_insertar(ArbolBinarioBusqueda arbolBB, TipoElemento elemento){

    //Verifica que el arbol no este lleno.
    if(abb_es_lleno(arbolBB)){

        printf("\nError al insertar elemento. El arbol esta lleno.\n");
        return;
    }

    //Crea un nuevo nodo con los datos del elemento.
    NodoArbol nuevo_nodo = n_crear(elemento);

    //Si el arbol esta vacio establece el nuevo nodo como raiz del arbol.
    if(abb_es_vacio(arbolBB)){

        arbolBB->raiz = nuevo_nodo;
        arbolBB->cantidad++;

    }
    else{

        NodoArbol nodoAux = arbolBB->raiz;
        NodoArbol padreNodoAux;

        //Hace busqueda binaria del elemento.
        while(nodoAux != NULL){

            //Salva la posicion del nodo padre para realizar el enlace luego.
            padreNodoAux = nodoAux;

            if(elemento->clave > nodoAux->datos->clave){

                nodoAux = nodoAux->hd;
            }
            else if(elemento->clave < nodoAux->datos->clave){

                nodoAux = nodoAux->hi;
            }
            else{

                //Si el elemento ya se encuentra en el arbol sale.
                break;
            }

        }

        //Si el elemento no se encontro se realiza la insercion.
        if(nodoAux == NULL){

            if(elemento->clave > padreNodoAux->datos->clave){

                padreNodoAux->hd = nuevo_nodo;
            }
            else if(elemento->clave < padreNodoAux->datos->clave){

                padreNodoAux->hi = nuevo_nodo;
            }

            arbolBB->cantidad++;

        }
        //Si el elemento ya se encuentra en el arbol no se inserta.
        else{

            printf("\nError al insertar elemento. La clave %d ya se encuentra en el arbol.\n", elemento->clave);
            return;

        }

    }

}


/**
 * @brief Funcion interna para hallar el elemento minimo. 
 * 
 * @param raiz 
 * @return NodoArbol 
 */
NodoArbol abb_buscar_minimo(NodoArbol raiz){

    NodoArbol nodoActual = raiz;
    
    while(nodoActual != NULL && nodoActual->hi != NULL){

        nodoActual = nodoActual->hi;
    }

    return nodoActual;

}


/**
 * @brief Funcion interna para eliminar un nodo.
 * 
 * @param root 
 * @param claveABorrar 
 * @return NodoArbol 
 */
NodoArbol abb_eliminar_recursivo(NodoArbol raiz, int clave) {
    
    //Caso base.
    if(raiz == NULL){

        printf("\nError al eliminar elemento. La clave %d no se encuentra en el arbol.\n", clave);
        return raiz;
    }

    //Busqueda binaria del elemento a eliminar.
    if(clave < raiz->datos->clave){

        raiz->hi = abb_eliminar_recursivo(raiz->hi, clave);
        
    }
    else if(clave > raiz->datos->clave){

        raiz->hd = abb_eliminar_recursivo(raiz->hd, clave);
    
    }
    else{
        
        if(raiz->hi == NULL) {
           
            NodoArbol temp = raiz->hd;
            free(raiz);
            return temp;
        }
        else if(raiz->hd == NULL) {
            
            NodoArbol temp = raiz->hi;
            free(raiz);
            return temp;
        }

        NodoArbol temp = abb_buscar_minimo(raiz->hd);
        raiz->datos->clave = temp->datos->clave;
        raiz->datos->valor = temp->datos->valor;

        raiz->hd = abb_eliminar_recursivo(raiz->hd, temp->datos->clave);
    }

    return raiz;

}


void abb_eliminar(ArbolBinarioBusqueda arbolBB, int clave) {
    
    //Verifica que el arbol no este vacio.
    if(abb_es_vacio(arbolBB)){

        printf("\nError al eliminar elemento. El arbol esta vacio.\n");
        return;
    }

    TipoElemento te;
    NodoArbol ND, NI;
    te = n_recuperar(abb_raiz(arbolBB));
    ND = n_hijoderecho(abb_raiz(arbolBB));
    NI = n_hijoizquierdo(abb_raiz(arbolBB));

    // Contemplo que si borra la raiz y no tiene hijos por la derecha el hijo izquierdo se convierte en raiz.
    if ((ND == NULL) && (NI != NULL) && (te->clave == clave)) {
        
        ND = abb_raiz(arbolBB);
        arbolBB->raiz = NI;
        free(ND);
        arbolBB->cantidad--;
        return;
    }
    // Contemplo que si borra la raiz y no tiene hijos por la izquierda el hijo derecho se convierte en raiz
    else if ((NI == NULL) && (ND != NULL)&& (te->clave == clave)) {
        
        NI = abb_raiz(arbolBB);
        arbolBB->raiz = ND;
        free(NI);
        arbolBB->cantidad--;
        return;
    }
    // Contemplo que si borra la raiz y no tiene ningun hijo, el arbol queda vacio.
    else if((NI == NULL) && (ND == NULL) && (te->clave == clave)){

        NodoArbol raiz = abb_raiz(arbolBB);
        arbolBB->raiz = NULL;
        free(raiz);
        arbolBB->cantidad--;
        return;
    }

    // Cualquier otro caso
    // Sino llamo al proceso recursivo
    bool eliminado = abb_eliminar_recursivo(abb_raiz(arbolBB), clave);

    if(eliminado == true){

        arbolBB->cantidad--;
    }

}


/**
 * @brief Funcion interna para buscar un elemento.
 * 
 * @param raiz 
 * @param clave 
 * @return TipoElemento 
 */
TipoElemento abb_buscar_recursivo(NodoArbol raiz, int clave){

    //Caso de corte.
    if(raiz == NULL){

        return NULL;
    }
    
    //Busqueda binaria.
    if(clave < raiz->datos->clave){

        abb_buscar_recursivo(raiz->hi, clave);
    }
    else if(clave > raiz->datos->clave){

        abb_buscar_recursivo(raiz->hd, clave);
    }
    else{

       return raiz->datos;

    }

}


TipoElemento abb_buscar(ArbolBinarioBusqueda arbolBB, int clave){

    //Verifica que el arbol no este vacio.
    if(abb_es_vacio(arbolBB)){

        printf("\nError al eliminar elemento. El arbol esta vacio.\n");
        return NULL;
    }

    TipoElemento te = abb_buscar_recursivo(arbolBB->raiz, clave);

    if(te == NULL){

        printf("\nLa clave %d no se encuentra en el arbol.\n", clave);
        
    }

    return te;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////