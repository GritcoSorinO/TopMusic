void writeNotaMelodie(int sockfdsc, char* notaMelodie)
{
	unsigned short nota;
	bzero(notaMelodie, 3);
	printf("Dati o nota intre 1 si 10: ");
		
	fflush(stdout);
	read(0, notaMelodie, 3);
	nota = atoi(notaMelodie);
	
	while(nota<1 || nota>10)
	{
		printf("Ati introdus o nota invalida.\nMai incercati odata:");
		fflush(stdout);
		bzero(notaMelodie, 3);
		read(0, notaMelodie, 3);
		nota = atoi(notaMelodie);
	}

	if(write(sockfdsc, notaMelodie, 3)<=0)
	{
		perror("[client] Eroare la write() spre server.\n");
	}
}