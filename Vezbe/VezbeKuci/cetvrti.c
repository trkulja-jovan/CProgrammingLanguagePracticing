#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void ucitaj_matricu(float* matrica, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            printf("Unesite element matrice \n");
            scanf("%f", &matrica[i * n + j]);
        }
    }

}

float* izdvoj_dijagonalu(float* matrica, int n){

    float* povratni = malloc(n * sizeof(float));

    for(int i = 0; i < n; i++){

        povratni[i] = matrica[i * n + i];
    }

    return povratni;
}

float aritmeticka_sredina(float n, float m) {

    return (n + m) / 2;
}

float geometrijska_sredina(float n, float m) {

    return sqrt(n * m);
}

float* novi_niz(float* glavnaD, int n, float (*fun)(float, float)) {

    float* noviNiz = malloc((n - 1) * sizeof(float));

    for(int i = 0; i < n - 1; i++){
        int j = 0;
        noviNiz[i] = fun(glavnaD[i], glavnaD[j++]);
    }

    return noviNiz;

}

int main() {

    int n;
    float* matrica;

    printf("Unesite velicinu matrice \n");
    scanf("%i", &n);

    matrica = malloc(n * sizeof(float));

    ucitaj_matricu(matrica,n);

    float* glavna = izdvoj_dijagonalu(matrica, n);

    float* aritmeticka = novi_niz(glavna, n, aritmeticka_sredina);
    printf("Niz aritmetickih sredina na glavnoj dijagonali\n");

    for(int i = 0; i < n - 1; i++){
        printf("%f , ", aritmeticka[i]);
    }

    float* geometrijska = novi_niz(glavna, n, geometrijska_sredina);
    printf("Niz geometrijskih sredina na glavnoj dijagonali\n");

    for(int i = 0; i < n - 1; i++){
        printf("%f , ", geometrijska[i]);
    }

    free(matrica);
    free(glavna);
    free(aritmeticka);
    free(geometrijska);

    return 0;
}