#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(v), left(l), right(r) {}
};

pair<int, int> dfs(TreeNode* n) {
    if (!n) return {0, 0};
    auto [l0, l1] = dfs(n->left);
    auto [r0, r1] = dfs(n->right);
    int take = n->val + l0 + r0;
    int skip = max(l0, l1) + max(r0, r1);
    return {skip, take};
}

int rob_tree(TreeNode* root) {
    auto p = dfs(root);
    return max(p.first, p.second);
}

int main() {
    TreeNode n3(3), n3b(3), n1(1);
    TreeNode n2(2, nullptr, &n3);
    TreeNode r(3, &n2, new TreeNode(3, nullptr, &n1));
    assert(rob_tree(&r) == 7);
    cout << "tree_dp OK" << endl;
    return 0;
}
