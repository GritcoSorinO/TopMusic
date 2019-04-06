void writeIdMelodie(int sockfdsc, char *idMelodie)
{
	bzero(idMelodie, 20);
	printf("Dati id-ul melodiei: ");
	fflush(stdout);
	
	read(0, idMelodie, 20);
        
	if(write(sockfdsc, idMelodie, 20)<=0)
	{
		perror("[client] Eroare la write() spre server.\n");
	}

}