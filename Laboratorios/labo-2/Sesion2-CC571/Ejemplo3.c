#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("Hola CC-571 (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork ha fallado; salir
        fprintf(stderr, "fork ha fallado\n");
        exit(1);
    } else if (rc == 0) {
        // child (nuevo proceso)
        printf("Hola, soy un proceso hijo(pid:%d)\n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("wc");   // programa: "wc" (word count)
        myargs[1] = strdup("Ejemplo3.c"); // argumento: archivo a contar
        myargs[2] = NULL;           // marca el fin del array
        execvp(myargs[0], myargs);  // runs wc
        printf("esto no debería imprimirse");
    } else {
        // El proceso padre sigue este camino (proceso original)
        int wc = wait(NULL);
        printf("Hola soy un proceso padre de %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
    return 0;
}
