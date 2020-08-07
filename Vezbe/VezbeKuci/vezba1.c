#include<stdio.h>
#include<stdlib.h>

float** matrica;

void ucitajCene(float** matrica, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Unesite element matrice : ");
            scanf("%f", &matrica[i][j]);
        }
    }
}

int veci_od(float b1, float b2){
    return b1 > b2 ? 1 : 0;
}

int manji_od(float b1, float b2){
    return b2 > b1 ? 1 : 0;
}

void uvecaj(float* vrednost, float postotak){

    *(vrednost) += *(vrednost) * postotak / 100.0;
}

void umanji(float* vrednost, float postotak){
    *(vrednost) -= *(vrednost) * postotak / 100.0;
}

void modifikuj_vrednost(float** matrica, float postotak, void (*fun)(float*, float)){

    for(int i = 0; i < n; i++){
        fun(matrica[i], postotak);
    }

    
}


int main(){

    int n;

    printf("Unesite velicinu matrice \n");
    scanf("%d", &n);

    matrica = malloc(n * sizeof(float*));

    ucitajCene(matrica, n);

    int opcija;

    printf("Unesite 1 za uvecanje ili 0 za umanjenje cena\n");

    do {
        scanf("%i", &opcija);
    } while(opcija < 0 || opcija > 1);

    if(opcija == 1){
        printf("Sada racunamo uvecanje cena\n");
    }

    float cena, postotak;

    printf("Unesite cenu za poredjenje \n");
    scanf("%f", &cena);
    printf("Unesite postotak \n");
    scanf("%f", postotak);




    free(matrica);

}