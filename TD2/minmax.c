#include <stdio.h>
#include <stdlib.h>

int q1(int *, int);
void f(int, int, int *, int *);
int q1bis(int *, int);
void q4(int *, int, int *, int *);
int* q67(int *, int);
int* q8(int *, int);


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
	int j = 0;
	int k = 0;
	while (j < nbc*nbl){
		t1 = malloc(sizeof(int) * nbc);
		for(int i = 0; i < nbc; i++){
			t1[i] = valeurs[j];
			j++;
		}
		t[k]=t1;
		k++;
	}
	Matrice m = {.nb_lignes = nbl, .nb_colonnes = nbc, .valeurs = t};
	return m;
}

void efface(Matrice m){
	for(int i = 0; i < m.nb_lignes; i++){
		free(m.valeurs[i]);
	}
	free(m.valeurs);
}

int main(){

	//Question 1 :

	int tab[4] = {1,8,9,2};
	printf("Le maximum du tableau t : %i\n", q1(tab, 4));
	printf("Le minimum du tableau t : %i\n", q1bis(tab, 4));

	//Question 5 :

	int a, b;
	q4(tab, 4, &a, &b);
	printf("Le minimum et le maximum du tableau t : %d, %d\n", a, b);
	int x, y;
	f(12, 4, &x, &y);
	printf("x = %d, y = %d\n", x, y);

	//Question 6 et 7 :

	int *t = q67(tab, 4);
	printf("Le minimum et le maximum de la copie du tableau : %i, %i\n",
	q1bis(t, 4), q1(t, 4));

	//Question 8 :

	int tab1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *tab_bis;
    tab_bis = q8(tab1, 10);
    for (int i = 0; i < 5; i++) {
        printf("%d ", tab_bis[i]);
    }
    printf("\n");

    /*Lorsque l'on utilise la fonction malloc pour réserver de l'espace en mémoire, cet espace n'est pas 
    libéré automatiquement pendant l'exécution du programme, d'où le free. Il faut savoir qu'après une exécution
    du main le stack et heap sont vidés automatiquement*/
    free(tab_bis);

    //Question 9 :

    int l1[3] = {1, 2, 3};
	int l2[3] = {4, 5, 6};
	int *v[2] = {l1, l2};
	Matrice m = {.nb_lignes = 2, .nb_colonnes = 3, .valeurs = v};
    affiche(m);

    //Question 11 :

    int v1[12] = {
    1, 2, 3, 4,
    2, 4, 6, 8,
    3, 6, 9, 12
	};

	Matrice m1 = matrice(3, 4, v1);
	affiche(m1);

	//Question 12 :

	efface(m1);

	/*Les matrices contruites par matrice() contiennent des tableaux alloués dynamiquement (heap) ainsi si nous en avons
	plus besoin il faut libérer l'espace mémoire manuellement. Pour vérifier que ça marche je peux faire affiche(m1)*/

	//affiche(m1);

}

int q1(int *t, int n){
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

void f(int a, int b, int *s, int *p) {
    *s = a + b;
    *p = a * b;
}

int q1bis(int *t, int n){
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

void q4(int *t, int n, int *x, int *y){
	*x = q1bis(t, n);
	*y = q1(t, n);
}

int* q67(int *tab, int n) {
	int *p;
	p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        p[i] = tab[i];
    }
    return p;
}

int* q8(int *tab, int n){
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

/* Réponse Q2 : il faut donner la taille du tableau car si l'on dépasse
cette taille il va afficher l'adresse suivante de la dernière case mais
qui n'appartient pas au tableau.*/

/*Réponse Q3 : on appelle la fonction f avec 2 int en adresse
et les valeurs sont données ensuite ainsi on peut retourner 2
objets.*/




