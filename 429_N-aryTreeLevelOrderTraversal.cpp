/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
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

        while (!q.empty()) {
            int size = q.size();

            vector<int> level;
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();

                level.emplace_back(cur->val);

                for (auto child : cur->children)
                    if (child != nullptr) q.push(child);
            }
            ans.emplace_back(level);
        }

        return ans;
    }
};
// @lc code=end

