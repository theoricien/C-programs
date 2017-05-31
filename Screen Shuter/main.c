#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char touche;

    while(1) {
            Sleep(30);

    if (kbhit()) {
        puts("touche presse");
        touche = getch();
        printf("%d\n\n", (int) touche);
        if((int)touche == 47) {

            SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2); //donne l'instrution pour éteindre le moniteur

            char touche2;
            if (kbhit()) {
                puts("touche presse");
                touche2 = getch();
                printf("%d\n\n", (int) touche2);
                if((int)touche2 != 8) {
                        SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1); //donne l'instrution pour rallumer le moniteur

            exit(0);
                }
            }

        }

    }
}
}
