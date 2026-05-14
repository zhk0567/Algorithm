// LeetCode 98
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool dfs(TreeNode* node, long long lo, long long hi) {
        if (!node) return true;
        if (node->val <= lo || node->val >= hi) return false;
        return dfs(node->left, lo, node->val) &&
               dfs(node->right, node->val, hi);
    }
};

int main() {
    TreeNode a(1), b(3), root(2, &a, &b);
    assert(Solution().isValidBST(&root));
    TreeNode c(3), d(6), e(4, &c, &d), f(1);
    TreeNode bad(5, &f, &e);
    assert(!Solution().isValidBST(&bad));
    cout << "0098 OK" << endl;
    return 0;
}
