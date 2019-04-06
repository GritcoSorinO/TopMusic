
void sendLoginOrAuthentication(int sockfdsc, char *loginOrAuthentication)
{

	if(write(sockfdsc, loginOrAuthentication, 5) <= 0)
	{
		perror("[client] Eroare la write() spre server.\n");
	}
}