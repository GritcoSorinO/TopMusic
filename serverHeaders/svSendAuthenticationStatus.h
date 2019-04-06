
void sendAuthenticationStatus(int client, char *msgrasp, int userExistence)
{
	bzero(msgrasp, 100);
	
 	if(userExistence == 0)
	{
		strcat(msgrasp, "Autentificare Reusita!\n"); 
	}
	else if(userExistence == 1)
	{
		strcat(msgrasp, "Autentificarea a esuat, deoarece acest utilizator exista in baza de date.\n");
	}		

	if(write(client, msgrasp, 100)<=0)
        {
                perror("[server] Eroare la write() catre client.\n");
                /*continuarea ascultarii*/
        }
            else 
                printf("[server] Mesajul a fost transmis cu succes.\n");

}