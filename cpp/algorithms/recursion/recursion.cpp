#include <bits/stdc++.h>
#include <cassert>
using namespace std;

long long factorial(int n) {
    if (n < 0) throw invalid_argument("n");
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

unordered_map<int, long long> fib_mem;
long long fib(int n) {
    if (n <= 1) return n;
    auto it = fib_mem.find(n);
    if (it != fib_mem.end()) return it->second;
    return fib_mem[n] = fib(n - 1) + fib(n - 2);
}

long long hanoi_moves(int n) {
    if (n <= 0) return 0;
    return (1LL << n) - 1;
}

int main() {
    assert(factorial(5) == 120);
    fib_mem.clear();
    assert(fib(10) == 55);
    assert(hanoi_moves(3) == 7);
    cout << "recursion OK" << endl;
    return 0;
}
