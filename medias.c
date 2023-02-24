
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Función que calcula la media aritmetica de un conjunto de datos.
Parametros:
    datos: array de datos
    n: numero de datos
*/
float media_aritmetica(float datos[], int n){
    float suma = 0;
    for(int i = 0; i < n; i++){
        suma += datos[i];
    }
    return suma / n;
}
/*
Funcion que calcula la media armonica de un conjunto de datos.
Parametros:
    datos: array de datos
    n: numero de datos
*/
float media_armonica(float datos[], int n){
    float suma = 0;
    for(int i = 0; i < n; i++){
        suma += 1 / datos[i];
    }
    return n / suma;
}
/*
Función que calcula la media geometrica de un conjunto de datos.
Parametros:
    datos: array de datos
    n: numero de datos
Dado que la media geometrica consiste en calcular la raiz n-esima de la
multiplicacion de todos los datos, se utiliza la funcion pow() de la libreria
math.h
*/
float media_geometrica(float datos[], int n){
    float producto = 1;
    for(int i = 0; i < n; i++){
        producto *= datos[i];
    }
    float resultado = pow(producto, 1.0 / n);
    return resultado;
}
   


/*
Función main que recibe el número de argumentos pasados por la línea de comandos (argc) y un array 
de apuntadores (argv) con las siguientes cadenas:
-El nombre del programa
-Una letra que representa la media que se quiere calcular:
    A: media aritmetica
    H: media armonica
    G: media geometrica
-Los datos de entrada con los cuales debe calcular la media seleccionada.    
*/
int main(int arc, char *argv[]){
    //Se obtiene la letra que representa la media que se quiere calcular
    char letra = argv[1][0];
    //Se obtiene el numero de datos que se van a introducir, se resta 2 porque el primer argumento
    //es el nombre del programa y el segundo es la letra que representa la media que se quiere calcular
    int n = arc - 2;
    //Se crea un array de floats para almacenar los datos
    float datos[n];
    //Se recorren los datos introducidos por la linea de comandos y se almacenan en el array
    for(int i = 0; i < n; i++){
        datos[i] = atof(argv[i + 2]);
    }
    //Se calcula la media correspondiente
    float media;
    switch(letra){
        case 'A':
            media = media_aritmetica(datos, n);
            break;
        case 'H':
            media = media_armonica(datos, n);
            break;
        case 'G':
            media = media_geometrica(datos, n);
            break;
        default:
            printf("Error: La letra introducida no es valida \nDebe ser A, H o G\n");
            return 1;
    }
    //Se imprime el resultado
    printf("La media es: %f", media);

    return 0;
}
