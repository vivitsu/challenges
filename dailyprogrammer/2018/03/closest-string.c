// https://www.reddit.com/r/dailyprogrammer/comments/826coe/20180305_challenge_353_easy_closest_string/
// TODO: Implement other string similarity algos

/* HOW TO RUN THIS PROGRAM:
 *
 * cat input.txt | a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N   256
#define MAX_LEN 64

int hamming_distance(char *s1, char *s2)
{
  int distance = 0;
  int len1 = strlen(s1);
  int len2 = strlen(s2);

  if (len1 != len2) return -1;

  for (int i = 0; i < len1; i++)
    {
      if (s1[i] != s2[i]) distance += 1;
    }
  return distance;
}

int main(int argc, char **argv)
{

  int min = INT_MAX;  
  int min_index;
  char strings[MAX_N][MAX_LEN];

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    {
      scanf("%s", strings[i]);
    }

  int distances[n][n];
  
  for (int i = 0; i < n; i++)
    {
      char *str1 = strings[i];
      int sum = 0;
      for (int j = 0; j < n; j++)
  	{
  	  if (i == j) continue;
  	  else
  	    {
  	      char *str2 = strings[j];
  	      distances[i][j] = hamming_distance(str1, str2);
  	      sum += distances[i][j];
  	    }
  	}

      if (sum < min)
  	{
  	  min = sum;
  	  min_index = i;
  	}
    }

  
  printf("The closest string to all the input strings is %s\n", strings[min_index]);

  int sum = 0;
  for (int i = 0; i < n; i++)
    {
      if (i == min_index) continue;
      sum += distances[min_index][i];
      printf("The distance between string %d and %d is %d\n", min_index+1, i+1, distances[min_index][i]);
    }
  printf("The sum of all distances for string %s is %d\n", strings[min_index], sum);

  exit(EXIT_SUCCESS);
}
