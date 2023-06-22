#include <stdlib.h>
#include "Tipo_elemento.h"

struct TipoElementoRep{

    //Clave de acceso al elemento
    void* clave;
    //Contenido del elemento
    void* valor;

};

TipoElemento te_crear(void* clave){

    //inicializo la estructura TipoElemento asignando el espacio en memoria.
    TipoElemento te = (TipoElemento)malloc(sizeof(struct TipoElementoRep));

    te->clave = clave;
    te->valor = NULL;

    return te;
}

TipoElemento te_crear_con_valor(void* clave, void* valor){

    //inicializo la estructura TipoElemento asignando el espacio en memoria.
    TipoElemento te = (TipoElemento)malloc(sizeof(struct TipoElementoRep));

    te->clave = clave;
    te->valor = valor;

    return te;

}