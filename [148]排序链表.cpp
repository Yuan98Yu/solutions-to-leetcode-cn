#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		//1.cut
		ListNode* slow = head;
		ListNode* fast = head->next;
		for (; fast && fast->next; slow = slow->next, fast = fast->next->next);
		ListNode* mid = slow->next;
		slow->next = nullptr;
		//2. µÝ¹écut
		ListNode* left = sortList(head);
		ListNode* right = sortList(mid);
		//3.merge
		ListNode* dummy = new ListNode(-1);
		ListNode* p = dummy;
		while (left != nullptr && right != nullptr) {
			if (left->val < right->val) {
				p->next = left;
				left = left->next;
			}
			else {
				p->next = right;
				right = right->next;
			}
			p = p->next;
		}
		p->next = left != nullptr ? left : right;

		return dummy->next;
	}
};