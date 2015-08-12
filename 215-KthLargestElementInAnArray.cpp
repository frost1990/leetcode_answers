/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	void quicksort(vector<int> &array, int left, int right) {
		if (left < right) {
			int key = array[left];
			// Partition
			size_t low = left;
			size_t high = right;
			while (low < high) {
				// Low remain stable
				while (low < high && array[high] >= key){
					high--;
				}
				if (high > low) {
					array[low] = array[high];
				}
				// High remain stable
				while (low < high && array[low] <= key){
					low++;
				}
				if (low < high) {
					array[high] = array[low];
				}
			}
			array[low] = key;
			// Recursively invoke
			quicksort(array, left, low - 1);
			quicksort(array, low + 1, right);
		} else {
			return;
		}
	}
	
    int findKthLargest(vector<int>& nums, int k) {
		if (nums.size() == 1) {
			return nums[0];
		}
		
		quicksort(nums, 0, nums.size() - 1);
		for (size_t i = 0; i < nums.size(); i++) {
			printf("%d ", nums[i]);
		}
		return nums[nums.size() - k];
	}
};

int main() {
	vector<int> source;
	int array[11] = {5, 2, 9, 6, 10, 11, 1, 4, 7, 8, 3};
	for (int i = 0; i < 11; i++) {
		source.push_back(array[i]);
	}

	for (int i = 0; i < 11; i++) {
		printf("%d ", source[i]);
	}
	printf("\n");


	Solution s;
	int ret = s.findKthLargest(source, 8);
	printf("Return value %d\n", ret);

	return 0;
}

