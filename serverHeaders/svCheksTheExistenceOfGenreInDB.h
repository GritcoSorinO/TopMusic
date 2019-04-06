unsigned int cheksTheExistenceOfGenreInDB(MYSQL *conn, char *genMuzical)
{
	char query[256];
	unsigned int numOfRows = 0;
	
	sprintf(query, "SELECT Nume_Gen FROM Genuri_Muzicale WHERE Nume_Gen='%s'", genMuzical);

	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	
	MYSQL_RES *res = mysql_store_result(conn);
	
	numOfRows = mysql_num_rows(res);
	mysql_free_result(res);
	
	if((numOfRows) == 1){
		return 1;
	}
	else 
		return 0;
}