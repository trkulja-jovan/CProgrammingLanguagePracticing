#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct voce {

    char naziv[100];
    int cena;
    int kolicina;

    struct voce* sledeci;

} Voce;

Voce* ucitaj(){
    
    FILE* fajl = fopen("voce.txt", "r");
    int brojVoca;

    fscanf(fajl, "%i", &brojVoca);
    Voce* koren = NULL;

    for(int i = 0; i < brojVoca; i++){
        int indeks;

        Voce* elem = (Voce*) malloc(sizeof(Voce*));

        fscanf(fajl, "%s", elem->naziv);
        fscanf(fajl, "%i", &(elem->cena));
        fscanf(fajl, "%i", &(elem->kolicina));

        fscanf(fajl, "%i", &indeks);
        elem->sledeci = NULL;

        if(indeks < 0 || koren == NULL){
            elem->sledeci = koren;
            koren = elem;
        } else {
            Voce* tekuci = koren;
            while (tekuci->sledeci != NULL && indeks > 1) {
                tekuci = tekuci->sledeci;
                indeks--;
            }
            elem->sledeci = tekuci->sledeci;
            tekuci->sledeci = elem;
        }
    }

    fclose(fajl);

    return koren;

}

void rasprodaja(Voce* koren){

    Voce* tekuci = koren;

    while(tekuci -> sledeci != NULL){

        if(tekuci->kolicina < 30){
            tekuci->cena *= 0.8;
        }

        tekuci = tekuci -> sledeci;
    }
     
}

void izracunajZaradu(Voce* koren){

    int vr = 0;

    Voce* tekuci = koren;

    while(tekuci->sledeci != NULL){
        vr += tekuci->cena;
        tekuci = tekuci->sledeci;
    }

    printf("Od prodaje svog voca moze se zaraditi -> %i", vr);
}

void oslobodiMemoriju(Voce* koren){

    Voce* tekuci = koren;

    while(tekuci->sledeci != NULL){
        free(tekuci);
        tekuci = tekuci->sledeci;
    }
}

void stampaj(Voce* koren) {
    Voce* tekuci = koren;
    while (tekuci != NULL) {
        printf("Naziv: %s, cena: %i, kolicina: %i\n", tekuci->naziv, tekuci->cena, tekuci->kolicina);
        tekuci = tekuci->sledeci;
    }
}

int main(){

    Voce* koren = ucitaj();

    rasprodaja(koren);

    izracunajZaradu(koren);
    
    stampaj(koren);
    oslobodiMemoriju(koren);

    return 0;
}