/*
Napisati program koji učitava stringove od korisnika sve dok se ne unese string
“stop”. Omogućiti korisniku da može da unese string koji sadrži razmak. Program po
učitavanju svakog stringa poziva funkciju int prebroj(char* s) koji akumulira u globalnoj
promenljivoj int ukupno_slova koliko je ukupno slova uneto. Na kraju ispisati koliko je
slova ukupno uneto.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ukupno_slova = 0;

int prebroj(char* niz){

    for(int i = 0; i < strlen(niz); i++){
        ukupno_slova += 1;
    }
}

int main(){

    printf("Unosite stringove dokle god ne unesete string stop\n");

    char* niz = malloc(20 * sizeof(char));

    do {

        printf("Unesite string \n");
        gets(niz);
        prebroj(niz);

    } while(strcmp(niz, "stop"));

    printf("Ukupno je uneto %i slova\n", ukupno_slova);

    free(niz);

    return 0;
}