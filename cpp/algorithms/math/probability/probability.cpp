#include <bits/stdc++.h>
using namespace std;

double expected_first_success(int p_num, int p_den) { return (double)p_den / p_num; }

int main() {
    assert(abs(expected_first_success(1, 6) - 6.0) < 1e-12);
    cout << "probability OK" << endl;
    return 0;
}
