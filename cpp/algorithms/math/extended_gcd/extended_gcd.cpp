// 扩展欧几里得：模逆与线性同余
#include <alg_std.hpp>
#include <cassert>
using namespace std;

tuple<long long, long long, long long> extgcd(long long a, long long b) {
    if (!b) {
        long long s = a >= 0 ? 1 : -1;
        return {abs(a), s, 0};
    }
    auto [g, x1, y1] = extgcd(b, a % b);
    return {g, y1, x1 - (a / b) * y1};
}

optional<long long> modInverse(long long a, long long mod) {
    auto [g, x, y] = extgcd(a % mod, mod);
  (void)y;
    if (g != 1) return nullopt;
    return (x % mod + mod) % mod;
}

optional<pair<long long, long long>> solveLinearCongruence(long long a, long long b, long long m) {
    auto [g, x0, y] = extgcd(a % m, m);
  (void)y;
    if (b % g != 0) return nullopt;
    long long modM = m / g;
    x0 = ((__int128)x0 * (b / g)) % modM;
    if (x0 < 0) x0 += modM;
    return make_pair(x0, modM);
}

int main() {
    auto [g, x, y] = extgcd(35LL, 15LL);
    assert(g == 5 && 35 * x + 15 * y == 5);

    assert(modInverse(3, 11) == 4);
    assert(!modInverse(4, 6).has_value());

    auto sol = solveLinearCongruence(3, 2, 7);
    assert(sol.has_value());
    auto [x0, period] = *sol;
    assert((3 * x0 - 2) % 7 == 0);
    cout << "extended_gcd OK" << endl;
    return 0;
}
