
void sendCommand(int sockfdsc, char *command)
{
	if(write(sockfdsc, command, 32) <= 0)
	{
		perror("[client] Eroare la write() spre server.\n");
	}
}