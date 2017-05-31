#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int taille;

static const char alphabet[] =   // Alphabet
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

static const int alphabetTaille = sizeof(alphabet) - 1;     // Taille avec sizeof()

void bruteImpl(char * str, int index, int maxDepth)
{
    int i;
    for (i = 0; i < alphabetTaille; ++i)
    {
        str[index] = alphabet[i];  // buf[0]

        if (index == maxDepth - 1)
        {
            printf("%s\n", str);
        }

        else
        {
            bruteImpl(str, index + 1, maxDepth); // on incrémente index
        }

    }
}

void bruteTaille(int maxTaille)
{
    char* buf = malloc(maxTaille + 1); // pb
    int i;

    for (i = 1; i <= maxTaille; ++i)
    {
        memset(buf, 0, maxTaille + 1); // Buf pointe maxTaille + 1 qui remplit la mémoire avec 0 octet
        bruteImpl(buf, 0, i); // buf = *str ; 0 = index ; maxDepth = i de for()
    }

    free(buf);
}

int main(void)
{
    puts("Vas-y dit moi le nbr de carateres mdr: ");
    scanf("%d",&taille);
    bruteTaille(taille);
    return 0;
}
