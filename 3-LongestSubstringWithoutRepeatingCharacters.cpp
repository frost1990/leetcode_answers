/* 
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.empty()) {
			return 0;
		}

		int record[512];
		memset(record, -1, 512);
		int max = 0;
		for	(size_t i = 0 ; i < s.length(); i++) {
			int count = 0;
			for (size_t j = i; j < s.length(); j++) {
				char c = s[j];
				if (record[c] == -1) {
					record[c] = j;
					count++;
					if (count >= max) {
						max = count;
						printf("max=%d, i=%u, j=%u\n", max, i, j);
					}
				} else {
					break;
				}
			}
			memset(record, -1, 512);
		}

		return max;
    }
};

int main() {
	string source = "helloworld, I want to make you happy abcdefgg,hijklmn";
	source = "dv";

	printf("source: %s\n", source.c_str());
	Solution s;
	int ret = s.lengthOfLongestSubstring(source);
	printf("Max Substr Length %d\n", ret);

	return 0;
}
