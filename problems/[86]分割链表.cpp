#include <cstdlib>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* pre_front = NULL;
		ListNode* pre_back = NULL;
		ListNode* for_front = NULL;
		ListNode* for_back = NULL;
		for (ListNode* cur = head; cur != NULL; cur = cur->next) {
			if (cur->val < x) {
				if (pre_front) {
					pre_back->next = cur;
				}
				else {
					pre_front = cur;
				}
				pre_back = cur;
			}
			else {
				if (for_front) {
					for_back->next = cur;
				}
				else {
					for_front = cur;
				}
				for_back = cur;
			}
		}
		if (pre_front == NULL)
			return for_front;

		if (for_front) {
			for_back->next = NULL;
			pre_back->next = for_front;
		}
		return pre_front;
	}
};