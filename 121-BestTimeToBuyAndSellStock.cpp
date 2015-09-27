/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

#include <stdio.h>
#include <vector>

using namespace std;

void print_vector(vector<int> source) {
	for (size_t i = 0; i < source.size(); i++) {
		printf("%d ", source[i]);
	}
	printf("\n");
}

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) {
			return 0;
		}

		int low1, low2, high;
		low1 = low2 = high = 0;

		for (size_t i = 0; i < prices.size(); i++) {
			if (prices[i] <= prices[low1]) {
				low1 = i;
			}		

			if (prices[i] - prices[low1] >= prices[high] - prices[low2]) {
				high = i;
				low2 = low1;
			}

		}
		return prices[high] - prices[low2];
	}
};

int main() {
	int array[9] = {3, 8, 9, 1, 7, 2, 1, 4, 8};
	vector <int> source;	
	for (int i = 0; i < 9; i++) {
		source.push_back(array[i]);
	}
	print_vector(source);

	Solution s;
	int ret = s.maxProfit(source);
	printf("Return value is %d.\n", ret);

	return 0;
}
