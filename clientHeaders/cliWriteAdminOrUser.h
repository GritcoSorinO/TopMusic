void writeAdminOrUser(int sockfdsc, char *adminOrUser)
{
	if(write(sockfdsc, adminOrUser, 10)<=0)
	{
		perror("[client] Eroare la write() spre server.\n");
	}
}