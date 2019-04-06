//#include <mysql/mysql.h>

void receiveResultOfQueryingTheDB(int sockfdsc, char *resultOfQuerying, char *lengthOfQuerying)
{
	if(read(sockfdsc, resultOfQuerying, atoi(lengthOfQuerying)+1)<0){
		perror("[client] Eroare la read() de la server.\n");
	}
	
	 printf("%s", resultOfQuerying);
}