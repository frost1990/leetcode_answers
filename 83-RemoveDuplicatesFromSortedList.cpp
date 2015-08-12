/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
#include <set>
using namespace std;

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}
		ListNode *p = head;
		ListNode *q = head;

		set <int> store;
		for ( ; p != NULL; p = p->next) {
			// 1->2->3->3->4->5->6
			// 1->2->3->4->5->6
			if (store.find(p->val) == store.end()) {
				store.insert(p->val);
				q = p;
			} else {
				q->next = p->next;	
			}
		}

   		return head;     
	}
};

int main() {
	ListNode l1(1), l2(2), l3(2);
	ListNode l4(1), l5(3), l6(3), l7(3), l8(5), l9(6), l10(7), l11(7), l12(9), l13(10);

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

	print_list(s.deleteDuplicates(&l1));
	return 0;
}
