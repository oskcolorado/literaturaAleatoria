# Autores: Patricia Valencia 10-10916
#          Luis Colorado     09-11086

# Makefile para aplicacion "mArchivo.c"
CFLAGS	= 
CC	= gcc
OBJS	= funciones.o mArchivo.o 

mArchivo:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@


mArchivo.o:	mArchivo.c funciones.h Makefile
		$(CC) $(CFLAGS) -c mArchivo.c

funciones.o:	funciones.c funciones.h Makefile
		$(CC) $(CFLAGS) -c funciones.c

clean:
		/bin/rm *.o mArchivo
