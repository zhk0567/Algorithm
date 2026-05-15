// LeetCode 124
#include <alg_std.hpp>
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
    int maxPathSum(TreeNode* root) {
        best = INT_MIN;
        dfs(root);
        return best;
    }

private:
    int best;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = max(dfs(node->left), 0);
        int r = max(dfs(node->right), 0);
        best = max(best, node->val + l + r);
        return node->val + max(l, r);
    }
};

int main() {
    TreeNode a(2), b(3), r1(1, &a, &b);
    assert(Solution().maxPathSum(&r1) == 6);
    TreeNode n15(15), n7(7), n20(20, &n15, &n7), n9(9);
    TreeNode r2(-10, &n9, &n20);
    assert(Solution().maxPathSum(&r2) == 42);
    TreeNode r3(-3);
    assert(Solution().maxPathSum(&r3) == -3);
    cout << "0124 OK" << endl;
    return 0;
}
