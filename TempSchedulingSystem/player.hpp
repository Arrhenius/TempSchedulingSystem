#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "team.hpp"

#define DOW_MON	0
#define DOW_TUE	1
#define DOW_WED	2
#define DOW_THU	3
#define DOW_FRI	4
#define DOW_SAT	5
#define DOW_SUN	6
#define AV_MXSZ	7


// NOTE: This file inclusion seems to cause problems if not placed at the top
// Intellisense (I think that's what it is called) seems to be buggy with this
// This is based on forum searches
//#include "team.hpp"	

typedef struct
{
	char dayOfWeek[4];	// Day of the week abbr.
	int start;				// Available start time; In military time
	int stop;				// End time; In military time

} Availability;


typedef struct
{
	char name[32];						// Name of player
	char alias[32];					// Alias of player
	int timezone;						// variable for boolean instructions
											// Will use a timezone constant from help_func.hpp
	char timeZoneFull[32];			// Full timezone name
	Availability avl[AV_MXSZ];		// Player weekly availability
} Player;


Player createPlayer(const char *fullName, const char *alias, int tz);
void playerAvailability(Team **tm, int playerIndex);
#endif