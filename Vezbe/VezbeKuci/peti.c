#include<stdio.h>
#include<stdlib.h>

void ucitaj_matricu(float** matrica, int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Unesite element matrice -> ");
            scanf("%f", &matrica[i][j]);
            printf("\n");
        }
    }
}

float* izdvoj_vrstu(float** matrica, int n, int m, int i) {

    float* povratni = malloc(n * sizeof(float));

    for(int j = 0; j < m; j++){
        povratni[j] = matrica[i][j];
    }

    return povratni;
}

int br_pozitivnih(float* drugiNiz, int duzina_niza) {

    int broj;

    for(int i = 0; i < duzina_niza; i++){
        if(drugiNiz[i] >= 0)
            broj++;
    }

    return broj;

}

int br_negativnih(float* drugiNiz, int duzina_niza) {

    int broj;

    for(int i = 0; i < duzina_niza; i++){
        if(drugiNiz[i] < 0)
            broj++;
    }

    return broj;

}

int main() {

    int n,m;

    printf("Unesite prvu dimenziju matrice -> ");
    scanf("%i", &n);

    printf("\n");

    printf("Unesite drugu dimenziju matrice -> ");
    scanf("%i", &m);

    float** matrica = malloc(n * m * sizeof(float*));

    ucitaj_matricu(matrica, n , m);

    printf("Unesite vrstu za izdvajanje -> ");
    int i;
    
    do {
        scanf("%i", &i);
        printf("\n");
    } while(i > n || i < 0);

    float* drugiNiz = izdvoj_vrstu(matrica, n, m, i);

    int br_poz = br_pozitivnih(drugiNiz, n);
    int br_neg = br_negativnih(drugiNiz, n);

    printf("U izdvojenom nizu ima %i pozitivnih i %i negativnih brojeva \n", br_poz, br_neg);
    

}