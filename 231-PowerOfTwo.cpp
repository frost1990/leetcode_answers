/*
Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

*/

#include <stdio.h>
#include <stdint.h>

class Solution {
public:
	 int hammingWeight(uint32_t n) {
		int count = 0;
		while (n) {
			if ((n & 1) == 1) {
				count++;
			}
			n >>= 1;
		}
       	return count; 
    }

	bool isPowerOfTwo(int n) {
		if (n < 0) {
			return false;
		}
		
		if (hammingWeight(n) == 1)	{
			return true;
		}

		return false;
	}
};

int main() {
	Solution s;

	int n = 1;

	for (int i = 1; i <= 1234564; i++) {
		if (s.isPowerOfTwo(i)) {
			printf("Number:%d is power of two\n", i);	
		}
	}

	//printf("Return value is %s\n", ret ? "true":"false");	

	return 0;
}
