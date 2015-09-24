/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <stdio.h>
#include <vector>

using namespace std;

void print_vector(vector<int> source) {
	for (size_t i = 0; i < source.size(); i++) {
		printf("%d ", source[i]);
	}
	printf("\n");
}

// 1 0 0 3 12 0 1
// 1 3 12 0  1 0 0
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.empty()) {
			return;
		}

		for (size_t i = 0; i < nums.size(); i++) { 
			size_t step = 1;
			if (nums[i] == 0) {
				for (size_t j = i + 1; (j < nums.size()) && (nums[j] == 0); j++) {
					step++;		
				}
				
				for (size_t j = i; j < nums.size(); j++) {
					if (j + step  <  nums.size()) {
						nums[j] = nums[j + step];
					} else {
						nums[j] = 0;
					}
				}
			}
		}
	}
};

int main() {
	int array[10] = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
	vector<int> source;

	for (int i = 0; i <  10; i++) {
		source.push_back(array[i]);
	}
	print_vector(source);
	Solution s;
	s.moveZeroes(source);
	print_vector(source);

	return 0;
}
