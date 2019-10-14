#include <cstdlib>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<ListNode*> s1;
		stack<ListNode*> s2;
		for (ListNode* p=l1; p; p = p->next)
			s1.push(p);
		for (ListNode* p=l2; p; p = p->next)
			s2.push(p);

		int carry = 0;
		ListNode* front = NULL;
		ListNode* cur;
		while (!s1.empty() || !s2.empty() || carry == 1) {
			int tmp = carry;
			if (!s1.empty()) {
				tmp += s1.top()->val;
				s1.pop();
			}
			if (!s2.empty()) {
				tmp += s2.top()->val;
				s2.pop();
			}

			if (tmp >= 10) {
				tmp = tmp - 10;
				carry = 1;
			}
			else
				carry = 0;
			cur = new ListNode(tmp);
			cur->next = front;
			front = cur;
		}
		return front;
	}
};