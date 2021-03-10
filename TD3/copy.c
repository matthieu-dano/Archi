#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>



int main(int argc, char **argv){
	if(argc != 3){
		printf("Je n'ai pas le bon nombre de fichiers ... ?\n");
		exit(1);
	}
	char *texte;
    int fd, sz;
    int tailleMax = 651;
    texte = malloc(sizeof(char)*tailleMax);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) { 	
		perror("Error ");
		exit(-1);
	} 
    sz = read(fd,texte,tailleMax);
    if(sz < 0){
    	perror("Error ");
		exit(-1);
    }
    if(sz == tailleMax){
        texte[sz] = '\0';
    }
    
    close(fd);

<<<<<<< HEAD
    fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if (fd < 0) { 	
		perror("Error ");
		exit(-1);
	}
=======
    fd = open("texte_copie",O_WRONLY | O_CREAT, 0644);
    if(fd < 0){
        exit(1);
    }
>>>>>>> 0067804a24f50e253e94f25010fdc1265134170c
    sz = write(fd,texte,tailleMax);
    if(sz != tailleMax){
    	perror("Error ");
    	exit(-1);
    }
    close(fd);
    printf("%s",texte);
    return 0;

}
