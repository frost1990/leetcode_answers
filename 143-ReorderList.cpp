/*
Reorder List Total Accepted: 42047 Total Submissions: 200515 My Submissions Question Solution 
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
#include <vector>
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

void print_node(ListNode *list) {
	if (list != NULL) {
		printf("%d\n", list->val);
	} else {
		printf("NULL\n");
	}
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
	
    void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return;
		}
		ListNode *p, *q;
		int length = getlength(head);
		ListNode *idx, *store;
		vector <ListNode *> mark;
		for (p = head; p != NULL; p = p->next) {	
			mark.push_back(p);
		}

		// 1->2->3->4->5->NULL
		int step = 0;
		for (q = head; q->next != NULL; step++ ) {
			p = mark[length - step - 1];
			// 1->5->2->3->4->5 NULL
			if (q->next == p) {
				break;
			}
			
			p->next = q->next;	
			q->next = p;	

			q = mark[length - step - 2];
			// 1->5->2->3->4->NULL
			q->next = NULL;
			q = p->next;
			// 1->5->2->4->3->NULL
			//    p  q
    	}
	}
};

int main() {
	ListNode l4(1), l5(2), l6(3), l7(4), l8(5), l9(6), l10(7), l11(8), l12(9), l13(10);
	ListNode *l = NULL;

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
	s.reorderList(&l4);

	print_list(&l4);
	return 0;
}
