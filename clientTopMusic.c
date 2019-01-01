#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "cliLogging.h"

/*codul de eroare returnat de anumite apeluri*/
extern int errno;

/*portul de conectare la server*/
int port;

int main(int argc, char *argv[])
{
    int sockfdsc; /*descriptorul socket-ului*/
    struct sockaddr_in server; /*structura folosita pentru conectare*/
         //mesaj trimis
    char answer[32];

    if(argc != 3)
    {
        printf("Sintaxa: %s <adresa_server> <port>\n", argv[0]);
        return -1;
    }

    /*stabilim portul*/

    port = atoi(argv[2]);

    /*creare socket*/

    if((sockfdsc = socket(AF_INET, SOCK_STREAM, 0))==-1)
    {
        perror("Eroare la socket().\n");
        return errno;
    }

    /*umplem structura*/
    /*familia socket-ului*/

    server.sin_family = AF_INET;

    /*adresa IP a serverului*/
    server.sin_addr.s_addr = inet_addr(argv[1]);

    /*portul pentru conectare*/ 

    server.sin_port = htons(port);

    /*conectare la server*/

    if(connect(sockfdsc, (struct sockaddr*)&server, sizeof(struct sockaddr))){
        perror("[client] Eroare la connect().\n");
        return errno;
    }
    
    logging(sockfdsc);
    /*citirea raspunsului dat de server*/

    if(read(sockfdsc, answer, 32)<0)
    {
        perror("[client] Eroare la read() de la server.\n");
        return errno;
    } 

    /*afisam mesajul primit*/
    printf("[client] Mesajul primit este: %s\n", answer);


    /*inchidem conexiunea am terminat*/
    close(sockfdsc);
}