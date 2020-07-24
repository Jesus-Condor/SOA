// Programa que utiliza la funcion fork() y open() para llamar a un nuevo proceso

// Librerias a utilizar
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>	
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
    int i,j,arch;// Variables enteras declaradas
    int date;
    pid_t pid;// Variable pid declarada para un proceso
    arch = open("Tarea2-codificacion-CC571.mkd", O_RDONLY);// Leemos como ejemplo el texto de la tarea para ver la ejecucion de los procesos
    pid = fork();// Iniciamos un proceso
    if(pid != 0){
        while(read(arch, &date, sizeof(int)) > 0){
            for(i = 0; i < 100; i++)
               printf("Proceso padre - Dato = %d\n",date);// Va mostrando por consola el comportamiento del proceso padre  
        } 
    }else{
        while(read(arch, &date, sizeof(int)) > 0){
            for(j = 0; j < 100; j++)
               printf("Proceso hijo - Dato = %d\n",date);// Va mostrando por consola el comportamiento del proceso hijo
        }
    }
    close(arch);
    exit(0);
    return 0;
}
// Al ejecutar el programa el proceso padre e hijo estan ejecutandose al mismo tiempo hasta que el proceso padre termina primero
// luego termina de ejecutar el proceso hijo
