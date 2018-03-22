#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define PATH_MAX 1024

void
welcome_message (void)
{
    printf(
            " ######\\              ##\\               #######\\  \n"
            "##  __##\\             ## |              ##  __##\\ \n"
            "## /  ## |##\\   ##\\ ######\\    ######\\  ## |  ## |##\\   ##\\ \n"
            "######## |## |  ## |\\_##  _|  ##  __##\\ #######  |## |  ## |\n"
            "##  __## |## |  ## |  ## |    ## /  ## |##  ____/ ## |  ## |\n"
            "## |  ## |## |  ## |  ## |##\\ ## |  ## |## |      ## |  ## |\n"
            "## |  ## |\\######  |  \\####  |\\######  |## |      \\####### |\n"
            "\\__|  \\__| \\______/    \\____/  \\______/ \\__|       \\____## |\n"
            "                                                  ##\   ## |\n"
            "                                                  \\######  |\n"
            "                                                   \\______/ \n"
            "\n"
            "AutoPy 1.0\n"
            "Tool for windows users to just paste the path of their py file to execute it.\n"
            "Type \'s\' to change python path, \'q\' to exit the program\n");
}

void
settings_message (void)
{
    printf( " ######\\             ##\\     ##\\     ##\\                               \n"
            "##  __##\\            ## |    ## |    \\__|                              \n"
            "## /  \\__| ######\\ ######\\ ######\\   ##\\ #######\\   ######\\   #######\\ \n"
            "\\######\\  ##  __##\\\\_##  _|\\_##  _|  ## |##  __##\\ ##  __##\\ ##  _____|\n"
            " \\____##\\ ######## | ## |    ## |    ## |## |  ## |## /  ## |\\######\\  \n"
            "##\\   ## |##   ____| ## |##\\ ## |##\\ ## |## |  ## |## |  ## | \\____##\\ \n"
            "\\######  |\\#######\\  \\####  |\\####  |## |## |  ## |\\####### |#######  |\n"
            " \\______/  \\_______|  \\____/  \\____/ \\__|\\__|  \\__| \\____## |\\_______/ \n"
            "                                                   ##\\   ## |          \n"
            "                                                   \\######  |          \n"
            "                                                    \\______/           \n");
}

void
prepare_console (void)
{
    system("echo off");
    system("color 3f");
    system("cls");
}

void
set_python_path (FILE *cfg, char *py_path)
{
    system("cls");
    settings_message();
    printf("Type the python.exe path\n"
           "(q) to quit\n>");
    char new_path[PATH_MAX];
    memset(new_path,'\0',PATH_MAX);

    if (fgets(new_path, PATH_MAX, stdin) != NULL)
    {
        new_path[strlen(new_path)-1] = '\0';
        if (strcmp(new_path,"q") == 0)
        {
            return;
        }
        else
        {
            fwrite(new_path,1,PATH_MAX,cfg);
            memset(py_path, '\0', PATH_MAX + 1 + PATH_MAX);
            strcat(py_path, new_path);
        }
    }
    else
    {
        printf("[ERROR] fgets get NULL value. Exiting..\n");
        exit(-1);
    }
}

int
main (int argc, char *argv[])
{
    #ifndef _WIN32
        printf("You are not on Windows. Exiting..\n");
        exit(-1);
    #endif
    prepare_console();
    welcome_message();
    char *program_path = getenv("APPDATA");
    strcat(program_path,"\\AutoPy");

    // Looking for directory
    if (CreateDirectory(program_path,NULL) == ERROR_PATH_NOT_FOUND)
    {
        printf("[ERROR] Can't create directory. Exting..\n");
        free(program_path);
        exit(-1);
    }

    strcat(program_path, "\\autopy.cfg");
    FILE *config = fopen(program_path,"a+");
    char python_path[PATH_MAX + 1 + PATH_MAX];
    memset(python_path, '\0', PATH_MAX + 1 + PATH_MAX);

    fgets(python_path, PATH_MAX, config);
    python_path[strlen(python_path)-1] = '\0';

    char file_path[PATH_MAX];

    while(1)
    {
        printf(">");
        if (fgets(file_path, sizeof(file_path), stdin) != NULL)
        {
            file_path[strlen(file_path)-1] = '\0';
            if (strcmp(file_path,"s") == 0)
            {
                set_python_path(config, &python_path);
                system("cls");
                welcome_message();
            }
            else if (strcmp(file_path,"q") == 0)
            {
                printf("Exiting..\n");
                fclose(config);
                free(program_path);
                exit(-1);
            }
            else
            {
                strcat(python_path, " ");
                strcat(python_path, file_path);
                system(python_path);
            }
        }
        else
        {
            printf("[ERROR] fgets get NULL value. Exiting..\n");
            fclose(config);
            free(program_path);
            exit(-1);
        }
        memset(file_path, '\0', PATH_MAX);
    }
    fclose(config);
    free(program_path);
    return 0;
}
