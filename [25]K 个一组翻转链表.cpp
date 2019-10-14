#include <cstdlib>
#include <stack>
using namespace std;
/*
	对于一个链表反转问题，解法可分两种：栈、双指针。
	由于该问题是规定每K个一组反转，不足k个不动，使用双指针的话不便于计数，因而选择用栈。
	当然也可以遍历两次，第一次计数，第二次反转。
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/*
		递归
	*/
	ListNode* reverseKGroup(ListNode* head, int k) {
		stack<ListNode*> s;
		ListNode* p = head;
		for (int i = 0; p != NULL && i < k; ++i, p = p->next)
			s.push(p);
			
		if (s.size()<k)
			return head;

		ListNode* ac_head = s.top();
		ListNode* next = ac_head->next;
		s.pop();
		p = ac_head;
		while (!s.empty()) {
			p->next = s.top();
			s.pop();
			p = p->next;
		}
		p->next = reverseKGroup(next, k);

		return ac_head;
	}
};