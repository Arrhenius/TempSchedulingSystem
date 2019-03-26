#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help_func.hpp"
#include "player.hpp"
#include "team.hpp"


Player createPlayer(const char *fullName, const char *alias, int tz)
{
	Player p;

	strcpy(p.name, fullName);	// Copy their full name
	strcpy(p.alias, alias);		// Copy their alias
	p.timezone = tz;			// Set timezone constant

	strcpy(p.avl[DOW_MON].dayOfWeek, "Mon");
	strcpy(p.avl[DOW_TUE].dayOfWeek, "Tue");
	strcpy(p.avl[DOW_WED].dayOfWeek, "Wed");
	strcpy(p.avl[DOW_THU].dayOfWeek, "Thu");
	strcpy(p.avl[DOW_FRI].dayOfWeek, "Fri");
	strcpy(p.avl[DOW_SAT].dayOfWeek, "Sat");
	strcpy(p.avl[DOW_SUN].dayOfWeek, "Sun");


	// Sets the correct timezone for the player
	if (tz = TZ_PST)
		strcpy(p.timeZoneFull, "Pacific Standard Time");
	else if (tz = TZ_MST)
		strcpy(p.timeZoneFull, "Mountain Standard Time");
	else if (tz = TZ_CST)
		strcpy(p.timeZoneFull, "Central Standard Time");
	else if (tz = TZ_EST)
		strcpy(p.timeZoneFull, "Eastern Standard Time");
	else
		errExit("Invalid constant provided! Terminating program.", __FILE__, __LINE__);

	return p;
}


void playerAvailability(Team **tm, const int playerIndex)
{
	if (!(*tm))
	{
		while (1)
		{
			char buffer[MENU_TKN_SIZE + 1];
			int handle;
			system("cls");
			printf("\t\tPlayer Availability Menu\n\n");

			printf("Which day would you like to modify?\n");
			printf("List of choices to enter is provided: \n");
			printf("Mon\nTue\nWed\nThu\nFri\nSat\nSun\n");
			printf("Enter a choice exactly as listed: ");
			fgets(buffer, MENU_TKN_SIZE, stdin);
			handleString(buffer, __FILE__, __LINE__);

			if (strcmp(buffer, "Mon") == 0)
				handle = DOW_MON;
			else if (strcmp(buffer, "Tue") == 0)
				handle = DOW_TUE;
			else if (strcmp(buffer, "Wed") == 0)
				handle = DOW_WED;
			else if (strcmp(buffer, "Thu") == 0)
				handle = DOW_THU;
			else if (strcmp(buffer, "Fri") == 0)
				handle = DOW_FRI;
			else if (strcmp(buffer, "Sat") == 0)
				handle = DOW_SAT;
			else if (strcmp(buffer, "Sun") == 0)
				handle = DOW_SUN;
			else
				handle = -1;

			switch (handle)
			{
			case DOW_MON:
			case DOW_TUE:
			case DOW_WED:
			case DOW_THU:
			case DOW_FRI:
			case DOW_SAT:
			case DOW_SUN:
			default:

			}
		}
	}
}