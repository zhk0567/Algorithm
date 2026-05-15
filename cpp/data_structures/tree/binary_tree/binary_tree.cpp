#include <alg_std.hpp>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(v), left(l), right(r) {}
};

void preorder(TreeNode* r, vector<int>& out) {
    if (!r) return;
    out.push_back(r->val);
    preorder(r->left, out);
    preorder(r->right, out);
}

vector<int> inorder_iter(TreeNode* root) {
    vector<int> out;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (!st.empty() || cur) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        out.push_back(cur->val);
        cur = cur->right;
    }
    return out;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = (int)q.size();
        vector<int> level;
        for (int i = 0; i < sz; ++i) {
            TreeNode* n = q.front();
            q.pop();
            level.push_back(n->val);
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        res.push_back(move(level));
    }
    return res;
}

int main() {
    TreeNode n4(4), n2(2, &n4, nullptr), n3(3), root(1, &n2, &n3);
    vector<int> pre;
    preorder(&root, pre);
    assert(pre == vector<int>({1, 2, 4, 3}));
    assert(inorder_iter(&root) == vector<int>({4, 2, 1, 3}));
    auto lv = levelOrder(&root);
    assert(lv.size() == 3);
    cout << "BinaryTree OK" << endl;
    return 0;
}
