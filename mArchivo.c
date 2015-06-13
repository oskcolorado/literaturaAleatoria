/* Autores: Patricia Valencia 10-10916
 *          Luis Colorado     09-11086
 */

#include "funciones.h"

int main (int argc, char const *argv[]) {
	srand(time(NULL));  /* semilla */
	pid_t pid;
	int j, x, i, p[2], pArreglo[5];
    int rArreglo[5];
	char *strcat(char *dest, const char *src);
    char str[RUTA],aux[RUTA];

	char rutaArreglo[5][RUTA];	/* Ruta de los pipes */

    if ((strcmp(argv[1],"-d") == 0)) {
        leeDirectorio(argc,argv[2]);
    }

    /* Se crea un areglo de pipes */
    /* Se crea un areglo con los numeros de los archivos */
    for (i = 0; i < 5; ++i) {
    	pArreglo[i] = pipe(p);
        rArreglo[i] = 0;
        while (rArreglo[i] == 0) {
            x = numero_random(10)+1;
            for (j = 0; j < 5; j++) {
                if (rArreglo[j] == x) {
                    j = 6;
                }
            }
            if (j == 5) {
                rArreglo[i] = x;
            }
        }
    }

    /* Se crea un areglo de con las rutas de cada proceso */
    for (i = 0; i < 5; ++i) {
    	strcpy(str, "./");
    	sprintf(aux, "%d", rArreglo[i]); 
    	strcat(str, aux);
    	strcat(str, "/");
    	strcpy(rutaArreglo[i], str);
    	memset(str, '\0', sizeof(str)); /* Se inicializa el arreglo str. */
    }

    ///* Imprime los tres arreglos */
    //for (i = 0; i < 5; ++i) {
    //	printf("pArreglo[%d] : %d\n", i, pArreglo[i]);
    //	printf("rutaArreglo[%d] : %s\n", i, rutaArreglo[i]);
    //}

    int* arreglo = mArregloAleatorio(5,5);

	//for (i = 0; i < 4; ++i) {
    //    printf("--> %d\n", arreglo[i]);
    //}

    /* Prueba de la funcion composicion */

    composicion();

    /* Liberacion de memoria */
    free(arreglo);

    return 0;
}