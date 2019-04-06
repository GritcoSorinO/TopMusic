
void readNumeMelodie(int client, char *numeMelodie){
	bzero(numeMelodie, 64);
	printf("[server] Asteptam numele melodiei...\n");

	if(read(client, numeMelodie, 64)<=0)
	{
		perror("[server] Eroare la read() de la client.\n");
		close(client);
	}

	printf("[server] Numele melodiei a fost receptionat ... %s\n", numeMelodie);
	
}