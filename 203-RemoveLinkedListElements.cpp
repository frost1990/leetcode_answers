/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
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
	// 1->2->3->4->5->NULL
	// 1->2->4->5->NULL
    ListNode* removeElements(ListNode* head, int val) {
		ListNode* p = head;
		ListNode* q = head;
		ListNode* s = head;
		ListNode* result = NULL;
		if (head == NULL) {
			return result;
		}
		if (head->next == NULL && head->val == val) {
			return result;
		}

		result = head;
		for ( ; p != NULL; ) {
			if (p->val != val ) {
				break;
			}
			result = p->next;
			p = p->next;
		}

		if (result == NULL) {
			return result;
		}
	
		p = head;
		for ( ; p->next != NULL; ) {
			q = p;
			p = p->next;

			if (p->val == val) {
				q->next = p->next;
				p = q;
			}
		}

		if (p->val == val) {
			q->next = NULL;
		}
			
		if (head->val == val) {
			result = head->next;
		}

		return result;
    }
};

int main() {
	ListNode l1(1), l2(2), l3(3);
	ListNode l4(4), l5(5), l6(6), l7(6), l8(6), l9(9), l10(10), l11(11), l12(12), l13(6);
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

//	n1.next = &n2;
//	n2.next = &n3;
	//n3.next = &n4;

	print_list(&l4);
	Solution s;
	print_list(s.removeElements(&l4, 6));
	return 0;
}
