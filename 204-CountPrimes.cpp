/*
Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(int num) {
	if (num <= 1) { 
		return false;
	}

   	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}

 	return true;
}

class Solution {
public:
	int countPrimes(int n) {
		bool *store = (bool *)malloc(n * sizeof(bool));
		if (store == NULL) {
			return 0;
		}
		memset(store, true, n * sizeof(bool));

		int count = 0;
		for (int i = 2; i * i <= n; i++) {
			if (!isPrime(i)) {
				continue;
			}
			// If i is a prime, i*i + pi cannot be a prime.
			for (int j = i * i; j < n; j += i) {
         		store[j] = false;
      		}
		}

		for (int i = 2; i < n; i++) {
      		if (store[i]) {
				count++;
			}
   		}	
		
		free(store);
		return count;
	}
};

int main() {
	Solution s;
	int ret = s.countPrimes(100);
	printf("Primes number %d\n", ret);

	return 0;
}
