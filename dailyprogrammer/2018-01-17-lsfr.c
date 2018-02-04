// https://www.reddit.com/r/dailyprogrammer/comments/7r17qr/20180117_challenge_347_intermediate_linear/
#include <stdio.h>
#include <stdlib.h>


// SAMPLE INPUT: [0,2] XOR 001 7

// TODO: Print binary number

int main(int argc, char *argv[]) {

  printf("Count of arguments: %d\n", argc);

  printf("Tap locations: %s\n", argv[1]);

  /*
  if (argc < 4) {
    printf("Insufficient arguments\n");
    exit(-1);
  } else if (argc > 4) {
    printf("This program accepts only 4 arguments\n");
    exit(-1);
  } else {
  }
  */

  int tap_locations[] = { 0, 2 };
  char *feedback_function = "XOR";
  unsigned int initial_value = 0b001;
  int num_clock_steps = 7;
  int lfsr = initial_value;
  int iter = 0;
  
  do {
    lfsr = (lfsr & 0b100) ^ (lfsr << 2);
    printf("%d %d\n", iter, lfsr);
    iter++;
  } while (iter < num_clock_steps);
  

  return 0;
}
