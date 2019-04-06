
void readComment(int client, char* readComment)
{
	bzero(readComment, 128);
	printf("[server] Asteptam comentariul ...\n");

	if(read(client, readComment, 128)<=0)
	{
		perror("[server] Eroare la read() de la client.\n");
		close(client);
	}
	
	printf("[server] Comentariul a fost receptionat: %s\n", readComment);

}