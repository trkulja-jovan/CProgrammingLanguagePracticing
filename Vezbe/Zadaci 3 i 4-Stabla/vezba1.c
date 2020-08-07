#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char ime[50];
    int bri;
    int bodovi;
    struct node* levi;
    struct node* desni;
} root;

void dodajCvor(root* koren, root* tekuci) {
    if(koren == NULL) {
        koren = tekuci;
        koren->levi = NULL;
        koren->desni = NULL;
    } else {
        if(tekuci->bodovi < koren->bodovi) {
            dodajCvor(koren->levi, tekuci);
        } else {
            dodajCvor(koren->desni, tekuci);
        }
    }
}

void stampajStablo(root* koren) {
    if(koren == NULL) return;
    stampajStablo(koren->levi);
    printf("%s", koren->ime);
    stampajStablo(koren->desni);
}

root* ucitaj() {
    FILE* file = fopen("studenti.dat", "r");
    int br;
    fscanf(file, "%i ", &br);
    root* koren = NULL;
    for(int i = 0; i < br; i++) {
        root* tekuci = (root*) malloc(sizeof(root*));
        fgets(file, 50, tekuci->ime);
        fscanf(file, "%i ", &tekuci->bri);
        fscanf(file, "%i ", &tekuci->bodovi);
        dodajCvor(koren, tekuci);
    }
    return koren;
}



int main() {
    root* koren = ucitaj();
    stampajStablo(koren);
    return 1;
}