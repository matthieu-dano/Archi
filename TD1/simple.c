#include <stdio.h>
#define MESSAGE "Super\n"

int dbl(int);
void q7();
void q7bis();
void q9(int);
void qbonus(char);
void q12();
void q13();
void q14();
void q1516();
void q17();
void q18();
void q18bis();
int palindrome(char *);
int t[3];
float f[3];


int main() {
	printf(MESSAGE);
	printf("Double de 2 : %i\n", dbl(2));
	q7();
	q7bis();
	printf("Taille de la chaine Youpi/n : %li\n", sizeof("Youpi\n"));
	q9(12);
	qbonus('0');
	/*q12();
	q13();
	q14();
	q1516();*/
	q17();
	//q18();
	q18bis();	
}

int dbl(int n){
	return 2*n;
}

void q7(){
	int tab[3];
	tab[0] = 1;
	tab[1] = 2;
	printf("%i %i %i %i %i\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
}

void q7bis(){
	t[0] = 1;
	t[1] = 2;
	printf("%i %i %i %i\n", t[0], t[1], t[2], t[3]);
}

void q9(int a){
	int *b;
	b = &a;
	*b = a + 1;
	//printf("a = %i, b = %i\n", a, b);
	printf("a = %i, b = %lu\n", a, (long unsigned) b);
}

void qbonus(char c){
	/*C'est le principe de caste on considère le résultat comme int*/
	printf("Valeur du caractère en table ASCII : %i\n", (int)c);
}

void q12(){
	printf("%p %p\n", &t[0], &t[1]);
	printf("%p %p\n", t, t+1);
}

void q13(){
	f[0] = 1.0;
	f[1] = 2.0;
	printf("%p %p\n", &f[0], &f[1]);
	printf("%p %p\n", f, f+1);
}

void q14(){
	int t[2];
	printf("Premiere adresse: %i, seconde adresse: %i\n", (int)t,(int)(t+1));
}

void q1516(){
	for(int i = 1; i < 101; i++){
		if((i%3!=0) && (i%7!=0)){
			printf("%i ", i);
		}
	}
}

void q17(){
	int bool = 1;
	int n = 2262;
	while(bool){
		if((n%2262==0)&&(n%13195==0)){
			printf("%i\n", n);
			bool = 0;
		}
		n++;
	}
}

void q18(){
	char chaine[80];
	printf("Entrez une chaîne: ");
	fgets(chaine, 80, stdin); //‘\n’ et ‘\0’ à la fin
	fputs(chaine, stdout);
	printf("%i \n" , strlen(chaine)); 
	//Autre version avec le while(char c!='\0') et printf
}

void q18bis(){
	t[0] = 'a';
	t[1] = 'baz';
	printf("%i %i\n", strlen(t), strlen(t+1));
	//Pas d'autre version avec while car tableau d'int ne finit par \0
}

