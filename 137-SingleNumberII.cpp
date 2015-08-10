/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int ones = 0;
		int twos = 0;
		int not_threes = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			twos |= ones & nums[i];
			ones ^= nums[i];
			not_threes = ~(ones & twos);
			ones &= not_threes;
			twos &= not_threes;
    	}
		return ones;
	}
};

int main() {
	int array[16] = {0, 0, 0, 1, 1, 1, 4, 3, 3, 3, 6, 6, 6, 2, 2, 2};
	vector <int> source;	
	for (int i = 0; i < 16; i++) {
		source.push_back(array[i]);
	}

	Solution s;
	int ret = s.singleNumber(source);
	
	printf("Return value is %d\n", ret);
	return 0;
}
