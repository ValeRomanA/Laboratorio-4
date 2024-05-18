#include <stdio.h>

//Funcion para encontrar el valor minimo
int encontrarminimo(int arreglo[], int tamano) {
    int minimo = arreglo[0]; 

    for (int i = 1; i < tamano; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }

    return minimo; 
}

//Funcion para encontrar el valor maximo
int encontrarmaximo(int arreglo[], int tamano) {
    int maximo = arreglo[0];
    for (int i = 1; i < tamano; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }
    return maximo;
}

//Funcion para encontrar el valor Min y Max y almacenarlos 
void punteros(int *arreglo, int *minimo, int *maximo, int tamano) {
    *minimo = *maximo = arreglo[0];
    for (int i = 1; i < tamano; i++) {
        if (arreglo[i] < *minimo) {
            *minimo = arreglo[i];
        } else if (arreglo[i] > *maximo) {
            *maximo = arreglo[i];
        }
    }
}

int main() {
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    int min = encontrarminimo(arreglo, tamano);
    int max = encontrarmaximo(arreglo, tamano);
    printf("Mínimo: %d\n", min);
    printf("Máximo: %d\n", max);

    int min_puntero, max_puntero;
    punteros(arreglo, &min_puntero, &max_puntero, tamano);
    printf("Mínimo (puntero): %d\n", min_puntero);
    printf("Máximo (puntero): %d\n", max_puntero);

    return 0;
}