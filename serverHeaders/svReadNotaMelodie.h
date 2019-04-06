short int readNotaMelodie(int client)
{
	char notaMelodie[3];
	bzero(notaMelodie, 3);
	printf("[server] Asteptam nota pusa de utilizator...\n");

	if(read(client, notaMelodie, 3)<=0)
	{
		perror("[server] Eroare la read() de la client.\n");
	}
	
	printf("[server] Nota acordata de utilizator a fost receptionata... %s\n", notaMelodie);
	
	notaMelodie[strlen(notaMelodie)-1]='\0';
	
	return atoi(notaMelodie);
}