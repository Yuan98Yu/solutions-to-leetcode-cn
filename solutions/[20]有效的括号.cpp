#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s == "") return true;
		if (s.length() % 2 != 0) return false;

		stack<char> my_stack;
		for (char c : s) {
			if (c == '(' || c == '{' || c == '[')
				my_stack.push(c);
			else {
				if (my_stack.empty())
					return false;
				
				if (c == ')') {
					if (my_stack.top() != '(')
						return false;
				}
				else if(c == '}') {
					if (my_stack.top() != '{')
						return false;
				}
				else{
					if (my_stack.top() != '[')
						return false;
				}
				my_stack.pop();
			}
		}
		return my_stack.empty();
	}
};
