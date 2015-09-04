/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <stdio.h>
#include <vector>

using namespace std;

void print_vector(vector<int> source) {
	for (size_t i = 0; i < source.size(); i++) {
		printf("%d ", source[i]);
	}
	printf("\n");
}

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> result;
		if (digits.empty()) {
			result.push_back(1);
			return result;	
		}

		result = digits;
		int last = digits[digits.size() - 1];
		last += 1;
		size_t count = 1;
		result[result.size() - count] = last;
		if (0 < last && last < 10) {
			result[result.size() - count] = last;
		} else if (last >= 10) {
			while ((result[result.size() - count] >= 10)) {
				result[result.size() - count] -= 10;	
				count++;
				if (count > result.size()) {
					break;
				}
				result[result.size() - count]++;	
			}
		}

		if (count == digits.size() + 1) {
			vector<int> ret;
			ret.push_back(1);
			for (size_t i = 0; i < result.size(); i++) {
				ret.push_back(result[i]);
			}
			return ret;	
		}

		return result;
	}
};

int main() {
	int array[8] = {9, 9, 9, 9, 9, 9, 9, 9};
	vector<int> source;
	for (int i = 0; i < 1; i++) {
		source.push_back(array[i]);	
	}
	print_vector(source);

	Solution s;
	vector<int> result = s.plusOne(source);

	print_vector(result);
	return 0;
}
