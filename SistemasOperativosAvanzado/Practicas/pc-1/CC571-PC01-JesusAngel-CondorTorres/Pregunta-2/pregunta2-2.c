// Programa que bifurca en proceso padre e hijo 

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
   int a = 5;
   int fd = open(texto,O_RDONLY) //abriendo un archivo
   int ret = fork();
   if(ret > 0){//proceso padre
      close(fd);
      a = 6;

   }
   else if(ret == 0){//proceso hijo
     printf("a=%d\n", a);//Imprime el valor de 5
     read(fd, texto);
   }
   else{// error
      printf("Error en la creacion del proceso\n");
   }
   close(fd);
   return 0;
}
