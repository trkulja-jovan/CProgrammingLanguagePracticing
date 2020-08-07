#include<stdio.h>
#include<stdlib.h>

typedef struct cvor {

    char ime[50];
    int bri;
    int bodovi;

    struct cvor* veza;

} Student;

Student* ucitaj(){

    int broj;

    FILE* fajl = fopen("studenti.dat", "r");

    fscanf(fajl, "%i", &broj);

    Student* koren = NULL;

    for(int i = 0; i < broj; i++){

        Student* student = (Student*) malloc(sizeof(Student));

        fgets(student->ime, 50, fajl);
        fscanf(fajl, "%i", &student->bri);
        fscanf(fajl, "%i", &student->bodovi);

        student->veza = koren;
        koren = student;

    }

    return koren;
}

void stampaj(Student* koren){

    Student* tekuci = koren;

    while(tekuci != NULL){

        printf("Student: ime %s, broj indeksa %i, broj bodova %i \n", tekuci->ime, tekuci->bri, tekuci->bodovi);
        fflush(stdout);
        tekuci = tekuci->veza;
    }
}

void oslobodiMemoriju(Student* koren){

    Student* tekuci = koren;

    while(tekuci -> veza != NULL){

        free(tekuci);
        tekuci = tekuci->veza;
    }
}

int main(){ 

    Student* koren = ucitaj();

    stampaj(koren);
    oslobodiMemoriju(koren);

    return 0;
}