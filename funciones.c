#include "funciones.h"

int solucion(int argc, char* argv[])
{
    tArgumento argumento;
    int funcionUsada [15] = {0};
    char img [100];
    char imgConcaCH [100];
    char imgConcaCV [100];
    int posCH = 0;
    int posCV = 0;
    int j, cantCV = 0, cantCH = 0, lugarCV = 2, lugarCH = 2;
    int pos = posImagen (argc, argv); // busca la posicion de la imagen en los parametros enviados
    if (pos)
    {
        strcpy (img,argv [pos]);
    }

    else
    {
        puts ("No se ha mandado la imagen");
        return 0;
    }

    tDatosBMP datImg = datoImagen (img);  //copia los datos de la imagen en un struct

    if (datImg.flag)
    {
        for (int i = 1; i < argc; i++)
        {
            argumento = argumentoValido (argv [i]);
            switch (argumento.pos)
            {
            case 1:
            {
                //"escala de grises"
                if (funcionUsada [0] == 0)
                {
                    escalaDeGrises (datImg,img);
                    funcionUsada [0] = 1;
                }
                else
                    puts ("Escala de grises ya fue usado");
            }
            break;
            case 2:
            {
                //"espejar horizontal"
                if (funcionUsada [1] == 0)
                {
                    espejarHorizontal (datImg,img);
                    funcionUsada [1] = 1;
                }
                else
                    puts ("Espejar horizontal ya fue usado");
            }
            break;
            case 3:
            {
                //"espejar vertical"
                if (funcionUsada [2] == 0)
                {
                    espejarVertical (datImg,img);
                    funcionUsada [2] = 1;
                }
                else
                    puts ("Espejar vertical ya fue usado");
            }
            break;
            case 4:
            {
                //"rotar derecha"
                if (funcionUsada [3] == 0)
                {
                    rotarDerecha (datImg,img);
                    funcionUsada [3] = 1;
                }
                else
                    puts ("Rotar derecha ya fue usado");
            }
            break;
            case 5:
            {
                //"rotar izquierda"
                if (funcionUsada [4] == 0)
                {
                    rotarIzquierda (datImg,img);
                    funcionUsada [4] = 1;
                }
                else
                    puts ("Rotar izquierda ya fue usado");
            }
            break;
            case 6:
            {
                //"concatenar horizontal"
                if (funcionUsada [5] == 0)
                {
                    if (!cantCV)
                        posCH = posImagenConcatenar (argc, argv,lugarCH);
                    else
                        posCH = posImagenConcatenar (argc, argv,lugarCH + cantCV);
                    if (posCH)
                    {
                        strcpy (imgConcaCH,argv [posCH]);
                        tDatosBMP datImgCH = datoImagen (imgConcaCH);
                        if (datImgCH.flag)
                        {
                            concatenarHorizontal (datImg,img,datImgCH);
                            for (j = 0; j < datImgCH.header.alto; j++)
                            {
                                free(datImgCH.matriz[j]);
                            }
                            free(datImgCH.matriz);
                            cantCH++;
                            funcionUsada [5] = 1;
                        }
                        else
                        {
                            cantCH++;
                            lugarCH++;
                        }
                    }
                    else
                    {
                        puts ("No se ha mandado la segunda imagen");
                    }
                }
                else
                    puts ("Concatenar horizontal ya fue usado");
            }
            break;
            case 7:
            {
                //"concatenar vertical"
                if (funcionUsada [6] == 0)
                {
                    if (!cantCH)
                        posCV = posImagenConcatenar (argc, argv,lugarCV);
                    else
                        posCV = posImagenConcatenar (argc, argv,lugarCV + cantCH);
                    if (posCV)
                    {
                        strcpy (imgConcaCV,argv [posCV]);
                        tDatosBMP datImgCV = datoImagen (imgConcaCV);
                        if (datImgCV.flag)
                        {
                            concatenarVertical (datImg,img,datImgCV);
                            for (j = 0; j < datImgCV.header.alto; j++)
                            {
                                free(datImgCV.matriz[j]);
                            }
                            free(datImgCV.matriz);
                            cantCV++;
                            funcionUsada [6] = 1;
                        }
                        else
                        {
                            lugarCV++;
                            cantCV++;
                        }
                    }
                    else
                    {
                        puts ("No se ha mandado la segunda imagen");
                    }
                }
                else
                    puts ("Concatenar vertical ya fue usado");
            }
            break;
            case 8:
            {
                //"invertir"
                if (funcionUsada [7] == 0)
                {
                    invertir (datImg,img);
                    funcionUsada [7] = 1;
                }

                else
                    puts ("Comodin ya fue usado");
            }
            break;
            case 9:
            {
                //"aumentar contraste"
                if (funcionUsada [8] == 0)
                {
                    if (argumento.porcentaje < 100 && argumento.porcentaje > 0)
                    {
                        aumentarContraste (datImg,img,argumento.porcentaje);
                        funcionUsada [8] = 1;
                    }
                    else
                        puts ("Porcentaje fuera de los limites permitido");
                }

                else
                    puts ("Aumentar contraste ya fue usado");

            }
            break;
            case 10:
            {
                //"reducir contraste"
                if (funcionUsada [9] == 0)
                {
                    if (argumento.porcentaje < 100 && argumento.porcentaje > 0)
                    {
                        reducirContraste (datImg,img,argumento.porcentaje);
                        funcionUsada [9] = 1;
                    }
                    else
                        puts ("Porcentaje fuera de los limites permitido");
                }

                else
                    puts ("Reducir contraste ya fue usado");
            }
            break;
            case 11:
            {
                //"tonalidad azul"
                if (funcionUsada [10] == 0)
                {
                    if (argumento.porcentaje < 100 && argumento.porcentaje > 0)
                    {
                        tonalidadAzul (datImg,img,argumento.porcentaje);
                        funcionUsada [10] = 1;
                    }
                    else
                        puts ("Porcentaje fuera de los limites permitido");
                }

                else
                    puts ("Tonalidad azul ya fue usado");

            }
            break;
            case 12:
            {
                //tonalidad verde"
                if (funcionUsada [11] == 0)
                {
                    if (argumento.porcentaje < 100 && argumento.porcentaje > 0)
                    {
                        tonalidadVerde (datImg,img,argumento.porcentaje);
                        funcionUsada [11] = 1;
                    }
                    else
                        puts ("Porcentaje fuera de los limites permitido");
                }

                else
                    puts ("Tonalidad verde ya fue usado");
            }
            break;
            case 13:
            {
                //"tonalidad roja"
                if (funcionUsada [12] == 0)
                {
                    if (argumento.porcentaje < 100 && argumento.porcentaje > 0)
                    {
                        tonalidadRoja (datImg,img,argumento.porcentaje);
                        funcionUsada [12] = 1;
                    }
                    else
                        puts ("Porcentaje fuera de los limites permitido");
                }

                else
                    puts ("Tonalidad roja ya fue usado");
            }
            break;
            case 14:
            {
                //"recortar"
                if (funcionUsada [13] == 0)
                {
                    if (argumento.porcentaje < 100 && argumento.porcentaje > 0)
                    {
                        recortar (datImg,img,argumento.porcentaje);
                        funcionUsada [13] = 1;
                    }
                    else
                        puts ("Porcentaje fuera de los limites permitido");
                }

                else
                    puts ("Recortar ya fue usado");
            }
            break;
            case 15:
            {
                //"achicar"
                if (funcionUsada [14] == 0)
                {
                    if (argumento.porcentaje < 100 && argumento.porcentaje > 0)
                    {
                        achicar (datImg,img,argumento.porcentaje);
                        funcionUsada [14] = 1;
                    }
                    else
                        puts ("Porcentaje fuera de los limites permitido");
                }

                else
                    puts ("Achicar ya fue usado");
            }
            break;
            default:
            {
                if (i != pos && i != posCH && i != posCV)
                    puts ("Argumento invalido\n");
            }
            break;
            }
        }
        for (j = 0; j < datImg.header.alto; j++)
        {
            free(datImg.matriz[j]);
        }
        free(datImg.matriz);
    }

    return 0;
}

