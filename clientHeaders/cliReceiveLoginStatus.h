void receiveLoginStatus(int sockfdsc, char* loginStatus)
{
	if(read(sockfdsc, loginStatus, 100) < 0)
	{
		perror("[client] Eroare la read() de la server.\n");
	}
}