#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "display.hpp"
#include "team.hpp"




// Displays team name at the top of the console.
// Looks unusual due to the necessary escape sequences
// that had to be dealt with.
void nameLoader()
{

	// This print was a joke
#if 0
	printf("\n\n");
	printf("\t  _                             _                _           _           _    \n");
	printf("\t | |                           ( )         /\\   (_)         | |         | |   \n");
	printf("\t | |     ___   __ _  __ _ _ __ |/ ___     /  \\   _ _ __ ___ | |__   ___ | |_  \n");
	printf("\t | |    / _ \\ / _` |/ _` | '_ \\  / __|   / /\\ \\ | | '_ ` _ \\| '_ \\ / _ \\| __| \n");
	printf("\t | |___| (_) | (_| | (_| | | | | \\__ \\  / ____ \\| | | | | | | |_) | (_) | |_  \n");
	printf("\t |______\\___/ \\__, |\\__,_|_| |_| |___/ /_/    \\_\\_|_| |_| |_|_.__/ \\___/ \\__| \n");
	printf("\t               __/ |                                                          \n");
	printf("\t              |___/                                                           \n");
#endif
#if 1
	printf("\n\n");
	printf("\t\t __     ___ _             _  \n");
	printf("\t\t \\ \\   / (_) |           | | \n");
	printf("\t\t  \\ \\_/ / _| | _____  ___| | \n");
	printf("\t\t   \\   / | | |/ / _ \\/ __| | \n");
	printf("\t\t    | |  | |   <  __/\\__ \\_| \n");
	printf("\t\t    |_|  |_|_|\\_\\___||___(_) \n");
	printf("\t\t                               \n");
#endif

#if 0
	printf("                              ___           ___           ___      \n");
	printf("      ___       ___          /__/|         /  /\         /  /\     \n");
	printf("     /__/|     /  /\        |  |:|        /  /:/_       /  /:/_    \n");
	printf("    |  |:|    /  /:/        |  |:|       /  /:/ /\     /  /:/ /\   \n");
	printf("    |  |:|   /__/::\      __|  |:|      /  /:/ /:/_   /  /:/ /::\  \n");
	printf("  __|__|:|   \__\/\:\__  /__/\_|:|____ /__/:/ /:/ /\ /__/:/ /:/\:\ \n");
	printf(" /__/::::\      \  \:\/\ \  \:\/:::::/ \  \:\/:/ /:/ \  \:\/:/~/:/ \n");
	printf("    ~\~~\:\      \__\::/  \  \::/~~~~   \  \::/ /:/   \  \::/ /:/  \n");
	printf("      \  \\:\     /__/:/    \  \\:\        \  \\:\\/:/     \__\/ /:/   \n");
	printf("       \__\/     \__\/      \  \:\        \  \::/        /__/:/    \n");
	printf("                             \__\/         \__\/         \__\/     \n");
#endif
}



// Still need to finish this function
#if 1
void displayTeam(Team *tm)
{
#if 0
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
#endif

	if (tm)
	{
	//	printf("%*s\n", 10, "a");
		int i;
		printf("%*s: %s\n", 65, "Team", tm->tmName); 
	//	printf("%*s:\n", columns-16, tm->tmName);
		printf("%*s: \n", 65, "Players");
		for (i = 0; i < tm->sz; i++)
		{
			printf("%*s\n", 75, tm->players[i].name);

		//	printf("%*s\n", columns, tm->players->name);
		}
	}
}
#endif
