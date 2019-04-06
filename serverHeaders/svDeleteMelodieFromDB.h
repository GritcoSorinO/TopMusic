void deleteMelodieFromDB(MYSQL *conn, unsigned int idMelodie)
{
	char query[256];
	
	sprintf(query, "DELETE FROM Melodii WHERE Id_Melodie = %d", idMelodie);

	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

}