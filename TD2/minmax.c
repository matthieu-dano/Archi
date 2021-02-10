#include <stdio.h>
#include <stdlib.h>

int max(int *t, int n){
	int i = 0;
	int max = t[0];
	while (i < n){
		if (t[i] > max){
			max = t[i];
		}
		i++;
	}
	return max;
}

int min(int *t, int n){
	int i = 0;
	int min = t[0];
	while (i < n){
		if (t[i] < min){
			min = t[i];
		}
		i++;
	}
	return min;
}

void f(int a, int b, int *s, int *p) {
    *s = a + b;
    *p = a * b;
}

void min_max(int *t, int n, int *x, int *y){
	*x = min(t, n);
	*y = max(t, n);
}

int* copie(int *tab, int n) {
	int *p;
	p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        p[i] = tab[i];
    }
    return p;
}

int* unsurdeux(int *tab, int n){
	int *p;
	int a = 0;
	p = malloc(sizeof(int) * n/2);
	for(int i = 0 ; i < n ; i++){
		if(i%2 == 0){
			p[a] = tab[i];
			a++;
		}
	}
	return p;
}

typedef struct Matrice Matrice;

struct Matrice {
    int nb_lignes;
    int nb_colonnes;
    int **valeurs;
};

void affiche(Matrice m){
	for(int i = 0 ; i < m.nb_lignes; i++){
		for(int j = 0; j < m.nb_colonnes; j++){
			printf("%3i", m.valeurs[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

Matrice matrice(int nbl, int nbc, int *valeurs){
	int **t;
	t = malloc(sizeof(int *) * nbl);
	int *t1;
	t1 = malloc(sizeof(int) * nbc);
	for(int i = 0; i < nbc; i++){
		/*a finir*/
	}
}

int main(){
	int tab[4] = {1,8,9,2};
	printf("Le maximum du tableau t : %i\n", max(tab, 4));
	int a, b;
	min_max(tab, 4, &a, &b);
	printf("Le minimum et le maximum du tableau t : %d, %d\n", a, b);
	int x, y;
	f(12, 4, &x, &y);
	printf("x = %d, y = %d\n", x, y);
	int *t = copie(tab, 4);
	printf("Le maximum et le minimum de la copie du tableau : %i, %i\n",
	 min(t, 4), max(t, 4));
	int tab1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *tab_bis;
    tab_bis = unsurdeux(tab1, 10);
    for (int i = 0; i < 5; i++) {
        printf("%d ", tab_bis[i]);
    }
    printf("\n");
    free(tab_bis);
    int l1[3] = {1, 2, 3};
	int l2[3] = {4, 5, 6};
	int *v[2] = {l1, l2};
	Matrice m = {.nb_lignes = 2, .nb_colonnes = 3, .valeurs = v};
    affiche(m);
}

/* Réponse Q2 : il faut donner la taille du tableau car si l'on dépasse
cette taille il va afficher l'adresse suivante de la dernière case mais
qui n'appartient pas au tableau.*/

/*Réponse Q3 : on appelle la fonction f avec 2 int en adresse
et les valeurs sont données ensuite ainsi on peut retourner 2
objets.*/




