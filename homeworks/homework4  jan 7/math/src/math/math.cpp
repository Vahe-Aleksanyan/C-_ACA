#include "include/math/math.h"

bool isPrime(int num) {
   if(num == 2) return true;
   for(int i = 2; i <= num/2; ++i)
      if(num%i==0) return false;
   return true;
}


int fibonacci(int num) {
   int x = 0, y = 1, z = 0;
   for (int i = 0; i < num; i++) {
      z = x + y;
      x = y;
      y = z;
   }
}


bool isPowerOfTwo(int num)
{
    if (num == 0)
        return 0;
    while (num != 1) {
        if (num % 2 != 0)
            return 0;
        num = num / 2;
    }
    return 1;
}
 