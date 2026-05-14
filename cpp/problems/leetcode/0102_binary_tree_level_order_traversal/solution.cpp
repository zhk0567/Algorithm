// LeetCode 102
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = (int)q.size();
            vector<int> level;
            for (int i = 0; i < sz; ++i) {
                TreeNode* n = q.front();
                q.pop();
                level.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    TreeNode n15(15), n7(7), n9(9), n20(20, &n15, &n7);
    TreeNode root(3, &n9, &n20);
    assert((Solution().levelOrder(&root) ==
            vector<vector<int>>{{3}, {9, 20}, {15, 7}}));
    assert(Solution().levelOrder(nullptr).empty());
    cout << "0102 OK" << endl;
    return 0;
}