int posImagen (int argc, char* argv [])
{
    int i = 1;
    size_t largo;
    while (i < argc)
    {
        largo = strlen (argv [i]);
        if (largo > 4 && strncmp(argv [i]+ largo - 4, ".bmp", 4) == 0) //compara los ultimos 4 caracteres para verificar si es .bmp
            return i;                                                  // devuelve la pos
        i++;
    }
    return 0;                                                          //devuelve 0 si no encontro un parametro que sea la imagen
}

tArgumento argumentoValido (char argv[])
{
    tArgumento arg;
    arg.pos = 0;
    size_t longitud;
    const char* comandoValido [] = {"--escala-de-grises","--espejar-horizontal","--espejar-vertical","--rotar-derecha","--rotar-izquierda","--concatenar-horizontal","--concatenar-vertical","--invertir"};
    const char* comandoValidoParcial [] = {"--aumentar-contraste=","--reducir-contraste=","--tonalidad-azul=","--tonalidad-verde=","--tonalidad-roja=","--recortar=","--achicar="};

    for (int i = 0; i < sizeof (comandoValido)/sizeof (comandoValido [0]); i++)
    {
        if (strcmp (argv, comandoValido [i]) == 0)                   //compara con las opciones de comandoValido
            arg.pos = i + 1;                                         // agrega la posicion del parametro que luego se usa como dato para el switch
    }
    int c;
    char* p = NULL;
    if (!arg.pos)

        for (int a = 0; a < sizeof (comandoValidoParcial)/sizeof (comandoValidoParcial [0]); a++)
        {
            longitud = strlen (comandoValidoParcial [a]);
            if (strncmp (argv,comandoValidoParcial [a],longitud) == 0)          // compara si la primera parte es igual a algun dato de comandoValidoParcial
            {
                p = strchr (argv, '=');                                         //posiciona el puntero p en el caracter =
                c = atoi (p+1);                                                 //tomamos el numero en la variable c
                if (c)                                                          // verificamos si la funcion atoi funciono para poner los datos en arg
                {
                    arg.porcentaje = c;
                    arg.pos = a + 9;
                }
            }
        }
    return arg;
}

