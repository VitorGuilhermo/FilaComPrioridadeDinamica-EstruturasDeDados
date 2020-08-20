#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include "TADFilaPrioridadeDinamica.h"

int main(){
    TpDescritor descritor;

    inicializar(descritor);

    inserir(descritor, 'A', 1);
    inserir(descritor, 'B', 2);
    inserir(descritor, 'C', 2);
    inserir(descritor, 'D', 3);

    retirar(descritor);

    exibir(descritor);
}
