/* 
 Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
*/

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i, sum;  
        vector<int> results;  
        map<int, int> store;  
        for (i = 0; i < numbers.size(); i++){  
            if(!store.count(numbers[i])){  
                store.insert(pair<int, int>(numbers[i], i));  
            }  
            if (store.count(target - numbers[i])){  
                int n = store[target - numbers[i]];  
                if (n < i){  
                    results.push_back(n + 1);  
                    results.push_back(i + 1);  
                    return results;  
                }  
            }  
        }  
        return results;  
    }  
};

int main() {
	int array[5] = {2, 3, 4, 5, 6};
	vector<int> source;
	for (int i = 1; i <= 5; i++) {
		source.push_back(array[i]);
	}

	Solution s;

	vector<int> result = s.twoSum(source, 8);
	for (size_t i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
