/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
		if (a.empty() && b.empty()) {
			return "0";
		} else if (a.empty()  && !b.empty()) {
			return b;
		} else if (!a.empty() && b.empty()) {
			return a;
		}

		size_t len1 = a.length();
		size_t len2 = b.length();
		size_t max = (len1 > len2) ? len1 : len2;
		size_t min = (len1 <= len2) ? len1 : len2;
		size_t gap = max - min;

		string result;
		int overflow = 0;
		for (size_t i = 0; i < max; i++) {
			int digit = 0;
			if (i > min - 1) {
				if (len1 > len2) {
					digit = a[max - 1 - i] - '0' + overflow;
				} else {
					digit = b[max - 1 - i] - '0' + overflow;
				}
			} else {
				if (len1 > len2) {
					digit = a[max - 1 - i] - '0' + b[max - 1 - gap - i]  - '0' + overflow;
				} else {
					digit = a[max - 1 - gap - i] - '0' + b[max - 1 - i]  - '0' + overflow;
				}	
			}
			if (digit > 1) {
				overflow = 1;
			} else {
				overflow = 0;
			}
			if (digit % 2) {
				result = '1' + result;
			} else {
				result = '0' + result;
			}
		}

		if (overflow) {
			result = '1' + result;
		}
		return result;
    }
};


int main () {
	string a = "1";
	string b = "111";

	Solution s;
	string result = s.addBinary(a, b);
	printf("a = %s, b = %s,  add result = %s\n", a.c_str(), b.c_str(), result.c_str());

	return 0;
}
