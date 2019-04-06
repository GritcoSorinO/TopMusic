void writeNumeMelodie(int sockfdsc, char *numeMelodie)
{

	bzero(numeMelodie, 64);
	printf("Introduceti numele melodiei: ");
	fflush(stdout);
	
	read(0, numeMelodie, 64);
	

	if(write(sockfdsc, numeMelodie, 64)<=0){
		perror("[client] Eroare la write() spre server.\n");
	}
}