#include <stdio.h>
int busquedalineal(int arreglo[], int tamano, int valor);
int busquedaBinaria(int arreglo[], int tamano, int valor);
int busquedabinariarecurs(int arreglo[], int izq, int der, int valor);

int main() {
    
    int numero;
    printf("Ingrese un valor entero \n");
    scanf("%i",&numero);

    int arreglo[] = {2,4,6,23,56,79};

    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    int resultadoLineal = busquedalineal(arreglo, tamano, numero);
    if (resultadoLineal != -1) {
        printf("Búsqueda lineal: El valor %d se encuentra en la posición %d del arreglo.\n", numero, resultadoLineal);
    } else {
        printf("Búsqueda lineal: El valor %d no fue encontrado en el arreglo.\n", numero);
    }

    int resultadobinaria = busquedaBinaria(arreglo, tamano, numero);
    if (resultadobinaria != -1) {
        printf("Búsqueda binaria iterativa: El valor %d se encuentra en la posición %d del arreglo.\n", numero, resultadobinaria);
    } else {
        printf("Búsqueda binaria iterativa: El valor %d no fue encontrado en el arreglo.\n", numero);
    }

    int resultadobr = busquedabinariarecurs(arreglo, 0, tamano - 1, numero);
    if (resultadobr != -1) {
        printf("Búsqueda binaria recursiva: El valor %d se encuentra en la posición %d del arreglo.\n", numero, resultadobr);
    } else {
        printf("Búsqueda binaria recursiva: El valor %d no fue encontrado en el arreglo.\n", numero);
    }

    return 0;
}

//Definición de la función que realiza la búsqueda lineal
int busquedalineal(int arreglo[], int tamano, int valor) {
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == valor) {
            return i; // Retornar la posición si el valor es encontrado
        }
    }
    return -1; // Retornar -1 si el valor no es encontrado
}

//Definicion de la funcion que realiza la busqueda binaria
int busquedaBinaria(int arreglo[], int tamano, int valor) {
    int izquierda = 0;
    int derecha = tamano - 1;
    
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        
        // Verificar si el valor está en el medio
        if (arreglo[medio] == valor) {
            return medio;
        }
        
        // Si el valor es mayor, ignorar la mitad izquierda
        if (arreglo[medio] < valor) {
            izquierda = medio + 1;
        }
        // Si el valor es menor, ignorar la mitad derecha
        else {
            derecha = medio - 1;
        }
    }
    
    // Retornar -1 si el valor no es encontrado
    return -1;
}

//Definicion de la funcion que realiza la busqueda binaria recursiva
int busquedabinariarecurs(int arreglo[], int izq, int der, int valor) {
    if (izq <= der) {
        int medio = izq + (der - izq) / 2;
        
        if (arreglo[medio] == valor) {
            return medio;
        }
        
        if (arreglo[medio] < valor) {
            return busquedabinariarecurs(arreglo, medio + 1, der, valor);
        }
        else {
            return busquedabinariarecurs(arreglo, izq, medio - 1, valor);
        }
    }
    
    // Retornar -1 si el valor no es encontrado
    return -1;
}