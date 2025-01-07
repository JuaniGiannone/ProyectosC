/*Escribir una función para validar una nueva clave de acceso. 
La función deberá recibir una cadena de caracteres, que contendrá la clave 
candidata, que ya fue ingresada previamente por el usuario. 
Devolverá true o false, dependiendo de si cumple o no, con las siguientes 
condiciones: - La clave debe estar formada únicamente por, entre 6 y 12 caracteres 
numéricos - La cantidad de dígitos pares debe ser mayor a la de los impares. 
A los sumo debe recorrer una vez la cadena. 
Evite realizar ciclos innecesarios.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXIMO 30

typedef char n_cadena[MAXIMO];

bool cantidad_numeros(n_cadena cadena){
    int i;
    int pares = 0;
    int impares = 0;
    int len = strlen(cadena);
    bool validez = false;
    if (len >= 6 && len<= 12){
        for (i=0; cadena[i] != '\0'; i++){
            if (cadena[i] >= '0' && cadena[i] <= '9'){
                if (cadena[i]%2==0){
                    pares++;  }
                else{
                    impares++;}}}
        if (pares > impares){
            validez = true;       }         
    }
    return validez;            
}

void main(){
    n_cadena cadena = "textoej142";
    if (cantidad_numeros(cadena)){
        printf("La contrasenia ha sido registada correctamente");
    }
    else{
        printf("La contrasenia no ha podido ser registada");
    }
}