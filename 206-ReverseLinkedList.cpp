/*
	Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}

		// head->1->2->3->4->5->NULL
		ListNode *p, *q, *result;
		result = NULL;
		p = head->next;
		if (p == NULL) {
			return head;
		}
		// Note that P will never move
		while (p->next != NULL) {
			// q = 2
			q = p->next;
			// head->1->3->4->5->NULL
			//		 2->3
			p->next = q->next;
			// head->1->3->4->5->NULL
			//		 2->1
			q->next = head->next;
			// head->2->1->3->4->5->NULL
			head->next = q;
			// next round: head->3->2->1->4->5->NULL
		} // head->5->4->3->2->1->NULL

		// head->5->4->3->2->1->head
		result = head->next;
		p->next = head;
		// head->5->4->3->2->1->head->NULL
		p->next->next = NULL;
		// 5->4->3->2->1->head->NULL
		return result;
    }
};

int main() {
	ListNode l4(1), l5(2), l6(3), l7(4), l8(5), l9(6), l10(7), l11(8), l12(9), l13(10);

	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	l9.next = &l10;
	l10.next = &l11;
	l11.next = &l12;
	l12.next = &l13;

	print_list(&l4);

	Solution s;

	print_list(s.reverseList(&l4));
	return 0;
}
