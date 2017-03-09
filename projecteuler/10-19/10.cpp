#include <stdio.h>
#include <math.h>

int isPrime(int num)
{
  double sqr_num = sqrt((double) num);

  for (int i = 1; i <= num; i++) {
    if (i != 1 || i != num) {
      if ((num / i) == 0) return false;
    }
  }
  return true;
}
  
int main(int argc, char **argv)
{
  int sum = 0;
  int LIMIT = 2000000; // 2 million

  for (int i = 1; i <= LIMIT; i++) {
    if (isPrime(i)) {
      sum += i;
    }
  }

  printf("%d\n", sum);
}
