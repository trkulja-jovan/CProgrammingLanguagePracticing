#include<stdio.h>
#include "header.h"

int saberi(int a, int b){

    return a + b;
}

int oduzmi(int a, int b){

    return a - b;
}

float pomnozi(int a, int b){

    return a * b;
}

float podeli(int a, int b){

    if(b == 0)
        return 0.0;

    return a / b;
}