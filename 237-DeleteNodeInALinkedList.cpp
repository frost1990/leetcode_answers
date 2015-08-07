/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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

// 1->2->3->4->5->NULL
// 1->2->4->5->5->NULL
//		3
class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* p = node;

		int step = 0;
		for (; p->next->next != NULL; p = p->next) {
			step++;
			p->val = p->next->val;	
		}
		if (step < 2) {
			p->val = p->next->val;	
			p->next = NULL;
			return;
		}

		p->val = p->next->val;	
		p->next = NULL;
	
		return;
    }
};

int main() {
	ListNode l1(1), l2(2), l3(3);
	ListNode l4(4), l5(5), l6(6), l7(7), l8(8), l9(9), l10(10), l11(11), l12(12), l13(13);
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

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	printf("Before deleteing:\n");
	print_list(&n1);

	Solution s;
	s.deleteNode(&n1);
	printf("After deleteing:\n");
	print_list(&n1);

	return 0;
}
