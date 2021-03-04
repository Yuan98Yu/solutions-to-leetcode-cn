#include <vector>
#include <map>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		map<Node*, Node*> visited;
		return backtrack(node, visited);
	}
	Node* backtrack(Node* node, map<Node*, Node*>& visited) {
		if (node == nullptr)
			return nullptr;
		if (visited.find(node) != visited.end())
			return visited[node];

		vector<Node*> neighbors;
		Node* new_node = new Node(node->val, neighbors);
		visited[node] = new_node;
		for (Node* n : node->neighbors)
			new_node->neighbors.push_back(backtrack(n, visited));

		return new_node;
	}
};