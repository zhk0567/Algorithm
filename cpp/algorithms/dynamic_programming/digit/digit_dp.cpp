#include <alg_std.hpp>
#include <cassert>
using namespace std;

int K;
string s;
int memo[25][2][10][2];

int dfs(int i, bool tight, int mod, int z) {
    if (i == (int)s.size()) return mod == 0 ? 1 : 0;
    int& mem = memo[i][tight][mod][z];
    if (mem != -1) return mem;
    int lim = tight ? s[i] - '0' : 9;
    int tot = 0;
    for (int d = 0; d <= lim; ++d) {
        bool ntight = tight && (d == lim);
        bool nz = z && (d == 0);
        int nmod = nz ? mod : (mod + d) % K;
        tot += dfs(i + 1, ntight, nmod, nz);
    }
    return mem = tot;
}

int count_digit_sum_mod0(long long n, int k) {
    if (k <= 0) throw runtime_error("k must be positive");
    if (n < 0) return 0;
    K = k;
    s = to_string(n);
    memset(memo, -1, sizeof(memo));
    return dfs(0, true, 0, true);
}

int brute(long long nn, int k) {
    int c = 0;
    for (long long x = 0; x <= nn; ++x) {
        int sm = 0;
        for (char ch : to_string(x)) sm += ch - '0';
        if (sm % k == 0) ++c;
    }
    return c;
}

int main() {
    int k = 3;
    for (long long nn = 0; nn < 500; ++nn) assert(count_digit_sum_mod0(nn, k) == brute(nn, k));
    try {
        count_digit_sum_mod0(10, 0);
        assert(false);
    } catch (const runtime_error&) {
    }
    cout << "digit_dp OK" << endl;
    return 0;
}
