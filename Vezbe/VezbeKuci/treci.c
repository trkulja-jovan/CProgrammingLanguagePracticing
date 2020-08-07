#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ucitajKnjige(char** knjige, int n){

    for(int i = 0; i < n; i++){
        printf("Unesite jednu knjigu \n");
        gets(knjige[i]);
    }

    for(int i = 0; i < n; i++){
        puts(knjige[i]);
    }
}

void sortiraj(char** knjige, int n, int(*fun)(char*,char*)){

    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j < n; j++){
            if(fun(knjige[i], knjige[j]) > 0){

                char* tmp = malloc(100 * sizeof(char));

                strcpy(tmp, knjige[i]);
                strcpy(knjige[i], knjige[j]);
                strcpy(knjige[j], tmp);
                free(tmp);
                
            }
        }
    }

}

int veci(char* prva, char* druga) {
    return strcmp(prva, druga);
}

int main(){

    int n;
    char** knjige;

    printf("Unesite koliko ukupno ima knjiga \n");
    scanf("%i", &n);
    getchar();

    knjige = malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        knjige[i] = malloc(100 * sizeof(char));
    }

    ucitajKnjige(knjige, n);
    sortiraj(knjige,n, veci);

    printf("Sortiran niz \n");
    for(int i = 0; i < n; i++){
        puts(knjige[i]);
    }

    free(knjige);

}