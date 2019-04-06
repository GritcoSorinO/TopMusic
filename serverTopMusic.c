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
#include "serverHeaders/svReadLogin.h"
#include "serverHeaders/svReadPassword.h"
#include "serverHeaders/svSHA256.h"
#include "serverHeaders/svOpenDataBase.h"
#include "serverHeaders/svDisconnectDataBase.h"
#include "serverHeaders/svCheksTheUserExistenceInDB.h"
#include "serverHeaders/svAddNewUserInDataBase.h"
#include "serverHeaders/svReadLoginOrAuthentication.h"
#include "serverHeaders/svSendAuthenticationStatus.h"
#include "serverHeaders/svSendLoginStatus.h"
#include "serverHeaders/svReceiveCommand.h"
#include "serverHeaders/svExecuteCommand.h"
#include "serverHeaders/svSendResultOfQueryingTheDB.h"
#include "serverHeaders/svSendLengthOfTheResultOfQuerying.h"
#include "serverHeaders/svReadNumeMelodie.h"
#include "serverHeaders/svReadLinkMelodie.h"
#include "serverHeaders/svReadDescriereMelodie.h"
#include "serverHeaders/svAddSong.h"
#include "serverHeaders/svReadIdMelodie.h"
#include "serverHeaders/svReadNotaMelodie.h"
#include "serverHeaders/svSelectIdOfUserFromDB.h"
#include "serverHeaders/svInsertNotaInDB.h"
#include "serverHeaders/svSelectNotaMedieMelodie.h"
#include "serverHeaders/svUpdateRatingOfMelodyInDB.h"
#include "serverHeaders/svReadNumarDeGenuri.h"
#include "serverHeaders/svReadGenMuzical.h"
#include "serverHeaders/svCheksTheExistenceOfGenreInDB.h"
#include "serverHeaders/svWriteTheExistenceOfGenreInDB.h"
#include "serverHeaders/svSelectIdGenFromTBGenuriMuzicale.h"
#include "serverHeaders/svSelectIdMelodieFromTBMelodii.h"
#include "serverHeaders/svInsertInToApartenentaGenRow.h"
#include "serverHeaders/svSelectTopByGenre.h"
#include "serverHeaders/svReadComment.h"
#include "serverHeaders/svInsertInToComentariiARow.h"
#include "serverHeaders/svSelectComments.h"
#include "serverHeaders/svWriteMesajAddSong.h"
#include "serverHeaders/svReadAdminOrUser.h"
#include "serverHeaders/svCheksIfUserIsAdmin.h"
#include "serverHeaders/svWriteIfUserIsAdmin.h"
#include "serverHeaders/svDeleteMelodieFromDB.h"
#include "serverHeaders/svWriteInfoAboutDel.h"
#define PORT 3030

extern int errno;

    

