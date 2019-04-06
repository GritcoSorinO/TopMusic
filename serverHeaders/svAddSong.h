
void addSong(MYSQL *conn, char *numeMelodie, char *descriereMelodie, char *linkMelodie, char *msgrasp)
{
	char query[512];
	int index;
	
	bzero(msgrasp, 100);
	numeMelodie[strlen(numeMelodie)-1] ='\0';
	descriereMelodie[strlen(descriereMelodie)-1] = '\0';
	linkMelodie[strlen(linkMelodie)-1] = '\0';

	sprintf(query, "INSERT INTO Melodii(Nume, Descriere, Link) VALUES('%s', '%s', '%s')", numeMelodie, descriereMelodie, linkMelodie);
	
	if(mysql_query(conn, query)){
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);	
	}else
		sprintf(msgrasp, "Melodia a fost adaugata cu succes!\n");

}