void copiarImagen (tPixel** matriz, tHeader header, tHeaderExt headerExt, char nombre [])
{
    unsigned char byte = 0;
    int i, j, a;
    FILE *pf = fopen(nombre, "wb");
    if(!pf)
    {
        puts("Error al crear la nueva imagen");
        return;
    }

    fwrite(&header, sizeof(tHeader), 1, pf);
    if (headerExt.existe)
        fwrite(&headerExt.headerExt, sizeof(headerExt.headerExt), 1, pf);

    int padding = (4 - (header.ancho * 3) % 4) % 4;

    for(i = 0; i < header.alto; i++)
    {
        for(j = 0; j < header.ancho; j++)
            fwrite(&matriz[i][j], sizeof(tPixel), 1, pf);
        if (padding)
            for (a = 0; a < padding; a++)
                fwrite (&byte, sizeof (byte),1,pf);
    }
    fclose (pf);
}

void tonalidadAzul (tDatosBMP datoBMP,char nombre[],int porcentaje)
{
    char nuevonombre [125]= "VARIABLE_tonalidad-azul_";
    strcat(nuevonombre,nombre);
    int i, j, a, azul;

    tPixel** copia = malloc(datoBMP.header.alto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.alto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.ancho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }
        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[i][a] = datoBMP.matriz[i][a];
            azul = copia[i][a].azul;
            azul = azul + (azul * porcentaje / 100);
            if (azul > 255)
                azul = 255;
            copia[i][a].azul = (unsigned char) azul;
        }
    }

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}

void tonalidadRoja (tDatosBMP datoBMP,char nombre[],int porcentaje)
{
    char nuevonombre [125]= "VARIABLE_tonalidad-roja_";
    strcat(nuevonombre,nombre);
    int i, j, a, rojo;

    tPixel** copia = malloc(datoBMP.header.alto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.alto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.ancho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }
        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[i][a] = datoBMP.matriz[i][a];
            rojo = copia[i][a].rojo;
            rojo = rojo + (rojo * porcentaje / 100);
            if (rojo > 255)
                rojo = 255;
            copia[i][a].rojo = (unsigned char) rojo;
        }
    }

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}

void tonalidadVerde (tDatosBMP datoBMP,char nombre[],int porcentaje)
{
    char nuevonombre [126]= "VARIABLE_tonalidad-verde_";
    strcat(nuevonombre,nombre);
    int i, j, a, verde;

    tPixel** copia = malloc(datoBMP.header.alto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.alto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.ancho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }
        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[i][a] = datoBMP.matriz[i][a];
            verde = copia[i][a].verde;
            verde = verde + (verde * porcentaje / 100);
            if (verde > 255)
                verde = 255;
            copia[i][a].verde = (unsigned char) verde;
        }
    }

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}

