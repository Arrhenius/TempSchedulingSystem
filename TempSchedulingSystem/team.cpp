#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>
#include "team.hpp"
#include "help_func.hpp"
#include "display.hpp"
#include "player.hpp"



Team *init_team(int num, const char *name)
{
	Team *tm;

	tm = (Team *)malloc(D_LIST_TM_SZ(num));		// malloc memory for team
	if (!tm)
		errExit("Unable to malloc memory for Team structure", __FILE__, __LINE__);
	memset(tm, 0, sizeof(Team));				// zero out memory
	tm->maxsz = num;
	tm->sz = 0;
	strcpy(tm->tmName, name);
	return tm;
}

void removePlayers(Team **tm)
{
	if ((*tm))
	{
		int i;
		int iRm_pl;
		char buffer[MENU_TKN_SIZE + 1];
		printf("Pick a player from the list below: \n");
		displayTeam(*tm, TRUE);
		/*
		for (i = 0; i < (*tm)->sz; i++)
		{
			printf("\t%d: %s (%s)\n", i + 1,
				(*tm)->players[i].alias,
				(*tm)->players[i].name);
		}
		*/

		printf("Choose a player number: ");
		fgets(buffer, MENU_TKN_SIZE, stdin);
		handleString(buffer, __FILE__, __LINE__);
		iRm_pl = atoi(buffer) - 1;

		for (i = iRm_pl; i < (*tm)->sz - 1; i++)
		{
			(*tm)->players[i] = (*tm)->players[i + 1];
		}
		(*tm)->sz--;
		printf("Player removed...\n");
		printf("Returning to team management menu...\n");
		Sleep(700);		// Debating on keeping this pause

	}
	else
	{
		fprintf(stderr, "Team structure failed to be passed correctly!\n");
		fprintf(stderr, "Returning to Team Menu!\n");
	}
}



/*
*
*/
void insertPlayerInTeam(Team **tm, Player p)
{
	Team *q;

	if (!(*tm))
	{
		errExit("Team structure was incorrectly passed to function",
			__FILE__,
			__LINE__);
	}

	if ((*tm)->sz == (*tm)->maxsz)
	{
		q = (Team *)realloc(*tm, D_LIST_TM_SZ((*tm)->maxsz + INCRTMSZ));
		if (!q)
			errExit("Failed to realloc memory for Team structure", __FILE__, __LINE__);
		q->maxsz += INCRTMSZ;
		*tm = q;
	}
	(*tm)->players[(*tm)->sz++] = p;
}


/*
*
*/
void addPlayers(Team **tm)
{
	Player p;
	char name[MAX_PLNM_SIZE + 1];
	char alias[MAX_PLNM_SIZE + 1];
	char tz[MENU_TKN_SIZE];
	char buffer[MAX_LINE_SIZE];

	system("cls");

	// Obtain name of player
	printf("\t\tPlayer Addition Menu:\n\n");
	printf("Enter a player's full name: ");
	fgets(name, MAX_PLNM_SIZE, stdin);
	handleString(name, __FILE__, __LINE__);

	// Obtain alias used by player
	printf("Enter the player's alias: ");
	fgets(alias, MAX_PLNM_SIZE, stdin);
	handleString(alias, __FILE__, __LINE__);


	// Obtain timezone of player
	printf("1. West\n");
	printf("2. Mountain\n");
	printf("3. Central\n");
	printf("4. East\n");
	printf("Enter player time zone choice (number): ");
	fgets(tz, MENU_TKN_SIZE, stdin);
	handleString(tz, __FILE__, __LINE__);


	// Create player profile based on data obtained
	switch (atoi(tz))
	{
	case 1:
		p = createPlayer(name, alias, TZ_PST);
		break;
	case 2:
		p = createPlayer(name, alias, TZ_MST);
		break;
	case 3:
		p = createPlayer(name, alias, TZ_CST);
		break;
	case 4:
		p = createPlayer(name, alias, TZ_EST);
		break;
	default:
		printf("Invalid option selected, returning to team management menu...\n");
		return;

	}
	
	printf("Add player '%s' to team? (Yes/No): ", name);
	fgets(buffer, MAX_LINE_SIZE, stdin);
	handleString(buffer, __FILE__, __LINE__);
	if (strcmp(buffer, "Yes") == 0 || strcmp(buffer, "Y") == 0 ||
		strcmp(buffer, "yes") == 0 || strcmp(buffer, "y") == 0)
	{
		(*tm)->players[(*tm)->sz++] = p;
	}
	else
	{
		printf("Discarding and returning to team management menu...\n");
		return;
	}
}



// Enhance this function with bitflags to list certain
// properties of players
void listTeamPlayers(Team *tm)
{
	int i;
	printf("\t\t\tTeam Info: \n\n\n");
	printf("\tTeam: \n");
	printf("\t      %s\n\n", tm->tmName);
	printf("\tPlayers: \n");
	for (i = 0; i < tm->sz; i++) 
	{
		printf("\t         %s\n", tm->players[i].name);
	}
		
	printf("Press any key to continue...");
	system("pause");
}

#if 0
void viewPlayerInfoMenu(Team *tm)
{
	int i;
	char buffer[MENU_TKN_SIZE + 1];
	printf("Choose a player from the list below: \n");
	printf("\n");
	for (i = 0; i < tm->sz; i++)
		printf("%d: %s\n", i + 1, tm->players[i].name);

	printf("Enter choice: ");
	fgets(buffer, MENU_TKN_SIZE, stdin);
	handleString(buffer, __FILE__, __LINE__);

	if (isdigit(atoi(buffer)) == 0) {
		displayPlayerData();
	}



}

#endif

// This function will be used for more features in the future
#if 0
void printTeamData(Team *tm)
{

}
#endif