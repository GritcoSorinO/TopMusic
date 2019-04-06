void writeInfoAboutDel(int client, char *msgrasp)
{
	bzero(msgrasp, 100);
	
	sprintf(msgrasp, "Melodia a fost stearsa cu succes!");

	if(write(client, msgrasp, 100)!=0){
		//perror("[server] Eroare la write() catre client.\n");
	} 
	else 
		printf("[server] Mesajul a fost transmis: %s\n", msgrasp);
	bzero(msgrasp, 100);
}