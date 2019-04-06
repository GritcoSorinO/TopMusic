void writeMesajAddSong(int client, char *msgrasp)
{
	if(write(client, msgrasp, 100)<=0)
	{
		perror("[server] Eroare la write() catre client.\n");
	}
 		else 
			printf("[server] Mesajul a fost transmis cu succes.\n");
	
}