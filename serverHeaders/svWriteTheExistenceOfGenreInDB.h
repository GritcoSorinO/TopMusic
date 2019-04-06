void writeTheExistenceOfGenreInDB(int client, char *existenceOfGenreInDB)
{
	if(write(client, existenceOfGenreInDB, 2)<=0)
	{
		perror("[server] Eroare la write() catre client.\n");
	}
	else 
		printf("[server] Mesajul a fost transmis cu succes.\n");

}