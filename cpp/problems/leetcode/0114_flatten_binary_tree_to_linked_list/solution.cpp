// LeetCode 114
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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* rm = cur->left;
                while (rm->right) rm = rm->right;
                rm->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};

int main() {
    TreeNode n3(3), n4(4), n2(2, &n3, &n4), n6(6), n5(5, nullptr, &n6);
    TreeNode root(1, &n2, &n5);
    Solution().flatten(&root);
    vector<int> out;
    for (TreeNode* p = &root; p; p = p->right) {
        assert(p->left == nullptr);
        out.push_back(p->val);
    }
    assert((out == vector<int>{1, 2, 3, 4, 5, 6}));
    Solution().flatten(nullptr);
    TreeNode one(0);
    Solution().flatten(&one);
    assert(one.left == nullptr && one.right == nullptr && one.val == 0);
    cout << "0114 OK" << endl;
    return 0;
}
