// Programa donde ejecutamos la funcion "fork()" y "exec", ademas de sus derivados como
// execl, execle, execl, execv, execvp y execvpe

//Librerias que utilizaremos
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
   pid_t pid;// Variable pid declarada
   int status;// Variable entera declarada
   char *arguments[5] = {"ls", "-l", "/bin/ls", "/usr/include", NULL};// Puntero char declarado para las multiples opciones del comando exec
   pid = fork();// Iniciamos un proceso
   switch(pid){
      case -1: 
         perror("Error en la funcion fork()");
         exit(-1);
      case 0://Usamos las distintas opciones de la funcion exec
         execvp(arguments[0],arguments);
         //execvpe(arguments[0],arguments);
         //execv(arguments[0],arguments);
         //execlp(arguments[3],arguments);
         //execle(arguments[0],arguments);
         //execl(arguments[2],arguments);
         perror("Error en la ejecucion del exec");
         exit(-1);
      default:
         while(wait(&status) != pid);
         if(status == 0)
            printf("Ejecucion normal del hijo\n");
         else
            printf("Error del hijo\n");
   }
   exit(0);
   return 0;
}
// Si bien todos los comandos de exec sirven para llamar a un fichero, estas se diferencian en el modo de llamado ya que algunas necesitan
// direcciones o otras variables para poder ejecutarse correctamente.
