/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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

	// 1->2->3->4->5->6->7->NULL k = 5
	// 3->4->5->6->7->1->2->NULL
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) {
			return NULL;
		}

		ListNode *result = head;
		int len = getlength(head);
		int step = k % len;

		ListNode *p = head;
		for (int count = 1; count <= len; count++) {
			if (count == (len - step)) {
				if (p->next != NULL) {
					result = p->next;	
				}
				break;
			}
			p = p->next;
		}
		if (p->next == NULL) {
			return result;
		}

		ListNode *q = p->next;
		p->next = NULL;
		while (q->next != NULL) {
			q = q->next;
		}

		q->next = head;
		return result;
	}
};

int main() {
	ListNode l1(2), l2(1), l3(3);
	ListNode l4(4), l5(2), l6(1), l7(6), l8(5), l9(9), l10(10), l11(11), l12(12), l13(6);
	ListNode n1(0), n2(0), n3(0), n4(1);
	l1.next = &l2;
	l2.next = &l3;

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
	ListNode *result = s.rotateRight(&l1, 0);
	print_list(result);
	return 0;
}
