
void receiveAuthenticationStatus(int sockfdsc, char* authenticationStatus)
{
	if(read(sockfdsc, authenticationStatus, 100) < 0)
	{
		perror("[client] Eroare la read() de la server.\n");
	}
}