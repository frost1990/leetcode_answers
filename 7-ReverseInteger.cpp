/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

#include <stdio.h>
#include <vector>
	
using namespace std;

class Solution {
public:
	bool muti_ok(int x, int y) {
		long long pll = (long long) x * y;
		return pll == (int) pll;
	}

	bool add_ok(int x, int y) {
		int sum = x + y;
		int neg_over = x < 0 && y < 0 && sum >= 0;
		int pos_over = x >= 0 && y >= 0 && sum < 0;
		return !neg_over && !pos_over;	
	}

	int GetPower(unsigned x) {
		int result = 1;
		if (x == 0) {
			return 1;
		}
		
		for (unsigned i = 1; i <= x; i++) {
			if (!muti_ok(result, 10)) {
				return 0;
			}
			
			result *= 10;
		}

		return result;
	}
	
    int reverse(int x) {
		int result = 0;
		vector<int> store;
		while (x) {
			store.push_back(x % 10);
			x /= 10;
		}
		
		size_t size = store.size();
		for (size_t i = 0; i < store.size(); i++) {
			int pre = result;
			if (GetPower(size - i - 1) == 0) {
				return 0;
			}
			int power = GetPower(size - i - 1);
			if (!muti_ok(power, store[i])) {
				return 0;
			}

			int step = store[i] * power;

			if (!add_ok(result, step)) {
				return 0;
			}
			result += step;	
			// Check OverFlow
			
		}
			
		return result;
    }
};

int main() {
	int source = 10;
	printf("source: %d\n", source);
	
	Solution s;
	int result = s.reverse(source);

	printf("result: %d\n", result);

	return 0;
}
