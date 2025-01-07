/*Pedirle al usuario que ingrese los datos de un vector, ordenarlo ascendentemente, realizar una busqueda binaria. Tambien devolver 
la cantidad de numeros pares e impares del vector.*/

#include <stdio.h>
#include <stdbool.h>

#define MF 40
#define NO_ENCONTRADO -1

typedef int n_vector [MF];

void crear_vector(n_vector vector, int *tamanio){
    int i;
    printf("\nIngrese el tamanio de tu vector    ");
    scanf("\n%d", tamanio);
    for (i=0; i<*tamanio; i++){
            printf("Ingrese el valor numerico que se colocara en la posicion %i     ", i+1);
            scanf("%i", &vector[i]);
        }
    }

void ordenar_vector(n_vector vector, int tamanio){
    int i;
    int j;
    int aux;
    for (i=0; i<tamanio-1; i++){
        for (j=i+1; j<tamanio; j++){
            if (vector[i] > vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }

}

int busqueda_binaria(n_vector vector, int tamanio, int buscado){
    int inferior = 0;
    int superior = tamanio - 1;
    bool encontrado = false;
    int posicion;
    int mitad;

    while (!encontrado){
        if ((buscado > vector[superior]) || (buscado < vector [inferior])){
            encontrado = true;
            posicion = NO_ENCONTRADO;
        }
        else{
            mitad = (inferior + superior) / 2;
            if (vector[mitad] == buscado){
                encontrado = true;
                posicion = mitad;
            }
            else{
                if(buscado > vector [mitad]){
                    inferior = mitad + 1;
                }
                else{
                    superior = mitad - 1;
                }
            }
        }
    }
    return posicion;
}

void cantidad_pares_impares(n_vector vector, int tamanio, int *numero_pares, int *numeros_impares){
    int i;
    for (int i=0; i<tamanio; i++){
        if(vector[i]%2 == 0){
            (*numero_pares)++;
        }
        else{
            (*numeros_impares)++;
        }
    }
}

void main(){
    n_vector vector_usuario = {0};
    int tamanio_vector = 0;
    int numero_buscado = 9;
    int pares = 0;
    int impares = 0;
    int posicion_numero = 0;
    crear_vector(vector_usuario, &tamanio_vector);
    ordenar_vector(vector_usuario, tamanio_vector);
    posicion_numero = busqueda_binaria(vector_usuario, tamanio_vector, numero_buscado);
    if (posicion_numero == NO_ENCONTRADO){
        printf("\nNO SE HA ENCONTRADO EL NUMERO SOLICITADO");
    }
    else{
        printf("\n EL NUMERO SOLICITADO SE ENCUENTRA EN LA POSICION %i", posicion_numero+1);
    }
    cantidad_pares_impares(vector_usuario, tamanio_vector, &pares, &impares);
    printf("\n HAY UNA CANTIDAD DE %i NUMEROS PARES", pares);
    printf("\n HAY UNA CANTIDAD DE %i NUMEROS IMPARES", impares);

}