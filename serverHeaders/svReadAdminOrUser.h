void readAdminOrUser(int client, char *adminOrUser)
{
	if(read(client, adminOrUser, 10)<=0)
	{
		perror("[client] Eroare la read() de la client.\n");
	}
	
	printf("[server] Admin or User: %s\n", adminOrUser);
}