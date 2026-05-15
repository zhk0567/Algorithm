// LeetCode 226
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* l = invertTree(root->left);
        TreeNode* r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};

int main() {
    TreeNode n1(1), n3(3), n6(6), n9(9);
    TreeNode n2(2, &n1, &n3), n7(7, &n6, &n9);
    TreeNode root(4, &n2, &n7);
    TreeNode* res = Solution().invertTree(&root);
    assert(res->val == 4 && res->left->val == 7 && res->right->val == 2);
    assert(res->left->left->val == 9 && res->right->right->val == 1);
    assert(Solution().invertTree(nullptr) == nullptr);
    cout << "0226 OK" << endl;
    return 0;
}
