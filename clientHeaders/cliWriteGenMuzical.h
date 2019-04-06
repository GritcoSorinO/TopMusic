void writeGenMuzical(int sockfdsc, char* genMuzical)
{
	printf("Dati genul muzical:");
	bzero(genMuzical, 32);
    	fflush(stdout);
	read(0, genMuzical, 32);

	genMuzical[strlen(genMuzical)-1] = '\0';

	if(write(sockfdsc, genMuzical, 32)<=0)
	{
		perror("[client] Eroare la write() spre server.\n");
	}
	printf("\n");

}