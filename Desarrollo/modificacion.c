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
        
        close (descr[LEER]);
        write (descr[ESCRIBIR], frase, strlen(frase));
        close (descr[ESCRIBIR]);
        
    }else{
        
        close (descr[ESCRIBIR]);
        bytesleidos = read (descr[LEER], mensaje, 100);
        mensaje[bytesleidos]='\0';
        printf ("Bytes leidos: %d\n", bytesleidos);
        printf ("Mensaje del Padre: %s\n", mensaje);
        close (descr[LEER]);
        
    }
    return 0;
    
}
