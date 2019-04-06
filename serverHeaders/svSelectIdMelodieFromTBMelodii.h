unsigned int selectIdMelodieFromTBMelodii(MYSQL *conn, MYSQL_RES *result, char *numeMelodie, char *linkMelodie)
{
	char query[256];
	unsigned int idMelodie;
	sprintf(query, "SELECT * FROM Melodii WHERE Nume = '%s' and Link = '%s'", numeMelodie, linkMelodie);

	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	result = mysql_store_result(conn);
	MYSQL_ROW row;
	
	row = mysql_fetch_row(result);
	printf("Id_Melodie = %s", row[0]);
	
	idMelodie = atoi(row[0]);
	mysql_free_result(result);
 	
	return idMelodie;

	

}