int main()
{
  
    struct sockaddr_in server;
    struct sockaddr_in from;

    
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
        
        int length = sizeof(from);
        

        printf("[server] Asteptam la portul %d...\n", PORT);
        fflush(stdout);

        /*acceptare client (stare blocanta pana la realizare conexiune)*/

        client = accept(sockfdsc, (struct sockaddr *)&from, &length);

        if((child_pid = fork())<0)
        {
            perror("Eroare la fork.");
            close(client);
            continue;
        }
        else if(child_pid == 0)
        {
            //copil
            close(sockfdsc);

            if(client < 0)
            {
                perror("[server] Eroare la accept.\n");
                continue;
            }

            char login[64];  //mesaj primit de la client
            char password[32];
            char hashSHA256[72];
            MYSQL *conn;
            MYSQL_RES *resultOfQueryingTheDB;
            char *used_server = "localhost";
            char *user = "root";
            char *passwordDB = "pass";
            char *database = "TopMusic";
            char logOrAuth[5];
	        char command[32];
            char lengthOfTheResultOfQuerying[6];
            char resultForClient[10240];
            char numeMelodie[64];
            char descriereMelodie[256];
            char linkMelodie[128];
	        char numarDeGenuri[3];
            char genMuzical[32];
            char existenceOfGenreInDB[2];
            unsigned int idMelodie;
            short int notaMelodie;
            unsigned int idUser;
            float notaMedieMelodie;
            int userExistence;
            unsigned int idGen;
            char comment[128];
            char msgrasp[100]; 
            char adminOrUser[10];
            short int isAdmin = 0;
            
            /*s-a realizat conexiunea, se asteapta mesajul*/
            readLogOrAuth(logOrAuth, client);

            if(strcmp("auth", logOrAuth) == 0)
            {
                printf("Inregistrare!!!");

                readLogin(login, client);  
    
                readPassword(password, client);

                readAdminOrUser(client, adminOrUser);
                
                hashFunctionSHA256(password, hashSHA256);
                
                conn = openDataBase(used_server, user, passwordDB, database);

                userExistence = cheksTheUserExistenceInDB(conn, login, hashSHA256);


                if(userExistence == 0)
                {
                    addNewUserInDataBase(conn, login, hashSHA256, adminOrUser);
                    sendAuthenticationStatus(client, msgrasp, userExistence);
                    bzero(adminOrUser, 10);
                }
                else if(userExistence == 1)
                {
                    printf("Acest utilizator exista in baza de date.");
                    sendAuthenticationStatus(client, msgrasp, userExistence);
                    exit(1);
                    dataBaseDisconnect(conn);
                }
               
                
                
            } 
            else if(strcmp("log", logOrAuth)==0)
            {
                printf("Logare!!!");

                readLogin(login, client);  
    
                readPassword(password, client);
                
                hashFunctionSHA256(password, hashSHA256);

                conn = openDataBase(used_server, user, passwordDB, database);
                userExistence = cheksTheUserExistenceInDB(conn, login, hashSHA256);

                isAdmin = cheksIfUserIsAdmin(conn, login, hashSHA256);

                
                sendLoginStatus(client, msgrasp, userExistence);
               
                writeIfUserIsAdmin(client, isAdmin);
                if(userExistence==0){
                            dataBaseDisconnect(conn);
                            exit(1);
                }
                
                    
                    while(strcmp(command, "quit")!=0){
                        receiveCommand(client, command);

                    if(strcmp(command, "disp_top") == 0){
                        bzero(resultForClient, 10240);
                        executeCommand(conn, command, resultOfQueryingTheDB, resultForClient);
                        sprintf(lengthOfTheResultOfQuerying, "%d", strlen(resultForClient)+1);
                        //printf("%s", lengthOfTheResultOfQuerying);
                        sendLengthOfTheResultOfQuerying(client, lengthOfTheResultOfQuerying);
                        printf("%s", lengthOfTheResultOfQuerying);
                        sendResultOfQuerying(client, resultForClient, lengthOfTheResultOfQuerying);
                    
                        bzero(resultForClient, 10240);
                        bzero(command, 32);
                    } else if(strcmp(command, "add_song") == 0)
                    {
                        readNumeMelodie(client, numeMelodie);
                        readDescriereMelodie(client, descriereMelodie);
                        readLinkMelodie(client, linkMelodie);
                        bzero(msgrasp, 100);
                        addSong(conn, numeMelodie, descriereMelodie, linkMelodie, msgrasp);
			            readNumarDeGenuri(client, numarDeGenuri);
                        printf("Numar de genuri = %s\n", numarDeGenuri);

                        for(unsigned int index = 0; index < atoi(numarDeGenuri); index++)
                        {
                            readGenMuzical(client, genMuzical);
                            printf("Gen muz = %s\n", genMuzical);
                            bzero(existenceOfGenreInDB, 2);
			                sprintf(existenceOfGenreInDB, "%d", cheksTheExistenceOfGenreInDB(conn, genMuzical));
                            writeTheExistenceOfGenreInDB(client, existenceOfGenreInDB);

                            if(strcmp(existenceOfGenreInDB, "1") == 0){
                                idGen = selectIdGenFromTBGenuriMuzicale(conn, resultOfQueryingTheDB, genMuzical);
                                idMelodie = selectIdMelodieFromTBMelodii(conn, resultOfQueryingTheDB, numeMelodie, linkMelodie);
                                insertInToApartenentaGenARow(conn, idGen, idMelodie);
                            }

                            writeMesajAddSong(client, msgrasp);
                            bzero(resultForClient, 10240);
                            bzero(existenceOfGenreInDB, 2);
                        }

                        
                    } else if(strcmp(command, "vote_song")==0)
                    {
                        idMelodie = readIdMelodie(client);
                        notaMelodie = readNotaMelodie(client);
                        printf("%d", idMelodie);
                        printf("%d", notaMelodie);
                        
                        idUser = selectIdOfUserFromDB(conn, resultOfQueryingTheDB, login, hashSHA256);
                        insertNotaInDB(idMelodie, notaMelodie, idUser, conn);
                        notaMedieMelodie = selectNotaMedieMelodie(conn, resultOfQueryingTheDB, idMelodie);
                        updateRatingOfMelodyInDB(idMelodie, notaMedieMelodie, conn);
                     
                    } else if(strcmp(command, "disp_top_by_genre") == 0)
                    {
                        readGenMuzical(client, genMuzical);
			            selectTopByGenre(conn, resultOfQueryingTheDB, resultForClient, genMuzical);
                        sprintf(lengthOfTheResultOfQuerying, "%d", strlen(resultForClient)+1);
                        //printf("%s", lengthOfTheResultOfQuerying);
                        sendLengthOfTheResultOfQuerying(client, lengthOfTheResultOfQuerying);
                        printf("%s", lengthOfTheResultOfQuerying);
                        sendResultOfQuerying(client, resultForClient, lengthOfTheResultOfQuerying);
                    
                        bzero(resultForClient, 10240);
                        bzero(command, 32);


                    } else if(strcmp(command, "add_comment")==0)
                    {

                        idUser = selectIdOfUserFromDB(conn, resultOfQueryingTheDB, login, hashSHA256);   
                        idMelodie = readIdMelodie(client);
                        readComment(client, comment);

                        insertInToComentariiARow(idUser, idMelodie, comment, conn);
                    
                    } else if(strcmp(command, "disp_comments")==0)
                    {
                        idMelodie = readIdMelodie(client);
                        idUser = selectIdOfUserFromDB(conn, resultOfQueryingTheDB, login, hashSHA256);
                        selectComments(conn, resultOfQueryingTheDB, resultForClient, idMelodie, idUser);
                    
                        sprintf(lengthOfTheResultOfQuerying, "%d", strlen(resultForClient)+1);

                        sendLengthOfTheResultOfQuerying(client, lengthOfTheResultOfQuerying);
                        sendResultOfQuerying(client, resultForClient, lengthOfTheResultOfQuerying);
                    
                        bzero(resultForClient, 10240);
                        bzero(command, 32);
                    } else if(strcmp(command, "del_song")==0 && isAdmin==1)
                    {
                            idMelodie = readIdMelodie(client);
                            deleteMelodieFromDB(conn, idMelodie);
                            writeInfoAboutDel(client, msgrasp);

                    }

                        if(strcmp(command, "quit")!=0)
                        {
                          
                        
                        }else if(strcmp(command, "quit")==0){
                            dataBaseDisconnect(conn);
                            
                            exit(1);
                        }

                    }
            }else if(strcmp(logOrAuth, "log")!=0 && strcmp(logOrAuth, "auth")!=0){
                exit(1);
            }
            /*pregatim mesajul de raspuns*/
            
            
        }
        close(client);
         while(waitpid(-1, NULL, WNOHANG)); //parinte    
        continue;
    }

     /*Inchide baza de date*/
    
}