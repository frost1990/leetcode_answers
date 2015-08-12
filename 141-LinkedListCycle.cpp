/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return false;
		}
	
		ListNode *p = head;
		ListNode *q = head;
		
		for ( ;  p != NULL && q->next != NULL; ) {
			p = p->next;
			q = q->next->next;

			if (p == q) {
				return true;
			}

			if (q == NULL) {
				return false;
			}
		}

       	return false; 
    }
};

int main() {
	ListNode l1(1), l2(2), l3(3);
	ListNode l4(4), l5(5), l6(6), l7(6), l8(6), l9(9), l10(10), l11(11), l12(12), l13(6);
	ListNode n1(0), n2(0), n3(0), n4(1);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l1;

	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	l9.next = &l4;
//	l10.next = &l11;
//	l11.next = &l12;
//	l12.next = &l13;

	Solution s;
	bool ret = s.hasCycle(&l1);

	printf("Return value is %s\n", ret ? "true":"false");
	return 0;
}
