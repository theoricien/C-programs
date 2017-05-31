#include <stdio.h>
#include <stdlib.h>

void wait()
{
    getchar(); // will stock the '\n'
    getchar();
}

int main(int    argc, char  **argv)
{
    int input;
    int character;

    printf("************************\n"
           "*  ASCII TABLE OF DOOM *\n"
           "************************\n\n");
    printf("What do you search ?\n-(t)able\n-(c)haracter\nEnter your choice:\n");

    input = getchar();

    switch(input)
    {
    case 't':
        printf("Character\tDecimal\tHexadecimal\tOctal\n");
        for(int i = 33; i < 255; i++){printf("%c\t\t%d\t%x\t\t%o\n",i,i,i,i);}
        #ifdef _WIN32
            wait();
        #endif
        return 0;
        break;
    case 'c':
        printf("\nWhat are you searching for ?\n");
        getchar(); // stock the '\n'
        character = getchar();
        printf("Your char is %c\nDecimal value:\t%d\nHexadecimal value:\t%x\nOctal value:\t%o\n",character,character,character,character);
        #ifdef _WIN32
            wait();
        #endif
        return 0;
        break;
    default:
        printf("Wrong input, exiting the program..");
        #ifdef _WIN32
            wait();
        #endif
        return 0;
        break;
    }
    return 0;
}
