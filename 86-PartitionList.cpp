/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
	
		ListNode *key = new ListNode(x);
		key->next = head;	

		ListNode *last = NULL;
		ListNode *right = NULL;
		ListNode *newhead = NULL;
		ListNode *append = NULL;

		for (ListNode *p = head; p != NULL; ) {
			ListNode* store = p->next;
			if (p->val < x) {
				if (newhead == NULL) {
					newhead = p;
				}

				ListNode *tmp = p->next;
				p->next = key;
				if (right == NULL) {
					key->next = tmp;
				} 
				if (last != NULL) {
					last->next = p;
				}
				last = p;
			} else {
				if (right == NULL) {
					right = p;
				}
				key->next = right;
				if (append == NULL) {
					append = right;
					right->next = NULL;
				} else {
					append->next = p;
					append = p;
					append->next = NULL;
				}
			}	
			p = store;
		}
		if (last != NULL)	{	
			last->next = right;
		}
		delete key;
		if (newhead == NULL) {
			newhead = head;
		}
		return newhead;
	}
};

int main() {
	// 2 1 3
	ListNode l1(2), l2(1), l3(3);
	ListNode l4(4), l5(2), l6(1), l7(6), l8(6), l9(9), l10(10), l11(11), l12(12), l13(6);
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
	ListNode *result = s.partition(&l1, 5);
	print_list(result);

	return 0;
}
