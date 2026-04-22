#include <stdio.h>
#include "pila.h"

int main(){
    APila p = apila_crear(1);

    apila_destruir(p);

    return 0;
}