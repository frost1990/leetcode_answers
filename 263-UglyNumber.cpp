/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPrime(int num) {
		if (num <= 1) { 
			return false;
		}

		for (int i = 2; ((long)i * (long)i) <= (long long)num; i++) {
			if (num % i == 0) {
				return false;
			}
		}

 		return true;
	}

	bool isUgly(int num) {
		if (num <= 0) {
			return false;
		} else if ( 0 < num && num <= 6 ) {
			return true;
		}

		if (isPrime(num)) {
			return false;
		}

		for (int i = 1; ((long)i * (long)i) <= (long long)num; i++) {
			if ((num % i == 0) && (i != 1)) {
				int ret = num / i;
				if ((i % 2 == 0) || (i % 3 == 0) || (i % 5 == 0)) {
					if ((ret % 2 == 0) || (ret % 3 == 0) || (ret % 5 == 0)) {
						continue;
					} else {
						printf("Factor is %d\n", ret);
						return false;
					}
				} else {
					printf("Factor is %d\n", i);
					return false;
				}
			} 
		}
		return true;
	}
};

int main() {
	//int source = 2147483647;
	int source = 14;
	Solution s;
	bool ret = s.isUgly(source);
	printf("Source is %d, Return value is %s\n", source, ret ? "true" : "false");
	return 0;
}
