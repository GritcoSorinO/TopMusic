void readNumarDeGenuri(int client, char *numarDeGenuri)
{

	bzero(numarDeGenuri, 3);
	printf("[server] Asteptam numarul de genuri la care apartine\n");
	
	if(read(client, numarDeGenuri, 3)<=0)
	{
		perror("[server] Eroare la read() de la client.\n");
		close(client);	
	}
	
	printf("[server] Numarul de genuri a fost receptionat...%s\n", numarDeGenuri);
	
	numarDeGenuri[strlen(numarDeGenuri)-1]='\0';

}