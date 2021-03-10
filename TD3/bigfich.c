#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char * compare(char *);

struct stat buf;
uid_t proprietaire;
if (stat("blop.txt", &buf) == 0) {
	proprietaire = buf.st_uid;
} else {
	perror("blop.txt");
}

int main(int argc, char **argv){
	if(argc == 1){
		printf("Vous avez oublié de donner une liste de fichiers en argument\n");
		exit(-1);
	}
	

}