
void dataBaseDisconnect(MYSQL *conn)
{
	mysql_close(conn);
}