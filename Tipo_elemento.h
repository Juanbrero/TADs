#ifndef TIPO_ELEMENTO
#define TIPO_ELEMENTO



// ---------------- ESTRUCTURA ----------------



struct TipoElementoRep{

    //Clave numerica de acceso al elemento
    int clave;
    //Contenido del elemento
    void *valor;

};
/**
 * @brief Puntero a la estructura TipoElementoRep.
 * 
 */
typedef struct TipoElementoRep *TipoElemento;



// ---------------- FUNCIONALIDADES ----------------



/**
 * @brief Crea un TipoElemento con la clave pasada como parametro sin contenido.
 * 
 * @param clave 
 * @return TipoElemento 
 */
TipoElemento te_crear(int clave);


/**
 * @brief Crea un TipoElemento con la clave y su contenido pasados por parametro.
 * 
 * @param clave 
 * @param valor 
 * @return TipoElemento 
 */
TipoElemento te_crear_con_valor(int clave, void* valor);


#endif //TIPO_ELEMENTO