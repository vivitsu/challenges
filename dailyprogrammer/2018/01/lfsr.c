// https://www.reddit.com/r/dailyprogrammer/comments/7r17qr/20180117_challenge_347_intermediate_linear/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

// SAMPLE INPUT: [0,2] XOR 001 7

// TODO: Print binary number
// TODO: Input validation needed for input bit string?

// TODO: Limit input bit string to sizeof(char)?

// TODO: It would be more efficient to convert the input string
// to binary, but it might be easier to do the computations if they are just characters? I dont know.

/*
char string_to_binary(char* s) {
  if (s == NULL) return 0;

  char binary = 0;
  char *ptr = s;
  int i = 0;

  for (int i = 0; *ptr != '\0'; i++) {
    if (*ptr == '1') binary | (1 << i);
    else binary | (0 << i);
    *ptr++;
  }
    
  return binary;  
}
*/

int main(int argc, char *argv[]) {

/*
  printf("Count of arguments: %d\n", argc);

  printf("Tap locations: %s\n", argv[1]);

  int is_xnor = FALSE;

  if (argc < 4) {
    printf("Insufficient arguments\n");
    exit(-1);
  } else if (argc > 4) {
    printf("This program accepts only 4 arguments\n");
    exit(-1);
  } else {
    char * feedback_function = argv[2];
    if (strcmp(feedback_function, "XNOR")) {
	    is_xnor = TRUE;
    }
    
  }
*/  

  int tap_locations[] = { 0, 2 };
  char *feedback_function = "XOR";
  int initial_value = 1;
  int num_clock_steps = 7;
  int lfsr = initial_value;
  int iter = 0;
  int temp = lfsr;
  
  do {
    printf("%d %d\n", iter, lfsr);
    temp = (lfsr & 1) << 2;
    temp  ^= (lfsr & 4);
    //printf("temp: %d\n", temp);
    // if (is_xnor) temp = !temp;
    lfsr >>= 1;
    //printf("lfsr after 1 right shift: %d\n", lfsr);    
    lfsr = lfsr | temp;
    //printf("final lfsr for next iteration: %d\n", lfsr);
    iter++;
  } while (iter <= num_clock_steps);
  

  return 0;
}
