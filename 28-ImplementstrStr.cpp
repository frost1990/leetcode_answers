/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		if (needle.empty()) {
			return 0;
		}

		if (haystack.length() < needle.length()) {
			return -1;
		}
		size_t sublen = needle.length();
		size_t totallen = haystack.length();
		size_t  k = 0;
		size_t  store = 0;
		for (size_t i = 0; i < totallen; ) {
			if (haystack[i] != needle[k]) {
				i = store + 1;
				store++;
				k = 0;
			} else {
				k++;
				i++;
				if (k == sublen) {
					return i - k;
				}
			}
		}
		return -1;
    }
};

int main() {
	string source = "abcde";
	printf("source :%s\n", source.c_str());
	string sub = "a";
	printf("sub :%s\n", sub.c_str());

	Solution s;
	int result = s.strStr(source, sub);

	printf("result = %d\n", result);
	return 0;
}
