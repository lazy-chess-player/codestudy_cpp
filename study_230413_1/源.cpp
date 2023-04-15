#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);

	cout << "The size of the stack is: " << s.size() << endl;

	cout << "The top element of the stack is: " << s.top() << endl;

	s.pop();
	s.pop();

	cout << "The stack is empty: " << (s.empty() ? "true" : "false") << endl;

	return 0;
}