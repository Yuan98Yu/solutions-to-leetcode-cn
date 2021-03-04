#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode* p = head;
		ListNode* next;
		while (p->next != NULL) {
			next = p->next;
			if (p->val == next->val) {
				p->next = next->next;
				delete next;
			}
			else {
				p = p->next;
			}
		}
		return head;
	}
};