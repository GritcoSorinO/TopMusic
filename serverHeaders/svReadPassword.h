
void readPassword(char *password, int client)
{

    bzero(password, 32);
    printf("[server] Asteptam password-ul...\n");
    fflush(stdout);

    password[strlen(password)-1] = '\0';

    if(read(client, password, 32)<=0)
    {
        perror("[server] Eroare la read() de la client.\n");
        close(client);
    }

    printf("[server] Mesajul(password-ul) a fost receptionat ...\n");
}