void aumentarContraste (tDatosBMP datoBMP,char nombre[],int porcentaje)
{
    char nuevonombre [129]= "VARIABLE_aumentar-contraste_";
    strcat(nuevonombre,nombre);
    float contraste = porcentaje * 2.55;
    float factor =  (259 * (contraste + 255)) / (255 * (259 - contraste));
    int i, j, a, verde, rojo, azul;

    tPixel** copia = malloc(datoBMP.header.alto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.alto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.ancho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }
        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[i][a] = datoBMP.matriz[i][a];
            verde = copia[i][a].verde;
            verde = factor * (verde - 128) + 128;
            if (verde > 255)
                verde = 255;
            if (verde < 0)
                verde = 0;
            copia[i][a].verde = (unsigned char) verde;

            rojo = copia[i][a].rojo;
            rojo = factor * (rojo - 128) + 128;
            if (rojo > 255)
                rojo = 255;
            if (rojo < 0)
                rojo = 0;
            copia[i][a].rojo = (unsigned char) rojo;

            azul = copia[i][a].azul;
            azul = factor * (azul - 128) + 128;
            if (azul > 255)
                azul = 255;
            if (azul < 0)
                azul = 0;
            copia[i][a].azul = (unsigned char) azul;
        }
    }

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}

void reducirContraste (tDatosBMP datoBMP,char nombre[],int porcentaje)
{
    char nuevonombre [129]= "VARIABLE_reducir-contraste_";
    strcat(nuevonombre,nombre);
    float contraste = porcentaje * (-2.55);
    float factor =  (259 * (contraste + 255)) / (255 * (259 - contraste));
    int i, j, a, verde, rojo, azul;

    tPixel** copia = malloc(datoBMP.header.alto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.alto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.ancho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }
        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[i][a] = datoBMP.matriz[i][a];
            verde = copia[i][a].verde;
            verde = factor * (verde - 128) + 128;
            if (verde > 255)
                verde = 255;
            else if (verde < 0)
                verde = 0;
            copia[i][a].verde = (unsigned char) verde;

            rojo = copia[i][a].rojo;
            rojo = factor * (rojo - 128) + 128;
            if (rojo > 255)
                rojo = 255;
            else if (rojo < 0)
                rojo = 0;
            copia[i][a].rojo = (unsigned char) rojo;

            azul = copia[i][a].azul;
            azul = factor * (azul - 128) + 128;
            if (azul > 255)
                azul = 255;
            else if (azul < 0)
                azul = 0;
            copia[i][a].azul = (unsigned char) azul;
        }
    }

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}

void rotarIzquierda (tDatosBMP datoBMP,char nombre[])
{
    char nuevonombre [126]= "VARIABLE_rotar-izquierda_";
    strcat(nuevonombre,nombre);
    int i, j, a;

    tPixel** copia = malloc(datoBMP.header.ancho * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.ancho; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.alto * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }
    }

    // Rellenar la nueva matriz con los píxeles rotados
    for ( i = 0; i < datoBMP.header.alto; i++)
    {
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[a][datoBMP.header.alto - i - 1] = datoBMP.matriz[i][a];
        }
    }

    int aux = datoBMP.header.ancho;
    datoBMP.header.ancho = datoBMP.header.alto;
    datoBMP.header.alto = aux;

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.ancho; j++)
    {
        free(copia[j]);
    }
    free(copia);
}


void rotarDerecha (tDatosBMP datoBMP,char nombre[])
{
    char nuevonombre [124]= "VARIABLE_rotar-derecha_";
    strcat(nuevonombre,nombre);
    int i, j, a;

    tPixel** copia = malloc(datoBMP.header.ancho * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.ancho; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.alto * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }
    }

    // Rellenar la nueva matriz con los píxeles rotados
    for ( i = 0; i < datoBMP.header.alto; i++)
    {
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[datoBMP.header.ancho - a - 1][i] = datoBMP.matriz[i][a];
        }
    }

    int aux = datoBMP.header.ancho;
    datoBMP.header.ancho = datoBMP.header.alto;
    datoBMP.header.alto = aux;

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.ancho; j++)
    {
        free(copia[j]);
    }
    free(copia);
}


