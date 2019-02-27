#include <stdio.h>
#include <stdlib.h>
#include "help_func.hpp"


int sreplace(char old, char n, char *buffer)
{
	int count = 0;
	if (*buffer)
	{
		while (*buffer)
		{
			if (*buffer == old)
			{
				*buffer = n;
				count++;
			}
			buffer++;
		}
	}
	return count;
}



void errExit(const char *errmsg, const char *fileName, int lineNumber)
{
	fprintf(stderr, "%s! \n\tFile: %s \n\tLine: %d\n", errmsg, fileName, lineNumber);
	system("pause");
	exit(EXIT_FAILURE);
}



void handleString(char *buffer, const char *fileName, int lineNumber)
{
	if (*buffer)
	{
		if (!sreplace('\n', '\0', buffer))
			errExit("Buffer overflow!", fileName, lineNumber);

		return;
	}
	errExit("handleString failed to execute on provided string!", fileName, lineNumber);
}


void listOptions()
{
	printf("\n\n");
	printf("1: Create team\n");
	printf("2: Load team\n");
	printf("3: Modify team\n");
	printf("4: Save team data\n");
	printf("5: List players in loaded team\n");
	printf("6: Connect to server (Note: option currently unavailable)\n");
	printf("7: Exit\n");
}

void listLogansOptions()
{
	printf("\n\n");
	printf("1: Load Cheats\n");
	printf("2: Save Cheats\n");
	printf("3: Make Cheats\n");
	printf("4: Just Cheats\n");
	printf("5: Start Cheats\n");
	printf("6: Gay Cheats\n");
	printf("7: Cheats\n");
}

