void receiveCommand(int client, char *command)
{
	if(read(client, command, 32) <= 0)
	{
		perror("[server] Eroare la read() de la client.\n");
		close(client);
	}
	
	printf("[server] Mesajul (command) a fost receptionat...%s\n", command);
}