/* Autores: Patricia Valencia 10-10916
 *          Luis Colorado     09-11086
 */

#include "funciones.h"

int main (int argc, char const *argv[]) {
	srand(time(NULL));  /* semilla */
	pid_t pid;
	int   j, x, i, p[2], pArreglo[10], m, n;
    int   rArreglo[10];
	char  *strcat(char *dest, const char *src);
    char  str[RUTA], aux[RUTA];
    FILE  *archivo1;
	char  rutaArreglo[10][MAXCHAR];	/* Ruta de los pipes */

    if ((strcmp(argv[1],"-d") == 0)) {
        leeDirectorio(argc,argv[2]);
        n = atoi(argv[3]);
        m = atoi(argv[4]);
    }

    /* Se crea un areglo de pipes */
    /* Se crea un areglo con los numeros de los archivos */
    for (i = 0; i < n; ++i) {
    	pArreglo[i] = pipe(p);
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

    /* Imprime los tres arreglos */
    //for (i = 0; i < n; ++i) {
    //	printf("pArreglo[%d] : %d\n", i, pArreglo[i]);
    //    printf("rutaArreglo[%d] : %s\n", i, rutaArreglo[i]);
    //}

    //int* arreglo = mArregloAleatorio(5,5);

	//for (i = 0; i < 4; ++i) {
    //    printf("--> %d\n", arreglo[i]);
    //}

    /* Prueba de la funcion composicion */

    //for (i = 0; i < n; ++i) {
    //    buscaArchivos(rutaArreglo[i]);
    //}

    archivo1 = fopen(argv[5],"w");
    for (i = 0; i < n; ++i) {
        printf(">>>>> %s\n", rutaArreglo[i]);
        composicion(&pArreglo[i], rutaArreglo[i], m, argv[5]);
    }
    fclose(archivo1);
    //composicion(&pArreglo[0], rutaArreglo[0], m);

    /* Liberacion de memoria */
    //free(arreglo);

    return 0;
}