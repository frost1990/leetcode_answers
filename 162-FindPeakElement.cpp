/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -¡Þ.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Note:
Your solution should be in logarithmic complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int result = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (i == 0) {
				if (nums[i] <= nums[i + 1])
				continue;
			}
			if (i == nums.size() - 1) {
				if (nums[i] <= nums[i - 1]) {
					continue;
				} else {
					result = i;
					return result;
				}
			}

			if (nums[i] <= nums[i + 1])
				continue;
			if (nums[i] <= nums[i - 1])
				continue;

			result = i;
			return result;
		}
	
       	return result; 
    }
};

int main() {
	int array[10] = {0, 1, 2, 5, 4, 3, 7, 6, 8, 2};
	vector <int> source;	
	for (int i = 0; i < 10; i++) {
		source.push_back(array[i]);
	}

	Solution s;
	int ret = s.findPeakElement(source);
	
	printf("Return value is %d\n", ret);

	return 0;
}
