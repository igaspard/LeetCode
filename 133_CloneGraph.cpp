/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
    
        unordered_map<Node*, Node*> map;
        Node* clone = new Node(node->val);
        map[node] = clone;
        
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for (auto n : cur->neighbors) {
                if (map.count(n) == 0) {
                    map[n] = new Node(n->val);
                    q.push(n);
                }
                map[cur]->neighbors.emplace_back(map[n]);
            }
        }
        
        return clone;
    }
};

// bfs, time complexity: O(V + E)
// Runtime: 8 ms, faster than 59.01% of C++ online submissions for Clone Graph.
// Memory Usage: 8.4 MB, less than 93.04% of C++ online submissions for Clone Graph.

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        return dfs(node);
    }
private:
    unordered_map<Node*, Node*> map;
    Node *dfs(Node* node) {
        if (map.count(node) != 0) return map[node];
        
        Node *clone = new Node(node->val);
        map[node] = clone;
        for (auto n : node->neighbors)
            clone->neighbors.emplace_back(dfs(n));
        
        return clone;
    }
};

// dfs, time complexity: O(V + E)
// Runtime: 13 ms, faster than 10.72% of C++ online submissions for Clone Graph.
// Memory Usage: 8.7 MB, less than 55.91% of C++ online submissions for Clone Graph.