int posImagenConcatenar (int argc, char* argv [], int ordinal)
{
    int i = 1,j = 1;
    size_t largo;
    while (i < argc)
    {
        largo = strlen (argv [i]);
        if (largo > 4 && strncmp(argv [i]+ largo - 4, ".bmp", 4) == 0)
        {
            if (j == ordinal )
                return i;
            else
                j++;
        }

        i++;
    }
    return 0;
}

void concatenarHorizontal (tDatosBMP datoBMP,char nombre[],tDatosBMP datoConcaBMP)
{
    char nuevonombre [132]= "VARIABLE_concatenar-horizontal_";
    strcat(nuevonombre,nombre);
    int nuevoAncho, nuevoAlto, i, j, a;

    nuevoAncho = datoBMP.header.ancho + datoConcaBMP.header.ancho;
    if (datoBMP.header.alto >= datoConcaBMP.header.alto)
        nuevoAlto = datoBMP.header.alto;
    else
        nuevoAlto = datoConcaBMP.header.alto;

    tPixel** copia = malloc(nuevoAlto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < nuevoAlto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(nuevoAncho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }

        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < nuevoAncho; a++)
        {
            if (a < datoBMP.header.ancho)
            {
                if (i < datoBMP.header.alto)
                    copia[i][a] = datoBMP.matriz[i][a];
                else
                {
                    copia [i][a].azul = (unsigned char) 107;
                    copia [i][a].verde = (unsigned char) 134;
                    copia [i][a].rojo = (unsigned char) 120;
                }
            }
            else
            {
                if (i < datoConcaBMP.header.alto)
                    copia[i][a] = datoConcaBMP.matriz[i][a-datoBMP.header.ancho];
                else
                {
                    copia [i][a].azul = (unsigned char) 107;
                    copia [i][a].verde = (unsigned char) 134;
                    copia [i][a].rojo = (unsigned char) 120;
                }
            }
        }
    }

    datoConcaBMP.header.ancho = nuevoAncho;
    datoConcaBMP.header.alto = nuevoAlto;

    if (datoConcaBMP.headerExt.existe)
        datoConcaBMP.header.tamFichero = sizeof (datoConcaBMP.header) + sizeof (datoConcaBMP.headerExt.headerExt) + (datoConcaBMP.header.alto * datoConcaBMP.header.ancho * 3);
    else
        datoConcaBMP.header.tamFichero = sizeof (datoConcaBMP.header) + (datoConcaBMP.header.alto * datoConcaBMP.header.ancho * 3);

    datoConcaBMP.header.tamImagen = datoConcaBMP.header.alto * datoConcaBMP.header.ancho * 3;

    copiarImagen (copia,datoConcaBMP.header,datoConcaBMP.headerExt,nuevonombre);

    for (j = 0; j < datoConcaBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}


void concatenarVertical (tDatosBMP datoBMP,char nombre[],tDatosBMP datoConcaBMP)
{
    char nuevonombre [130]= "VARIABLE_concatenar-vertical_";
    strcat(nuevonombre,nombre);
    int nuevoAncho, nuevoAlto, i, j, a;

    nuevoAlto = datoBMP.header.alto + datoConcaBMP.header.alto;
    if (datoBMP.header.ancho >= datoConcaBMP.header.ancho)
        nuevoAncho = datoBMP.header.ancho;
    else
        nuevoAncho = datoConcaBMP.header.ancho;

    tPixel** copia = malloc(nuevoAlto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < nuevoAlto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(nuevoAncho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }

        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < nuevoAncho; a++)
        {
            if (i < datoBMP.header.alto)
            {
                if (a < datoBMP.header.ancho)
                    copia[i][a] = datoBMP.matriz[i][a];
                else
                {
                    copia [i][a].azul = (unsigned char) 107;
                    copia [i][a].verde = (unsigned char) 134;
                    copia [i][a].rojo = (unsigned char) 120;
                }
            }
            else
            {
                if (a < datoConcaBMP.header.ancho)
                    copia[i][a] = datoConcaBMP.matriz[i-datoBMP.header.alto][a];
                else
                {
                    copia [i][a].azul = (unsigned char) 107;
                    copia [i][a].verde = (unsigned char) 134;
                    copia [i][a].rojo = (unsigned char) 120;
                }
            }
        }
    }

    datoConcaBMP.header.ancho = nuevoAncho;
    datoConcaBMP.header.alto = nuevoAlto;

    if (datoConcaBMP.headerExt.existe)
        datoConcaBMP.header.tamFichero = sizeof (datoConcaBMP.header) + sizeof (datoConcaBMP.headerExt.headerExt) + (datoConcaBMP.header.alto * datoConcaBMP.header.ancho * 3);
    else
        datoConcaBMP.header.tamFichero = sizeof (datoConcaBMP.header) + (datoConcaBMP.header.alto * datoConcaBMP.header.ancho * 3);

    datoConcaBMP.header.tamImagen = datoConcaBMP.header.alto * datoConcaBMP.header.ancho * 3;

    copiarImagen (copia,datoConcaBMP.header,datoConcaBMP.headerExt,nuevonombre);

    for (j = 0; j < datoConcaBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}

