/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

#include <iostream>

using namespace std;

template <class T>
struct node
{
	T val;
	struct node *next;
};

template <class T>
class Stack
{
	struct node<T> *top;

	public:

		Stack()
		{
			top = NULL;
		}

		void push(T item)
		{
			struct node<T> *t;
			t = new struct node<T>;
			t->val = item;
			t->next = top;
			top = t;
		}

		void pop(void)
		{
			if(empty())
				throw "There are no items in stack to pop!!!";

			struct node<T> *t;
			t = top;
			top = top->next;
			delete t;
		}

		T peek(void)
		{
			if(empty())
				throw "There are no items in stack to peek!!!";

			T item;
			item = top->val;
			return item;
		}

		bool empty(void)
		{
			return top == NULL ? true : false;
		}
};

int main(void)
{
	Stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	
	cout << s.peek() << endl;
	
	s.pop();
	
	cout << s.peek() << endl;
	cout << s.empty() << endl;

	s.pop();
	s.pop();

	cout << s.empty() << endl;

	return 0;
}