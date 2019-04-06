
void addNewUserInDataBase(MYSQL *conn,char *login, char *hashSHA256, char *adminOrUser)
{
    char query[256];
    short int isAdmin;
    /* Trimite interogarea MYSQL*/
	if(strcmp(adminOrUser, "admin")==0){
		isAdmin = 1;	
	} else if(strcmp(adminOrUser, "user")==0){
		isAdmin = 0;	
	}
	
    sprintf(query, "INSERT INTO Users(login, hash_of_password, isAdmin) VALUES ('%s', '%s', %d);", login, hashSHA256, isAdmin);

    if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
    }
}