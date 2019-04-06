void writeIfUserIsAdmin(int client, short int isAdmin)
{
	char msgIsAdmin[10];
	
	if(isAdmin == 1)
	{
		sprintf(msgIsAdmin, "admin");	
	}
	else if(isAdmin == 0)
	{
		sprintf(msgIsAdmin, "user");
	}

	if(write(client, msgIsAdmin, 10)<0){
		perror("[server] Eroare la write() catre client.\n");
	}
	else 
		printf("[server] Mesajul a fost transmis cu succes.\n");

}