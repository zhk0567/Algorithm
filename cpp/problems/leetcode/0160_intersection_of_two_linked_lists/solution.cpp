// LeetCode 160
#include <alg_std.hpp>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

int main() {
    ListNode c1(8), c2(4), c3(5);
    c1.next = &c2;
    c2.next = &c3;
    ListNode a1(4), a2(1);
    a1.next = &a2;
    a2.next = &c1;
    ListNode b1(5), b2(6), b3(1);
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    assert(Solution().getIntersectionNode(&a1, &b1) == &c1);

    ListNode x1(1), x2(2);
    x1.next = &x2;
    ListNode y1(3);
    assert(Solution().getIntersectionNode(&x1, &y1) == nullptr);
    cout << "0160 OK" << endl;
    return 0;
}
