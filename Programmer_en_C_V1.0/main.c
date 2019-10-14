#include <stdio.h>
#include <stdlib.h>

#define NFOIS 5

int main()
{
    int i;
    float x;
    float racx;

    printf("Bonjour \n");

    printf("Je vais vous calculer %d racines carrees\n", NFOIS);

    for(i=0;i<NFOIS;i++) {
        printf("Donnez un nombre : ");
        scanf("%f", &x);
        if (x<0.0)
            printf("Le nombre %f ne possède pas de racine carree \n", x);
        else{
            racx=sqrt(x);
            printf("le nombre %f a pour racine carrée : %f\n",x,racx);
        }
    }

    printf("C FINI A PLUS LES ZAMIS");
}
