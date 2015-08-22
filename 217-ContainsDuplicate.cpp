/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.empty()) {
			return false;
		}
		map <int, int> store;
		for (size_t i = 0; i < nums.size(); i++) {
			if (store.find(nums[i]) == store.end()) {
				store.insert(make_pair(nums[i], i));
			} else {
				return true;
			}
		}
		return false;
	}
};

int main() {
	//				 0   1  2  3  4  5  6  7  8  9
	int array[10] = {3, 3, 3, 5, 7, 7, 7, 8, 9, 10};
	vector<int> source;
	for (int i = 0; i < 2; i++) {
		source.push_back(array[i]);
		printf("%d ", array[i]);
	}
	printf("\n");
	
	Solution s;
	bool ret = s.containsDuplicate(source);
	printf("Return value is %s\n", ret ? "true" : "false");
	return 0;
}
