// LeetCode 437
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
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        target = targetSum;
        ans = 0;
        dfs(root, 0);
        return ans;
    }

private:
    unordered_map<long long, int> prefix;
    int target;
    int ans;
    void dfs(TreeNode* node, long long cur) {
        if (!node) return;
        cur += node->val;
        auto it = prefix.find(cur - target);
        if (it != prefix.end()) ans += it->second;
        ++prefix[cur];
        dfs(node->left, cur);
        dfs(node->right, cur);
        --prefix[cur];
    }
};

int main() {
    TreeNode n3a(3), n_2(-2), n1(1), n11(11);
    TreeNode n3b(3, &n3a, &n_2), n2(2, nullptr, &n1);
    TreeNode n5(5, &n3b, &n2), n_3(-3, nullptr, &n11);
    TreeNode root(10, &n5, &n_3);
    assert(Solution().pathSum(&root, 8) == 3);
    assert(Solution().pathSum(nullptr, 0) == 0);
    cout << "0437 OK" << endl;
    return 0;
}
