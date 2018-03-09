// https://www.reddit.com/r/dailyprogrammer/comments/826coe/20180305_challenge_353_easy_closest_string/

// Reference - https://www.reddit.com/r/dailyprogrammer/comments/826coe/20180305_challenge_353_easy_closest_string/dv80qei/

// TODO: Implement other string similarity algos

/* HOW TO RUN THIS PROGRAM:
 *
 * cat input.txt | a.out
 */

#include <stdio.h>
#include <string.h>

#define MAX_N   256
#define MAX_LEN 64

int main(void)
{
  int n;
  int distances[MAX_N];
  char strings[MAX_N][MAX_LEN];
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    {
      scanf("%s", strings[i]);
    }

  /* The central conceit of this loop is that Hamming
   * distances are reflective, i.e. the Hamming Distance
   * between string 1 & string 2 will be the same as the
   * distance between strings 2 & 1. In matrix form, it looks like this
   *    
   *     0   1   2   3
   *   *****************
   * 0 * 0 * x * y * z *
   *   *   *   *   *   *
   *   *****************
   * 1 * x * 0 * w * a *
   *   *   *   *   *   *
   *   *****************
   * 2 * y * w * 0 * b *
   *   *   *   *   *   *
   *   *****************
   * 3 * z * a * b * 0 *
   *   *  *  *  *  *   *
   *   *****************
   *
   * Where any pair, e.g., (1,2) = x represents the Hamming distance between
   * those two strings.
   *
   *   *****
   *   *   * <- Holds the sum of distances (0,1), (0,2), (0,3)
   *   *   *
   *   *****
   *   *   * <- Holds the sum of distances (1,0), (1,2), (1,3)
   *   *   *
   *   *****
   *   *   * <- Holds the sum of distances (2,0), (2,1), (2,3)
   *   *   *
   *   *****
   *   *   * <- Holds the sum of distances (3,0), (3,1), (3,2)
   *   *   *
   *   *****
   *
   */
  for (int i = 0; i < n-1; i++)
    {
      for (int j = i+1; j < n; j++)
  	{
	  int dist = 0;
	  
	  // Dont compute the distance for strings of different lengths
	  // NOTE: The '\0' (0) character is falsy in C
	  for (int s = 0; strings[0][s]; s++)
	      dist += strings[i][s] != strings[j][s];
	  distances[i] += dist;
	  distances[j] += dist;
  	}
    }

  /*
   * In order to find the string with the shortest total distance to all other
   * strings, we just need to add up the columns from 1-3, and find the column
   * with the minimum sum, and that's our answer.
   */
  int min_index = 0;
  for (int i = 1; i < n; i++)
    {
      if (distances[i] < distances[min_index]) min_index = i;
    }

  puts(strings[min_index]);
}
