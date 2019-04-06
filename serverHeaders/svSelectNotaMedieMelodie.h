float selectNotaMedieMelodie(MYSQL *conn, MYSQL_RES *result, unsigned int idMelodie)
{
	char query[256];
	float medieNoteMelodie;
	
	sprintf(query, "SELECT AVG(Nota) AS 'Medie' FROM Note WHERE Id_Melodie = %d", idMelodie);

	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	result = mysql_store_result(conn);
	MYSQL_ROW row;

	row = mysql_fetch_row(result);
	
	medieNoteMelodie = atof(row[0]);
	printf("Medie = %f", medieNoteMelodie);
	mysql_free_result(result);
	return medieNoteMelodie;

	
}