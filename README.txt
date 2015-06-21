MARCHIVO(1)                                          COMANDOS DE USUARIO


NOMBRE
       mArchivo - Componer Archivos

SINOPSIS
       mArchivo [-d DIRECTORIO] <N> <M> <SALIDA>.


DESCRIPCION
       Crea un archivo SALIDA que contiene el cuento final.
       El cuento final consta de una composicion de poesia aleatoria
       donde se escogeran n procesos que trabajaran m archivos cada uno.

       DIRECTORIO Especifica undirectorio donde se encuentran los 10
                  directorios de archivos de texto.
       Ejemplo : ./miDirectorio/
                 ./miDirectorio/carpeta1/
       (Note que la ruta termina con / )

       N Especifica el valor N que el proceso padre debe considerar.

       M Especifica el valor M que los procesos hijos deben considerar.

AUTOR
       Escrito por Luis Colorado y Patricia Valencia.

IMPORTANTE
       Para la implementacion de este proyecto se tomaron ciertas
       decisiones:
              *      Si un directorio tiene m archivos, 
                     donde 1 <= m <= 20, entonces dicho
                     directorio tendra archivos del 1 al m
                     Ejemplo: m = 4 => 1.txt, 2.txt,3.txt, 4.txt.

              *      El programa trabajara con un maximo de 10
                     procesos hijos. En el caso donde el usuario 
                     introduzca un valor para n mayor a 10, el 
                     programa asignara por defecto 10 procesos hijos.

              *      Nuevamente recordar que la ruta del directorio
                     donde se encuentren los archivos con las frases
                     de la poesia a compoer debe finalizar en /

GNU coreutils 8.21 
JUNIO 2015
MARCHIVO(1)