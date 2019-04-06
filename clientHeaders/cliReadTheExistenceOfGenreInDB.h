void readTheExistenceOfGenreInDB(int sockfdsc, char *existenceOfGenreInDB)
{

	if(read(sockfdsc, existenceOfGenreInDB, 2) < 0)
	{
		perror("[client] Eroare la read() de la server.\n");
	}

}