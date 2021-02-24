#include <stdio.h>
#include <string.h>
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
void q20();
int t[3];
float f[3];
char c[] = "requin";

typedef struct Personne {
	char *nom;
	int age;
	float taille;
}PERSONNE;


typedef struct Famille {
	char *nom;
	PERSONNE p;
	PERSONNE m;
	int nb_enfants;
	PERSONNE enfants[];
}FAMILLE;

void initialiserPersonne(PERSONNE* p){
	p->nom = c;
	p->age = 50;
	p->taille = 1.84;
}

PERSONNE creerPersonne(){
	PERSONNE user;
	printf("Quel est votre nom ? ");
    scanf("%s", user.nom);
    printf("Votre âge ? ");
    scanf("%i", user.age);
    printf("Votre taille ? ");
    scanf("%f\n", user.taille);
    return user;
}

void initialiserFamille(FAMILLE* f){
	f->nom = c;
	f->p = creerPersonne();
	f->m = creerPersonne();
	f->nb_enfants = 2;
	for(int i = 0; i < f->nb_enfants; i++){
		f->enfants[i] = creerPersonne();
	}
}

int q24(FAMILLE* f){
	int s_ages = 0;
	s_ages += f->p.age;
	s_ages += f->m.age;
	for(int i = 0; i < f->nb_enfants; i++){
		s_ages += (f->enfants[i]).age;
	}
	return s_ages;
}

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
	q20();
	printf("Requin est un palindrome : %i\n", palindrome(c));
	printf("chaine : %li, personne : %li, personne : %li, entier : %li, tableau de personnes : %li\n", sizeof(char *),
	 sizeof(PERSONNE), sizeof(PERSONNE), sizeof(int), sizeof(PERSONNE *));
	/*FAMILLE f;
	initialiserFamille(&f);
	printf("%i\n", q24(&f));
	creerPersonne();*/
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
	printf("%li\n" , strlen(chaine)); 
	//Autre version avec le while(char c!='\0') et printf
}

void q18bis(){
	t[0] = 'a';
	t[1] = 'baz';
	printf("%li %li\n", strlen(t), strlen(t+1));
	//Pas d'autre version avec while car tableau d'int ne finit par \0
}

int palindrome(char *s){
	int i = 0;
	int j, k, res;
	while(s[i]!='\0'){
		i++;
	}
	i = i - 2; //Taille de la chaine
	k = i / 2; //Moitié de la taille
	res = 1; //Booléen 
	for(j = 0; j <= k && res; j++){
		if(s[j]!=s[i-j]){ //On compare le début et la fin en se rapprochant du centre
			res = 0;
		}
	}
	return res;
}

void q20(){
	int i;
	FILE *f;
	f = fopen("message.txt","r");
	while(1) {
		i = fgetc(f);
		if(feof(f)) {
			break;
		}
		fputc(i,stdout);
	}
	fclose(f);
}




