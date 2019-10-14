#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* cur = dummy;
		ListNode* forward;
		while (cur && cur->next) {
			forward = cur->next;
			while (forward->next && forward->next->val == forward->val)
				forward = forward->next;
			if (cur->next != forward)
				cur->next = forward->next;
			else
				cur = cur->next;
		}

		return dummy->next;
	}
};