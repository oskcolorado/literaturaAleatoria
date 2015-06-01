/* Autores: Patricia Valencia 10-10916
 *          Luis Colorado     09-11086
 */

/* Librerias a importar */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <assert.h>

/* Definicion de constantes */
#define MAXCHAR 105

/* Estructura para manejar archivos */
struct dirent *pDirent;

/* Prototipos de funciones definidas en funciones.c */
extern int mgetline (char *line, int max, FILE *f);
extern void leeDirectorio(int tam, char const *directorio);