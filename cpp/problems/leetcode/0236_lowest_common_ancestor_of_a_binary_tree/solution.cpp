// LeetCode 236
#include <bits/stdc++.h>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (l && r) return root;
        return l ? l : r;
    }
};

int main() {
    TreeNode n7(7), n4(4);
    TreeNode n6(6);
    TreeNode n2(2, &n7, &n4);
    TreeNode n0(0), n8(8);
    TreeNode n5(5, &n6, &n2);
    TreeNode n1(1, &n0, &n8);
    TreeNode root(3, &n5, &n1);
    assert(Solution().lowestCommonAncestor(&root, &n5, &n1) == &root);
    assert(Solution().lowestCommonAncestor(&root, &n5, &n4) == &n5);
    cout << "0236 OK" << endl;
    return 0;
}
