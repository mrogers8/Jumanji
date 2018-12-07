// Random number generator for dice 

#include "../include/num_gen.h"

//*********************************************************
//*********************************************************
int16_t generate_number(int max)
{
	int16_t winner;
	winner = (rand() % max) + 1;
	return winner;
}

