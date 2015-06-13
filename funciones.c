/* Autores: Patricia Valencia 10-10916
 *          Luis Colorado     09-11086
 */

#include "funciones.h"

int mgetline (char *line, int max, FILE *f) {

    if (fgets(line, max, f)== NULL)
       return(0);
    else
        return(strlen(line));
}

void leeDirectorio(int tam, char const *directorio) {
    /* Declaracion de variables */
    DIR *pDir;
    FILE *archivo;
    /* char *flinea = (char*)malloc(sizeof(MAXCHAR)); */
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
        if ((strcmp(pDirent->d_name,"..") != 0) && (strcmp(pDirent->d_name,".") != 0) && (pDirent->d_type == DT_REG)) {
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
        else if ((strcmp(pDirent->d_name,"..") != 0) && (strcmp(pDirent->d_name,".") != 0) && (pDirent->d_type == DT_DIR)) {
            strcpy(str, directorio);
            strcat(str, pDirent->d_name);
            strcat(str, "/");
            leeDirectorio(MAXCHAR, str);
            memset(str, '\0', sizeof(str)); /* Se inicializa el arreglo str. */
        }
    }
    /* free(flinea); */
    closedir (pDir);
}

int numero_random(int x){
    int n;
    n = rand()%x;       /* rellena con numeros entre 0 y x-1 */
    return n; 
}

int* mArregloAleatorio(int m, int numArchivos) {
    int* arreglo = (int*)malloc(sizeof(int)*m);
    int arregloLocal[numArchivos];
    int i, tam, random;

    tam = numArchivos;

    for (i = 0; i <= numArchivos; ++i) {
        arregloLocal[i] = i+1;
    }

    i = 0;
    if (m >= numArchivos) {
        m = numArchivos;
    }
    while (i < m) {
        random = numero_random(tam);
        arreglo[i] = arregloLocal[random];
        arregloLocal[random] = arregloLocal[tam-1];
        tam--;
        i++;
    }

    return arreglo;
}

void procesos() {
    int nProcesos = 3;
    int i;
    int* status;

    pid_t proc;

    for (i = 0; i < nProcesos; ++i) {
        if ((proc = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (proc == 0) {
            printf("Soy el hijo con pid %d\n", getpid());
            exit(0);
        }
    }

    for (i = 0; i < nProcesos; ++i) {
        wait(&status);
    }
    printf("Soy el padre con pid %d\n", getppid());
}