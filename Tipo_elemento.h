#ifndef TIPO_ELEMENTO
#define TIPO_ELEMENTO


struct TipoElementoRep;
/**
 * @brief Puntero a la estructura TipoElementoRep.
 * 
 */
typedef struct TipoElementoRep *TipoElemento;


/**
 * @brief Crea un TipoElemento con la clave pasada como parametro sin contenido.
 * 
 * @param clave 
 * @return TipoElemento 
 */
TipoElemento te_crear(void* clave);

/**
 * @brief Crea un TipoElemento con la clave y su contenido pasados por parametro.
 * 
 * @param clave 
 * @param valor 
 * @return TipoElemento 
 */
TipoElemento te_crear_con_valor(void* clave, void* valor);


#endif //TIPO_ELEMENTO