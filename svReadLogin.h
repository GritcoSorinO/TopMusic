

void readLogin(char *login, int client){

    bzero(login, 64);
    printf("[server] Asteptam login-l...\n");
    fflush(stdout);

    if(read(client, login, 64)<=0)
    {
        perror("[server] Eroare la read() de la client.\n");
        close(client);
    }

    printf("[server] Mesajul(login-ul) a fost receptionat ...%s\n", login);    
    
}