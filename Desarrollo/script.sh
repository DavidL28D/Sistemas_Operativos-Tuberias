#!/bin/bash

if [ $# -ne 0 ]; then

    if [ $# -gt 1 ]; then
        echo "Cantidad de parametros incorrecto";
    else
        # El script recibe un parametro (ordena todos los archivos de manera descendente aplicando el filtro grep)
        echo "Ordenando archivos de manera descendente, aplicando grep"
        echo $(ls | grep $1 | sort -r);
    fi
 
else

    # El script no recibe parametros (ordena todos los archivos de manera descendente)
    echo "Ordenando todos los archivos de manera descendente"
    echo $(ls | sort -r)

fi