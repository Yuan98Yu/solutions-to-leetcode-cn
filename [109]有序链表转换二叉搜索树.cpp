#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
	ģ���������
*/
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		// Get the size of the linked list first
		int size = this->findSize(head);

		this->head = head;

		// Form the BST now that we know the size
		return convertListToBST(0, size - 1);
	}

private:
	ListNode* head;

	int findSize(ListNode* head) {
		ListNode* ptr = head;
		int c = 0;
		while (ptr != NULL) {
			ptr = ptr->next;
			c += 1;
		}
		return c;
	}

	TreeNode* convertListToBST(int l, int r) {
		// Invalid case
		if (l > r) {
			return NULL;
		}

		int mid = (l + r) / 2;

		// First step of simulated inorder traversal. Recursively form
		// the left half
		TreeNode* left = this->convertListToBST(l, mid - 1);

		// Once left half is traversed, process the current node
		TreeNode* node = new TreeNode(this->head->val);
		node->left = left;

		// Maintain the invariance mentioned in the algorithm
		this->head = this->head->next;

		// Recurse on the right hand side and form BST out of them
		node->right = this->convertListToBST(mid + 1, r);
		return node;
	}
};
