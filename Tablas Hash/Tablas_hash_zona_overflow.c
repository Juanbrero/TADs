#include <stdio.h>
#include "Tablas_hash.h"



// ---------------- ESTRUCTURAS ----------------



/**
 * @brief Contiene un puntero a la funcion de hashing, la cantidad de elementos de la tabla, el registro tabla donde se almacenan los datos y el registro zona overflow donde se almacenan las colisiones.
 * 
 */
struct TablaHashRep{
    
    int (*hash_function)(int);
    int capacidad;
    TipoRegistroTabla tabla;
    TipoRegistroTabla ZonaOverflow;

};


/**
 * @brief Contiene los datos de los elementos en cada posicion de la tabla/zona de overflow.
 * 
 */
struct TipoRegistroTablaRep{

    TipoElemento datos;
    bool ocupado;

};



// ---------------- FUNCIONALIDADES ----------------



TablaHash th_crear(int capacidad, int (*hash_function)(int)){

    //Inicializa la nueva tabla asignando el espacio en memoria.
    TablaHash nueva_tabla = (TablaHash)malloc(sizeof(struct TablaHashRep));

    //Asigna la capacidad de la tabla y la funcion hash asociada.
    nueva_tabla->capacidad = capacidad;
    nueva_tabla->hash_function = hash_function;

    //Inicializa los registros de tabla para la tabla y la zona overflow.
    nueva_tabla->tabla = (TipoRegistroTabla)malloc(capacidad * sizeof(struct TipoRegistroTablaRep));
    nueva_tabla->ZonaOverflow = (TipoRegistroTabla)malloc(capacidad * sizeof(struct TipoRegistroTablaRep));

    //Inicializa cada posicion de la tabla y la zona overflow como vacia.
    for(int i = 0; i < nueva_tabla->capacidad; i++){

        nueva_tabla->tabla[i].datos = NULL;
        nueva_tabla->tabla[i].ocupado = false;
        nueva_tabla->ZonaOverflow[i].datos = NULL;
        nueva_tabla->ZonaOverflow[i].ocupado = false;

    }

    return nueva_tabla;

}


void th_insertar(TablaHash th, TipoElemento elemento){

    //Transforma la clave con la funcion hash para obtener la posicion en la tabla y se posiciona en dicha posicion.
    int pos = th->hash_function(elemento->clave);
    TipoRegistroTabla registroTabla = &th->tabla[pos];

    //Si la posicion esta vacia inserta el elemento en la tabla directamente.
    if(!registroTabla->ocupado){

        registroTabla->datos = elemento;
        registroTabla->ocupado = true;

    }
    //Si el elemento ya se encuentra en la tabla no lo agrega.
    else if(registroTabla->datos->clave == elemento->clave){

        printf("\nError al insertar elemento. Ya se encuentra en la tabla.\n");
        return;
    }
    //Recorre la zona de overflow para agregar el elemento.
    else{

        int i = 0;
        bool vacio = false;

        while(i < th->capacidad && !vacio){

            TipoRegistroTabla Zo = &th->ZonaOverflow[i];
        
            if(Zo->ocupado){

                //Verifica si el elemento se encuentra en la zona de overflow.
                if(Zo->datos->clave == elemento->clave){

                    printf("\nError al insertar elemento. Ya se encuentra ingresado.\n");
                    break;
                }

                i++;

            }
            else{

                vacio = true;
            }
            //Se encontro el primer espacio vacio y el elemento no esta en la zona de overflow, por lo tanto se agrega.
            if(vacio){

                Zo->datos = elemento;
                Zo->ocupado = true;   
            }
        }

    }

}


void th_eliminar(TablaHash th, int clave){

    //Transforma la clave con la funcion hash para obtener la posicion en la tabla y se posiciona en dicha posicion.
    int pos = th->hash_function(clave);
    TipoRegistroTabla registroTabla = &th->tabla[pos];

    //Si el elemento esta en la tabla lo libera.
    if((registroTabla->ocupado) && (registroTabla->datos->clave == clave)){

        registroTabla->datos = NULL;
        registroTabla->ocupado = false;
        return;
    }
    //Si no esta en la tabla, lo busca en la zona de overflow, y si esta ahi, lo libera.
    int i = 0;

    while(i < th->capacidad){

        TipoRegistroTabla Zo = &th->ZonaOverflow[i];

        if(Zo->ocupado && Zo->datos->clave == clave){

            Zo->datos = NULL;
            Zo->ocupado = false;
            break;
        }

        i++;
    }

}


TipoElemento th_recuperar(TablaHash th, int clave){

    //Transforma la clave con la funcion hash para obtener la posicion en la tabla y se posiciona en dicha posicion.
    int pos = th->hash_function(clave);
    TipoRegistroTabla registroTabla = &th->tabla[pos];

    //Si el elemento esta en la tabla lo retorna.
    if((registroTabla->ocupado) && (registroTabla->datos->clave == clave)){

        return registroTabla->datos;
    }
    
    //Si el elemento no esta en la tabla, lo busca en la la zona de overflow
    int i = 0;

    while(i < th->capacidad){

        TipoRegistroTabla Zo = &th->ZonaOverflow[i];
            
        if((Zo->ocupado) && (Zo->datos->clave == clave)){

            return Zo->datos;
        }

        i++;            

    }

    return NULL;

}


/**
 * @brief Funcion interna para mostrar los elementos de la tabla segun opcion de mostrar solo los elementos ocupados o mostrar todos los elementos incluidos los vacios.
 * 
 * @param th 
 */
void th_mostrar_interna(TablaHash th, bool soloOcupados){

    printf("\nContenido de la tabla hash:\n");

    //Recorre toda la tabla.
    for(int i = 0; i < th->capacidad; i++){

        TipoRegistroTabla registroTabla = &th->tabla[i];

        //Muestra los ocupados.
        if(registroTabla->ocupado){

            printf(" tabla[%i] [ocupado] %i", i, registroTabla->datos->clave);
            printf("\n");
        }
        //Si la condicion de mostrar elementos indica que muestre tambien los vacios los muestra.
        else if(!soloOcupados){

            printf(" tabla[%i] [ libre ]\n", i);
            
        }
    }

    printf("\nZona de Overflow:\n");

    //Recorre la Zona de Overflow.
    for(int i = 0; i < th->capacidad; i++){

        TipoRegistroTabla Zo = &th->ZonaOverflow[i];

        //Muestra los ocupados
        if(Zo->ocupado){

            printf(" zo[%i] [ocupado] %i", i, Zo->datos->clave);
            printf("\n");
        }
        //Muestra los libres si asi lo indica la condicion.
        else if(!soloOcupados){

            printf(" zo[%i] [ libre ]\n", i);
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