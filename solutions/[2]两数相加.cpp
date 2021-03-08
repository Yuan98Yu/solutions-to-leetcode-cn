#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* l3 = new ListNode(-1);
		int tmp = 0;
		ListNode* tmp_node = l3;
		for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
			if (tmp >= 10)
				tmp = l1->val + l2->val + 1;
			else
				tmp = l1->val + l2->val;
			tmp_node->next = new ListNode(tmp%10);
			tmp_node = tmp_node->next;
		}
		if (l1) 
			tmp_node->next = l1;
		else if (l2) 
			tmp_node->next = l2;
		for (; tmp_node->next; tmp_node = tmp_node->next) {
			if (tmp >= 10)
				tmp = 1 + tmp_node->next->val;
			else
				tmp = tmp_node->next->val;
			tmp_node->next->val = tmp % 10;
		}

		if (tmp >= 10)
			tmp_node->next = new ListNode(1);
		return l3->next;
	}
};