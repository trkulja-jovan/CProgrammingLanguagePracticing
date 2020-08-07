#include<stdio.h>
#include<stdlib.h>

typedef struct cvor {

    char ime[50];
    int bri;
    float brbod;

    struct cvor* levi;
    struct cvor* desni;

} cvor;

cvor* ucitaj(){

    int prvibr;

    FILE* fajl = fopen("studenti.dat", "r");

    fscanf(fajl, "%i", &prvibr);

    cvor* koren = NULL;

    for(int i = 0; i < prvibr; i++){

        cvor* element = (cvor*) malloc(sizeof(cvor));

        fgets(element->ime, 50, fajl);
        fscanf(fajl, "%i", &element->bri);
        fscanf(fajl, "%f", &element->brbod);

        dodaj(element, &koren);
    }

    return koren;
}

void dodaj(cvor* element, cvor** pkoren){

    if(*pkoren == NULL){

        *pkoren = element;
        element->levi = NULL;
        element->desni = NULL;

    } else {
        
        if(element->bri < (*pkoren)->bri){
            dodaj(element, &(*pkoren)->levi);
        } else {
            dodaj(element, &(*pkoren)->desni);
        }

    }
}

cvor* pronadji_studenta(cvor* koren, int broj){

    if(koren == NULL)
        return NULL;

    else {
        if(koren->bri == broj){
            return koren;
        }

        pronadji_studenta(koren->levi, broj);
        pronadji_studenta(koren->desni, broj);
    }

}

cvor* nadji_najboljeg(cvor* koren){

    if(koren == NULL)
        return NULL;

    else {

        cvor* tmp = koren;

        if(tmp->brbod > koren->brbod)
            return tmp;

        nadji_najboljeg(koren->levi);
        nadji_najboljeg(koren->desni);
    }

}

int main(){

    cvor* koren = ucitaj();

    cvor* student = pronadji_studenta(koren, 12);

    if(student != NULL){

        printf("Ime studenta %s \n", student->ime);
        printf("Broj indeksa %i \n", student->bri);
        printf("Broj bodova %f \n", student->brbod);
    }

    cvor* najbolji = nadji_najboljeg(koren);

    if(najbolji != NULL){

        printf("Ime studenta %s \n", najbolji->ime);
        printf("Broj indeksa %i \n", najbolji->bri);
        printf("Broj bodova %f \n", najbolji->brbod);
    }

    return 0;
}