#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Function who will translate normal language to leet language
void leetspeak(char *str, int size, char* o)
{
	for(int i = 0; i < size; i++)
	{
		switch(str[i])
		{
			case 'e':
				printf("3");
				o[i] = '3';
				break;
			case 't':
				printf("7");
				o[i] = '7';
				break;
			case 'a':
				printf("4");
				o[i] = '4';
				break;
			case 'b':
				printf("8");
				o[i] = '8';
				break;
			case 'f':
				printf("ƒ");
				o[i] = 'f';
				break;
			case 'g':
				printf("6");
				o[i] = '6';
				break;
			case 'h':
				printf("#");
				o[i] = '#';
				break;
			case 'i':
				printf("!");
				o[i] = '!';
				break;
			case 'l':
				printf("1");
				o[i] = '1';
				break;
			case 'o':
				printf("0");
				o[i] = '0';
				break;
			case 's':
				printf("5");
				o[i] = '5';
				break;
			case 'y':
				printf("y");
				o[i] = 'y';
				break;
			default:
				printf("%c", str[i]);
				o[i] = str[i];
				break;
		}
	}
}

int main(int argc, char **argv)
{
	char    msg[1024]; // the message
	char    out[1024];

	for(int j = 0; j < sizeof(msg);j++){msg[j] = '\0'; out[j] = '\0';}

	fgets(msg,sizeof(msg),stdin); // input the message

	leetspeak(msg, sizeof(msg), out); // translation

	const char* output = out;
    const size_t len = strlen(output) + 1;

    // Copy to ClipBoard
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

	getchar(); // for windows users, don't close the console

	return 0;
}
