void writeDescriereMelodie(int sockfdsc, char *descriereMelodie)
{

	bzero(descriereMelodie, 256);
	printf("Introduceti descrierea melodiei: ");
	fflush(stdout);
	
	read(0, descriereMelodie, 256);
	
	if(write(sockfdsc, descriereMelodie, 256)<=0){
		perror("[client] Eroare la write() spre server.\n");
	}

}