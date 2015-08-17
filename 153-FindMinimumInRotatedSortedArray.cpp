/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int low = nums[0];
		for (size_t i = 0; i < nums.size() - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				low = nums[i + 1];
				break;
			}
		}
		return nums[0] < low ? nums[0] : low;
	}
};

int main() {
	// 1 2 3 4 5 6 7 8 9
	// 6 7 8 9 1 2 3 4 5
	// 1 2 3 4 5
	int array[8] = {6, 7, 8, 9, 2, 3, 4, 5};
	vector <int> source;	
	for (int i = 0; i < 8; i++) {
		printf("%d ", array[i]);
		source.push_back(array[i]);
	}
	printf("\n");

	Solution s;
	int ret = s.findMin(source);
	printf("Return value is %d\n", ret);

	return 0;
}
