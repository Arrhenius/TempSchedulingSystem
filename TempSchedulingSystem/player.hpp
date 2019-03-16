#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "availability.hpp"
#define AV_MXSZ 7

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

#endif

