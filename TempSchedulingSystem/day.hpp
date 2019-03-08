#ifndef DAY_H
#define DAY_H

typedef struct
{
	char dayOfWeek[4];	// Day of the week abbr.
	int start;			// Available start time; In military time
	int stop;			// end time; In military time
} DayAvailability;


#endif
