/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int result = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			result ^= nums[i];
    	}
		return result;
	}
};

int main() {
	int array[11] = {0, 0, 1, 1, 4, 3, 3, 6, 6, 2, 2};
	vector <int> source;	
	for (int i = 0; i < 11; i++) {
		source.push_back(array[i]);
	}

	Solution s;
	int ret = s.singleNumber(source);
	
	printf("Return value is %d\n", ret);
	return 0;
}
