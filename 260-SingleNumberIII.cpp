/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

or example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int xorret = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			xorret ^= nums[i];
    	}
		printf("xorret %x\n", xorret);
		// xorret must not be zero, find the first 1 bit, in which bit A cannot be equal to B
		int n = 0, count = 0;
		n = xorret & 1;
		while (!n) {
			xorret = xorret >> 1;
			n = xorret & 1;
			count++;
		}

		int mask = (1 << count);
		printf("mask %x\n", mask);
		int ret1 = 0;
		int ret2 = 0;
		
		// Partition into two arrays by mask &
		for (size_t i = 0; i < nums.size(); i++) {
			// not 1
			if ((mask & nums[i]) == 0) {
				ret1 ^= nums[i];
			} else {
				ret2 ^= nums[i];
			}
		}
		vector<int> result;
		result.push_back(ret1);
		result.push_back(ret2);

		return result;
	}
};

int main() {
	int array[22] = {-1638685546,-2084083624,-307525016,-930251592,-1638685546,1354460680,623522045,-1370026032,-307525016,-2084083624,-930251592,
		472570145,-1370026032,1063150409,160988123,1122167217,1145305475,472570145,623522045,1122167217,1354460680,1145305475};

	vector <int> source;	
	for (int i = 0; i < 22; i++) {
		source.push_back(array[i]);
	}

	Solution s;
	vector<int> result = s.singleNumber(source);
	
	printf("Return value is %d and %d\n", result[0], result[1]);
	return 0;
}
