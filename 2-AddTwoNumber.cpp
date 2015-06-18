/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stdint.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

void print_list(ListNode *list) {
	for ( ; list != NULL; list = list->next) {
		printf("%d", list->val);
	}
	printf("\n");
}


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = new ListNode(0);
		ListNode *start = p; 
		ListNode *result = NULL;
	
		ListNode *p1 = l1; 
		ListNode *p2 = l2; 
		int next = 0;
		while (p1 != NULL && p2 != NULL) {
			int val1 = p1->val;
			int val2 = p2->val;
			int val = val1 + val2 + next;
			
			if (val >= 10) {
				val = val % 10;
				next = 1;
			} else  {
				next = 0;
			}

			p->next = new ListNode(val);
			p = p->next;
			p->next = NULL;
		
			p1 = p1->next;
			p2 = p2->next;
		}
		
		ListNode* p3 = (p1 == NULL) ? p2 : p1;
		while (p3 != NULL) {
			int val = p3->val + next;
			if (val >= 10) {
					val = val % 10;
					next = 1;
			} else  {
				next = 0;
			}
			p->next = new ListNode(val);
			p = p->next;
			p->next = NULL;
			p3 = p3->next;
		}

		if (next == 1) {
			p->next = new ListNode(1);
			p = p->next;
			p->next = NULL;
		}
		
		result = start->next;
		delete(start);
		print_list(result);
		return result;
    }
};

int main() {
	// 9 + 1999999999
	ListNode l1(9), l2(4), l3(5);
	ListNode l4(1), l5(9), l6(9), l7(9), l8(9), l9(9), l10(9), l11(9), l12(9), l13(9);
	l1.next = NULL;

	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	l9.next = &l10;
	l10.next = &l11;
	l11.next = &l12;
	l12.next = &l13;

	print_list(&l1);
	print_list(&l4);

	Solution s;
	s.addTwoNumbers(&l1, &l4);

	return 0;
}
