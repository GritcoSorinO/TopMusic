
void sendLengthOfTheResultOfQuerying(int client, char *lengthOfTheResultOfQuerying)
{
	if(write(client, lengthOfTheResultOfQuerying, 6) <= 0)
	{
		perror("[server] Eroare la write() catre client.\n");
	}
	else 
		printf("[server] Mesajul a fost trimis cu succes.\n");
	
}