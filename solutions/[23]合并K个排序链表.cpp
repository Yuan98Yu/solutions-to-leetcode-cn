#include <queue>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
	bool operator ()(ListNode* x, ListNode* y)
	{
		return x->val > y->val;//小的优先级高
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return NULL;
		ListNode* dummy = new ListNode(0);

		priority_queue<ListNode*, vector<ListNode*>, cmp> q;
		for (ListNode* node : lists) {
			if (node != NULL) {
				q.push(node);
			}
		}

		ListNode* p = dummy;
		while (q.size() > 1) {
			p->next = q.top();
			q.pop();
			p = p->next;
			if (p->next != NULL)
				q.push(p->next);
		}
		if (q.size() == 1)
			p->next = q.top();

		return dummy->next;
	}
};