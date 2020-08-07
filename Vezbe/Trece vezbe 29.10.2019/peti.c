/*
Napraviti header fajl koji definiše operacije nad celim brojevima i
implementirati njegove funkcije. Definisati operacije +, -, *, / i % kao funkcije
koje kao argumente primaju dva cela broja a kao rezultat vraćaju rezultat
odgovarajuće operacije. U main-u testirati implementaciju header fajla.
*/

#include<stdio.h>

int main(){

    int a,b;
    printf("Unesite prvi broj -> ");

    scanf("%i", &a);

    printf("Unesite drugi broj -> ");

    scanf("%i", &b);

    int rezS = saberi(a,b);
    int rezO = oduzmi(a,b);
    float rezP = pomnozi(a,b);
    float rezPodel = podeli(a,b);

    printf("Rezultat sabiranja je %i \n", rezS);
    printf("Rezultat oduzimanja je %i \n", rezO);
    printf("Rezultat mnozenje je %f \n", rezP);
    printf("Rezultat podeli je %f \n", rezPodel);
}   