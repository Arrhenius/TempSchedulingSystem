#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "help_func.hpp"
#include "modifyTeam.hpp"
#include "team.hpp"
#include "display.hpp"
#include "player.hpp"


void modifyTeam(Team **tm)
{
	char buffer[MENU_TKN_SIZE];

	system("cls");

	while (1)
	{
		printf("\t\t Modify Team Menu\n\n");
		printf("1. Change availability\n");
		printf("2. Change player alias\n");
		printf("3. Change team name\n");
		printf("4. Return to previous menu\n\n");
		printf("Enter an option from the list above: ");

		fgets(buffer, MENU_TKN_SIZE, stdin);
		handleString(buffer, __FILE__, __LINE__);
		switch (atoi(buffer))
		{
		case 1:
			modifyAvailability(tm);
			break;
		case 2:
			modifyAlias(tm);
			break;
		case 3:
			modifyTeamName(tm);
			break;
		case 4:
			printf("Returning to previous menu...");
			Sleep(500);
			return;
		default:
			printf("Invalid option. Press any key to continue\n");
			system("pause");
			break;
		}
	}
	
}

void modifyAvailability(Team **tm)
{
	if ((*tm))
	{
		// TODO: Make this section more elegant.
		char buffer[MENU_TKN_SIZE + 1];
		displayTeam(*tm, TRUE);
		printf("\nWhich player availability would you like to change?\n");
		printf("Choose a player: ");
		fgets(buffer, MENU_TKN_SIZE, stdin);
		handleString(buffer, __FILE__, __LINE__);
		int menuTkn = atoi(buffer);

		if ((menuTkn > 0) && (menuTkn <= (*tm)->sz))
		{
			char response[MENU_TKN_SIZE + 1];
			displayAvailability(*tm, TRUE, (menuTkn - 1));
			printf("Would you like to change this player's availability? (Yes/No): ");
			fgets(response, MENU_TKN_SIZE, stdin);
			handleString(response, __FILE__, __LINE__);
			if (strcmp(response, "Yes") == 0 || strcmp(response, "Y") == 0 ||
				strcmp(response, "yes") == 0 || strcmp(response, "y") == 0)
			{
				//Player p = (*tm)->players[menuTkn];
				playerAvailability(tm, menuTkn);
				
			}
			else
				return;
		}
	}
	else
	{
		fprintf(stderr, "Team structure failed to be passed correctly!\n");
		fprintf(stdout, "Returning to Team Menu...\n");
	}
}

void modifyAlias(Team **tm)
{
	if ((*tm))
	{
		char buffer[MENU_TKN_SIZE];
		char alias[MAX_PLNM_SIZE];
		int i;


		system("cls");	// Clear screen
		printf("\t\tModify Alias Menu\n\n");
		printf("Which player alias would you like to modify?\n");
		

		// Display team and select player to modify
		displayTeam(*tm, TRUE);
		printf("Choose a player number: ");
		fgets(buffer, MENU_TKN_SIZE, stdin);
		handleString(buffer, __FILE__, __LINE__);

		// Obtain new alias name for selected player
		printf("Enter new alias for this player: ");
		fgets(alias, MAX_PLNM_SIZE, stdin);			// Get player alias
		handleString(alias, __FILE__, __LINE__);	// Make string safe

		// set variable to locate it within array
		i = atoi(buffer) - 1;
		strcpy((*tm)->players[i].alias, alias);		// copy new alias
		printf("Player %s's new alias is %s\n",
				(*tm)->players[i].name,
				(*tm)->players[i].alias);
		printf("Returning to previous menu...");
		Sleep(500);									// Delay before returning
	}
	else
	{
		fprintf(stderr, "Team structure failed to be passed correctly!\n");
		fprintf(stdout, "Returning to Team Menu...\n");
	}
}

void modifyTeamName(Team **tm)
{
	if ((*tm))
	{
		char buffer[MAX_LINE_SIZE];
		char tmName[MAX_TMNM_SIZE];
		system("cls");

		printf("\t\tModify Team Name Menu\n\n");
		printf("Enter new team name: ");
		fgets(tmName, MAX_TMNM_SIZE, stdin);
		handleString(tmName, __FILE__, __LINE__);

		printf("Changing team name to %s, is this correct? (Yes/No): ", tmName);
		fgets(buffer, MAX_LINE_SIZE, stdin);
		handleString(buffer, __FILE__, __LINE__);
		if (strcmp(buffer, "Yes") == 0 || strcmp(buffer, "Y") == 0 ||
			strcmp(buffer, "yes") == 0 || strcmp(buffer, "y") == 0)
		{
			strcpy((*tm)->tmName, tmName);
			printf("Team name changed\n");
		}
		else
			printf("Team name discarded!\n");
		printf("Returning to previous menu...\n");
		Sleep(500);
	}
	else
	{
		fprintf(stderr, "Team structure failed to be passed correctly!\n");
		fprintf(stdout, "Returning to Team Menu...\n");
	}
}