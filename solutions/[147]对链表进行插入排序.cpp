#include <cstdlib>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* cur = head;
		ListNode* tail = head;
		while (cur != nullptr) {
			ListNode* next_cur = cur->next;
			ListNode* tmp = dummy;
			for (; tmp->next->val < cur->val && tmp->next != cur; tmp = tmp->next);
			if (tmp->next != cur) {
				ListNode* tmp_next = tmp->next;
				tmp->next = cur;
				tail->next = cur->next;
				cur->next = tmp_next;
			}
			else {
				tail = cur;
			}
			cur = next_cur;
		}
		return dummy->next;
	}
};