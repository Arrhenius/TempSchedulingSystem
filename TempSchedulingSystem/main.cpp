#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "player.hpp"
#include "team.hpp"
#include "help_func.hpp"
#include "createTeam.hpp"
#include "display.hpp"
#include "modifyTeam.hpp"



int main(int nargs, char *argv[])
{

	/*
	 * Here we call the "ShowWindow" function, and pass it
	 * the active program window and the maximize constant
	 * to run the program in a maximized window
	 */
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	//	HWND wh = GetConsoleWindow();
	//	MoveWindow(wh, 100, 100, 1024, 768, TRUE);

	char buffer[4];
	Team *tm = NULL;

	while (1)
	{
		// Clear the screen
		system("cls");		// Clear the screen
		nameLoader();		// Display team name
		if (tm)				// If team is loaded, display it
			displayTeam(tm);
		listOptions();		// List program options

		printf("Enter an option from the list (number): ");
		fgets(buffer, MENU_TKN_SIZE, stdin);
		handleString(buffer, __FILE__, __LINE__);
		switch (atoi(buffer))
		{
		case 1:
			createTeamMenu(&tm);
			break;
		case 2:
			//loadTeam();
			break;
		case 3:
			modifyTeam(&tm);
			break;
		case 4:
			//saveTeamData(&tm);
			break;
		case 5:
			listTeamPlayers(tm);
			break;
		case 6:
			//connectToServer(); // Function will be defined in the future
			break;
		case 7:
			free(tm);
			exit(EXIT_SUCCESS);
		default:
			printf("Invalid option entered!\n");
			system("pause");
			break;
		}
	}


	return EXIT_SUCCESS;
}




