/* Autores: Patricia Valencia 10-10916
 *          Luis Colorado     09-11086
 */

#include "funciones.h"

int main (int argc, char const *argv[]) {

    if ((strcmp(argv[1],"-d") == 0)) {
        leeDirectorio(argc,argv[2]);
    }
    return 0;
}