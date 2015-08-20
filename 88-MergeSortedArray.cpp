/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m == 0 || nums1.empty()) {
			nums1 = nums2;
			return;
		} 
		if (n == 0 || nums2.empty()) {
			return;
		}

		size_t size1 = nums1.size() - m;
		for (size_t i = 1; i <= size1; i++) {
			nums1.pop_back();
		}
	
		for (size_t i = 1; i <= nums2.size() - n; i++) {
			nums1.pop_back();
		}

		for (size_t i = 0; i < nums2.size(); i++) {
			int key = nums2[i];
			if (key < nums1[0]) {
				nums1.push_back(key);
				for (size_t j = nums1.size() - 1; j > 0; j--) {
					nums1[j] = nums1[j - 1];
				}
				nums1[0] = key;
				continue;
			}
			if (key > nums1[nums1.size() - 1]) {
				nums1.push_back(key);
				continue;
			}

			for (size_t j = 0; j < nums1.size() - 1; j++) {
				if ((nums1[j]  <= key) && (key <= nums1[j + 1])) {
					nums1.push_back(key);
					// Note that nums1.size() has increased by one
					for (size_t k = nums1.size() - 1; k > j; k--) {
						nums1[k] = nums1[k - 1];
					}
					nums1[j + 1] = key;
					break;
				}
			}
		}
	}
};

int main() {
	int array1[6] = {1, 2, 3, 0, 0, 0};
	vector <int> source1;	
	vector <int> source;	
	for (int i = 0; i < 6; i++) {
		printf("%d ", array1[i]);
		source1.push_back(array1[i]);
	}
	printf("\n");

	int array2[3] = {2, 5, 6};
	vector <int> source2;	
	for (int i = 0; i < 3; i++) {
		printf("%d ", array2[i]);
		source2.push_back(array2[i]);
	}
	printf("\n");

	Solution s;
	s.merge(source1, 3, source2, 3);

	for (size_t i = 0; i < source1.size(); i++) {
		printf("%d ",source1[i]);
	}
	printf("\n");
	return 0;
}
