/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
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
	ListNode* detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
	
		ListNode *p = head;
		set <ListNode *> store;
		
		for ( ; p != NULL ; p = p->next ) {
			if (store.find(p) == store.end()) {
				store.insert(p);
			} else {
				return p;
			}
		}

       	return NULL; 
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
	l13.next = &l12;

	Solution s;
	ListNode* ret = s.detectCycle(&l4);

	if (ret == NULL) {
		printf("Return value is NULL\n");
	} else {
		printf("Return value is %d\n", ret->val);
	}
	return 0;
}
