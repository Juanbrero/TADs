#include "Arboles_AVL.h"
#include <stdio.h>


//Cantidad maxima de nodos del arbol.
static const int TAM_MAX = 100;



// ---------------- ESTRUCTURA ----------------



/**
 * @brief Contiene el nodo raiz del arbol y la cantidad de elementos.
 * 
 */
struct ArbolAVLRep{

    NodoArbol raiz;
    int cantidad;
};


/**
 * @brief Casos posibles de desbalanceo.
 * 
 */
enum Balanceo{

    DESBALANCEADO_DERECHA,
    APENAS_DESBALANCEADO_DERECHA,
    BALANCEADO,
    APENAS_DESBALANCEADO_IZQUIERDA,
    DESBALANCEADO_IZQUIERDA

};



// ---------------- FUNCIONALIDADES ----------------



// FUNCIONES INTERNAS PROPIAS DEL BALANCEO



/**
 * Rotación derecha
 *     b                                   a
 *    / \                                 / \
 *   a   e  -> b.avl_rotar_derecha() ->  c   b
 *  / \                                     / \
 * c   d                                   d   e
 * 
 */
NodoArbol avl_rotar_derecha(NodoArbol nodo){

    NodoArbol nodoAux = nodo->hi;

    //Rotacion simple a derecha RSD.
    nodo->hi = nodoAux->hd;
    nodoAux->hd = nodo;

    //Actualiza el factor de equilibrio de los nodos.
    nodo->FE = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    nodoAux->FE = avl_max(avl_altura_izq(nodoAux), nodo->FE) + 1;

    return nodoAux;

}


/**
 *  * Rotación izquierda
 *   a                                     b
 *  / \                                   / \
 * c   b  -> a.avl_rotar_izquierda() ->  a   e
 *    / \                               / \
 *   d   e                             c   d
 */
NodoArbol avl_rotar_izquierda(NodoArbol nodo){

    NodoArbol nodoAux = nodo->hd;

    //Rotacion simple a izquierda RSI.
    nodo->hd = nodoAux->hi;
    nodoAux->hi = nodo;

    //Actualiza el factor de equilibrio de los nodos.
    nodo->FE = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    nodoAux->FE = avl_max(avl_altura_izq(nodoAux), nodo->FE) + 1;

    return nodoAux;

}


int avl_altura_izq(NodoArbol nodo){

    if(nodo->hi == NULL){

        return -1;
    }

    return nodo->hi->FE;

}


int avl_altura_der(NodoArbol nodo){

    if(nodo->hd == NULL){

        return -1;
    }

    return nodo->hd->FE;

}


int avl_max(int a, int b){

    //Si el valor de a es mayor que b, retorna a, de lo contrario retorna b.
    return a > b ? a : b;

}


enum Balanceo avl_calcular_balanceo(NodoArbol nodo){

    int diferenciaAltura = avl_altura_izq(nodo) - avl_altura_der(nodo);

    switch(diferenciaAltura){
        case -2:
            return DESBALANCEADO_DERECHA;
        case -1:
            return APENAS_DESBALANCEADO_DERECHA;
        case 1:
            return APENAS_DESBALANCEADO_IZQUIERDA;
        case 2:
            return DESBALANCEADO_IZQUIERDA;
        default:
            return BALANCEADO;
    }

}


// --------------------------------------------------------------------------------------------------------------------


ArbolAVL avl_crear(){

    //Inicializa el arbol asignando el espacio en memoria.
    ArbolAVL nuevo_arbol = (ArbolAVL)malloc(sizeof(struct ArbolAVLRep));

    //Lo establece en condicion de arbol vacio.
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad = 0;

    return nuevo_arbol;

}


bool avl_es_vacio(ArbolAVL avl){

    return (avl->cantidad == 0);

}


bool avl_es_lleno(ArbolAVL avl){

    return (avl->cantidad == TAM_MAX);

}


bool avl_rama_nula(NodoArbol subArbol){

    return (subArbol == NULL);

}


int avl_cantidad_elementos(ArbolAVL avl){

    return avl->cantidad;

}


NodoArbol avl_raiz(ArbolAVL avl){

    return avl->raiz;

}


