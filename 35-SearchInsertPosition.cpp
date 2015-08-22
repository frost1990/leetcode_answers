/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int low = 0; 
		int high = nums.size() - 1; 
		int middle = (low + high) / 2;
		if (target < nums[low]) {
			return low;
		}
		if (target > nums[high]) {
			return high + 1;
		}

		while (low <= high) {
			if (target > nums[middle]) {
				low = middle + 1;
				middle = (low + high) / 2;
				printf("low %d middle %d high %d\n", low, middle, high);
			} else if (target < nums[middle]) {
				high = middle - 1;
				middle = (low + high) / 2;
				printf("low %d middle %d high %d\n", low, middle, high);
			} else {
				printf("low %d middle %d high %d\n", low, middle, high);
				return middle;
			}
		}
		return low;
	}
};

int main() {
	//				0   1  2  3  4  5  6  7  8  9
	int array[10] = {0, 2, 3, 4, 5, 6, 7, 8, 9, 12};
	vector<int> source;
	for (int i = 0; i < 10; i++) {
		source.push_back(array[i]);
		printf("%d ", array[i]);
	}
	printf("\n");
	
	Solution s;
	int ret = s.searchInsert(source, 10);

	printf("Return value is %d\n", ret);
	return 0;
}
