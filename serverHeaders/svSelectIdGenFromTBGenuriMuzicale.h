unsigned int selectIdGenFromTBGenuriMuzicale(MYSQL *conn, MYSQL_RES *result, char *genMuzical)
{
	char query[256];
	unsigned int idGenMuzical;
	sprintf(query, "SELECT * FROM Genuri_Muzicale WHERE Nume_Gen = '%s'", genMuzical);
	
	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	
	}

	result = mysql_store_result(conn);
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	printf("IdGen = %s", row[0]);
	
	idGenMuzical = atoi(row[0]);
	mysql_free_result(result);
	return idGenMuzical;
}