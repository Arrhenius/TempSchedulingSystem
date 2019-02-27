
#ifndef PLAYER_H
#define PLAYER_H

typedef struct
{
	char name[32];				// Name of player
	int timezone;				// variable for boolean instructions
								// Will use a timezone constant from help_func.hpp
	char timeZoneFull[32];		// Full timezone name

} Player;


Player createPlayer(const char *name, int tz);

#endif

