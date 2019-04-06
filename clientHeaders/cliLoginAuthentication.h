
void login_authentication(char *loginOrAuthentication, char *adminOrUser)
{
	bzero(loginOrAuthentication, 5);
	bzero(adminOrUser, 10);
  
	
	while(strcmp(loginOrAuthentication, "log")!=0 && strcmp(loginOrAuthentication, "auth")!=0)
	{		
			system("clear");
			printf("\t\tTop Music\n");
			printf("Mai incercati, ati introdus o comanda invalida.\n");
			printf("1)Logare (log)\n");
		    	printf("2)Inregistrare (auth)\n");
		    	printf("\nTastati una dintre comenzile din paranteze pentru actiunea dorita\n");
		    	scanf("%s", loginOrAuthentication);
			
			if(strcmp(loginOrAuthentication, "auth")==0){
				printf("Inregistrare ca:\n");
				printf("a) Administrator (admin)\n");
				printf("b) Utilizator obisnuit (user)\n");
				scanf("%s", adminOrUser);
			}
	}
    
}