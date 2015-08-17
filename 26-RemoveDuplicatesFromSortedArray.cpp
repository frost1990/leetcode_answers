/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		int newlen = 1;
		for (size_t i = 0; i < nums.size() - 1; i++) {
			if (nums[i] != nums[i + 1]) {
				newlen++;
			}
		}

		for (size_t i = 0, count = 1; i < nums.size() - 1; i++) {
			if (nums[i] == nums[i + 1]) {
				continue;
			} else {
				nums[count] = nums[i + 1];
				count++;
			} 
		}

		return newlen;
	}
};

int main() {
	int array[8] = {1, 1, 2, 5, 5, 5, 6, 8};
	vector <int> source;	
	for (int i = 0; i < 8; i++) {
		source.push_back(array[i]);
	}

	for (size_t i = 0; i < source.size(); i++) {
		printf("%d ", source[i]);
	}
	printf("\n");
	
	Solution s;
	int ret = s.removeDuplicates(source);
	for (size_t i = 0; i < source.size(); i++) {
		printf("%d ", source[i]);
	}
	printf("\n");
	
	printf("Return value is %d\n", ret);
	return 0;
}
