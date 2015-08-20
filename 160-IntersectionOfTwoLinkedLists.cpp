/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
                   ????                     c1 ¡ú c2 ¡ú c3
                   ????           
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
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

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) {
			return NULL;
		}

		int lena = getlength(headA);
		int lenb = getlength(headB);
		int max = (lena > lenb) ? lena : lenb;
		int gap = (lena < lenb) ? (lenb - lena) : (lena - lenb);

		ListNode *p = headA; 
		ListNode *q = headB;
		// 0->0
		//
		for (int count = 1;  count <= max; count++) {
			if (p == NULL || q == NULL) {
				return NULL;
			}
			if (p == q) {
				return p;
			}
			if (p->next == q) {
				return q;
			} else if (q->next == p) {
				return p;

			}
			if (count <= gap) {
				if (lena < lenb) {
					q = q->next;	
				} else {
					p = p->next;	
				}
				continue;
			}
			p = p->next;	
			q = q->next;	
		}

		return NULL;
	}
};

int main() {
	// 2 1 3
	ListNode l1(2), l2(1), l3(3);
	ListNode l4(4), l5(2), l6(1), l7(6), l8(6), l9(9), l10(10), l11(11), l12(12), l13(6);
	ListNode n1(0), n2(0), n3(0), n4(1);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l6;

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

	print_list(&n1);
	print_list(&n2);
	Solution s;
	ListNode *result = s.getIntersectionNode(&n1, &n2);
	print_list(result);
	return 0;
}
