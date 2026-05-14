#include <bits/stdc++.h>
#include <cassert>
using namespace std;

long long cross(long long ax, long long ay, long long bx, long long by) { return ax * by - ay * bx; }

long long orient(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    return cross(bx - ax, by - ay, cx - ax, cy - ay);
}

int main() {
    assert(orient(0, 0, 1, 0, 1, 1) > 0);
    assert(orient(0, 0, 1, 0, 2, 0) == 0);
    cout << "geometry OK" << endl;
    return 0;
}
