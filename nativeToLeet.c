/*
Funny program made by theoricien.
Description: Program who will ask you a message of a 1024 lenght and will translate him to leet speak.
*/


#include <stdio.h>
#include <stdlib.h>

// Function who will translate normal language to leet language
void leetspeak(char *str, int size)
{
	for(int i = 0; i < size; i++)
	{
		switch(str[i])
		{
			case 'e':
				printf("3");
				break;
			case 't':
				printf("7");
				break;
			case 'a':
				printf("4");
				break;
			case 'b':
				printf("8");
				break;
			case 'f':
				printf("ƒ");
				break;
			case 'g':
				printf("6");
				break;
			case 'h':
				printf("#");
				break;
			case 'i':
				printf("!");
				break;
			case 'l':
				printf("1");
				break;
			case 'o':
				printf("0");
				break;
			case 's':
				printf("5");
				break;
			case 'y':
				printf("?");
				break;
			default:
				printf("%c", str[i]);
				break;
		}
	}
}

int main(int argc, char **argv) 
{
	char msg[1024]; // the message
	
	fgets(msg,sizeof(msg),stdin); // input the message
	
	leetspeak(msg, sizeof(msg)); // translation

	getchar(); // for windows users, don't close the console
	
	return 0;
}
