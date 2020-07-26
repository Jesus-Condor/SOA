// Programa que mide el tiempo de ejecucion de dos procesos a traves de dos tuberias y como estas se conectan

//Librerias a utilozar
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/time.h>
// Para nuestros carateres
#define TAM 256

int main(int argc, char *argv[]){
    int i, arch, status;
    char buffer[TAM];
    struct timeval current_time;
    unsigned lon;// Toma valores de 0 a 255
    pid_t pid;// Declaramos nuestra variable pid
    pid = fork();// Inicializamos procesos
    pipe(arch);// Iniciamos una tuberia
    switch(pid){
        case -1:
            fprintf(stderr, "Error de resultado al utilizar fork()");
            exit(1);
            break;
        case 0:// Accion del proceso hijo
            dup2(arch, STDOUT_FILENO);
            close(arch);
            fprintf(stderr, "Proceso hijo [%ld] escribira en la tuberia\n", (long)getpid());// Cuando usa el printf no imprime ya que no es de
            sprintf(buffer, "Mensaje hecho por el hijo: [%ld]\n", (long)getpid());
            lon = strlen(buffer) + 1;
            if(write(1, buffer, lon) != lon){
                 fprintf(stderr, "Falla de escritura\n");
                 exit(1);
            }
            break;
        default:// Accion del proceso padre
            close(arch);
            fprintf(stderr, "Proceso padre [%ld] escribira la tuberia\n", (long)getpid());
            while((wait(&status) == -1) && (errno == EINTR));
            if(read(0, buffer, TAM) <= 0){
                 fprintf(stderr, "Falla en la lectura al padre\n");
                 gettimeofday(&current_time, NULL);
                 printf("Tiempo ejecutado : %ld\nTiempo ejecutado en microsegundos : %ld\n", current_time.tv_sec, current_time.tv_usec);
                 exit(1);
            }
            printf("Proceso Padre (mensaje leido): %s\n", buffer);
    }
    exit(0);
    printf("llegue aca\n");
    gettimeofday(&current_time, NULL);
    printf("Tiempo ejecutado : %ld\nTiempo ejecutado en microsegundos : %ld\n", current_time.tv_sec, current_time.tv_usec);
    return 0;
}


