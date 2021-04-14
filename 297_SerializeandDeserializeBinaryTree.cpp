class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur == nullptr) {
                ans << "# ";
                continue;
            }
            ans << cur->val << " ";
            q.push(cur->left);
            q.push(cur->right);
        }

        return ans.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        string str;
        input >> str;
        if (str == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (input >> str) {
            auto cur = q.front();
            q.pop();

            if (str == "#") cur->left = nullptr;
            else {
                cur->left = new TreeNode(stoi(str));
                q.push(cur->left);
            }

            input >> str;
            if (str == "#") cur->right = nullptr;
            else {
                cur->right = new TreeNode(stoi(str));
                q.push(cur->right);
            }
        }
        
        return root;
    }
};

// Level Order Traversal BFS
// Your runtime beats 72.58 % of cpp submissions
// Your memory usage beats 90.81 % of cpp submissions (29 MB)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ans;
        serialized(root, ans);
        return ans.str();
    }
    
    void serialized(TreeNode *root, ostringstream &ans) {
        if (root == nullptr) {
            ans << "# ";
            return;
        }
        
        ans << root->val << " ";
        
        serialized(root->left, ans);
        serialized(root->right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        return deserialized(input);
    }
    
    TreeNode *deserialized(istringstream &input) {
        string str;
        input >> str;
        if (str == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(str));
        root->left = deserialized(input);
        root->right = deserialized(input);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Preorder DFS
// Runtime: 36 ms, faster than 95.71% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 31 MB, less than 76.14% of C++ online submissions for Serialize and Deserialize Binary Tree.