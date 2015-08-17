/*Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <stdio.h>

class Solution {
public:
	int addDigits(int num) {
		return (num - 9 *((num - 1)/9));
	}
};


int main() {
	Solution s;

	int ret = s.addDigits(12345);
	printf("Return value is %d\n", ret);

	return 0;
}
