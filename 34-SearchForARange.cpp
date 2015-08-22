/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		result.push_back(-1);
		result.push_back(-1);
		if (nums.empty()) {
			return result;
		}	

		int low = 0; 
		int high = nums.size() - 1; 
		int middle = (low + high) / 2;
		if (target < nums[low] || target > nums[high]) {
			return result;
		}

		while (low <= high) {
			if (target > nums[middle]) {
				low = middle + 1;
				middle = (low + high) / 2;
			} else if (target < nums[middle]) {
				high = middle - 1;
				middle = (low + high) / 2;
			} else {
				for (int i = middle; (i >= 0) && (nums[i] == target); i--) {
					result[0] = i;
				}
				for (size_t i = middle; (i < nums.size()) && (nums[i] == target); i++) {
					result[1] = i;
				}
				break;
			}
		}
		return result;
	}
};

int main() {
	//				0   1  2  3  4  5  6  7  8  9
	//int array[10] = {1, 2, 3, 5, 7, 7, 7, 8, 9, 10};
	int array[10] = {1, 1, 2, 5, 7, 7, 7, 8, 9, 10};
	vector<int> source;
	for (int i = 0; i < 3; i++) {
		source.push_back(array[i]);
		printf("%d ", array[i]);
	}
	printf("\n");
	
	Solution s;
	vector<int> result = s.searchRange(source, 2);

	for (size_t i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
