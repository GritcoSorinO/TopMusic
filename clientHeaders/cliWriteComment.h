void writeComment(int sockfdsc, char *comment)
{
	bzero(comment, 128);
	printf("Comentati: ");
	fflush(stdout);

	read(0, comment, 128);
	
	comment[strlen(comment) - 1]='\0';

	if(write(sockfdsc, comment, 128)<=0)
	{
		perror("[client] Eroare la write() spre server.\n");
	}


}