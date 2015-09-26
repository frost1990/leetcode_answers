/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool is_blank(char c) {
   		if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == 0) {
        	return true;
    	}
    	return false;
	}

	void reverseWords(string &s) {
		if (s.empty()) {
			return;
		}

		stack <string> store;
		size_t start, end;
		start = end = 0;
		for (size_t i = 0; i < s.length(); ) {
			if (is_blank(s[i]) && i != 0) {
				end = i - 1;
				store.push(s.substr(start, end - start + 1));
				printf("push %s\n", s.substr(start, end - start + 1).c_str());
				size_t j = i;
				while (is_blank(s[j]) && j < s.length()) {
					j++;
				}
				start = i = j;
			}

			if (is_blank(s[i]) && i == 0) {
				size_t j = i;
				while (is_blank(s[j]) && j < s.length()) {
					j++;
				}
				end = start = i = j;
			}

			if (i == s.length() - 1) {
				store.push(s.substr(start, s.length() - start));
			}
			i++;
		}
		
		s.clear();
		while (!store.empty()) {
			string segment = store.top();
			s.append(segment);
			store.pop();
			if (!store.empty()) {
				s.append(" ");
			}
		}
	}
};

int main() {
	//string source = " the sky is   blue";
	string source = "    ";
	printf("Before reverse: %s|\n", source.c_str());
	Solution s;
	s.reverseWords(source);
	printf("After reverse: %s|\n", source.c_str());

	return 0;
}
