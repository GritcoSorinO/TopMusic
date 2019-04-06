
void readLogOrAuth(char *logOrAuth, int client)
{	
	bzero(logOrAuth, 5);
	printf("[server] Asteptam optiunea logOrAut...\n");
	fflush(stdout);
	
	if(read(client, logOrAuth, 5)<=0)
	{
		perror("[server] Eroare la read() de la client.\n");
		close(client);
	}	
	printf("[server] Mesajul (logOrAuth) a fost receptionat...%s\n", logOrAuth);
	
}