void readMesajAddSong(int client, char *msgrasp)
{
	bzero(msgrasp, 100);
	if(read(client, msgrasp, 100)<=0)
	{
		perror("[server] Eroare la read() de la server.\n");
	} 
	else
		printf("\n%s\n", msgrasp);
	

}