/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return _buildtree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);    
    }
    
    TreeNode* _buildtree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd) return nullptr;

        int root_val = postorder[postEnd];
        int idx = 0;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == root_val) {
                idx = i;
                break;
            }
        }
        int left_size = idx - inStart;

        TreeNode *root = new TreeNode(root_val);
        root->left = _buildtree(inorder, inStart, idx-1, postorder, postStart, postStart+left_size-1);
        root->right = _buildtree(inorder, idx+1, inEnd, postorder, postStart+left_size, postEnd-1);

        return root;
    }
};

// Runtime: 20 ms, faster than 59.63% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
// Memory Usage: 26 MB, less than 71.59% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
