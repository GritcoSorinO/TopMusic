void selectTopByGenre(MYSQL *conn, MYSQL_RES *result, char *resultForClient, char *genMuzical)
{

	char query[512];
	unsigned int numOfColumns, numOfRows;

	sprintf(query, "SELECT Raiting, m.Id_Melodie, Nume, Descriere, Link FROM Melodii m INNER JOIN Apartenenta_Gen ap ON m.Id_Melodie = ap.Id_Melodie INNER JOIN Genuri_Muzicale gm ON ap.ID_Gen = gm.ID_Gen WHERE gm.Nume_Gen = '%s'  ORDER BY Raiting DESC", genMuzical);

		if(mysql_query(conn, query))
		{
			fprintf(stderr, "%s\n", mysql_error(conn));
			exit(1);
		}
		
		result = mysql_store_result(conn);
		MYSQL_ROW row;
		numOfColumns = mysql_num_fields(result);
		numOfRows = mysql_num_rows(result);
		
		while ((row = mysql_fetch_row(result))) 
  		{ 
      			for(int i = 0; i < numOfColumns; i++) 
      			{ 
         			printf("%s ", row[i] ? row[i] : "NULL"); 
				sprintf(resultForClient,"%s %s",resultForClient,row[i]);
				//
      			} 
		sprintf(resultForClient, "%s\n", resultForClient);
          	printf("\n"); 
  		}


}