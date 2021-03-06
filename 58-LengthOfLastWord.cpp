/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
	// "Hello World "
	int lengthOfLastWord(string s) {
		int count = 0;
		bool space = true;
		for (size_t i = 0; i < s.length(); i++) {
			if (s[s.length() - 1 - i] != ' ') {
				space = false;
				count++;	
			} else {
				if (space) {
					continue;
				} else {
					break;
				}
			}
		}
		return count;
	}
};

int main() {
	string source = "helloworld ";
	Solution s;

	int ret = s.lengthOfLastWord(source);

	printf("Return value is %d\n", ret);
	return 0;
}
