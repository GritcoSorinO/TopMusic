
MYSQL *openDataBase(char *used_server, char *user, char *password, char *database)
{
    MYSQL *conn = mysql_init(NULL);

    /*connDataBase*/
    printf("%s", password);
    if(!mysql_real_connect(conn, used_server, user, password, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    return conn;
}