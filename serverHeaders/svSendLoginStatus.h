
void sendLoginStatus(int client, char *msgrasp, int userExistence){
	
	bzero(msgrasp, 100);
	
	if(userExistence == 0)
	{
		strcat(msgrasp, "Logarea a esuat, deoarece utilizatorul nu exista in baza de date.\n");
	} 
	else if(userExistence == 1)
	{
		strcat(msgrasp, "Logare reusita!");
	}

	if(write(client, msgrasp, 100) <= 0)
	{
		perror("[server] Eroare la write() catre client.\n");
	}
	else 
		printf("[server] Mesajul a fost trimis cu succes.\n");

}