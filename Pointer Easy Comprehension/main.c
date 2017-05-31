#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *pointer = NULL;
    pointer = malloc(sizeof(int));
    scanf("%d",pointer);        // PAS DE "&"
    printf("%d\n",*pointer);    // AJOUT DE "*"

    int entier = 0;
    scanf("%d",&entier);        // AJOUT DE "&"
    printf("%d\n", entier);     // PAS DE "*"

    int *p = NULL;
    p = malloc(sizeof(entier));
    p = &entier;

    // CONCLUSION
    printf("Conclusion: & <=> dérivé | rien <=> normal | * = primitive \n"
           "Donc quand on initialise un pointeur, on initialise une primitive, \n"
           "scanf() va demander la dérivé de la primitive, soit rien. \n"
           "Et quand on initialise normalement, c'est du normal.\n");

    printf("%d , %d , %d\n", *pointer, pointer, &pointer);
    printf("%d , \t , %d\n", entier, &entier);
    printf("%d , %d , %d", *p, p, &p);

    free(pointer);

    return 0;
}