/**
 * @brief Funcion interna para insertar elemento.
 * 
 * @param avl 
 * @param elemento 
 * @param nodoPadre 
 * @return NodoArbol 
 */
NodoArbol avl_insertar_recursivo(ArbolAVL avl, TipoElemento elemento, NodoArbol nodoPadre){

    //Condicion de corte.
    if(nodoPadre == NULL){

        NodoArbol nuevo_nodo = n_crear(elemento);
        return nuevo_nodo;

    }

    //Busqueda binaria.
    if(elemento->clave < nodoPadre->datos->clave){

        nodoPadre->hi = avl_insertar_recursivo(avl, elemento, nodoPadre->hi);

    }
    else if(elemento->clave > nodoPadre->datos->clave){

        nodoPadre->hd = avl_insertar_recursivo(avl, elemento, nodoPadre->hd);
    
    }
    else{

        //El elemento esta duplicado por lo que decrementa la cantidad de elementos para compensar el incremento de la funcion principal.
        avl->cantidad--;

        return nodoPadre;

    }

    //Calcula el factor de equilibrio y verifica la condicion de balanceo.
    nodoPadre->FE = avl_max(avl_altura_izq(nodoPadre), avl_altura_der(nodoPadre)) + 1;
    enum Balanceo balance = avl_calcular_balanceo(nodoPadre);

    if(balance == DESBALANCEADO_IZQUIERDA){

        if(elemento->clave < nodoPadre->hi->datos->clave){

            //Caso rotacion simple derecha RSD.
            nodoPadre = avl_rotar_derecha(nodoPadre);
        }
        else{

            // Caso rotacion doble izquierda-derecha RDID.
            nodoPadre->hi = avl_rotar_izquierda(nodoPadre->hi);

            return avl_rotar_derecha(nodoPadre);
        }
    }

    if(balance == DESBALANCEADO_DERECHA){

        if(elemento->clave > nodoPadre->hd->datos->clave){

            //Caso rotacion simple izquierda RSI.
            nodoPadre = avl_rotar_izquierda(nodoPadre);
        }
        else{

            //Caso rotacion doble derecha-izquierda RDDI.
            nodoPadre->hd = avl_rotar_derecha(nodoPadre->hd);

            return avl_rotar_izquierda(nodoPadre);
        }
    }

    return nodoPadre;

}


void avl_insertar(ArbolAVL avl, TipoElemento elemento){

    //Verifica que el arbol no este lleno.
    if(avl_es_lleno(avl)){

        printf("\nError al insertar elemento. El arbol esta lleno.\n");
        return;
    }

    //Llama a la funcion intera auxiliar encargada de insertar el elemento. Al balancear el arbol puede cambiar la raiz, por lo que es necesario retornala y reasignarla.
    avl->raiz = avl_insertar_recursivo(avl, elemento, avl_raiz(avl));
    avl->cantidad++;

}


/**
 * @brief Funcion interna para buscar sucesor minimo en caso de eliminacion de un nodo con 2 hijos validos.
 * 
 * @param nodo 
 * @return NodoArbol 
 */
NodoArbol avl_buscar_minimo(NodoArbol nodo){

    NodoArbol actual = nodo;

    while(actual != NULL && actual->hi != NULL){

        actual = actual->hi;
    }

    return actual;

}


/**
 * @brief Funcion recursiva interna encargada que eliminar un elemento del arbol y volver a balancearlo de ser necesario. 
 * 
 * @param avl 
 * @param raiz 
 * @param clave 
 * @return NodoArbol 
 */
