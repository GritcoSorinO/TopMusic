
void sendResultOfQuerying(int client, char *resultOfQueryingTheDB, char *lengthOfTheResultOfQuerying){
	if(write(client, resultOfQueryingTheDB, atoi(lengthOfTheResultOfQuerying)+1) <= 0)
	{
		 perror("[server] Eroare la write() catre client.\n");
	}
        else 
                printf("[server] Mesajul a fost transmis cu succes.\n");

}