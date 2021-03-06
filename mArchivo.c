#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <assert.h>

struct dirent *pDirent;
#define MAXCHAR 105

int mgetline (char *line, int max, FILE *f)
{

    if (fgets(line, max, f)== NULL)
       return(0);
    else return(strlen(line));

}

void leeDirectorio(int tam, char const *directorio) {
    /* Declaracion de variables */
    DIR *pDir;
    FILE *archivo;
    char *flinea = (char*)malloc(sizeof(MAXCHAR));
    char *strcat(char *dest, const char *src);
    char str[MAXCHAR];
    char linea[MAXCHAR];

    if (tam < 2) {
        printf ("Usage: testprog <dirname>\n");
        exit(0);
    }
    pDir = opendir (directorio);
    if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", directorio);
        exit(0);
    }

    while ((pDirent = readdir(pDir)) != NULL) {
        if ((strcmp(pDirent->d_name,"..") != 0) && (strcmp(pDirent->d_name,".") != 0) && (pDirent->d_type == 8)) {
            printf ("[%s]\n", pDirent->d_name);
            strcpy(str, directorio);
            strcat(str, pDirent->d_name);
            archivo = fopen(str,"r");

            if (archivo != NULL){
                while (mgetline(linea, sizeof(linea), archivo) > 0) {
                    printf("%s",linea);
                }
                printf("\n\n");
                fclose(archivo);    /* Se cierra el archivo. */
                memset(str, '\0', sizeof(str)); /* Se inicializa el arreglo str. */
            }
        }
        else if ((strcmp(pDirent->d_name,"..") != 0) && (strcmp(pDirent->d_name,".") != 0) && (pDirent->d_type == 4)) {
            strcpy(str, directorio);
            strcat(str, pDirent->d_name);
            strcat(str, "/");
            leeDirectorio(MAXCHAR, str);
            memset(str, '\0', sizeof(str)); /* Se inicializa el arreglo str. */
        }
    }
    free(flinea);
    closedir (pDir);
}

int main (int argc, char const *argv[]) {

    leeDirectorio(argc,argv[1]);
    return 0;
}