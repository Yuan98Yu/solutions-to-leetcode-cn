#include <cstdlib>
// definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		/*	
			需要考虑的边界情况：
				1.n无效（然而题目保证了n有效),
				2.链表只有1个节点
				3.删除的是链表的第一个节点
			解决2、3的最简单方法，增加头节点；否则需做边界检查。
		*/
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* forward = head;
		ListNode* rear = dummy;
		for (int i = 0; i < n-1; i++, forward = forward->next);
		for (; forward->next != NULL; rear = rear->next, forward=forward->next);
		forward = rear->next;
		rear->next = forward->next;
		delete forward;

		return dummy->next;
	}
};