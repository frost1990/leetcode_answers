/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

#include <stdio.h>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		vector<int> store;
		uint32_t result = 0;
		int count = 1;
		while (count <= 32) {
			if (n & 1) {
				store.push_back(1);
			} else {
				store.push_back(0);
			}
			n = n >> 1;
			count++;
		}

		for (size_t i = 0; i < store.size(); i++) {
			result += (store[i] << (store.size() - i - 1));
		}
		return result;
	}
};

int main() {
	Solution s;
	uint32_t source = 43261596;

	printf("Source = %u, return value = %u\n", source, s.reverseBits(source));
	return 0;
}
