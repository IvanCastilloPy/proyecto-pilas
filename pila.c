#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
/*Holaprobando*/
/*Crea una pila implementada con un arreglo dinamico, donde se inicializa con 
 un tamanho inicial, pero se redimensiona cuando se alcanza el limite de almacenamiento
 del arreglo. Esto es, crear un nuevo arreglo mas grande y referenciarlo a la pila.
 Retorna NULL si algun error ocurre durante el proceso creacion*/
    
APila apila_crear(int tamInicial){
    /*Agregue su codigo de implementacion aqui*/
    APila p;
    p = (APila) malloc (sizeof(_APila));
    if (p == NULL) return NULL;
    
    void** elem = (void*) malloc(sizeof(void*) * tamInicial);
    if (elem == NULL)
    {
        free(p);
        return NULL;
    }
    
    p->arr = elem;
    p->tam = tamInicial;
    p->sp = 0;

	return p;
}

/* Agrega un elemento a la pila (utilizando el metodo LIFO), el parametro void* valor significa que pasamos la direccion
 * del dato a guardar. 
 * Retorna ok si no hubo errores. Si hubo algun error la pila no es modificada
 */
BOOLEAN apila_push(APila p, void* valor){
    /*Agregue su codigo de implementacion aqui*/
    return OK;
}
/* Saca un elemento de la pila (utilizando el metodo LIFO), el parametro void** retval significa que pasamos la direccion
 * del puntero del dato a guardar.(puntero a puntero).
 * Y asigna el dato sacado en el parametro retval (paso por referencia);
 * Retorna ok si no hubo errores. Si hubo algun error la pila no es modificada
 */
BOOLEAN apila_pop(APila p, void** retval){
    /*Agregue su codigo de implementacion aqui*/
    return OK;
}
/* Muestra el elemento que esta en la cima de la pila (utilizando el metodo LIFO), el parametro void** retval significa que pasamos la direccion
 * del puntero del dato a guardar.(puntero a puntero).
 * Y asigna el dato de la cima en el parametro retval (paso por referencia);
 * Retorna ok si no hubo errores. Si hubo algun error la pila no es modificada
 */
BOOLEAN apila_top(APila p, void** retval){
    /*Agregue su codigo de implementacion aqui*/
    return OK;
}

/* Devuelve TRUE si la pila esta vacia. sino devuelve false, 
   Si hay error devuelve TRUE (para evitar portlemas de bucles infinitos en nuestro programa);
 */
BOOLEAN apila_isEmpty(APila p){
    /*Agregue su codigo de implementacion aqui*/
    return TRUE;
}
/* Elimina la pila.
    verificar que los datos sean eliminados correctamente.!
 */
BOOLEAN apila_destruir(APila p){
    if (p == NULL) return ERROR;
    free(p->arr);
    free(p);
    
    return OK;
}

/*Implementacion de Pila con lista ligada*/

/* Crea una pila implementada con listas ligadas.
 * 
 *Tip, no hay requisito de saber el tamanho de la pila. se puede usar un flag de vacio|novacio
 *para mantener la funcion isEmpty mas sencillo.
 * Retorna NULL si hubo errores.
 */

LPila lpila_crear(){
    /*Agregue su codigo de implementacion aqui*/
	LPila p;

    p = NULL;
    return p;
}
/* Agrega un elemento a la pila (utilizando el metodo LIFO), el parametro void* valor significa que pasamos la direccion
 * del dato a guardar. 
 * Retorna ok si no hubo errores. Si hubo algun error la pila no es modificada
 */
BOOLEAN lpila_push(LPila p, void* valor){
    /*Agregue su codigo de implementacion aqui*/

    Nodo * nodo ;
    nodo = (Nodo*)malloc(sizeof(Nodo));
    if(nodo == NULL) return ERROR;
    nodo->valor = valor;
    nodo->sig = NULL;
    p = nodo;
    return OK;

}
/* Saca un elemento de la pila (utilizando el metodo LIFO), el parametro void** retval significa que pasamos la direccion
 * del puntero del dato a guardar.(puntero a puntero).
 * Y asigna el dato sacado en el parametro retval (paso por referencia);
 * Retorna ok si no hubo errores. Si hubo algun error la pila no es modificada
 */
BOOLEAN lpila_pop(LPila p, void** valor){
     /*Agregue su codigo de implementacion aqui*/

    Nodo * aux = p;
    *valor = p->valor;
    
    p = aux->sig;
    free(aux);
    return OK;
}
/* Muestra el elemento que esta en la cima de la pila (utilizando el metodo LIFO), el parametro void** retval significa que pasamos la direccion
 * del puntero del dato a guardar.(puntero a puntero).
 * Y asigna el dato de la cima en el parametro retval (paso por referencia);
 * Retorna ok si no hubo errores. Si hubo algun error la pila no es modificada
 */
BOOLEAN lpila_top(LPila p, void** valor){
     /*Agregue su codigo de implementacion aqui*/
    * valor = p->valor;
    printf("%d",*(int *)&p->valor);
    return OK;
}
/* Devuelve TRUE si la pila esta vacia. sino devuelve false, 
   Si hay error devuelve TRUE (para evitar portlemas de bucles infinitos en nuestro programa);
 */
BOOLEAN lpila_isEmpty(LPila p){
    /*Agregue su codigo de implementacion aqui*/
    if(p == NULL) return  TRUE;
    else return FALSE;
    return OK;
}
/* Elimina la pila.
 * Verificar que la lista sea borrada correctamente!
 */
BOOLEAN lpila_destruir(LPila p){
    /*Agregue su codigo de implementacion aqui*/
    Nodo * aux = p;
    while(aux != NULL){
        free(aux);
        aux = aux->sig; 
    }
    free(p);
    return OK;
}