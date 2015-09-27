/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

void print_vector(vector<int> source) {
	for (size_t i = 0; i < source.size(); i++) {
		printf("%d ", source[i]);
	}
	printf("\n");
}

class Solution {
public:
	// 1 1 2 2 5 5 5 5 6 8 8 8 9 10 10
	// 1 1 2 2 5 5 6 5 6 8 8 8 9 10 10
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		map <int, int> store;
		int newlen = nums.size();

		for (size_t i = 0; i < nums.size(); i++) {
			if (store.count(nums[i]) > 0) {
				int appeared_times = store[nums[i]];
				store[nums[i]] = ++appeared_times;
			} else {
				store.insert(make_pair(nums[i], 1));
			}
		}

		for (size_t i = 0, count = 0; i < nums.size(); ) {
			int appeared_times = store[nums[i]];
			if (appeared_times <= 2) {
				nums[count] = nums[i];
				i++;
				count++;
			} else {
				newlen -= (appeared_times - 2);
				nums[count] = nums[count + 1] = nums[i];
				count += 2;
				i += appeared_times;
			}
		}
		return newlen;
	}
};

int main() {
	int array[15] = {1, 1, 2, 2, 5, 5, 5, 5, 6, 8, 8, 8, 9, 10, 10};
	vector <int> source;	
	for (int i = 0; i < 15; i++) {
		source.push_back(array[i]);
	}
	print_vector(source);

	Solution s;
	int ret = s.removeDuplicates(source);
	printf("Return value is %d.\n", ret);
	print_vector(source);

	return 0;
}
