void readIfUserIsAdmin(int sockfdsc, char *adminOrUser)
{
	bzero(adminOrUser, 10);

	if(read(sockfdsc, adminOrUser, 10)<0)
	{
		perror("[client] Eroare la read() de la server.\n");
	}
}