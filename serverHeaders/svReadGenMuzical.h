
void readGenMuzical(int client, char* genMuzical)
{
	bzero(genMuzical, 32);

	printf("[server] Asteptam genul muzical...\n");

	if(read(client, genMuzical, 32)<=0)
	{
		perror("[server] Eroare la read() de la client.\n");
		close(client);
	}
	
	printf("[server] Genul muzical a fost receptionat %s \n", genMuzical);

}