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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) return "";
        
        ostringstream ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            ans << cur->val << " " << cur->children.size() << " ";
            for (auto child : cur->children) 
                q.push(child);
        }
        
        return ans.str();
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        istringstream input(data);
        string sval, scnt;
        input >> sval >> scnt;
        int val = stoi(sval), cnt = stoi(scnt);
        Node* root = new Node(val);
        queue<pair<Node*, int>> q;
        q.push({root, cnt});
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for (int i = 0; i < cur.second; ++i) {
                input >> sval >> scnt;
                val = stoi(sval);
                cnt = stoi(scnt);
                Node *child = new Node(val);
                cur.first->children.emplace_back(child);
                q.push({child, cnt});
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// Level Order
// Runtime: 36 ms, faster than 88.59% of C++ online submissions for Serialize and Deserialize N-ary Tree.
// Memory Usage: 173.1 MB, less than 55.09% of C++ online submissions for Serialize and Deserialize N-ary Tree.