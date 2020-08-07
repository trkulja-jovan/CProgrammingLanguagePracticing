#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct voce{
    char naziv[100];
    int cena;
    int kolicina;
    struct voce* veza;
} vocka;

vocka* ucitaj(char *ime_fajla) {
    int broj_vocki;
    FILE* f = fopen(ime_fajla,"r");
    fscanf(f, "%i ", &broj_vocki);

    vocka* lista = NULL;
    for (int i = 0; i < broj_vocki; i++){
        int indeks;
        vocka* v = (vocka*) malloc(sizeof(vocka*));
		fscanf(f, "%s ", v->naziv);
        fscanf(f, "%i ", &(v->cena));
		fscanf(f, "%i ", &(v->kolicina));
		fscanf(f, "%i", &indeks);
        v->veza = NULL;
        if (indeks <= 0 || lista == NULL) {
            v->veza = lista;
            lista = v;
        } else {
            vocka* tekuci = lista;
            while (tekuci->veza != NULL && indeks > 1) {
                tekuci = tekuci->veza;
                indeks--;
            }
            v->veza = tekuci->veza;
            tekuci->veza = v;
        }
    }
    fclose(f);
    return lista;
}

void rasprodaja(vocka* lista) {
    vocka* tekuci = lista;
    while (tekuci != NULL) {
        if (tekuci->kolicina < 30)
            tekuci->cena *= 0.8;
        tekuci = tekuci->veza;
    }
}

void izracunaj_zaradu(vocka* lista) {
    vocka* tekuci = lista;
    int vrednost = 0;
    while (tekuci != NULL) {
        vrednost += tekuci->cena * tekuci->kolicina;
        tekuci = tekuci->veza;
    }
    printf("Ukupna zarada koja se moze ostvariti prodajom sveg voca koje je na lageru je %i.\n", vrednost);
}

void stampaj(vocka* lista) {
    vocka* tekuci = lista;
    while (tekuci != NULL) {
        printf("Naziv: %s, cena: %i, kolicina: %i\n", tekuci->naziv, tekuci->cena, tekuci->kolicina);
        tekuci = tekuci->veza;
    }
}

void oslobodi_memoriju(vocka* lista) {
    vocka* tekuci = lista;
    while (tekuci != NULL) {
        vocka* za_brisanje = tekuci;
        tekuci = tekuci->veza;
        free(za_brisanje);
    }
}

int main(){
    vocka* lista = ucitaj("voce.txt");
    rasprodaja(lista);
    izracunaj_zaradu(lista);
    stampaj(lista);
    oslobodi_memoriju(lista);
    return 0;
}

