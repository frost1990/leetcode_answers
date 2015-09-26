/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
	bool is_blank(char c) {
   		if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == 0) {
        	return true;
    	}
    	return false;
	}

	bool is_numeric(char c) {
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

	bool isNumber(string s) {
		bool dot_appeared = false;
		bool power_appeared = false;
		bool end_space_appeared = false;
		bool effective_number_started = false;
		
		for (size_t i = 0; i < s.length(); i++) {
			if (!is_blank(s[i])) {
				s = s.substr(i, string::npos);
				break;
			}
		}
		for (int j = s.length() - 1; j >= 0; j--) {
			if (!is_blank(s[j])) {
				s = s.substr(0, j + 1);
				break;
			}
		}
		printf("Real string is :%s.\n", s.c_str());
		
		for (size_t i = 0; i < s.length(); i++) {
			if (is_numeric(s[i])) {
				if (!effective_number_started) {
					effective_number_started = true;
				}
				continue;
			} else {
				if (i == (s.length() - 1) && !effective_number_started) {
					return false;
				}
			}

			if (is_blank(s[i])) {
				return	false;	
			}

			if (is_pos_neg(s[i])) {
				if (i == s.length() - 1) {
					return false;
				}

				if (i == 0 || s[i - 1] == 'e') {
					continue;
				} else {
					return false;
				}
			}

			if (s[i] == '.') {
				if (!dot_appeared) {
					if (power_appeared) {
						return false;
					}
					dot_appeared = true;
					continue;
				} else {
					return false;
				}
			}

			if (s[i] == 'e') {
				if (i == s.length() - 1) {
					return false;
				}

				if (effective_number_started) {
					if (power_appeared) {
						return false;
					} else {
						power_appeared = true;
						continue;
					}
				} else {
					return false;
				}
			}
			return false;
		}
		return true;
	}
};

int main() {
	string source = "  1   ";
	printf("Source:%s.\n", source.c_str());
	Solution s;

	bool ret = s.isNumber(source);
	printf("Return value is %s\n", ret ? "true" : "false");

	return 0;
}