tDatosBMP datoImagen (const char nombre [])
{
    tDatosBMP datosBMP = {0};

    FILE *pf = fopen(nombre, "rb");
    if(!pf)
    {
        puts("Error al abrir imagen");
        datosBMP.flag = false;
        return datosBMP;
    }
    fread(&datosBMP.header, sizeof(tHeader), 1, pf);

    int offsetArchivo = datosBMP.header.offset - sizeof (tHeader);

    if(offsetArchivo)
    {
        fread(&datosBMP.headerExt.headerExt, sizeof(datosBMP.headerExt.headerExt), 1, pf);
        datosBMP.headerExt.existe = true;
    }

    else
        datosBMP.headerExt.existe = false;

    int padding = (4 - (datosBMP.header.ancho * 3) % 4) % 4;

    datosBMP.matriz = (tPixel**) malloc (datosBMP.header.alto * sizeof (tPixel*));
    if (datosBMP.matriz == NULL)
    {
        puts ("Error al asignar memoria");
        datosBMP.flag = false;
        fclose (pf);
        return datosBMP;
    }

    for (int a = 0; a < datosBMP.header.alto; a++)
    {
        datosBMP.matriz [a] = (tPixel*) malloc (datosBMP.header.ancho * sizeof (tPixel));
        if (datosBMP.matriz [a] == NULL)
        {
            puts ("Error al asignar memoria");
            datosBMP.flag = false;
            for (int b = 0; b < a; b++)
                free (datosBMP.matriz [b]);
            free (datosBMP.matriz);
            fclose (pf);
            return datosBMP;
        }
    }


    for (int i=0; i < datosBMP.header.alto; i++)
    {
        for (int j = 0; j < datosBMP.header.ancho; j++)
            fread (&datosBMP.matriz [i][j],sizeof (tPixel), 1, pf);
        fseek (pf, padding, SEEK_CUR);
    }
    datosBMP.flag = true;
    fclose (pf);

    return datosBMP;
}


void achicar (tDatosBMP datoBMP,char nombre[],int porcentaje)
{
    char nuevonombre [118]= "VARIABLE_achicar_";
    strcat(nuevonombre,nombre);
    int i, j, a, x, y;

    float porAchicar = (float)porcentaje / 100;
    int nuevoAlto = (int) (datoBMP.header.alto * porAchicar);
    int nuevoAncho = (int) (datoBMP.header.ancho * porAchicar);

    tPixel** copia = malloc(nuevoAlto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }

    for (i = 0; i < nuevoAlto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(nuevoAncho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }

        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < nuevoAncho; a++)
        {
            x = (int)(i * ((float)datoBMP.header.alto / nuevoAlto));
            y = (int)(a * ((float)datoBMP.header.ancho / nuevoAncho));
            copia[i][a] = datoBMP.matriz[x][y];
        }
    }

    datoBMP.header.alto = nuevoAlto;
    datoBMP.header.ancho = nuevoAncho;

    if (datoBMP.headerExt.existe)
        datoBMP.header.tamFichero = sizeof (datoBMP.header) + sizeof (datoBMP.headerExt.headerExt) + (datoBMP.header.alto * datoBMP.header.ancho * 3);
    else
        datoBMP.header.tamFichero = sizeof (datoBMP.header) + (datoBMP.header.alto * datoBMP.header.ancho * 3);

    datoBMP.header.tamImagen = datoBMP.header.alto * datoBMP.header.ancho * 3;

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}

