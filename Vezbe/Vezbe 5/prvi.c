/*
1. Napisati program koji od korisnika učitava niz dužine n a kao rezultat izračunava i
ispisuje matricu dimenzija nxn. Matrica se sastoji od sledećih vrsta: prva vrsta matrice
su svi elementi niza pomnoženi sa prvim elementom niza, druga vrsta su svi elementi
pomnoženi sa drugim elementom niza, treća sa trećim itd. Memoriju za matricu (kao i
za niz) dinamički alocirati, ali koristiti za predstavljanje matrice samo jednostruki
pokazivač.
*/

#include<stdio.h>
#include<stdlib.h>

void napraviMatricu(int* niz, int n){
    
    int *matrica = malloc(n * n * sizeof(int));

    for(int i = 0; i<n; i++){

        for(int j = 0; j<n; j++){

            *(matrica + i*n + j) = i * j;
        }
    }

    printf("Stampam matricu \n");
    for(int i = 0; i<n; i++){

        for(int j = 0; j<n; j++){

            printf("%i\t", *(matrica + i*n + j));
        }

        printf("\n");
    }

    free(matrica);

}

int main() {

    int n;
    printf("Unesite duzinu niza: ");

    scanf("%i", &n);

    int* niz = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){

        printf("Unesite %i element niza ", i);
        scanf("%i", &niz[i]);
    }

    printf("Sada ulazim u funkciju!\n");

    napraviMatricu(niz, n);

    //free(niz);
}