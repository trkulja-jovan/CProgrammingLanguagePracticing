#include<stdio.h>
#include<stdlib.h>

typedef struct cvor {

    int info;

    struct cvor* veza;

} Cvor;

Cvor* ucitaj(int broj){

    Cvor* koren = NULL;

    for(int i = 0; i < broj; i++){

        Cvor* cvor = (Cvor*) malloc(sizeof(Cvor));

        cvor->info = i;

        cvor->veza = koren;
        koren = cvor;

    }

    return koren;
}

void stampaj(Cvor* koren){

    Cvor* tekuci = koren;

    while(tekuci != NULL){

        printf("Info u cvoru %i \n", tekuci->info);

        tekuci = tekuci->veza;

    }
}

void oslobodiMemoriju(Cvor* koren){

    Cvor* tekuci = koren;

    while(tekuci->veza != NULL){

        free(tekuci);
        tekuci = tekuci->veza;
    }
}

int main(){
    
    int broj;

    printf("Unesite veliicnu liste \n");

    scanf("%i", &broj);

    Cvor* koren = ucitaj(broj);

    stampaj(koren);

    oslobodiMemoriju(koren);

    return 0;
}