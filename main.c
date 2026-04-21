#include <stdio.h>
#include "pila.h"

int main(){
    APila p = apila_crear(10);
    apila_destruir(p);

    return 0;
}