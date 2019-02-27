#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help_func.hpp"
#include "player.hpp"


Player createPlayer(const char *name, int tz)
{
	Player p;

	
	strcpy(p.name, name);
	p.timezone = tz;

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
