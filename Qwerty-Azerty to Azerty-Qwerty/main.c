#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    end(char* str, FILE* save_file)
{
    fputs(str,save_file);
    fclose(save_file);
    exit(0);
}

void    clear()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

int main()
{
    int c;
    FILE    *save_file = fopen("save.txt", "w");
    char    str[5120];
    char    qwerty[94] = "qwertyuiopasdfghjkl;zxcvbnm,./QWERTYUIOPASDFGHJKL:ZXCVBNM<>?1234567890-=[]'\\!@#$%^&*()_+{}\"|\\|";
    char    azerty[94] = "azertyuiopqsdfghjklmwxcvbn,;:!AZERTYUIOPQSDFGHJKLMWXCVBN?./§&é\"'(-è_çà)=^$ù*1234567890°+¨£%µ<>";
    char    *cat;
    printf("Auto-corrector QWERTY to AZERTY (the opposite works)(Max length is 5120 chars)\nPress Escape for quit the program (your text will be save in save.txt\nBegin your text:\n");
    while(1)
    {
        c = getch();
        sprintf(&cat,"%c",(int)c);
        if(cat == (int)27)
        {
            end(str, save_file);
        }
        // Search for the qwerty character
        for(int i = 0; i < sizeof(qwerty); i++)
        {
            if(qwerty[i] == cat)
            {
                cat = azerty[i];
                break;
            }
        }
        clear();
        strcat(str,&cat);
        printf("%s", str);
    }
    fputs(str,save_file);
    fclose(save_file);

    return 0;
}
