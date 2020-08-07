/*
Napisati funkciju koja kao parametar prima string i za njega proverava da
li je palindrom.
*/

#include<stdio.h>
#include<string.h>

int palindrom(char niz[]){

    int i;
    int j = strlen(niz) - 1;

    for(i = 0; (i < strlen(niz) || j >= 0); i++, j--){

        if(niz[i] != niz[j])
            return 0;
    }

    return 1;
}

int main(){

   char niz[30];

   printf("Unesi string -> ");

   gets(niz);

   if(palindrom(niz)){
       printf("Uneti string je palindrom \n");
   } else {
       printf("Uneti string nije palindrom \n");
   }





}