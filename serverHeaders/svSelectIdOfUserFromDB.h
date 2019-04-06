unsigned int selectIdOfUserFromDB(MYSQL *conn, MYSQL_RES *result, char *login, char *hashSHA256)
{
	char query[256];

	sprintf(query, "SELECT * FROM Users WHERE login LIKE '%%%s%%' AND hash_of_password LIKE '%%%s%%'", login, hashSHA256);
	
	if(mysql_query(conn, query))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	
	result = mysql_store_result(conn);
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	printf("Login = %s", login);
	
	unsigned int idUser = atoi(row[0]);
	
	printf("Id_User=%s\n",row[0]);
	mysql_free_result(result);
	return idUser;	

}