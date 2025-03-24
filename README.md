# BMP-Manipulator
Un programa en C que permite realizar modificaciones a imagenes en formato bmp.


## FUNCIONAMIENTO

El programa se invoca por consola y se le pasan por argumentos las modificaciones a realizar en la imagen. Se creara una imagen en la misma carpeta y con el prefijo "VARIABLE" para distinguirla de la original, ademas de añadir en el titulo la modificacion realizada.

EJEMPLO: C:\Users\Bmp> bmp.exe sample.bmp --espejar-vertical

## FUNCIONALIDADES INCLUIDAS

A continuacion se detallan los argumentos disponibles, junto con su forma de uso y resultado obtenido:

### Espejar

**Vertical**: Rota la imagen 180°. (--espejar-vertical)

**Horizontal**: Espeja la imagen de manera horizontal. (--espejar-horizontal)


### Escala de grises
  Convierte la imagen en escala de grises. (--escala-de-grises)

### Rotar

**Derecha**: Gira la imagen 90° hacia la derecha. (--rotar-derecha)

**Izquierda**: Gira la imagen 90° hacia la izquierda. (--rotar-izquierda)

### Concatenar

**Vertical**: Se le envia un archivo bmp adicional y crea una unica imagen combinando ambos, dejando la segunda imagen arriba. En el caso de ser de resoluciones distintas, se rellena el espacio con un color. (--concatenar-vertical nombre_imagen.bmp)

**Horizontal**: Igual que vertical. La segunda imagen se ubica a la derecha.  (--concatenar-horizontal nombre_imagen.bmp)


### Invertir
  Invierte los colores de la imagen (--invertir)

### Aumentar/Reducir contraste
  Se le envia tambien un numero para indicar el porcentaje de incremento o disminucion y realiza lo propio con el contraste de la imagen. (--aumentar-contraste=numero)/(--reducir-contraste=numero)

### Tonalidad azul/roja/verde
  Se le envia un un numero y aumenta en ese porcentaje la tonalidad deseada. (--tonalidad-azul=numero)/(--tonalidad-roja=numero)/(--tonalidad-verde=numero)


### Recortar
  Recorta al X% la imagen, sin conservar la informacion. (--recortar=numero)


### Achicar
  Tambien recorta la imagen al X%, pero conserva la informacion, aunque a menor resolucion. (--achicar=numero)
