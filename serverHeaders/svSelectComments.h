void selectComments(MYSQL *conn, MYSQL_RES *result, char *resultForClient, unsigned int idMelodie, unsigned int idUser)
{
	char query[512];

	unsigned int numOfColumns, numOfRows;

	sprintf(query, "SELECT us.login AS 'Nume' , c.Comment FROM Comentarii c INNER JOIN Users us ON c.Id_User = us.Id WHERE c.Id_Melodie = %d AND us.Id = %d;", idMelodie, idUser);

	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	result = mysql_store_result(conn);
	MYSQL_ROW row;
	numOfColumns = mysql_num_fields(result);
	numOfRows = mysql_num_rows(result);
	
	while((row = mysql_fetch_row(result)))
	{
		for(int i = 0; i < numOfColumns; i++){
			printf("%s ", row[i] ? row[i] : "NULL");
			sprintf(resultForClient, "%s %s", resultForClient, row[i]);		
		}

		sprintf(resultForClient, "%s\n", resultForClient);
		printf("\n");
	}

}