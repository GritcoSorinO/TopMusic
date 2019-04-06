
void executeCommand(MYSQL *conn, char *command, MYSQL_RES *result, char *resultForClient)
{
	char query[256];
	int numOfRows = 0;
	int numOfColumns = 0;
	if(strcmp(command, "disp_top") == 0){
		sprintf(query, "SELECT Raiting, Id_Melodie, Nume, Descriere, Link FROM Melodii ORDER BY Raiting DESC");

		if(mysql_query(conn, query))
		{
			fprintf(stderr, "%s\n", mysql_error(conn));
			exit(1);
		}
		
		MYSQL_RES *result = mysql_store_result(conn);
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

	

	
printf("Result for client %s", resultForClient);

}