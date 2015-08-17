/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <stdio.h>
#include <vector>

using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) {
			return 0;
		}
		int count = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				nums[count] = nums[i];
				count++;
			} else {
				continue;
			} 
		}
		return count;	
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
	int ret = s.removeElement(source, 5);
	for (size_t i = 0; i < source.size(); i++) {
		printf("%d ", source[i]);
	}
	printf("\n");
	
	printf("Return value is %d\n", ret);
	return 0;
}
