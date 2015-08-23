/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	int binarysearch(vector<int> &nums, int target, int low, int high) {
		if (nums.empty()) {
			return -1;
		}

		if (target < nums[low] || target > nums[high]) {
			return -1;
		}

		int middle = (low + high) / 2;
		while (low <= high) {
			if (target > nums[middle]) {
				low = middle + 1;
				middle = (low + high) / 2;
			} else if (target < nums[middle]) {
				high = middle - 1;
				middle = (low + high) / 2;
			} else {
				return middle;
			}
		}

		return -1;
	}


	int search(vector<int>& nums, int target) {
		if (nums.empty()) {
			return -1;
		}

		int divide = -1;
		for (size_t i = 0; i < nums.size() - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				divide = i;
				break;
			}
		}
		if (divide == -1) {
			return binarysearch(nums, target, 0, nums.size() - 1);
		}

		int ret1 = binarysearch(nums, target, 0, divide);
		int ret2 = binarysearch(nums, target, divide + 1, nums.size() - 1);
	
		if (ret1 == -1 && ret2 == -1) {
			return -1;
		}

		return (ret1 != -1) ? ret1 : ret2;
	}
};

int main() {
	//				 0  1  2  3  4  5  6  7  8  9
	int array[10] = {8, 9, 10, 11, 1, 2, 3, 4, 5, 6};
	vector<int> source;
	for (int i = 0; i < 10; i++) {
		source.push_back(array[i]);
		printf("%d ", array[i]);
	}
	printf("\n");
	
	Solution s;
	int ret = s.search(source, 1);

	printf("Return value is %d\n", ret);
	return 0;
}