NodoArbol avl_eliminar_recursivo(ArbolAVL avl, NodoArbol nodo, int clave){

    //Si el elemento no se encuentra. Incrementa la cantidad para compensar el decremento en la funcion principal y retorna NULL.
    if(nodo == NULL){

        avl->cantidad++;
        return nodo;

    }

    //Busqueda binaria del elemento a eliminar.
    if(clave < nodo->datos->clave){
        
        nodo->hi = avl_eliminar_recursivo(avl, nodo->hi, clave);
    }
    else if(clave > nodo->datos->clave){

        nodo->hd = avl_eliminar_recursivo(avl, nodo->hd, clave);
    }
    //Se encuentra el elemento.
    else{

        //Caso 1: El nodo no tiene hijos validos.
        if(nodo->hi == NULL && nodo->hd == NULL){

            nodo = NULL;
        }
        //Caso 2: El nodo tiene 1 hijo valido (derecho).
        else if(nodo->hi == NULL && nodo->hd != NULL){

            NodoArbol nodoAux = nodo->hd;
            nodo = NULL;
            return nodoAux;
        }
        //Caso 2: El nodo tiene 1 hijo valido (izquierdo).
        else if(nodo->hi != NULL && nodo->hd == NULL){

            NodoArbol nodoAux = nodo->hi;
            nodo = NULL;
            return nodoAux;
        }
        //Caso 3: El nodo tiene los 2 hijos validos.
        else{

            //Llama a una rutina interna para buscar el sucesor menor del subarbol derecho.
            NodoArbol nodoAux = avl_buscar_minimo(nodo->hd);
            //Pisa los datos del nodo con los del sucesor.
            nodo->datos->clave = nodoAux->datos->clave;
            nodo->datos->valor = nodoAux->datos->valor;
            nodo->hd = avl_eliminar_recursivo(avl, nodo->hd, nodoAux->datos->clave);

        }
    }

    if (nodo == NULL){

        return nodo;
    }

    //Actualiza altura y rebalancea el arbol de ser necesario.
    nodo->FE = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo));
    enum Balanceo balance = avl_calcular_balanceo(nodo);

    if(balance == DESBALANCEADO_IZQUIERDA){

        //Rotacion simple derecha RSD.
        if(avl_calcular_balanceo(nodo->hi) == BALANCEADO || avl_calcular_balanceo(nodo->hi) == APENAS_DESBALANCEADO_IZQUIERDA){

            return avl_rotar_derecha(nodo);
        }

        //Rotacion doble izquierda-derecha RDID.
        nodo->hi = avl_rotar_izquierda(nodo->hi);

        return avl_rotar_derecha(nodo);

    }

    if(balance == DESBALANCEADO_DERECHA){

        //Rotacion simple izquierda RSI.
        if (avl_calcular_balanceo(nodo->hd) == BALANCEADO || avl_calcular_balanceo(nodo->hd) == APENAS_DESBALANCEADO_DERECHA){

            return avl_rotar_izquierda(nodo);
        }

        //Rotacion doble derecha-izquierda RDDI.
        nodo->hd = avl_rotar_derecha(nodo->hd);
        return avl_rotar_izquierda(nodo);

    }

    return nodo;
    
}


void avl_eliminar(ArbolAVL avl, int clave){

    //Verifica que el arbol no este vacio.
    if(avl_es_vacio(avl)){

        printf("\nError al eliminar elemento. El arbol esta vacio.\n");
        return;
    }

    //Llama a la funcion intera auxiliar encargada de buscar y eliminar el elemento. Al balancear el arbol puede cambiar la raiz, por lo que es necesario retornala y reasignarla.
    avl->raiz = avl_eliminar_recursivo(avl, avl_raiz(avl), clave);
    avl->cantidad--;

}


/**
 * @brief Funcion recursiva interna que busca un elemento en el arbol a traves de busqueda binaria.
 * 
 * @param raiz 
 * @param clave 
 * @return TipoElemento 
 */
TipoElemento avl_buscar_recursivo(NodoArbol raiz, int clave){

    //Caso de corte.
    if(raiz == NULL){

        return NULL;
    }
    else if(clave < raiz->datos->clave){

        return avl_buscar_recursivo(raiz->hi, clave);
    }
    else if(clave > raiz->datos->clave){

        return avl_buscar_recursivo(raiz->hd, clave);
    }
    else{

        return raiz->datos;
    }

}


TipoElemento avl_buscar(ArbolAVL avl, int clave){

    if(avl_es_vacio(avl)){

        printf("\nError al buscar elemento. El arbol esta vacio.\n");
        return NULL;
    }

    TipoElemento te = avl_buscar_recursivo(avl->raiz, clave);

    if(te == NULL){

        printf("\nLa clave %d no se encuentra en el arbol.\n", clave);
        
    }

    return te;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////