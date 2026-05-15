// LeetCode 138: Copy List with Random Pointer
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Node {
public:
    int val;
    Node *next, *random;
    Node(int v) : val(v), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mp;
        for (Node* cur = head; cur; cur = cur->next)
            mp[cur] = new Node(cur->val);
        for (Node* cur = head; cur; cur = cur->next) {
            mp[cur]->next = cur->next ? mp[cur->next] : nullptr;
            mp[cur]->random = cur->random ? mp[cur->random] : nullptr;
        }
        return mp[head];
    }
};

vector<int> vals(Node* h) {
    vector<int> o;
    for (; h; h = h->next) o.push_back(h->val);
    return o;
}

vector<int> rnd_vals(Node* h) {
    vector<int> o;
    for (; h; h = h->next)
        o.push_back(h->random ? h->random->val : -1);
    return o;
}

int main() {
    vector<Node*> nodes;
    for (int v : {7, 13, 11, 10, 1}) nodes.push_back(new Node(v));
    for (int i = 0; i + 1 < (int)nodes.size(); ++i) nodes[i]->next = nodes[i + 1];
    nodes[1]->random = nodes[0];
    nodes[2]->random = nodes[4];
    nodes[4]->random = nodes[0];
    Node* head = nodes[0];
    Node* copy = Solution().copyRandomList(head);
    assert(vals(copy) == vector<int>({7, 13, 11, 10, 1}));
    auto r = rnd_vals(copy);
    assert(r == vector<int>({-1, 7, 1, -1, 7}));
    assert(Solution().copyRandomList(nullptr) == nullptr);
    cout << "0138 OK" << endl;
    return 0;
}
