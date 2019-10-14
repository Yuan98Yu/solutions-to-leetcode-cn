#include <cstdlib>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* p = dummy;
		for (int i = 1; i < m; ++i, p= p->next);
		ListNode* back = p->next;
		ListNode* cur = back;
		ListNode* front = NULL;
		for(int i =0; i<=n-m; ++i) {
			ListNode* nextCur = cur->next;
			cur->next = front;
			front = cur;
			cur = nextCur;
		}
		back->next = cur;
		p->next = front;
		return dummy->next;
	}
};