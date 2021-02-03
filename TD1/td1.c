#include <stdio.h>
#define MESSAGE "Super\n"
#include <string.h>
#include <stdlib.h>

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

int palindrome(char *s){
	int resultat = 1;
	if(strlen(s) <= 1){
       resultat = 0;
	}
	else if(s[0] == s[strlen(s)-1]){
		char temp[strlen(s)-2];
		//Copie le tableau avec un intervalle donné
	 	memcpy( temp, &s[1], strlen(s) - 2 );
	 	temp[strlen(s) - 2] = '\0';
	 	resultat = palindrome(temp);
	}
	return resultat;
}

struct Personne {
    char *nom;
    int age;
    float taille;
}; 

typedef struct Personne Personne;

struct Famille
{
	char *nom;
	Personne pere;
	Personne mere;
	int nb_enfants;
	Personne enfants[];
};

typedef struct Famille Famille;

int age_total(Famille f1){
	int s = 0;
	for(int i = 0; i< f1.nb_enfants; i++){
		s+= f1.enfants[i].age;
	}
	return s;
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
	/*char chaine[80];
    printf("Entrez une chaîne: ");
    fgets(chaine, 80, stdin);
    fputs(chaine, stdout);
    for(int i=0; i < 80; i++){
    	if(chaine[i]=='\0'){
    		printf("La taille de la chaîne transmise est : %i\n", i-1);
    		break;
    	}
    }*/
    /*Réponse de la 21 est 8 pour le nom, pour le pere 16 (pointeur+
    +int+float) +pour la mere 16+ 4 (int)+ pointeur(vers tab de personnes
    ) donc 8. Final : 8+16+16+4+8=52octets*/
    struct Personne p1;
    char nom[] = "Guy";
    p1.nom = nom;
    p1.age = 10;
    p1.taille = 3.04;

    struct Personne p2;
    char nom2[] = "Lili";
    p2.nom = nom2;
    p2.age = 54;
    p2.taille = 1.73;

    struct Personne p3;
    char nom3[] = "Polo";
    p3.nom = nom3;
    p3.age = 43;
    p3.taille = 2.81;

    struct Famille f;
    char nom4[] = "Yolo";
    f.nom = nom4;
    f.pere = p1;
    f.mere = p2;
    f.nb_enfants = 1;
    f.enfants[0]=p3;

    //age_total(f);
    char palin[] = "kayak";
    if(palindrome(palin)==0){
    	printf("C'est un palindrome yes\n");
    }
    else{
    	printf("Ce n'est pas un palindrome\n");
    }

}
	