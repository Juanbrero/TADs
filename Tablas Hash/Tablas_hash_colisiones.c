#include <stdio.h>
#include "Tablas_hash.h"
#include "../Listas/Listas.h"





// ---------------- ESTRUCTURAS ----------------



/**
 * @brief Contiene un puntero a la funcion de hashing, la cantidad de elementos de la tabla, y el registro tabla donde se almacenan los datos.
 * 
 */
struct TablaHashRep{

    int (*hash_function)(int);
    int capacidad;
    TipoRegistroTabla tabla;

};


/**
 * @brief Contiene los datos de los elementos en cada posicion de la tabla.
 * 
 */
struct TipoRegistroTablaRep{

    TipoElemento datos;
    bool ocupado;
    Lista lista_colisiones;

};



// ---------------- FUNCIONALIDADES ----------------



TablaHash th_crear(int capacidad, int (*hash_function)(int)){

    //Inicializa la tabla asignando el espacio en memoria.
    TablaHash nueva_tabla = (TablaHash)malloc(sizeof(struct TablaHashRep));

    //Asigna la cantidad de elemento y la funcion de hash asociada a la tabla.
    nueva_tabla->capacidad = capacidad;
    nueva_tabla->hash_function = hash_function;

    //Inicializa el registro tabla.
    nueva_tabla->tabla = (TipoRegistroTabla)malloc(capacidad * sizeof(struct TipoRegistroTablaRep));

    //Inicializa para cada elemento de la tabla la condicion de vacio y la lista de colisiones asociada.
    for(int i = 0; i < capacidad; i++){

        nueva_tabla->tabla[i].datos = NULL;
        nueva_tabla->tabla[i].ocupado = false;
        nueva_tabla->tabla[i].lista_colisiones = l_crear();

    }

    return nueva_tabla;

}


void th_insertar(TablaHash th, TipoElemento elemento){

    //Convierte la clave del elemento a traves de la funcion hash para obtener la posicion de insercion.
    int pos = th->hash_function(elemento->clave);

    TipoRegistroTabla registroTabla = &th->tabla[pos];

    //Si la posicion de la tabla esta vacia inserta el elemento.
    if(!registroTabla->ocupado){

        registroTabla->datos = elemento;
        registroTabla->ocupado = true;

    }
    //Si esta ocupada la posicion, inserta el elemento en la lista de colisiones.
    else{

        //Verifica que el elemento no este repetido en la tabla ni en la lista de colisiones.
        if((registroTabla->datos->clave != elemento->clave) && (l_buscar(registroTabla->lista_colisiones, elemento->clave) == NULL)){

            l_agregar(registroTabla->lista_colisiones, elemento);

        }

    }

}


void th_eliminar(TablaHash th, int clave){

    //Convierte la clave del elemento a traves de la funcion hash para obtener la posicion de eliminacion.
    int pos = th->hash_function(clave);
    TipoRegistroTabla registroTabla = &th->tabla[pos];

    //Verifica que haya elemento(s) en la posicion.
    if(registroTabla->ocupado){

        //Verifica que el elemento es el que esta en la tabla.
        if(registroTabla->datos->clave == clave){

            //Verifica si hay elementos en la lista de colisiones de la posicion.
            if(!l_es_vacia(registroTabla->lista_colisiones)){

                //Recupera el primer elemento de la lista para pasarlo a la tabla y borrarlo de la lista de colisiones.
                registroTabla->datos = l_recuperar(registroTabla->lista_colisiones, 1);

                l_eliminar(registroTabla->lista_colisiones, 1);
            }
            //No hay elementos en la lista de colisiones.
            else{

                registroTabla->ocupado = false;
                registroTabla->datos = NULL;
            }

        }
        //El elemento esta en la posicion pero no en la tabla, sino que esta en la lista de colisiones.
        else{

            l_borrar(registroTabla->lista_colisiones, clave);

        }

    }

}

TipoElemento th_recuperar(TablaHash th, int clave){

    // Convierte la clave del elemento a traves de la funcion hash para obtener su posicion.
    int pos = th->hash_function(clave);
    TipoRegistroTabla registroTabla = &th->tabla[pos];

    //Verifica que haya elementos en la posicion.
    if(registroTabla->ocupado){

        //Verifica si el elemento de la tabla coincide con la clave.
        if(registroTabla->datos->clave == clave){

            return registroTabla->datos;
        }
        //Busca el elemento en la lista de colisiones.
        else{

            return l_buscar(registroTabla->lista_colisiones, clave);
        }
    }

    //Si el elemento no se encuentra en la tabla retorna NULL.
    return NULL;

}


/**
 * @brief Funcion interna para mostrar elementos de la tabla.
 * 
 * @param th Tabla a mostrar.
 * @param soloOcupados Indicador para mostrar solo espacios ocupados de la tabla o mostrar todos los elementos incluyendo los vacios.
 */
void th_mostrar_interna(TablaHash th, bool soloOcupados){

    printf("\nContenido de la tabla hash:\n");

    for(int i = 0; i < th->capacidad; i++){

        TipoRegistroTabla registroTabla = &th->tabla[i];

        //Verifica que haya elementos en la posicion actual.
        if(registroTabla->ocupado){

            printf(" tabla[%i] [ocupado] %i", i, registroTabla->datos->clave);
            //Luego de mostrar el elemento de la tabla, inicia un iterador para recorrer la lista de colisiones de la posicion.
            Iterador iter = iterador(registroTabla->lista_colisiones);

            while(hay_siguiente(iter)){

                TipoElemento te = siguiente(iter);
                printf(" -> %i", te->clave);
            }
            free(iter);
            printf("\n");

        }
        //Muestra los espacio libres en caso de haberlo indicado.
        else if(!soloOcupados){

            printf(" tabla[%i] [ libre ]\n", i);
        }

    }

    printf("\n");

}


void th_mostrar(TablaHash th){

    th_mostrar_interna(th, false);
}


void th_mostrar_solo_ocupados(TablaHash th){

    th_mostrar_interna(th, true);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////