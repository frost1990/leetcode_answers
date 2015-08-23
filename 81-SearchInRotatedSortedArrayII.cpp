/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
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

	bool search(vector<int>& nums, int target) {
		int divide = -1;
		for (size_t i = 0; i < nums.size() - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				divide = i;
				break;
			}
		}

		if (divide == -1) {
			if (binarysearch(nums, target, 0, nums.size() - 1) == -1) {
				return false;
			} else {
				return true;
			}
		}

		int ret1 = binarysearch(nums, target, 0, divide);
		int ret2 = binarysearch(nums, target, divide + 1, nums.size() - 1);

		if (ret1 == -1 && ret2 == -1) {
			return false;
		}
		return true;
	}
};

int main() {
	//				 0  1  2  3  4  5   6   7   8   9
	int array[10] = {9, 9, 10, 11, 1, 2, 3, 3, 5, 6};
	vector<int> source;
	for (int i = 0; i < 10; i++) {
		source.push_back(array[i]);
		printf("%d ", array[i]);
	}
	printf("\n");
	
	Solution s;
	bool ret = s.search(source, 0);

	printf("Return value is %s\n", ret ? "true" : "false");
	return 0;
}
