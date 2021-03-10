#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

<<<<<<< HEAD

=======
>>>>>>> 0067804a24f50e253e94f25010fdc1265134170c
#define TAILLEMAX 260


int lireligne(int, char *, int);
int lireligne2(int, char *, int);

<<<<<<< HEAD
int main(int argc, char **argv){
	if(argc != 2){
		printf("Je n'ai pas le nombre de fichiers... ?\n");
		exit(1);
	}
	int fd;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) { 	
		perror("Error ");
		exit(-1);
	} 
=======
int main(){
	int fd;
	fd = open("message", O_RDONLY);
	if(fd < 0){
        exit(1);
    }
>>>>>>> 0067804a24f50e253e94f25010fdc1265134170c
    char *s;
    s = malloc(sizeof(char)*TAILLEMAX);
	/*lireligne(fd, s, TAILLEMAX);
	lireligne(fd, s, TAILLEMAX);*/
	lireligne2(fd, s, TAILLEMAX);
<<<<<<< HEAD
	printf("\n");
	//lireligne(fd, s , TAILLEMAX);
=======
	lireligne(fd, s , TAILLEMAX);
>>>>>>> 0067804a24f50e253e94f25010fdc1265134170c
}

int lireligne(int fd, char *s, int size){
	int sz;
	int i = 0;
	char c;
	while (i < size){
		sz = read(fd, &c, 1);
<<<<<<< HEAD
		if(sz < 0){
    	perror("Error ");
		exit(-1);
    	}
=======
>>>>>>> 0067804a24f50e253e94f25010fdc1265134170c
		s[i]=c;
		if(s[i]=='\n'){
			break;
		}
		i++;
	}
	printf("%s", s);	
    return 0;
}

int lireligne2(int fd, char *s, int size){
	int sz;
	sz = read(fd, s, size);
<<<<<<< HEAD
	if(sz < 0){
    	perror("Error ");
		exit(-1);
    }
=======
>>>>>>> 0067804a24f50e253e94f25010fdc1265134170c
	printf("%s", s);
	
	for(int i = 0; i < size; i++){
		if(s[i]=='\n'){
			lseek(fd, size-i, SEEK_CUR);
		}
	}
	close(fd);
	return 0;
}