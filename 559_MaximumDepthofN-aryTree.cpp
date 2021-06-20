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
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        
        int ans = 0;
        for (auto child : root->children)
            ans = max(ans, maxDepth(child));
        
        return ans + 1;
    }
};

// recursive postorder
// Runtime: 8 ms, faster than 99.55% of C++ online submissions for Maximum Depth of N-ary Tree.
// Memory Usage: 10.8 MB, less than 66.41% of C++ online submissions for Maximum Depth of N-ary Tree.
