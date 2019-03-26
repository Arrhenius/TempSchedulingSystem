#ifndef HELP_FUNC_HPP
#define HELP_FUNC_HPP


// These are defined constants to indicate a TimeZone
#define TZ_PST 100
#define TZ_MST 101
#define TZ_CST 102
#define TZ_EST 103

// Max constants used for fgets
#define MAX_LINE_SIZE 1024		// Max string size from stdin
#define MENU_TKN_SIZE 4			// Max menu token size
#define MAX_PLNM_SIZE 32		// Max player name size
#define MAX_TMNM_SIZE 64		// Max team name size

// Boolean constants
#define FALSE	0
#define TRUE	1



// Function prototypes
int sreplace(char old, char n, char *buffer);
void errExit(const char *errmsg, const char *fileName, int lineNumber);
void handleString(char *buffer, const char *fileName, int lineNumber);
void listOptions();







#endif
