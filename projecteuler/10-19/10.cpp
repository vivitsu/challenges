#include <stdio.h>
#include <math.h>

int isPrime(int num)
{
  double num_sqrt = sqrt((double) num);

  for (int i = 2; i <= num_sqrt; i++) {
    if (!(num % i)) return 0;
  }
  return 1;
}

int main(int argc, char **argv)
{
  long sum = 0;
  int LIMIT = 2000000; // 2 million

  for (int i = 2; i <= LIMIT; i++) {
    if (isPrime(i)) {
      sum += i;
    }
  }

  printf("%ld\n", sum);
}
