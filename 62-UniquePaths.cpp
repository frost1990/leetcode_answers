/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

Illustration picture:
https://leetcode.com/problems/unique-paths/
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

	int uniquePaths(int m, int n) {
		if (m <= 1 || n <= 1) {
			return 1;
		}
		return (int)Combination(m + n - 2, m - 1);
	}
};

int main() {
	Solution s;
	int m = 2;
	int n = 2;
	int ret = s.uniquePaths(m, n);

	printf("m = %d, n = %d, and there are %d possible unique paths.\n", m, n, ret);
	return 0;
}
