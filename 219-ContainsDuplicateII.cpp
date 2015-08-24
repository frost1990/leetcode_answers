/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.empty()) {
			return false;
		}

		//  value key
		map <int, vector<size_t> > store;
		map <int, vector<size_t> >::iterator it;
		for (size_t i = 0; i < nums.size(); i++) {
			if ((it = store.find(nums[i])) == store.end()) {
				vector<size_t> tmp;
				tmp.push_back(i);
				store.insert(make_pair(nums[i], tmp));
			} else {
				vector<size_t> record = it->second;
				if ((i - record[record.size() - 1]) <= k) {
					return true;
				}
				(it->second).push_back(i);
			}
		}

		return false;
	}
};

int main() {
	//				 0   1  2  3  4  5  6  7  8  9
	int array[10] = {3, 4, 3, 5, 7, 17, 7, 8, 9, 10};

	vector<int> source;
	for (int i = 0; i < 10; i++) {
		source.push_back(array[i]);
		printf("%d ", array[i]);
	}
	printf("\n");
	
	Solution s;
	bool ret = s.containsNearbyDuplicate(source, 1);
	printf("Return value is %s\n", ret ? "true" : "false");

	return 0;
}
