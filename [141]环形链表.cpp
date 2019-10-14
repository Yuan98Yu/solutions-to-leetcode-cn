#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head == NULL)
			return false;
		ListNode* slow = head;
		ListNode* fast = head->next;
		for (; fast && fast->next && slow != fast; slow = slow->next, fast = fast->next->next);
		if (fast && fast->next)
			return true;
		else
			return false;
	}
};