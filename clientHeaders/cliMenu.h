
void menu(char *command, char *adminOrUser){
	if(strcmp(adminOrUser, "user")==0){
		printf("\n1) Afisare top general (disp_top)\n");
		printf("2) Afisare top general dupa gen muzical (disp_top_by_genre)\n");
		printf("3) Adauga o melodie la top (add_song)\n");
		printf("4) Voteaza o melodie (vote_song)\n");
		printf("5) Adaugati un comentariu (add_comment)\n");
		printf("6) Afisare comentarii pentru o anumita melodie (disp_comments)\n");
		printf("7) Inchideti aplicatia (quit)\n");
		printf("\nIntroduceti o comanda:");
		scanf("%s", command);
	}else if(strcmp(adminOrUser, "admin")==0)
	{
		printf("\n1) Afisare top general (disp_top)\n");
		printf("2) Afisare top general dupa gen muzical (disp_top_by_genre)\n");
		printf("3) Adauga o melodie la top (add_song)\n");
		printf("4) Voteaza o melodie (vote_song)\n");
		printf("5) Adaugati un comentariu (add_comment)\n");
		printf("6) Afisare comentarii pentru o anumita melodie (disp_comments)\n");
		printf("7) Sterge o melodie (del_song)\n");
		printf("8) Inchideti aplicatia (quit)\n");
		printf("\nIntroduceti o comanda:");
		scanf("%s", command);
	}
}