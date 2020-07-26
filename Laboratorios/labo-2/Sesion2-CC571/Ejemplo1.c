#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Hola CC-571 (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork ha fallado; salir
        fprintf(stderr, "fork ha fallado\n");
        exit(1);
    } else if (rc == 0) {
        //proceso hijo (nuevo proceso)
        printf("Hola a todos, soy un proceso hijo (pid:%d)\n", (int) getpid());
    } else {
        // el proceso padre sigue este camino(proceso original)
        printf("Hola, soy un proceso padre de %d (pid:%d)\n",
	       rc, (int) getpid());
    }
    return 0;
}
