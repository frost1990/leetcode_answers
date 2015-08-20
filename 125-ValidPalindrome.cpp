/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
	bool caselesscmp(char a, char b) {
		if ((a == b) || (a == tolower(b)) || (a == toupper(b))) {
			return true;
		}
		return false;
	}

	bool isAlphanum(char c) {
   		if ('0' <= c && c <= '9') {
        	return true;
    	} else if ('a' <= c && c <= 'z') {
			return true;
		} else if ('A' <= c && c <= 'Z') {
			return true;
		} else {
			return false;
		}
	}

	bool isPalindrome(string s) {
		if (s.empty() || s.length() == 1) {
			return true;
		}

		string t;
		for (size_t i = 0;  i < s.length(); i++) {
			if (isAlphanum(s[i])) {
				t.append(1, s[i]);
			}
		}
		
		size_t length = t.length();
		printf("Alphabet and numeric string %s\n", t.c_str());

		for (size_t i = 0;  i < length / 2; i++) {
			if (!caselesscmp(t[i], t[length - i - 1])) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	string source = "ababa";
	Solution s;
	bool ret = s.isPalindrome(source);

	printf("Return value is %s\n", ret ? "true":"false");
	return 0;
}
