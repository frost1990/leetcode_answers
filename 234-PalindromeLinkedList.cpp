/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
	// 1->3->2->4->5->4->2->3->1->NULL
	// 1->2->3->4->4->3->2->1->NULL
	bool isPalindrome(ListNode* head) {
		if (head == NULL) {
			return true;
		}
		int len = getlength(head);
		ListNode *p = head;
		ListNode *middle = head;
		int count = 1;
		while (count < (len / 2) + 1) {
			middle = middle->next;
			count++;
		}
		
		printf("Middle = %d\n", middle->val);
		ListNode *s = NULL;
		ListNode *reverse = middle;
		// Reverse middle
		while (middle->next != NULL) {
			s = middle->next;
			ListNode *store = s->next;
			s->next = reverse;
			reverse = s;
			middle->next = store;
		}

		print_list(reverse);
		ListNode *q = reverse;
		for (count = 1; count <= len / 2;  p = p->next, q = q->next, count++) {
			if (p->val != q->val) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	ListNode l1(1), l2(1), l3(1);
	ListNode l4(4), l5(5), l6(6), l7(6), l8(6), l9(9), l10(10), l11(11), l12(12), l13(6);
	ListNode n1(0), n2(0), n3(0), n4(1);
//	l1.next = &l2;
//	l2.next = &l3;

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
	bool ret = s.isPalindrome(&l1);
	printf("Return value is %s\n", ret? "true" : "false");
	return 0;
}
