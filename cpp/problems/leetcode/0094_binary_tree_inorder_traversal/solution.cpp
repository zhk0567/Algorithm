// LeetCode 94
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};

int main() {
    TreeNode n3(3), n2(2, &n3, nullptr), n1(1, nullptr, &n2);
    assert((Solution().inorderTraversal(&n1) == vector<int>{1, 3, 2}));
    assert(Solution().inorderTraversal(nullptr).empty());
    TreeNode one(1);
    assert((Solution().inorderTraversal(&one) == vector<int>{1}));
    cout << "0094 OK" << endl;
    return 0;
}
