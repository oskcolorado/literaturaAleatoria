/* Autores: Patricia Valencia 10-10916
 *          Luis Colorado     09-11086
 */

#include "funciones.h"

/**
 * @brief  mgetline Calcula el tamaño de una cadena de caracteres.
 * @param *line Contiene la cadena de caracteres.
 * @param  max  Tamaño en bytes de la cadena de caracteres.
 * @param *f Contiene el archivo de donde viene la cadena.
 * @return 0 Regresa cero.
 * @return strlen(line) Regresa el tamaño de la cadena.
**/
int mgetline (char *line, int max, FILE *f) {

    if (fgets(line, max, f)== NULL)
       return(0);
    else
        return(strlen(line));
}

/**
 * @brief  leeDirectorio Lee un directorio determinado.
 * @param  tam Tamaño entero del directorio.
 * @param  *directorio Contiene un directorio .
 * @return void.
**/
void leeDirectorio(int tam, char const *directorio) {
    /* Declaracion de variables */
    DIR *pDir;
    FILE *archivo;
    char *strcat(char *dest, const char *src);
    char str[MAXCHAR];
    char linea[MAXCHAR];

    pDir = opendir (directorio);
    
    if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", directorio);
        exit(0);
    }

    while ((pDirent = readdir(pDir)) != NULL) {
        if ((strcmp(pDirent->d_name,"..") != 0) && (strcmp(pDirent->d_name,".") != 0) && (pDirent->d_type == DT_REG)) {
            strcpy(str, directorio);
            strcat(str, pDirent->d_name);
            archivo = fopen(str,"r");

            if (archivo != NULL){
                while (mgetline(linea, sizeof(linea), archivo) > 0) {
                }
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

/**
 * @brief  buscarArchivos Calcula el numero de archivos dentro de un directorio determinado.
 * @param  *directorio Contiene el directorio donde se buscara los archivos.
 * @return numArchivos Numero de archivos encontrados en el directorio.
**/
int buscaArchivos(char *directorio) {
    /* Declaracion de variables */
    DIR *pDir;
    int  numArchivos = 0;

    pDir = opendir (directorio);
    if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", directorio);
        exit(0);
    }

    while ((pDirent = readdir(pDir)) != NULL) {
        if ((strcmp(pDirent->d_name,".") != 0) && (strcmp(pDirent->d_name,"..") != 0) && (pDirent->d_type == DT_REG)) {
            numArchivos ++;
        }
    }
    closedir (pDir);
    return numArchivos;
}

/**
 * @brief  numero_random Genera un numero aleatorio.
 * @param  x Entero cualquiera que establece el tope de hasta donde se generara el numero.
 * @return n Entero aleatorio generado.
**/
int numero_random(int x){
    int n;
    n = rand()%x;       /* rellena con numeros entre 0 y x-1 */
    return n; 
}

/**
 * @brief  mArregloAleatorio Modifica un arreglo devolviendolo en orden aleatorio.
 * @param  m Es el tamaño del arreglo a considerar (m introducido por el usuario).
 * @param  numArchivos Contiene el numero de archivos dentro de un directorio.
 * @return arreglo Arreglo desordenado.
**/
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

/**
 * @brief  composicion Compone la "literatura aleatoria".
 * @param  *p Pipe.
 * @param  *dirArchivo Contiene un directorio.
 * @param  m Numero de archivos que los procesos hijos deben considerar.
 * @param  *salida Contiene un archivo donde se generarala salida.
 * @return void.
**/
void composicion(int *p, char *dirArchivo, int m, const char *salida) {
    /* Inicializacion de variables */
    pid_t pid;
    int   i, readbytes, numArchivos;
    char  buffer[SIZE], linea[SIZE];
    FILE  *archivo, *archivo1;
    char  rutaArreglo[10][SIZE];
    char  *strcat(char *dest, const char *src);
    char  str[RUTA], aux[RUTA];
 
    /* Instrucciones */

    numArchivos = buscaArchivos(dirArchivo);

    if (m >= numArchivos) {
        m = numArchivos;
    }

    int* arreglo = mArregloAleatorio(m, numArchivos);

    /* Se crea un areglo con las rutas de cada proceso */
    for (i = 0; i < m; ++i) {
        strcpy(str, dirArchivo);
        sprintf(aux, "%d", arreglo[i]); 
        strcat(str, aux);
        strcat(str, ".txt");
        strcpy(rutaArreglo[i], str);
        memset(str, '\0', sizeof(str)); /* Se inicializa el arreglo str. */
    }   

    pid = fork();

    if (pid == 0) {

        close(p[1]); /* cerramos el lado de escritura del pipe */
        archivo1 = fopen(salida,"a");

        while((readbytes=read(p[0], buffer, SIZE)) > 0) {
            fwrite(buffer, 1, readbytes,archivo1);
        }
        close(p[0]);

        exit(m);
    }
    else {

        strcpy(buffer,"");
        close(p[0]); /* cerramos el lado de lectura del pipe */
        for (i = 0; i < m; ++i) {
            archivo = fopen(rutaArreglo[i],"r");
            while (mgetline(linea, sizeof(linea), archivo) > 0) {
                strcat( buffer,linea);
            }
            strcat( buffer,"\n\n");
        }
        write(p[1], buffer, strlen(buffer));
        printf("%s", buffer);
        close(p[1]);
    }
    waitpid(pid, NULL, 0);

    /* Liberacion de memoria */
    free(arreglo);
}