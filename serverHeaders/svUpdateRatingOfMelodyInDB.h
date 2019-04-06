void updateRatingOfMelodyInDB(unsigned int idMelodie, float notaMedieMelodie, MYSQL *conn)
{
	char query[256];

	sprintf(query, "UPDATE Melodii SET Raiting = %2.2f WHERE Id_Melodie = %d", notaMedieMelodie, idMelodie);
	
	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
}