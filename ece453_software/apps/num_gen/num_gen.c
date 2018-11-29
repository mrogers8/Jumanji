// Random number generator for dice 

#include "../include/num_gen.h"

//*********************************************************
//*********************************************************
int16_t generate_number(void)
{
	int16_t winner;
	winner = (rand() % 6) + 1;
	return winner;
}

int main(int argc, char **argv) {
  
  int16_t rand;
  int16_t count;
  //values[0] = out of bounds
  int values[] = {0,0,0,0,0,0,0};

  while (count < 100) {
	rand = generate_number();
	//printf("%d\n", rand);
	count++;
	
	//update values
	if (rand < 1 || rand > 6) 
	   values[0]++;
	else 
	   values[rand]++;
  }

  printf(" Breakdown:\n");
  printf("   1: %d\n", values[1]); 
  printf("   2: %d\n", values[2]);
  printf("   3: %d\n", values[3]);
  printf("   4: %d\n", values[4]);
  printf("   5: %d\n", values[5]);
  printf("   6: %d\n", values[6]);
  printf("   out of bounds: %d\n", values[0]);
}


