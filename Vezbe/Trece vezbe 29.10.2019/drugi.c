/*Napisati funkcije obim i površina koje kao argument primaju poluprečnik
kruga a kao povratnu vrednost vraćaju redom obim i površinu kruga. 
Konstantu π u kodu definisati kao makro koji ima vrednost 3.14.
*/

#include<stdio.h>

#define PI 3.14

float obim(float r){

    return 2 * r * PI;
}

float povrsina(float r){

    return r * r * PI;
}

int main(){

    float pp;
    printf("Unesite poluprecnik kruga -> ");

    scanf("%f", &pp);

    float obimK = obim(pp);
    float povr = povrsina(pp);

    printf("Za uneti poluprecnik %f obim kruga je: %f, a povrsina je: %f \n", pp, obimK, povr);
}