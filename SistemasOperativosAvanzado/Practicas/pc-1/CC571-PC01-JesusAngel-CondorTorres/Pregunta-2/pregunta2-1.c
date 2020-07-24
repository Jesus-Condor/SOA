//Programa que redirige la salida de un STDOUT a un archivo .txt

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

#define TAM 256
//Funcion principal
int main(int argc, char *argv[]){
    int status,arch,arch1, bytes;
    char buffer[TAM];
    //comando = leer_usuario();
    char *command[3] = {"/bin/ls","ls",NULL}
    int rc = fork();
    if(rc == 0) { //proceso hijo
       exec(command);
       arch = open(command[1], O_RDONLY);//Abrimos archivo
       arch1 = open("f.txt", O_WRONLY);//Abre archivo
       while ((bytes = read(arch, &buffer, sizeof(char))) > 0)
            write(arch1, &buffer, bytes);//Redirigimos a un archivo de texto llamado f.txt
     }
    else {// proceso padre
       wait(&status);//espera si esta ejecutando el proceso hijo
    }
    close(arch);
    close(arch1);
    return 0;
}
