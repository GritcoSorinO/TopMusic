
void readDescriereMelodie(int client, char *descriereMelodie)
{
	bzero(descriereMelodie, 256);

	printf("[server] Asteptam descrierea melodiei...\n");

	if(read(client, descriereMelodie, 256)<=0)
	{
		perror("[server] Eroare la read() de la client.\n");
		close(client);
	}

	printf("[server] Descrierea melodiei a fost receptionata... %s\n", descriereMelodie);
}