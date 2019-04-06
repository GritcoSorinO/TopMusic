unsigned int readIdMelodie(int client)
{
 	char idMelodie[20];
	bzero(idMelodie, 20);
	printf("[server] Asteptam id-ul melodiei...\n");
	
	if(read(client, idMelodie, 20)<=0)
	{
		perror("[server] Eroare la read() de la client.\n");
		close(client);
	}
	
	printf("[server] Id-ul melodiei a fost receptionat...%s\n", idMelodie);
	
	idMelodie[strlen(idMelodie)-1]='\0';

	return atoi(idMelodie);
}