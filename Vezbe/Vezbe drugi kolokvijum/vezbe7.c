#include<stdio.h>
#include<stdlib.h>

int globalnaVelNiz;

typedef struct {

    char ime[50];
    char prezime[50];
    int godine;
    int god_iskustva;

} Osoba;

Osoba* ucitaj(int n) {
    
    Osoba* osobe = malloc(n * sizeof(Osoba));
    printf("Unesite osobe: \n");

    for (int i = 0; i < n; i++) {

        printf("Unesite ime osobe %i> ", i);
        scanf(" %[^\n]", osobe[i].ime);
        printf("Unesite prezime osobe %i> ", i);
        scanf(" %[^\n]", osobe[i].prezime);
        printf("Unesite godine starosti osobe %i> ", i);
        scanf("%i", &osobe[i].godine);
        printf("Unesite godine iskustva osobe %i> ", i);
        scanf("%i", &osobe[i].god_iskustva);

    }

    return osobe;
}

float prosecna_starost(int n, Osoba* niz){

    float vr = 0.0;
    
    for(int i = 0; i < n; i++){

        vr += niz[i].godine;
        
    }

    return vr / n;
}

float prosecni_staz(int n, Osoba* niz){

    float vr = 0.0;

    for(int i = 0; i < n; i++){

        vr += niz[i].god_iskustva;
    }

    return vr / n;
}

Osoba* novNiz(int n, Osoba* niz){

    for(int i = 0; i < n; i++){

        if(niz[i].godine < 50 && niz[i].god_iskustva > 20){
            globalnaVelNiz++;
        }
    }

    Osoba* povratni = malloc(globalnaVelNiz * sizeof(Osoba));

    int j = 0;

    for(int i = 0; i < n; i++){

        if(niz[i].godine < 50 && niz[i].god_iskustva > 20){
            povratni[j++] = niz[i];
        }
    }

    return povratni;
}

int main(){

    int n;

    printf("Unesite velicinu niza \n");

    scanf("%i", &n);

    Osoba* niz = ucitaj(n);

    printf("Uneli ste sledece osobe: \n");

    for(int i = 0; i < n; i++){

        printf("Osoba %i\n", i);

        printf("Ime: %s \n", niz[i].ime);
        printf("Prezime: %s \n", niz[i].prezime);
        printf("Godine: %i \n", niz[i].godine);
        printf("Godine iskustva: %i \n", niz[i].god_iskustva);
    }

    printf("Prosecna starost osoba je %f \n", prosecna_starost(n, niz));

    printf("Prosecna godina iskustva unetih osoba je %f \n", prosecni_staz(n, niz));

    Osoba* nizic = novNiz(n, niz);

    printf("Osobe koje imaju vise od 20 god radnog isk i manje od 50 god ima ih %i \n", globalnaVelNiz);

    for(int i = 0; i < globalnaVelNiz; i++){

        printf("Osoba %i\n", i);

        printf("Ime: %s \n", nizic[i].ime);
        printf("Prezime: %s \n", nizic[i].prezime);
        printf("Godine: %i \n", nizic[i].godine);
        printf("Godine iskustva: %i \n", nizic[i].god_iskustva);
    
    }

    free(niz);
    free(nizic);

    return 0;
    
}