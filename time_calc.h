#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

double measureTime(void (*functionToMeasure)(int[], int), int tableau[], int taille) {
    clock_t start, end;
    double res;

    start = clock(); // enregistrer le temps avant le départ

    functionToMeasure(tableau, taille);

    end = clock(); // enregistrer le temps aprés le départ
    
    res = (double)(end - start) / CLOCKS_PER_SEC;

    return res;
}
