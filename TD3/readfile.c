#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>




int main(int argc, char **argv){
	if(argc != 2){
		printf("Je n'ai pas le nombre de fichiers... ?\n");
		exit(1);
	}
	char *b;
  	b = malloc(sizeof(char) * 1001);
	int fd, sz;
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
		b[sz]= '\0';
		printf("lu: %s\n", b);
	} while (sz==1000);
	close(fd);
	return 0;
}