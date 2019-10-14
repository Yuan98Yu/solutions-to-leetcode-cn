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
	void reorderList(ListNode* head) {
		if (head == NULL)
			return;

		ListNode* p2 = head;
		for (ListNode* fast = head; fast && fast->next; p2 = p2->next, fast = fast->next->next);
		ListNode* p1 = head;
		stack<ListNode*> s;
		for (ListNode* p = p2; p != NULL; p = p->next)
			s.push(p);
		ListNode* p = head;
		while (p != p2) {
			ListNode* tmp = p->next;
			p->next = s.top();
			s.pop();
			p->next->next = tmp;
			p = tmp;
		}
		p->next = NULL;
	}
};