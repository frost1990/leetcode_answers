/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		size_t size = nums.size();
		if (size == 0) {
			return;	
		}
		if (k == 0) {
			return;
		}
		
		size_t shift = (size >= k) ? (size - k) : (k - size);
		shift = size - k % size;
		vector<int> store = nums;
		//												 0 1 2 3 4 5 6
		// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] 
		//								  is rotated to [5,6,7,1,2,3,4].
		size_t idx = 0;
		for (size_t i = 0; i < size; i++) {
			if (i + shift <= size - 1) {
				nums[i] = store[i + shift];
			} else {
				nums[i] = store[idx];
				idx++;
			}
		}
    }
};

int main() {
	vector<int> array;
	int number = 3;
	for (int i = 1; i <= number; i++) {
		array.push_back(i);
		printf("%d ", i);
	}
	printf("\n");

	Solution s;

	s.rotate(array, 4);

	for (int i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
	return 0;
}
