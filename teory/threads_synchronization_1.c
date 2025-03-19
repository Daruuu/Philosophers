#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int glob = 0;  // Variable compartida entre los hilos

// Función para manejar errores en hilos
void handleError(int err, const char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(err));
    exit(EXIT_FAILURE);
}

// Función ejecutada por los hilos: incrementa 'glob' 'arg' veces
static void *threadFunc(void *arg)
{
    int loops = *((int *)arg);
    int loc, j;
    
	while (j < loops)
	{
        loc = glob;  // Copia el valor de 'glob' a una variable local
        loc++;       // Incrementa la variable local
        glob = loc;  // Actualiza 'glob' (condición de carrera)
		j ++;
	}
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int loops, s;
    
    // Determina el número de iteraciones (por argumento o por defecto)
    loops = (argc > 1) ? atoi(argv[1]) : 10000000;
    
    // Crea el primer hilo
    s = pthread_create(&t1, NULL, threadFunc, &loops);
    if (s != 0)
        handleError(s, "pthread_create");
    
    // Crea el segundo hilo
    s = pthread_create(&t2, NULL, threadFunc, &loops);
    if (s != 0)
        handleError(s, "pthread_create");
    
    // Espera la finalización del primer hilo
    s = pthread_join(t1, NULL);
    if (s != 0)
        handleError(s, "pthread_join");
    
    // Espera la finalización del segundo hilo
    s = pthread_join(t2, NULL);
    if (s != 0)
        handleError(s, "pthread_join");
    
    // Muestra el valor final de 'glob' (posible resultado inconsistente por condición de carrera)
    printf("glob = %d\n", glob);
    
    return EXIT_SUCCESS;
}
