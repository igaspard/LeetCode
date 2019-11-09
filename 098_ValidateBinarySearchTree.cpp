#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Will fail only one single node which value is max of int [2147483647]
class SolutionMinMax {
public:
    bool isValidBST(TreeNode* root) {
        return ValidBST(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }

    bool ValidBST(TreeNode *root, int min, int max) {
        if (!root)
            return true;
        if (root->val <= min || root->val >= max)
            return false;

        return ValidBST(root->left, min, root->val) &&
               ValidBST(root->right, root->val, max);
    }
};

class SolutionInOrder {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return ValidBST(root, prev);
    }
    bool ValidBST(TreeNode* node, TreeNode* &prev) {
        if (!node) return true;
        if (!ValidBST(node->left, prev)) return false;
        if (prev && prev->val >= node->val) return false;
        prev = node;
        return ValidBST(node->right, prev);
    }
};

int main(int argc, char const *argv[]) {
    SolutionMinMax ibst1;
    SolutionInOrder ibst2;
    TreeNode t(numeric_limits<int>::max());
    cout<<"A single node value is max of int: "<<numeric_limits<int>::max()<<" is BST? "<<endl;
    cout<<"Min Max Method: "<<ibst1.isValidBST(&t)<<", In-Order Traversal: "<<ibst2.isValidBST(&t)<<endl;

    TreeNode t1(1);
    TreeNode t2(1);
    t1.right = &t2;
    cout<<"[1, 1] "<<ibst2.isValidBST(&t1)<<endl;

    return 0;
}
