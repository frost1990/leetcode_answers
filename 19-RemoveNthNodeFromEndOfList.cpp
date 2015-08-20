/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
#include <unistd.h>

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
	int getlength(ListNode *list) {
		if (list == NULL) {
			return 0;
		}
		int count = 0;
		for ( ; list != NULL; list = list->next) {
			count++;
		}
		return count;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) {
			return head;
		}

		int len = getlength(head);
		if (len == n ) {
			return head->next;
		}
		int step = len - n - 1;
		ListNode *p = head; 
		for (int count = 0; p != NULL; p = p->next)	 {
			if (count != step) {
				count++;
			} else {
				break;
			}
		}	

		p->next = p->next->next;
		return head;
	}
};

int main() {
	// 2 1 3
	ListNode l1(2), l2(1), l3(3);
	ListNode l4(4), l5(2), l6(1), l7(6), l8(6), l9(9), l10(10), l11(11), l12(12), l13(6);
	ListNode n1(0), n2(0), n3(0), n4(1);
	l1.next = &l2;
	//l2.next = &l3;

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
	Solution s;
	ListNode *result = s.removeNthFromEnd(&l1, 2);
	print_list(result);
	return 0;
}
