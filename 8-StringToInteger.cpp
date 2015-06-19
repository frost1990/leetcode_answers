/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

#include <stdio.h>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool is_blank(char c) {
   		if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == 0) {
        	return true;
    	}
    	return false;
	}

	bool is_number(char c) {
		if (c >= '0' && c <= '9') {
			return true;
		}
    	return false;
	}

	bool is_pos_neg(char c) {
		if (c == '+' || c == '-') {
			return true;
		}
		return false;
	}

	bool valid_start(char c) {
		return ((is_number(c)) || (is_pos_neg(c)));
	}

	int GetPower(unsigned x) {
		int result = 1;
		if (x == 0) {
			return 1;
		}
		
		for (unsigned i = 1; i <= x; i++) {
			if (!muti_ok(result, 10)) {
				printf("2ret 0\n");
				return 0;
			}
			result *= 10;
		}

		return result;
	}

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

    int myAtoi(string str) {
		if (str.empty()) {
			return 0;
		}
		int result = 0;
		int mark = 1;
		bool start = false;
		vector<int> store;
		size_t i = 0;
		size_t size = str.length();

		for (; i < str.length(); i++) {
			char c = str[i];
			if (!is_blank(c) && !valid_start(c)) {
				return 0;
			}

			if (valid_start(c)) {
				start = true;
				if (is_pos_neg(c)) {
					if (c == '-') {
						mark = -1;
					}
					i++;
				}
				break;
			}

			if ((i == size - 1) && (!start)) {
				return 0;
			}
		}

		size_t start_idx = i;
		for ( ; i < str.length(); i++) {
			char c = str[i];
			if (is_number(c)) {
				store.push_back(c - '0');
			}
			if (is_blank(c)) {
				break;
			}
			if (!is_number(c)) {
				break;	
			}
		}

		size_t store_size = store.size();
		if (store.empty()) {
			return 0;
		}

		for (size_t i = 0; i < store_size; i++) {
			int pre = result;
			if (GetPower(store_size - i - 1) == 0) {
				return (mark == 1) ? INT_MAX:INT_MIN;
			}
			int power = GetPower(store_size - i - 1);
			if (!muti_ok(power, store[i])) {
				return (mark == 1) ? INT_MAX:INT_MIN;
			}

			int step = store[i] * power;

			if (!add_ok(result, step)) {
				return (mark == 1) ? INT_MAX:INT_MIN;
			}
			result += step;	
		}
		result *= mark;
		return result;
    }
};

int main() {
	string source = "-2147483648";
	printf("source: %s\n", source.c_str());
	
	Solution s;
	int result = s.myAtoi(source);

	printf("result: %d\n", result);
	return 0;
}
