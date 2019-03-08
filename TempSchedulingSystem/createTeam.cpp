#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <Windows.h>
#include "display.hpp"
#include "help_func.hpp"
#include "createTeam.hpp"
#include "team.hpp"


void createTeamMenu(Team **tm)
{

	char buffer[MAX_LINE_SIZE];

	system("cls");
	printf("\n\n");
	printf("\t\t\tTeam creation menu: \n");
	printf("\n\n");
	printf("Enter new team name: ");
	fgets(buffer, MAX_LINE_SIZE, stdin);
	handleString(buffer, __FILE__, __LINE__);

	(*tm) = init_team(INITTMSZ, buffer);

	while (1)
	{
		if (*tm)
			displayTeam(*tm);
		system("cls");
		printf("\t\tTeam Management Menu\n");

		printf("1. Add Players: \n");
		printf("2. Remove Players \n");
		printf("3. Exit Team Management Menu\n");
		printf("Enter menu option: ");
		fgets(buffer, MENU_TKN_SIZE, stdin);
		handleString(buffer, __FILE__, __LINE__);
		switch (atoi(buffer))
		{
		case 1:
			addPlayers(tm);
			break;
		case 2:
			removePlayers(tm);
			break;
		case 3:
			printf("\tReturning to main menu...\n");
			Sleep(1000);
			return;
		default:
			printf("Unknown choice. Please enter a number from the ones listed.\n");
			break;
		}
	}
}
