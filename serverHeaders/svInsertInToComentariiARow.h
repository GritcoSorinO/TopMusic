void insertInToComentariiARow(unsigned int idUser, unsigned int idMelodie, char* comment, MYSQL *conn)
{

	char query[512];
	sprintf(query, "INSERT INTO Comentarii(Id_Melodie, Id_User, Comment) VALUES(%d, %d, '%s');", idMelodie, idUser, comment);

	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

}