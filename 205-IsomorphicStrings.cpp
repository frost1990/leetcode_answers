/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		map<char, vector<int> > store1;
		map<char, vector<int> > store2;

		for (int i = 0; i < s.length(); i++) {
			if (store1.find(s[i]) != store1.end()) {
				vector<int> tmp;
				tmp.push_back(i);
				store1.insert(make_pair(s[i], tmp));
			} else {
				store1[s[i]].push_back(i);
			}

			if (store2.find(t[i]) != store2.end()) {
				vector<int> tmp;
				tmp.push_back(i);
				store2.insert(make_pair(t[i], tmp));
			} else {
				store2[t[i]].push_back(i);
			}
			
			if (store1[s[i]].size() != store2[t[i]].size()) {
				return false;
			}

			for (size_t j = 0; j < store1[s[i]].size(); j++) {
				if (store1[s[i]][j] != store2[t[i]][j]) {
					return false;
				}
			}
		} 
        
		return true;
    }
};

int main() {
	Solution s;
	bool ret = s.isIsomorphic("banana", "nmamam");

	printf("Return value is %s\n", ret ? "true":"false");
	return 0;
}
