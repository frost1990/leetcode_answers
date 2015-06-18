/* 
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	int checksubstr(const string &s, size_t start) {
		if (start >= s.length() - 1) {
			return 1;
		}

		set <char> check_set;
		for (size_t i = start; i < s.length() - 1; i++) {
			check_set.insert(s[i]);
			if (check_set.size() < i - start) {
				return i - start;
			}
		}		

		return s.length() - start;
	}

    int lengthOfLongestSubstring(string s) {
		printf("source %s\n", s.c_str());
		if (s.empty()) {
			return 0;
		}

		if (s.length() == 1) {
			return 1;
		}

		vector <int> store;
		for	(size_t i = 0 ; i < s.length(); i++) {
			store.push_back(checksubstr(s, i));
		}

		int max = 0;
		for	(size_t i = 0 ; i < store.size(); i++) {
			if (store[i] >= max) {
				max = store[i];
			}

		}
		return max;
    }
};

int main() {
	string source = "helloworld, I want to make you happy abcdeffghijklmnopqrstuvwxyz";

	Solution s;
	int ret = s.lengthOfLongestSubstring(source);
	printf("Max Substr Length %d\n", ret);

	return 0;
}
