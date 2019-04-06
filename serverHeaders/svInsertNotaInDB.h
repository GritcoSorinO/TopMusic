
void insertNotaInDB(unsigned int idMelodie, unsigned int notaMelodie, unsigned int idUser, MYSQL *conn)
{
 	char query[256];
	sprintf(query, "INSERT INTO Note(Id_Melodie, Nota, Id_User) VALUES(%d, %d, %d)", idMelodie, notaMelodie, idUser);
	
	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
}
