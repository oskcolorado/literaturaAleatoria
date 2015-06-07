/* Autores: Patricia Valencia 10-10916
 *          Luis Colorado     09-11086
 */

#include "funciones.h"

int main (int argc, char const *argv[]) {
	pid_t pid;
	int j,i, p[2], pArreglo[5], numer;
	int rArreglo[5];	/* Ruta de los pipes */

    if ((strcmp(argv[1],"-d") == 0)) {
        leeDirectorio(argc,argv[2]);
    }

    /* Se crea un areglo de pipes */

    for (i = 0; i < 5; ++i) {
    	pArreglo[i] = pipe(p);
    	//rArreglo[i] = (numero_random(10)+1);
    	numer = (numero_random(10)+1);
    	printf("-----> random : %d\n", numer);
    }

    for (i = 0; i < 5; ++i) {
    	printf("pArreglo%d : %d\n", i, pArreglo[i]);
    	//printf("rArreglo%d : %d\n", i, rArreglo[i]);
    }

    int* arreglo = mArregloAleatorio(5,5);

	for (i = 0; i < 4; ++i) {
        printf("--> %d\n", arreglo[i]);
    }

    /* Liberacion de memoria */
    free(arreglo);

    return 0;
}