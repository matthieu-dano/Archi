#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(){

	char *b;
  	b = malloc(sizeof(char) * 11);
	int fd, sz;
	fd = open("message", O_RDONLY);
	//printf("%d\n", fd);
	if (fd < 0) {
	 	exit(1); 
	} 
	do {
		sz = read(fd, b, 10);
		b[sz]= '\0';
		printf("%s", b);
	} while (sz==10);
	close(fd);
	return 0;

}