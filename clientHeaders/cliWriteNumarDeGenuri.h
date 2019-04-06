void writeNumarDeGenuri(int sockfdsc, char *numarDeGenuri)
{
	bzero(numarDeGenuri, 3);
	printf("Introduceti numarul de genuri la care apartine: ");
	fflush(stdout);

	read(0, numarDeGenuri, 3);

	if(write(sockfdsc, numarDeGenuri, 3)<=0)
	{
		perror("[client] Eroare la write() spre server.\n");
	}


}