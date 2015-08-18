/*
Sort a linked list using insertion sort.
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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		ListNode *m = head->next->next;
		ListNode *low = (head->val <= head->next->val) ? head : head->next;
		ListNode *high = (head->val > head->next->val) ? head : head->next;
		low->next = high;
		high->next = NULL;
		// 4->8->3->5->9->7->NULL
		//  3  4      8
		for ( ; m != NULL; ) {
			ListNode *store = m->next;
			if (low->val > m->val) {
				m->next = low;
				low = m;
				m = store;
				continue;
			}
			if (high->val < m->val) {
				high->next = m;
				high = m;
				high->next = NULL;
				m = store;
				continue;
			}

			for (ListNode *step = low; step->next != NULL; step = step->next) {
				int left = step->val;
				int right = step->next->val;
				if ((left <= m->val) && (m->val <= right)) {
					ListNode *tmp = step->next;
					step->next = m;	
					m->next = tmp;
					m = store;
					break;
				} 
			}
		}
		return low;
	}
};

int main() {
	ListNode l1(2), l2(1), l3(3);
	ListNode l4(4), l5(2), l6(1), l7(6), l8(6), l9(9), l10(10), l11(11), l12(12), l13(6);
	ListNode n1(0), n2(0), n3(0), n4(1);
	l1.next = &l2;

	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	l9.next = &l10;
	l10.next = &l11;
	l11.next = &l12;
	l12.next = &l13;

	//n1.next = &n2;
	//n2.next = &n3;
	//n3.next = &n4;

	print_list(&l1);
	Solution s;
	ListNode *result = s.insertionSortList(&l1);
	print_list(result);

	return 0;
}
