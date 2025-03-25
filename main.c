#include <stdio.h>
#include "funciones.h"

/*
Este programa permite realizar modificaciones basicas a imagenes en formato bmp.

ARGUMENTOS:

"nombre_de_la_imagen.bmp"                                   Ejemplo: perro.bmp

"--escala-de-grises"
"--espejar-horizontal"
"--espejar-vertical"
"--rotar-derecha"
"--rotar-izquierda"
"--invertir"
"--concatenar-vertical nombre_de_la_nueva_imagen.bmp"       Ejemplo: --concatenar-vertical gato.bmp (puede concatenarse a si misma)
"--concatenar-horizontal nombre_de_la_nueva_imagen.bmp"     Ejemplo: --concatenar-vertical gato.bmp (puede concatenarse a si misma)
"--aumentar-contraste= numero"                              Ejemplo: --aumentar-contraste=50 (aumenta el contraste en un 50%)
"--reducir-contraste= numero"
"--tonalidad-azul= numero"
"--tonalidad-verde= numero"
"--tonalidad-roja= numero"
"--recortar= numero"
"--achicar= numero"
*/

int main(int argc, char* argv[])
{
    return solucion(argc, argv);
}

