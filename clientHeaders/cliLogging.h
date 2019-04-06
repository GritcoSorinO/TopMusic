

int logging(int sockfdsc){
    char login[64];
    char password[32];
    
     /*citire login*/
    bzero(login, 64);
    printf("[client] Introduceti login: ");
    fflush(stdout);
    read(0, login, 64);

    if(write (sockfdsc, login, 64)<=0)
    {
        perror("[client] Eroare la write() spre server.\n");
        return errno;
    }

    /*citire parola*/
    bzero(password, 32);
    printf("[client] Introduceti parola: ");
    fflush(stdout);
    read(0, password, 32);


    if(write(sockfdsc, password, 32)<=0)
    {
        perror("[client] Eroare la write() spre server.\n");
        return errno;
    }
}