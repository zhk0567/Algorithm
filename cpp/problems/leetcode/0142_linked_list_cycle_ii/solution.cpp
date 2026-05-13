// LeetCode 142
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* p = head;
                while (p != slow) {
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};

int main() {
    ListNode n1(3), n2(2), n3(0), n4(-4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2;
    assert(Solution().detectCycle(&n1) == &n2);
    ListNode a(1), b(2);
    a.next = &b;
    assert(Solution().detectCycle(&a) == nullptr);
    cout << "0142 OK" << endl;
    return 0;
}
