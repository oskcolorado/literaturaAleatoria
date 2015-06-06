/* Autores: Patricia Valencia 10-10916
 *          Luis Colorado     09-11086
 */

#include "funciones.h"

int main (int argc, char const *argv[]) {
	int i;

    if ((strcmp(argv[1],"-d") == 0)) {
        leeDirectorio(argc,argv[2]);
    }

    fflush(stdin);

    int* arreglo = mArregloAleatorio(5,5);

	for (i = 0; i < 4; ++i) {
        printf("--> %d\n", arreglo[i]);
    }    

    return 0;
}