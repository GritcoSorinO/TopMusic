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
#include "clientHeaders/cliLogging.h"
#include "clientHeaders/cliLoginAuthentication.h"
#include "clientHeaders/cliSendLoginOrAuthentication.h"
#include "clientHeaders/cliReceiveAuthenticationStatus.h"
#include "clientHeaders/cliReceiveLoginStatus.h"
#include "clientHeaders/cliMenu.h"
#include "clientHeaders/cliSendCommand.h"
#include "clientHeaders/cliReceiveResultOfQueryingTheDB.h"
#include "clientHeaders/cliReceiveLengthOfTheResultOfQuerying.h"
#include "clientHeaders/cliWriteNumeMelodie.h"
#include "clientHeaders/cliWriteDescriereMelodie.h"
#include "clientHeaders/cliWriteLinkMelodie.h"
#include "clientHeaders/cliWriteIdMelodie.h"
#include "clientHeaders/cliWriteNotaMelodie.h"
#include "clientHeaders/cliWriteNumarDeGenuri.h"
#include "clientHeaders/cliWriteGenMuzical.h"
#include "clientHeaders/cliReadTheExistenceOfGenreInDB.h"
#include "clientHeaders/cliWriteComment.h"
#include "clientHeaders/cliReadMesajAddSong.h"
#include "clientHeaders/cliWriteAdminOrUser.h"
#include "clientHeaders/cliReadIfUserIsAdmin.h"
#include "clientHeaders/cliReadInfoAboutDel.h"
/*codul de eroare returnat de anumite apeluri*/
extern int errno;

/*portul de conectare la server*/
int port;

int main(int argc, char *argv[])
{
    int sockfdsc; /*descriptorul socket-ului*/
    char loginOrAuthentication[5];
    char authenticationStatus[100];
    char loginStatus[100];
    char command[32];
    struct sockaddr_in server; /*structura folosita pentru conectare*/
         //mesaj trimis
    char answer[32];
    char lengthOfQuerying[6];
    char resultOfQuerying[10240];
    char numeMelodie[64];
    char descriereMelodie[256];
    char linkMelodie[128];
    char idMelodie[20];
    char notaMelodie[3];
    char numarDeGenuri[3];
    char genMuzical[32];
    char existenceOfGenreInDB[2];
    char comment[128];
    char mesajAddSong[100];
    char adminOrUser[10];


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
    
    login_authentication(loginOrAuthentication, adminOrUser);

    sendLoginOrAuthentication(sockfdsc, loginOrAuthentication);
	
    if(strcmp("auth", loginOrAuthentication) == 0)
    {
        logging(sockfdsc);
        writeAdminOrUser(sockfdsc, adminOrUser);
    	receiveAuthenticationStatus(sockfdsc, authenticationStatus);
        printf("Authentication status = %s\n", authenticationStatus);
        

    }
    else if(strcmp("log", loginOrAuthentication) == 0)
    {
        logging(sockfdsc);
        receiveLoginStatus(sockfdsc, loginStatus);
        printf("Login status = %s\n", loginStatus);
        readIfUserIsAdmin(sockfdsc, adminOrUser);
    
        if(strcmp("Logare reusita!", loginStatus) == 0)
        {
            
                
                while(strcmp(command, "quit")!=0)
                {
                        bzero(command, 32);
                        menu(command, adminOrUser);
                        printf("\n");
                    if(strcmp(command, "disp_top")==0){
                        sendCommand(sockfdsc, command);
                        receiveLengthOfTheResultOfQuerying(sockfdsc, lengthOfQuerying);
                        bzero(resultOfQuerying, atoi(lengthOfQuerying)+1);
                        receiveResultOfQueryingTheDB(sockfdsc, resultOfQuerying, lengthOfQuerying);
                    } 
                    else if(strcmp(command, "disp_top_by_genre")==0)
                    {
                        sendCommand(sockfdsc, command);
                        writeGenMuzical(sockfdsc, command);
                        receiveLengthOfTheResultOfQuerying(sockfdsc, lengthOfQuerying);
                        receiveResultOfQueryingTheDB(sockfdsc, resultOfQuerying, lengthOfQuerying);
                        bzero(resultOfQuerying, atoi(lengthOfQuerying)+1);
                        bzero(command, 32);
                    }
                    else if(strcmp(command, "add_song")==0)
                            {
                                sendCommand(sockfdsc, command);
                                writeNumeMelodie(sockfdsc, numeMelodie);
                                writeDescriereMelodie(sockfdsc, descriereMelodie);
                                writeLinkMelodie(sockfdsc, linkMelodie);
				                writeNumarDeGenuri(sockfdsc, numarDeGenuri);

                                for(unsigned int index = 0; index < atoi(numarDeGenuri); index++)
                                {
                                    printf("Introduceti genul muzical numarul %d: ",index+1);
                                    writeGenMuzical(sockfdsc, genMuzical);
                                    bzero(existenceOfGenreInDB, 2);
                                    readTheExistenceOfGenreInDB(sockfdsc, existenceOfGenreInDB);
                                    //printf("%s\n", existenceOfGenreInDB);

                                    if(strcmp(existenceOfGenreInDB, "1")!=0){
                                            printf("Ati introdus un gen muzical inexistent.\n");
                                    }
                                    bzero(existenceOfGenreInDB, 2);
                                }

                                readMesajAddSong(sockfdsc, mesajAddSong);

                            } else if(strcmp(command, "vote_song")==0)
                            {
                                sendCommand(sockfdsc, command);
                                writeIdMelodie(sockfdsc, idMelodie);
                                writeNotaMelodie(sockfdsc, notaMelodie);
                            } else if(strcmp(command, "add_comment")==0)
                            {
                                sendCommand(sockfdsc, command);   
                                writeIdMelodie(sockfdsc, idMelodie);
                                writeComment(sockfdsc, comment);

                            } else if(strcmp(command, "disp_comments")==0)
                            {
                                sendCommand(sockfdsc, command);
                                writeIdMelodie(sockfdsc, idMelodie);
                                receiveLengthOfTheResultOfQuerying(sockfdsc, lengthOfQuerying);
                                receiveResultOfQueryingTheDB(sockfdsc, resultOfQuerying, lengthOfQuerying);
                                bzero(resultOfQuerying, atoi(lengthOfQuerying)+1);
                                bzero(command, 32);

                            } else if(strcmp(command, "del_song")==0 && strcmp(adminOrUser, "admin")==0)
                            {
                                sendCommand(sockfdsc, command);
                                writeIdMelodie(sockfdsc, idMelodie);
                                readInfoAboutDel(sockfdsc);

                            }else if(strcmp(command, "quit")==0)
                            {
                                sendCommand(sockfdsc, command);
                        
                            }
                }
                
        }
    }

   //logging(sockfdsc);


    /*inchidem conexiunea am terminat*/
        close(sockfdsc);
        exit(EXIT_SUCCESS);
}