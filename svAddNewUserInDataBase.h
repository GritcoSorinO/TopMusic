
void addNewUserInDataBase(MYSQL *conn,char *login, char *hashSHA256)
{
    char query[256];
    /* Trimite interogarea MYSQL*/
    sprintf(query, "INSERT INTO Users(login, hash_of_password) VALUES ('%s', '%s')",login, hashSHA256);

    if (mysql_query(conn, query)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
    }
}