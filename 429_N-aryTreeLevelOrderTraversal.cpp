/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        queue<Node*> q;
        q.push(root);
        ans.push_back({root->val});
        
        while (!q.empty()) {
            int size = q.size();
            
            vector<int> levels;
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                for (auto child : cur->children) {
                    levels.emplace_back(child->val);
                    q.push(child);
                }    
            }
            
            if (!levels.empty()) ans.emplace_back(levels);
        }
        
        return ans;
    }
};

// Runtime: 24 ms, faster than 52.64% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 11.8 MB, less than 59.45% of C++ online submissions for N-ary Tree Level Order Traversal.