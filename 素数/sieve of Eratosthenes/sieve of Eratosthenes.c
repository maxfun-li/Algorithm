#include<stdio.h>
int main()
{
       int N, currentPrime, timesOfCurrentPrime, range = 2, counter = 0;
       unsigned char primeFlag[65536] = { 0 };
       printf("please input a number(<65536) for searching area£º ");
       scanf("%d", &N);
       printf("\nAll primes in range between 0 and %d are:\n", N);
       while ((range * range) <= N)
       {
              range++;
       }
       for (currentPrime = 2; currentPrime < range;)
       {
              for (timesOfCurrentPrime = currentPrime * 2; timesOfCurrentPrime <= N; timesOfCurrentPrime += currentPrime)
              {
                     primeFlag[timesOfCurrentPrime] = 1;
              }
              while ((primeFlag[++currentPrime]) && (currentPrime < range));
       }
       for (currentPrime = 2; currentPrime <= N; currentPrime++)
       {
              if (primeFlag[currentPrime] == 0)
              {
                     printf("%d  ", currentPrime);
                     counter++;
                     if (counter % 10 == 0)
                     {
                           printf("\n");
                     }
              }
       }
       
       printf("\n----------------------\nTotal: %d\n\n", counter);
       system("pause"); 
}
