/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <stdio.h>

class Solution {
public:
	long long Combination(long long m, long long n) {
		if (m <= n) {
			return 1;
		}

		long long result = 1;
		for (long long i = n + 1; i <= m; i++) {
			result = (result * i) / (i - n);
		}
		return result;
	}
	
	int climbStairs(int n) {
		int result = 0;		
       	for (int p = 0; p <= n; p++)  {
       		for (int q = 0; q <= n; q++)  {
				if ((p +  2 * q) == n) {
					int sum = p + q;
					int combine = Combination(sum , p);
					result += combine; 
				}
			}
		}

		return result;
    }
};

int main() {
	int steps = 44;
	Solution s;
	int ret = s.climbStairs(steps);

	printf("Distinct Ways: %d\n", ret);
	return 0;
}
