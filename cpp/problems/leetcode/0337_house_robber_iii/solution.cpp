// LeetCode 337
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
    int rob(TreeNode* root) {
        auto [s, k] = dfs(root);
        return max(s, k);
    }

private:
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [ls, lk] = dfs(node->left);
        auto [rs, rk] = dfs(node->right);
        int steal = node->val + lk + rk;
        int skip = max(ls, lk) + max(rs, rk);
        return {steal, skip};
    }
};

int main() {
    TreeNode n3a(3), n1a(1);
    TreeNode n2(2, nullptr, &n3a), n3b(3, nullptr, &n1a);
    TreeNode root(3, &n2, &n3b);
    assert(Solution().rob(&root) == 7);
    TreeNode l1(1), l3(3), n4(4, &l1, &l3), l1b(1), n5(5, nullptr, &l1b);
    TreeNode root2(3, &n4, &n5);
    assert(Solution().rob(&root2) == 9);
    assert(Solution().rob(nullptr) == 0);
    cout << "0337 OK" << endl;
    return 0;
}
