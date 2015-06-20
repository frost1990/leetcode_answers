/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
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

    ListNode* reverseList(ListNode* head, ListNode* end) {
		if (head == NULL) {
			return NULL;
		}

		// head->1->2->3->4->5->NULL
		ListNode *p, *q, *result, *tail;
		tail = end->next;
		result = NULL;
		p = head->next;
		if (p == NULL) {
			return head;
		}
		while (p->next != tail) {
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
		p->next->next = tail;
		// 5->4->3->2->1->head->NULL
		print_list(result);
		return result;
    }

	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		if (m == n) {
			return head;
		}

		int length = getlength(head);
		ListNode *p, *pm, *pn;
		vector <ListNode *> mark;
		for (p = head; p != NULL; p = p->next) {	
			mark.push_back(p);
		}

		pm = mark[m - 1];
		pn = mark[n - 1];

		int step = 0;
		ListNode* result  = reverseList(pm, pn);
		if (m >= 2) {
			mark[m - 2] ->next = result;
		} else {
			return result;	
		}
		return head;
	}
};

int main() {
	ListNode l4(1), l5(2), l6(3), l7(4), l8(5), l9(6), l10(7), l11(8), l12(9), l13(10);

	l4.next = &l5;
//	l5.next = &l6;
	
//	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	l9.next = &l10;
	l10.next = &l11;
	l11.next = &l12;
	l12.next = &l13;

	print_list(&l4);

	Solution s;

	print_list(s.reverseBetween(&l4, 1, 2));
	return 0;
}
