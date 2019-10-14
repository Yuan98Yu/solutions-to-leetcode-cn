#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode* p1 = head;
		ListNode* p2_front = head->next;
		ListNode* p2 = p2_front;
		while (p2 && p2->next) {
			p1->next = p2->next;
			p1 = p1->next;
			p2->next = p1->next;
			p2 = p2->next;
		}
		p1->next = p2_front;
		return head;
	}
};