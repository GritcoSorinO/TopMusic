
void readLinkMelodie(int client, char *linkMelodie)
{
 
	bzero(linkMelodie, 128);
	
	printf("[server] Asteptam link-ul unde poate fi gasita melodia...\n");

	if(read(client, linkMelodie, 128)<=0){
		perror("[server] Eroare la read() de la client.\n");
		close(client);
	}

	printf("[server] Link-ul melodiei a fost receptionat... %s\n", linkMelodie);
}