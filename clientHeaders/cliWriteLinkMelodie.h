
void writeLinkMelodie(int sockfdsc, char *linkMelodie)
{

	bzero(linkMelodie, 128);
	printf("Dati un link pentru melodie: ");
       	fflush(stdout);

	read(0, linkMelodie, 128);

	if(write(sockfdsc, linkMelodie, 128)<=0){
		perror("[client] Eroare la write() spre server.\n");
	}

}