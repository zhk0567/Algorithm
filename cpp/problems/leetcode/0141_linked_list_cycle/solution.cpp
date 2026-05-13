// LeetCode 141
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    ListNode n1(3), n2(2), n3(0), n4(-4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2;
    assert(Solution().hasCycle(&n1));
    ListNode a(1), b(2);
    a.next = &b;
    assert(!Solution().hasCycle(&a));
    cout << "0141 OK" << endl;
    return 0;
}
