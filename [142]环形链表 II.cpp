#include <cstdlib>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		for (; fast && fast->next && slow != fast->next; slow = slow->next, fast = fast->next->next);
		if (fast && fast->next) {
			ListNode* p1 = slow->next;
			ListNode* p2 = head;
			for (; p1 != p2; p1 = p1->next, p2 = p2->next);
			return p1;
		}
		else
			return NULL;
	}
};