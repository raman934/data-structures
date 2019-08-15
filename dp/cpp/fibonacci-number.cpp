/* The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
   Fibonacci sequence, such that each number is the sum of the two preceding
   ones, starting from 0 and 1. That is,
   F(0) = 0,   F(1) = 1
   F(N) = F(N - 1) + F(N - 2), for N > 1.
   Given N, calculate F(N).

   LC 509. Fibonacci Number
   Author: Shruti
*/

class Solution {
public:
    int fib(int N) {
        if(N <= 1) {
            return N; // base case
        }
        vector<int> cache(N + 1, 0); // memory for memoization
        cache[0] = 0;
        cache[1] = 1;
        for(int i = 2; i <= N; i++) {
            cache[i] = cache[i-1] + cache[i-2];
        }
        return cache[N];
    }
};
