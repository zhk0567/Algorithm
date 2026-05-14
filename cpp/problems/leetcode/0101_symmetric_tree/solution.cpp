// LeetCode 101
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return mirror(root->left, root->right);
    }

private:
    bool mirror(TreeNode* a, TreeNode* b) {
        if (!a || !b) return a == b;
        return a->val == b->val && mirror(a->left, b->right) &&
               mirror(a->right, b->left);
    }
};

int main() {
    TreeNode l3a(3), l4a(4), l4b(4), l3b(3);
    TreeNode l2a(2, &l3a, &l4a);
    TreeNode l2b(2, &l4b, &l3b);
    TreeNode root(1, &l2a, &l2b);
    assert(Solution().isSymmetric(&root));

    TreeNode r3a(3), r3b(3);
    TreeNode r2a(2, nullptr, &r3a);
    TreeNode r2b(2, nullptr, &r3b);
    TreeNode bad(1, &r2a, &r2b);
    assert(!Solution().isSymmetric(&bad));
    cout << "0101 OK" << endl;
    return 0;
}
