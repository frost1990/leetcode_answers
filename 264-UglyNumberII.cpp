/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whore prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15 is the sequence of the first 11 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:
1. The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
2. An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
3. The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
4. Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	int min(int a, int b, int c) {
		int m = (a <= b) ? a : b;
		return (c <= m) ? c : m;
	}

	int nthUglyNumber(int n) {
		if (n <= 2) {
			return n;
		} 	

		int *store = new int[n];
		store[0] = 1;
		int m2 = 0, m3 = 0, m5 = 0;
		for (int i = 1; i < n; i++) {
			int n2 = 2 * store[m2];
			int n3 = 3 * store[m3];
			int n5 = 5 * store[m5];
			int mininum = min(n2, n3, n5);
			store[i] = mininum;
			printf("%dth ugly number is %d\n", i + 1, mininum);
			if (mininum == n2) {
				m2++;
			} 
			if (mininum == n3) {
				m3++;
			} 
			if (mininum == n5) {
				m5++;
			}
		}
		int result = store[n - 1];
		delete []store;
		return result;
	}
};

int main() {
	Solution s;

	int ret = s.nthUglyNumber(10);
	printf("Return value is %d\n", ret);
	return 0;
}
