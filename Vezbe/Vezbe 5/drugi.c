#include<stdio.h>
#include<stdlib.h>

void ucitaj(int* matrica, int n){
    
    for (int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++){
            
            scanf("%i",*(matrica + i*n + j));
            
        }
    }
}

int main() {

    int n;

    printf("Unesite velicinu matrice [n x n]\n");

    scanf("%i",&n);

    int* matrica = malloc(n * n * sizeof(int));

    printf("Unesite matricu sada\n");
    
    ucitaj(*matrica, n);
    
    
}