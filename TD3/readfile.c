#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>



<<<<<<< HEAD

int main(int argc, char **argv){
	if(argc != 2){
		printf("Je n'ai pas le nombre de fichiers... ?\n");
		exit(1);
	}
=======
int main(){

>>>>>>> 0067804a24f50e253e94f25010fdc1265134170c
	char *b;
  	b = malloc(sizeof(char) * 11);
	int fd, sz;
<<<<<<< HEAD
	fd = open(argv[1], O_RDONLY);
	printf("%d\n", fd);
	if (fd < 0) { 	
		perror("Error ");
		exit(-1);
	} 
	do {
		sz = read(fd, b, 1000);
		if(sz < 0){
    		perror("Error ");
			exit(-1);
    	}
=======
	fd = open("message", O_RDONLY);
	//printf("%d\n", fd);
	if (fd < 0) {
	 	exit(1); 
	} 
	do {
		sz = read(fd, b, 10);
>>>>>>> 0067804a24f50e253e94f25010fdc1265134170c
		b[sz]= '\0';
		printf("%s", b);
	} while (sz==10);
	close(fd);
	return 0;

}