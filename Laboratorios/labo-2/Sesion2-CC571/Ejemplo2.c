#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
        // proceso hijo (nuevo proceso)
        printf("Hola, soy un proceso hijo(pid:%d)\n", (int) getpid());
	sleep(1);
    } else {
        // El proceso padre sigue este camino (proceso original)
        int wc = wait(NULL);
        printf("Hola, soy un proceso padre de %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
    return 0;
}
