/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

/*
 * Definition for singly-linked list.
 *  * struct ListNode {
 *   *     int val;
 *    *     ListNode *next;
 *     *     ListNode(int x) : val(x), next(NULL) {}
 *      * };
 *       */

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL) {
			return NULL;	
		} 

		ListNode  *r, *result;

		r = new ListNode(0);
		result = r;
		for ( ; ; ) {
			if (l1 == NULL && l2 != NULL) {
				r->val = l2->val;
				l2 = l2->next;
			} else if (l1 != NULL && l2 == NULL) {
				r->val = l1->val;
				l1 = l1->next;
			} else if (l1 != NULL && l2 != NULL) {
				int val1 = l1->val;	
				int val2 = l2->val;	
				if (val1 < val2) {
					r->val = val1;
					l1 = l1->next;
				} else {
					r->val = val2;
					l2 = l2->next;
				}
			}

			if (l1 == NULL && l2 == NULL) {
				break;	
			} else {
				r->next = new ListNode(0); 
				r = r->next;
			}
		}
		return result;
	}
};

int main() {
	ListNode l1(1), l2(4), l3(5);
	ListNode l4(1), l5(2), l6(3), l7(5), l8(9), l9(9), l10(9), l11(9), l12(9), l13(9);
	l1.next = &l2;
	l2.next = &l3;
	print_list(&l1);

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
	
	print_list(s.mergeTwoLists(&l1, &l4));
	return 0;
}
