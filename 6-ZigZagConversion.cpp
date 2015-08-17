/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string result;
		if (s.length() <= numRows) {
			return s;
		}
 		if (numRows <= 1) {
			return s;
		}

		vector<string> store;
		vector<vector<int> > step;
		for (size_t i = 0; i < numRows; i++) {
			store.push_back("");			
			vector<int> unit;
			if (i % (numRows - 1)) {
				unit.push_back( 2 * (numRows - 1 - i % (numRows - 1)));
				unit.push_back( 2 * ( i % (numRows - 1)));
				step.push_back(unit);
			} else {
				unit.push_back( 2 * (numRows - 1));
				unit.push_back( 2 * (numRows - 1));
				step.push_back(unit);
			}
		}

		for (size_t i = 0; i < numRows; i++) {
			printf("Row %lu\n", i);
			for (size_t j = i, k = 0; j < s.length(); j = j + step[i][k++ % 2]) {
				store[i].append(1, s[j]);
				printf("j = %lu, next step %d\n", j, step[i][k % 2]);
			}
			printf("Row %lu,  %s\n", i, store[i].c_str());
		}

		for (size_t i = 0; i < numRows; i++) {
			for (size_t j = 0; j < store[i].size(); j++) {
				result.append(1, store[i][j]);	
			}
		}

		return result;	
	}
};

int main() {
	string source = "ABCDE";
	Solution s;
	string result = s.convert(source, 4);

	printf("Source string:%s, result string %s\n", source.c_str(), result.c_str());
	printf("Should return PAHNAPLSIIGYIR.\n");
	return 0;
}
