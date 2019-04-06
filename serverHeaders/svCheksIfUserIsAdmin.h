short int cheksIfUserIsAdmin(MYSQL *conn, char *login, char *hashSHA256)
{
	char query[256];
	short int isAdmin;
	MYSQL_RES *result;
	sprintf(query, "SELECT isAdmin FROM Users WHERE login LIKE '%%%s%%' AND hash_of_password LIKE '%%%s%%'", login, hashSHA256);
	
	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	result = mysql_store_result(conn);
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	
	isAdmin = atoi(row[0]);
	printf("Is_Admin = %s\n", row[0]);
	mysql_free_result(result);
	return isAdmin;
}