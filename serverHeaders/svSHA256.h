
void hashFunctionSHA256(char *password, char *hashSHA256)
{
    unsigned char *shaASCII = SHA256(password, strlen(password)-1, 0);
    int i;
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(&hashSHA256[i*2], "%02x", (unsigned int)shaASCII[i]);

}