/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

#include <stdio.h>

struct DoubleList {
	int val;
 	DoubleList *next;
 	DoubleList *pre;
	DoubleList(int x) : val(x), next(NULL), pre(NULL) {}
};

class MinStack {
public:
	MinStack():store(NULL), current(NULL), min(0), size(0) {

	}

	~MinStack() {
		for (DoubleList *p = store; p != NULL; ) {
			DoubleList *q = p->next;
			delete p;
			p = q;
		}
	}

	void push(int x) {
		if (store == NULL) {
			store = new DoubleList(x);
			current = store;
			min = x;
		} else {
			DoubleList *tmp = current;
			current->next = new DoubleList(x);
			current = current->next;
			current->pre = tmp;
		}

		if (min >= x) {
			min = x;
		}
		size++;
	}

	void pop() {
		if (current == NULL) {
			return;
		}
		int tmpval = current->val;
		DoubleList *tmp = current;
		if (current->pre != NULL) {
			current = current->pre;
			current->next = NULL;

			if (min == tmpval) {
				min = store->val;	
				for (DoubleList *p = store; p != NULL; p = p->next) {
					if (min >= p->val) {
						min = p->val;
					}
				}
			}
		} else {
			store = NULL;
			current = NULL;
			min = 0;
		}
		delete tmp;
		size--;
	}

	int top() {
		return current->val;
	}

	int getMin() {
		return min;
	}

	void print_stack() {
		for (DoubleList *p = store; p != NULL; p = p->next) {
			printf("%d ", p->val);
		}
		printf("\n");
	}
	
private:
	DoubleList *store;
	DoubleList *current;
	int min;
	int size;
};

int main() {
	MinStack stack;

	stack.push(2147483646); 
	stack.push(2147483646);
	stack.push(2147483647);
	stack.top();
	stack.pop();
	stack.getMin();
	stack.pop();
	stack.getMin();
	stack.pop();
	stack.push(2147483647);
	stack.top();
	stack.getMin();
	stack.push(-2147483648);
	stack.top();
	stack.getMin();
	stack.pop();
	stack.getMin();

	return 0;
}
