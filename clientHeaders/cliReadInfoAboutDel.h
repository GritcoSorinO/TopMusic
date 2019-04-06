void readInfoAboutDel(int sockfdsc)
{
	char msgrasp[100];
	bzero(msgrasp, 100);
	
	if(read(sockfdsc, msgrasp, 100)<0)
	{
		perror("[client] Eroare la read() de la server.\n");
	}

	printf("%s\n", msgrasp);
}