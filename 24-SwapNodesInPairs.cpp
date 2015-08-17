/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *list) {
	for ( ; list != NULL; list = list->next) {
		printf("%d->", list->val);
	}
	printf("NULL\n");
}

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *p = head;
		ListNode *q = head;

		for (int count = 0; p != NULL; p = p->next, count++) {
			if (count % 2 == 1) {
				int tmp = p->val;
				p->val = q->val;
				q->val = tmp;
			}
			q = p;	
		}

		return head;
	}
};

int main() {
	ListNode l3(-1), l4(1), l5(2), l6(3), l7(4), l8(5), l9(6), l10(7), l11(8), l12(9), l13(10);

	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	l9.next = &l10;
	l10.next = &l11;
	l11.next = &l12;
	l12.next = &l13;

	print_list(&l3);

	Solution s;

	print_list(s.swapPairs(&l3));
	return 0;
}
