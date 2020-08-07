#include<stdio.h>
#include<stdlib.h>

typedef struct cvor {

    char naziv[50];
    char sifra[50];
    float prosek;

    struct cvor* levi;
    struct cvor* desni;

} Cvor;

Cvor* ucitaj(){

    int broj;

    FILE* fajl = fopen("predmeti.txt", "r");

    fscanf(fajl, "%i", &broj);   

    Cvor* koren = NULL;

    Cvor* korenski = (Cvor*) malloc(sizeof(Cvor*));
    fscanf(fajl, "%s", korenski->naziv);
    fscanf(fajl, "%s", korenski->sifra);
    fscanf(fajl, "%f", korenski->prosek);

    korenski->levi = NULL;
    korenski->desni = NULL;

    koren = korenski;

    for(int i = 1; i < broj; i++){

        Cvor* novi2 = (Cvor*) malloc(sizeof(Cvor*));
        fscanf(fajl, "%s", novi2->naziv);
        fscanf(fajl, "%s", novi2->sifra);
        fscanf(fajl, "%f", novi2->prosek);

        dodaj(novi2, &koren);
    }
}


void dodaj(Cvor* elem, Cvor** koren){

    if(*koren != NULL){
        *koren = elem;
        koren->levi = NULL;
        koren->desni = NULL;
        return;
    }

    if(elem->prosek > koren->prosek){
        dodaj(elem, koren->desni);
    } else {
        dodaj(elem, koren->levi);
    }
}

int main(){

    Cvor* koren = ucitaj();

}