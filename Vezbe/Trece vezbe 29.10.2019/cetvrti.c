/*
Napisati funkciju koja kao parametar prima string i u prosleđenom stringu
menja sva mala slova u velika (aLiBaba → ALIBABA). Funkcija nema
povratnu vrednost.
*/

#include<stdio.h>
#include<string.h>


void malaVelika(char niz[]){
    
    int i = 0;
    while(i < strlen(niz)){

        putchar(toupper(niz[i++]));

    }

    printf("\n");
}

int main(){

    char niz[30];
    printf("Unesite string: \n");

    gets(niz);

    malaVelika(niz);

}
