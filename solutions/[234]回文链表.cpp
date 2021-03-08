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
	bool isPalindrome(ListNode* head) {
		ListNode* mid;
		ListNode* fast;
		for (mid = head, fast = head; fast && fast->next; mid = mid->next, fast = fast->next->next);

		ListNode* front = NULL;
		while (mid) {
			ListNode* tmp = mid->next;
			mid->next = front;
			front = mid;
			mid = tmp;
		}

		for (; front && head; front = front->next, head = head->next)
			if (front->val != head->val)
				break;
		if (front)
			return false;
		else
			return true;
	}
};