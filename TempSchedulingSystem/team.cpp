#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <Windows.h>
#include "team.hpp"
#include "help_func.hpp"




Team *init_team(int num, const char *name)
{
	Team *tm;

	tm = (Team *)malloc(D_LIST_TM_SZ(num));
	if (!tm)
		errExit("Unable to malloc memory for Team structure", __FILE__, __LINE__);
	memset(tm, 0, sizeof(Team));
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
		char buffer[MENU_TKN_SIZE + 1];
		printf("Pick a player from the list below: \n");
		for (i = 0; i < (*tm)->sz; i++)
		{
			printf("\t%d: %s\n", i + 1, (*tm)->players[i].name);
		}
		printf("Choose a player number: ");
		fgets(buffer, MENU_TKN_SIZE, stdin);
		handleString(buffer, __FILE__, __LINE__);
		int iRm_pl = atoi(buffer) - 1;

		for (i = iRm_pl; i < (*tm)->sz - 1; i++)
		{
			(*tm)->players[i] = (*tm)->players[i + 1];
		}
		(*tm)->sz--;
		printf("Player removed...\n");
		printf("Returning to team management menu\n");
		Sleep(1000);
		
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
	char tz[MENU_TKN_SIZE];
	char buffer[MAX_LINE_SIZE];

	system("cls");

	// Obtain name of player
	printf("\t\tPlayer Addition Menu:\n\n");
	printf("Enter a player name: ");
	fgets(name, MAX_PLNM_SIZE, stdin);
	handleString(name, __FILE__, __LINE__);


	// Obtain timezone of player
	printf("1. West\n");
	printf("2. Mountain\n");
	printf("3. Central\n");
	printf("4. East\n");
	printf("Enter player time zone choice (number): ");
	fgets(tz, MENU_TKN_SIZE, stdin);
	handleString(tz, __FILE__, __LINE__);


	switch (atoi(tz))
	{
	case 1:
		p = createPlayer(name, TZ_PST);
		break;
	case 2:
		p = createPlayer(name, TZ_MST);
		break;
	case 3:
		p = createPlayer(name, TZ_CST);
		break;
	case 4:
		p = createPlayer(name, TZ_EST);
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
	printf("\tTeam: \n");
	printf("\t      %s\n\n", tm->tmName);
	printf("\tPlayers: \n");
	for (i = 0; i < tm->sz; i++)
		printf("\t         %s\n", tm->players[i].name);
}


// This function will be used for more features in the future
#if 0
void printTeamData(Team *tm)
{

}
#endif