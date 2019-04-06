
int cheksTheUserExistenceInDB(MYSQL *conn, char* login, char *hashSHA256)
{
	
	char query[256];
	int numOfRows = 0;
	int numOfColumns = 0;
	login[strlen(login) - 1] ='\0';
	sprintf(query, "SELECT login, hash_of_password FROM Users WHERE login LIKE '%%%s%%' AND hash_of_password LIKE '%%%s%%';", login, hashSHA256);
	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	MYSQL_RES *res = mysql_store_result(conn);
	MYSQL_ROW row;
    
	numOfColumns = mysql_num_fields(res); //numarul de coloane
	numOfRows = mysql_num_rows(res);  //numarul de linii
    	mysql_free_result(res);
	
	
	if((numOfRows) >= 1)
	{
		return 1;
	}
	else 
		return 0;
		
}