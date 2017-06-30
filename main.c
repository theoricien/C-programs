#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void encrypt(FILE* f, char e[], int size)
{
    char s[size+1];
    char fname[48];
    for(int i=0;i<48;i++)
        fname[i] = '\0';
    strcat(fname, e);
    strcat(fname, ".crypt");
    printf("%s", fname);
    FILE *ff = fopen(fname, "a+");
    fgets(s, sizeof(s), f);
    for(int i=0; i<sizeof(s);i++)
    {
        s[i] += 5;
    }
    fwrite(s,1,sizeof(s),ff);
}

void decrypt(FILE* f, char e[], int size)
{
    char f_name[48];
    for(int i=0;i<48;i++)
        f_name[i] = '\0';
    strcat(f_name, e);
    strcat(f_name, ".txt");
    FILE *output = fopen(f_name,"a+");
    char s[size + 1];
    fgets(s,sizeof(s),f);
    for(int i = 0; i < sizeof(s); i++)
        s[i] -= 5;
    fwrite(s, 1, sizeof(s), output);
}

int main()
{
    int choice = 0;
    int ch;
    char *p;
    printf("Welcome to File De/Encoder !\n Choose what you want to do:\n(1) Encrypt\n(2) Decrypt\n");
    while(!choice)
    {
        if(kbhit())
        {
            int key = getch();
            switch(key)
            {
            case '1':
                choice = 1;
                break;
            case '2':
                choice = 2;
                break;
            default:
                printf("Bad key entered\n");
                break;
            }
        }
    }
    char filename[48];
    for(int i=0;i<48;i++)
        filename[i] = '\0';
    FILE *file;
    if(choice == 1)
    {
        printf("\nInput the file you want to encrypt (extension included):");

        if (fgets(filename, sizeof(filename), stdin))
        {
            p = strchr(filename, '\n');
            if (p)
                *p = '\0';
            else
                while (  ((ch = getchar()) != '\n')&& !feof(stdin)&& !ferror(stdin)  );
        }
        char dest[48];
        for(int i=0;i<48;i++)
            dest[i] = '\0';
        for(int i  = 0; i < 48; i++)
        {
            if(filename[i] == '.')
            {
                i = 50;
            }
            else
            {
                dest[i] = filename[i];
            }
        }
        file = fopen(filename, "a+");
        int size = 0;
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        fseek(file, 0, SEEK_SET);

        encrypt(file, dest, size);
        fclose(file);
        remove(filename);
        FILE *pass = fopen("p.pass","a+");
        char password[48];
        for(int i=0;i<48;i++)
            password[i] = '\0';
        printf("\nInput a password (48 length):");

        if (fgets(password, sizeof(password), stdin))
        {
            p = strchr(password, '\n');
            if (p)
                *p = '\0';
            else
                while (  ((ch = getchar()) != '\n')&& !feof(stdin)&& !ferror(stdin)  );
        }
        // encrypt the pass
        for(int i = 0; i < 48; i++)
            password[i] += 10;
        fwrite(password, 1, sizeof(password), pass);
        fclose(pass);
    }
    else
    {
        printf("\nInput the file you want to decrypt (extension included):");
        char dest[48];
        for(int i=0;i<48;i++)
            dest[i] = '\0';
        if (fgets(filename, sizeof(filename), stdin))
        {
            p = strchr(filename, '\n');
            if (p)
                *p = '\0';
            else
                while (  ((ch = getchar()) != '\n')&& !feof(stdin)&& !ferror(stdin)  );
        }
        for(int i  = 0; i < 48; i++)
        {
            if(filename[i] == '.')
            {
                char verif[5] = ".crypt";
                for(int j = 0; j < 5; j++)
                {
                    if(filename[i+j] != verif[j])
                    {
                           printf("Bad file\n");
                           getchar();
                           exit(1);
                    }
                }
                i = 50;
            }
            else
            {
                dest[i] = filename[i];
            }
        }

        printf("\nInput the password of the file:");
        char password[48];
        if (fgets(password, sizeof(password), stdin))
        {
            p = strchr(password, '\n');
            if (p)
                *p = '\0';
            else
                while (  ((ch = getchar()) != '\n')&& !feof(stdin)&& !ferror(stdin)  );
        }
        FILE *pass = fopen("p.pass", "a+");
        char r_pwd[48];
        for(int i=0;i<48;i++)
            r_pwd[i] = '\0';
        fgets(r_pwd, sizeof(r_pwd), pass);

        for(int i = 0; i < 48; i++)
            r_pwd[i] -= 10;
        printf("r_pwd: %s / password: %s\n", r_pwd, password);
        if(strcmp(r_pwd,password) == 0)
        {
            file = fopen(filename, "a+");
            int size = 0;
            fseek(file, 0, SEEK_END);
            size = ftell(file);
            fseek(file, 0, SEEK_SET);
            decrypt(file, dest, size);
            fclose(pass);
            remove("p.pass");
            fclose(file);
            remove(filename);
        }
        else
        {
            printf("Bad password\n");
            getchar();
            exit(1);
        }
    }
    return 0;
}