void recortar (tDatosBMP datoBMP,char nombre[],int porcentaje)
{
    char nuevonombre [119]= "VARIABLE_recortar_";
    strcat(nuevonombre,nombre);
    int i, j, a;

    float porAchicar = (float) porcentaje / 100;
    int nuevoAlto = (int) (datoBMP.header.alto * porAchicar);
    int nuevoAncho = (int) (datoBMP.header.ancho * porAchicar);

    tPixel** copia = malloc(nuevoAlto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < nuevoAlto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(nuevoAncho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }

        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < nuevoAncho; a++)
        {
            copia[i][a] = datoBMP.matriz[i][a];
        }
    }

    datoBMP.header.alto = nuevoAlto;
    datoBMP.header.ancho = nuevoAncho;

    if (datoBMP.headerExt.existe)
        datoBMP.header.tamFichero = sizeof (datoBMP.header) + sizeof (datoBMP.headerExt.headerExt) + (datoBMP.header.alto * datoBMP.header.ancho * 3);
    else
        datoBMP.header.tamFichero = sizeof (datoBMP.header) + (datoBMP.header.alto * datoBMP.header.ancho * 3);

    datoBMP.header.tamImagen = datoBMP.header.alto * datoBMP.header.ancho * 3;

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}


void espejarHorizontal (tDatosBMP datoBMP,char nombre[])
{
    char nuevonombre [129]= "VARIABLE_espejar-horizontal_";
    strcat(nuevonombre,nombre);
    int i, j, a;

    tPixel** copia = malloc(datoBMP.header.alto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.alto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.ancho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }

        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[i][a] = datoBMP.matriz[i][datoBMP.header.ancho - a - 1];
        }
    }

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}


void espejarVertical (tDatosBMP datoBMP,char nombre[])
{
    char nuevonombre [127]= "VARIABLE_espejar-vertical_";
    strcat(nuevonombre,nombre);
    int i, j, a;

    tPixel** copia = malloc(datoBMP.header.alto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }

    for (i = 0; i < datoBMP.header.alto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.ancho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }

        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[i][a] = datoBMP.matriz[datoBMP.header.alto - i - 1][a];
        }
    }

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}


void escalaDeGrises (tDatosBMP datoBMP,char nombre[])
{
    char nuevonombre [127]= "VARIABLE_escala-de-grises_";
    strcat(nuevonombre,nombre);
    int i, j, a, promGris;

    tPixel** copia = malloc(datoBMP.header.alto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.alto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.ancho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }

        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[i][a] = datoBMP.matriz[i][a];
            promGris = (int) ((copia[i][a].azul + copia[i][a].rojo + copia[i][a].verde) / 3);
            copia[i][a].azul = (unsigned char) promGris;
            copia[i][a].rojo = (unsigned char) promGris;
            copia[i][a].verde = (unsigned char) promGris;
        }
    }

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}


void invertir (tDatosBMP datoBMP,char nombre[])
{
    char nuevonombre [118]= "VARIABLE_invertir_";
    strcat(nuevonombre,nombre);
    int i, j, a;

    tPixel** copia = malloc(datoBMP.header.alto * sizeof(tPixel*));
    if (copia == NULL)
    {
        puts("Error al asignar memoria");
        return;
    }
    for (i = 0; i < datoBMP.header.alto; i++)
    {
        // Reservar memoria para cada fila
        copia[i] = malloc(datoBMP.header.ancho * sizeof(tPixel));
        if (copia[i] == NULL)
        {
            puts("Error al asignar memoria");
            // Liberar la memoria previamente asignada si falla
            for (j = 0; j < i; j++)
            {
                free(copia[j]);
            }
            free(copia);
            return;
        }

        // Copiar los datos de la fila original a la fila de copia
        for (a = 0; a < datoBMP.header.ancho; a++)
        {
            copia[i][a] = datoBMP.matriz[i][a];
            copia[i][a].azul = 255 - copia[i][a].azul;
            copia[i][a].rojo = 255 - copia[i][a].rojo;
            copia[i][a].verde = 255 - copia[i][a].verde;
        }
    }

    copiarImagen (copia,datoBMP.header,datoBMP.headerExt,nuevonombre);

    for (j = 0; j < datoBMP.header.alto; j++)
    {
        free(copia[j]);
    }
    free(copia);
}

