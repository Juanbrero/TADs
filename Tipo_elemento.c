#include <stdlib.h>
#include "Tipo_elemento.h"



// ---------------- FUNCIONALIDADES ----------------



TipoElemento te_crear(int clave){

    //inicializo la estructura TipoElemento asignando el espacio en memoria.
    TipoElemento te = (TipoElemento)malloc(sizeof(struct TipoElementoRep));

    te->clave = clave;
    te->valor = NULL;

    return te;
}


TipoElemento te_crear_con_valor(int clave, void* valor){

    //inicializo la estructura TipoElemento asignando el espacio en memoria.
    TipoElemento te = (TipoElemento)malloc(sizeof(struct TipoElementoRep));

    te->clave = clave;
    te->valor = valor;

    return te;

}