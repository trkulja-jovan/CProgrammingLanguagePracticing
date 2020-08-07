#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int pojavljivanje(char* niz){

    int br = 0;

    for(int i = 0; i < strlen(niz); i++){

        if(niz[i] == 'a')
            br++;
    }

    return br;
}

int main() {

    char* niz = malloc(50 * sizeof(char));

    printf("Unesite neki string: \n");

    scanf("%s",niz);
    printf("stigao vamo %s\n", niz);

    int a = pojavljivanje(niz);

    printf("Slovo 'a' se u stringu %s pojavljuje ukupno -> %i puta", niz, a);

}
