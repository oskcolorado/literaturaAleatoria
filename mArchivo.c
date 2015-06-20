/* Autores: Patricia Valencia 10-10916
 *          Luis Colorado     09-11086
 */

#include "funciones.h"

int main (int argc, char const *argv[]) {
	srand(time(NULL));  /* semilla */
	int   j, x, i, p[atoi(argv[3])][2], m, n;
    int   rArreglo[10];
	char  *strcat(char *dest, const char *src);
    char  str[RUTA], aux[RUTA];
    FILE  *archivo1;
	char  rutaArreglo[10][MAXCHAR];	/* Ruta de los pipes */

    if (argc < 6) {
        printf ("Usage: testprog <dirname>\n");
        exit(0);
    }
    if ((strcmp(argv[1],"-d") == 0)) {
        leeDirectorio(argc,argv[2]);
        n = atoi(argv[3]);
        m = atoi(argv[4]);
    }
    else {
        printf("Syntax error: Lack -d\n");
        exit(0);
    }

    /* Se crea un areglo de pipes */
    /* Se crea un areglo con los numeros de los archivos */
    for (i = 0; i < n; ++i) {
    	pipe(p[i]);;
        rArreglo[i] = 0;
        while (rArreglo[i] == 0) {
            x = numero_random(10)+1;
            for (j = 0; j < n; j++) {
                if (rArreglo[j] == x) {
                    j = n+1;
                }
            }
            if (j == n) {
                rArreglo[i] = x;
            }
        }
    }

    /* Se crea un areglo con las rutas de cada proceso */
    for (i = 0; i < n; ++i) {
    	strcpy(str, argv[2]);
    	sprintf(aux, "%d", rArreglo[i]); 
    	strcat(str, aux);
    	strcat(str, "/");
    	strcpy(rutaArreglo[i], str);
    	memset(str, '\0', sizeof(str)); /* Se inicializa el arreglo str. */
    }

    archivo1 = fopen(argv[5],"w");
    for (i = 0; i < n; ++i) {
        composicion(p[i], rutaArreglo[i], m, argv[5]);
    }
    fclose(archivo1);

    return 0;
}