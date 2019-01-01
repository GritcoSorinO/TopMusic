#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <openssl/sha.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <mysql/mysql.h>
#include "svReadLogin.h"
#include "svReadPassword.h"
#include "svSHA256.h"
#include "svOpenDataBase.h"
#include "svDisconnectDataBase.h"
#include "svCheksTheUserExistenceInDB.h"
#include "svAddNewUserInDataBase.h"
#define PORT 3030

extern int errno;

    

int main()
{

    

    struct sockaddr_in server;
    struct sockaddr_in from;

    char login[64];  //mesaj primit de la client
    char password[32];
    char hashSHA256[72];
    char msgrasp[100] =" "; //mesaj de rapuns pentru client
    int sockfdsc; //descriptor de socket

    

    /*crearea unui sokcet*/

    if((sockfdsc = socket(AF_INET, SOCK_STREAM, 0))==-1)
    {
        perror("[server] Eroare creare socket().\n");
        return errno;
    }
    
    bzero(&server, sizeof(server));
    bzero(&from, sizeof(from));

    /*umplerea structurii serverului*/
    /*stabilirea familiei de socket-uri*/
    server.sin_family = AF_INET;

    /*acceptarea oricarei adrese*/

    server.sin_addr.s_addr = inet_addr("127.0.0.4");

    /*utilizarea unui anumit port*/

    server.sin_port = htons(PORT);

    /*atasare socket */

    if (bind(sockfdsc, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
    {
        perror("[server] Eroare la bind().\n");
        return errno;
    }
    
    if(listen(sockfdsc, 20) == -1)
    {
        perror("[server] Eroare la listen().\n");
        return errno;
    }

    while(1)
    {

        int client;
        int child_pid;
        int userExistence;
        int length = sizeof(from);

        printf("[server] Asteptam la portul %d...\n", PORT);
        fflush(stdout);

        /*acceptare client (stare blocanta pana la realizare conexiune)*/

        client = accept(sockfdsc, (struct sockaddr *)&from, &length);

        if((child_pid = fork())<0)
        {
            perror("Eroare la fork.");
        }
        else if(child_pid == 0)
        {
            //copil
            //close(sockfdsc);

            if(client < 0)
            {
                perror("[server] Eroare la accept.\n");
                continue;
            }

            MYSQL *conn;
            char *used_server = "localhost";
            char *user = "root";
            char *passwordDB = "pass";
            char *database = "TopMusic";

            conn = openDataBase(used_server, user, passwordDB, database);
            /*s-a realizat conexiunea, se asteapta mesajul*/
            readLogin(login, client);  
    
            readPassword(password, client);
            
            hashFunctionSHA256(password, hashSHA256);
            
            userExistence = cheksTheUserExistenceInDB(conn, login, hashSHA256);

            addNewUserInDataBase(conn, login, hashSHA256);
            
            
            printf("User Exist= %d", userExistence);
           
            /*pregatim mesajul de raspuns*/
            
            bzero(msgrasp, 100);
            if(userExistence == 1) {
            strcat(msgrasp, "Logare reusita!");
            }
            else
            strcat(msgrasp, "Logarea a esuat!");
            printf("[server] Trimitem mesajul inapoi... %s\n", msgrasp);

            /*return mesajul clientului*/

            if(write(client, msgrasp, 100)<=0)
            {
                perror("[server] Eroare la write() catre client.\n");
                continue; /*continuarea ascultarii*/
            }
            else 
                printf("[server] Mesajul a fost transmis cu succes.\n");
                dataBaseDisconnect(conn);
                close(client);
                exit(1);
        }
         wait(NULL); //parinte    

    }

     /*Inchide baza de date*/
    
}