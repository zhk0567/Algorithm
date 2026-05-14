// LeetCode 104
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    TreeNode n15(15), n7(7), n9(9), n20(20, &n15, &n7);
    TreeNode root(3, &n9, &n20);
    assert(Solution().maxDepth(&root) == 3);
    assert(Solution().maxDepth(nullptr) == 0);
    cout << "0104 OK" << endl;
    return 0;
}
