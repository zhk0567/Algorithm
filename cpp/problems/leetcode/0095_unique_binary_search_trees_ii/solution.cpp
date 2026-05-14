// LeetCode 95
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

private:
    vector<TreeNode*> build(int l, int r) {
        if (l > r) return {nullptr};
        vector<TreeNode*> out;
        for (int i = l; i <= r; ++i)
            for (auto* lt : build(l, i - 1))
                for (auto* rt : build(i + 1, r))
                    out.push_back(new TreeNode(i, lt, rt));
        return out;
    }
};

static void inorderTraverse(TreeNode* n, vector<int>& out) {
    if (!n) return;
    inorderTraverse(n->left, out);
    out.push_back(n->val);
    inorderTraverse(n->right, out);
}

int main() {
    auto trees = Solution().generateTrees(3);
    assert((int)trees.size() == 5);
    for (auto* t : trees) {
        vector<int> seq;
        inorderTraverse(t, seq);
        auto sorted_seq = seq;
        sort(sorted_seq.begin(), sorted_seq.end());
        assert(seq == sorted_seq);
    }
    assert(Solution().generateTrees(0).empty());
    cout << "0095 OK" << endl;
    return 0;
}
