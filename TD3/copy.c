#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
	
	char *texte;
    int fd, sz;
    int tailleMax = 651;
    texte = malloc(sizeof(char)*tailleMax);
    fd = open("message",O_RDONLY);
    if(fd < 0){
        exit(1);
    }
    sz = read(fd,texte,tailleMax);
    if(sz == tailleMax){
        texte[sz] = '\0';
    }
    
    close(fd);

    fd = open("texte_copie",O_WRONLY | O_CREAT, 0644);
    if(fd < 0){
        exit(1);
    }
    sz = write(fd,texte,tailleMax);
    close(fd);
    printf("%s",texte);
    return 0;

}