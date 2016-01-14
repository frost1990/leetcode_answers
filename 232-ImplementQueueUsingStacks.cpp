/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
Subscribe to see which companies asked this question
*/

#include <stack>

using namespace std;

class Queue {
private:
	stack<int> s1, s2;
public:
	void push(int x) {
		s1.push(x);
	}

	void pop(void) {
		while (!s1.empty()) {
			int x = s1.top();
			s2.push(x);
			s1.pop();
		}

		if (!s2.empty()) {
			s2.pop();    
		}

		while (!s2.empty()) {
				int x = s2.top();
				s1.push(x);
				s2.pop();
			}
		}

		int peek(void) {
			while (!s1.empty()) {
				int x = s1.top();
				s2.push(x);
				s1.pop();
			}

			if (!s2.empty()) {
				int retval = s2.top();
				while (!s2.empty()) {
					int x = s2.top();
					s1.push(x);
					s2.pop();
				}
				return retval;
			} else {
				return 0;
			}
		}

		bool empty(void) {
			return s1.empty();
		}

		void printqueue() {

		}
};

int main() {
	Queue q;
	q.push(1);
	q.push(3);
	q.push(2);
	q.push(5);

	printf("Peek = %d\n", q.peek());
	q.pop();
	printf("Peek = %d\n", q.peek());

	return 0;
}
