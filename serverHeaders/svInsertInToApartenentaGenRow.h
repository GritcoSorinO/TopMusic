void insertInToApartenentaGenARow(MYSQL *conn, unsigned int idGen, unsigned int idMelodie)
{
	char query[256];
	sprintf(query, "INSERT INTO Apartenenta_Gen(ID_Gen, Id_Melodie) VALUES(%d, %d)", idGen, idMelodie);
 
	if(mysql_query(conn, query)){
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
}