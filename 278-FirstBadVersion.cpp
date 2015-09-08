/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <stdio.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
	if (version >= 2) {
		return true;
	}
	return false;
}

class Solution {
public:
	int firstBadVersion(int n) {
		long long low = 1; 
		long long high = n;
		long long middle = (high + low) / 2;

		while (low <= high) {
			if (isBadVersion(middle)) {
				high = middle - 1;
				printf("high = %llu\n", high);
			} else {
				low = middle + 1;
				printf("low = %llu\n", low);
			}
			middle = (high + low) / 2;
		}
		return low;
	}
};

int main() {
	Solution s;
	int ret = s.firstBadVersion(3);

	printf("Return value is %d\n", ret);
	return 0;
}
