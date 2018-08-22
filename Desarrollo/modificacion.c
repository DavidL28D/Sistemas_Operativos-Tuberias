#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define LEER 0
#define ESCRIBIR 1

int main () {
    
    int descr[2],descr2[2]; /* Descriptores de E y S de la tubería */
    int bytesleidos;
    char mensaje[100], *frase="EL padre leyó lo que el hijo escribió en la tuberia.";
    char *frase2="El hijo leyó lo que el padre escribió en la tubería.";
    printf ("Comunicacion en ambos sentidos con tuberias.\n");
    pipe (descr);
    pipe (descr2);
    
    if (fork () == 0) {
        
        close (descr[LEER]);
        write (descr[ESCRIBIR], frase, strlen(frase));
        close (descr[ESCRIBIR]);

        close (descr2[ESCRIBIR]);
        bytesleidos = read (descr2[LEER], mensaje, 100);
        mensaje[bytesleidos]='\0';
        printf("Bytes leidos: %d\n",bytesleidos );
        printf("Mensaje del hijo: %s\n",mensaje );
        close (descr2[LEER]);
        
    }else{

        close (descr2[LEER]);
        write (descr2[ESCRIBIR], frase2, strlen(frase2));
        close (descr2[ESCRIBIR]);

        close (descr[ESCRIBIR]);
        bytesleidos = read (descr[LEER], mensaje, 100);
        mensaje[bytesleidos]='\0';
        printf ("Bytes leidos: %d\n", bytesleidos);
        printf ("Mensaje del Padre: %s\n", mensaje);
        close (descr[LEER]);
        
    }
    return 0;
    
}
