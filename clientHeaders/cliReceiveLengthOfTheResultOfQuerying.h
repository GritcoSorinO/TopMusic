
int receiveLengthOfTheResultOfQuerying(int sockfdsc, char *lengthStr)
{

	if(read(sockfdsc, lengthStr, 6) < 0)
	{
		perror("[client] Eroare la read() de la server.\n");
	}

}