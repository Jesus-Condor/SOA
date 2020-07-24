#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

// gcc -o Ejemplo4 Ejemplo4.c, ./Ejemplo, cat Ejemplo4.output

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork ha fallado; salir
        fprintf(stderr, "fork a fallado\n");
        exit(1);
    } else if (rc == 0) {
	// El proceso hijo: redirige la salida estándar a un archivo
	close(STDOUT_FILENO); 
	open("./Ejemplo4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

	// Ahora se ejecuta "wc"...
        char *myargs[3];
        myargs[0] = strdup("wc");   // programa: "wc" (word count)
        myargs[1] = strdup("Ejemplo4.c"); // argumento: archivo a contar
        myargs[2] = NULL;           // marca el fin del array
        execvp(myargs[0], myargs);  // runs wc
    } else {
        // El proceso padre sigue este camino (proceso original)
        int wc = wait(NULL);
	assert(wc >= 0);
    }
    return 0;
}
