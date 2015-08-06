/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;
// Spilt String By A Delimter
vector<string> split(const string &str, char pattern) {  
    string::size_type i = 0;  
    string::size_type j = str.find(pattern);  
    vector<string> result;
	if (j == string::npos)
    {
        result.push_back(str);
        return result;
    }

	while (j != string::npos) {
		result.push_back(str.substr(i, j - i));
		i = ++j;
		j = str.find(pattern, i);
	
		if (j == string::npos) {
			result.push_back(str.substr(i));
		}
	}
	
    return result;  
}

class Solution {
	public:
		int compareVersion(string version1, string version2) {
			vector<string> store1, store2;
			store1 = split(version1, '.');		
			store2 = split(version2, '.');		
			size_t size1 = store1.size();
			size_t size2 = store2.size();
			size_t min = (size1 <= size2)  ? size1 : size2; 
			size_t max = (size1 >= size2)  ? size1 : size2; 
		
			for (size_t i = 0; i < min; i++) {
				int digit1 = atoi(store1[i].c_str());
				int digit2 = atoi(store2[i].c_str());
				if (digit1 > digit2) {
					return 1;
				} else if (digit1 < digit2) {
					return -1;
				}
			}
			
			if (size1 == size2) {
				return 0;
			} else if (size1 > size2) {
				for (size_t i = min; i < max; i++) {
					if (atoi(store1[i].c_str()) != 0) {
						return 1;
					}
				}
				return 0;
			} else {
				for (size_t i = min; i < max; i++) {
					if (atoi(store2[i].c_str()) != 0) {
						return -1;
					}
				}
				return 0;
			}

		}
};

int main() {
	Solution s;

	int ret = s.compareVersion("124.0.0", "124");
	printf("Return value = %d\n", ret);

	return 0;
}
