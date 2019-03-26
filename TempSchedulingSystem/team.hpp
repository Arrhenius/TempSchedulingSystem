#ifndef TEAM_HPP
#define TEAM_HPP


typedef struct
{
	int sz;
	int maxsz;
	char tmName[64];
	Player players[1];
} Team;


#define INITTMSZ 6
#define INCRTMSZ 9
#define D_LIST_TM_SZ(n)  ( (size_t)sizeof(Team) + ((n-1) * (size_t)sizeof(Player)) )

Team *init_team(int num, const char *name);
void removePlayers(Team **tm);
void insertPlayerInTeam(Team **tm, Player p);
void addPlayers(Team **tm);
void listTeamPlayers(Team *tm);

//void printTeamData(Team tm);

#endif

