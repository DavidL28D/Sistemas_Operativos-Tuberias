#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define LEER 0
#define ESCRIBIR 1

int main () {
    
    int descr[2]; /* Descriptores de E y S de la tubería */
    int bytesleidos;
    char mensaje[100], *frase="EL padre prueba al hijo si la transferencia es buena.";
    
    printf ("Ejemplo de tubería entre padre e hijo.\n");
    pipe (descr);
    
    if (fork () == 0) {
        //cierra el descriptor de lectura
        close (descr[LEER]);
        // escribe en el pipe la frase
        write (descr[ESCRIBIR], frase, strlen(frase));
        //cierra el descriptor de escritura
        close (descr[ESCRIBIR]);
        
    }else{
        //Cierra el descriptor de escritura
        close (descr[ESCRIBIR]);
        //lee del pipe y guarda en mensaje
        bytesleidos = read (descr[LEER], mensaje, 100);
        mensaje[bytesleidos]='\0';

        printf ("Bytes leidos: %d\n", bytesleidos);
        printf ("Mensaje del Padre: %s\n", mensaje);
        //cierra el descriptor de lectura
        close (descr[LEER]);
        
    }
    return 0;
    
}
