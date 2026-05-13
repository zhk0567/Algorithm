// LeetCode 105
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < (int)inorder.size(); ++i) idx[inorder[i]] = i;
        pre = &preorder;
        cursor = 0;
        return build(0, (int)inorder.size() - 1);
    }

private:
    unordered_map<int, int> idx;
    vector<int>* pre = nullptr;
    int cursor = 0;
    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int v = (*pre)[cursor++];
        TreeNode* node = new TreeNode(v);
        int m = idx[v];
        node->left = build(l, m - 1);
        node->right = build(m + 1, r);
        return node;
    }
};

static void inorderTraverse(TreeNode* n, vector<int>& out) {
    if (!n) return;
    inorderTraverse(n->left, out);
    out.push_back(n->val);
    inorderTraverse(n->right, out);
}

int main() {
    vector<int> pre{3, 9, 20, 15, 7}, ino{9, 3, 15, 20, 7};
    auto* root = Solution().buildTree(pre, ino);
    vector<int> out;
    inorderTraverse(root, out);
    assert((out == vector<int>{9, 3, 15, 20, 7}));
    vector<int> e1, e2;
    assert(Solution().buildTree(e1, e2) == nullptr);
    cout << "0105 OK" << endl;
    return 0;
}
