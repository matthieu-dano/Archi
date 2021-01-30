#include <stdio.h>
#define MESSAGE "Super\n"

int dbl(int n){
	return 2*n;
}

void cent(){
	for(int i=1; i<101; i++){
		if(i%3!=0 && i%7!=0){
			printf("Valeur de i : %i\n", i);
		}
		
	}
}

void div(){
	int n = 1;
	while (n!=0){
		if(n%2262==0 && n%13195==0){
			printf("Valeur de n : %i\n", n);
			break;
		}
		n+=1;
	}

}

int main() {
	printf(MESSAGE);
	printf("resulat : %i\n", dbl(2));
	int tab[2];
	tab[0] = 1;
	tab[1] = 2;

	//Tab[2], tab[3] ne sont pas definies et pourtant elle donnent 
	//un nombre aléatoire en rapport avec la pile
	printf("tab[0] : %i, tab[1] : %i, tab[2] : %i, tab[3] : %i\n",
	tab[0], tab[1], tab[2], tab[3]);
	//La chaîne Youpi\nTralala\n représente 13 octets en mémoire
	printf("Taille de la chaîne : %lu\n", sizeof("Youpi\nTralala\n"));
	//Notation int *tab = pointeur vers la valeur d'un entier tab
	//Notation &obj désigne la mémoire de l'objet
	int a, *b;
	a = 12;
	b = &a;
	*b = a +1;
	printf("a = %i, b = %lu\n", a, (long unsigned) b);
	tab[2]=0;
	//printf("Adresse de tab : %p\n, Adresse de tab[1] %p\n", &tab, &tab[1]);
	//On voit que chaque pour un tab d'int est représenté par +4 en adresse mem
	//Pareil pour flott et double 8octet en plus
	int t[2];
	/*printf("Premiere adresse: %i, seconde adresse: %i\n",
	(int)t,(int)(t+1));*/
	//cent();
	div();

}
	