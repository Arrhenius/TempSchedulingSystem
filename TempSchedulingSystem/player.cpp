#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help_func.hpp"
#include "availability.hpp"
#include "player.hpp"


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
