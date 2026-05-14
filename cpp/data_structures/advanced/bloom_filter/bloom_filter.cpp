#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct BloomFilter {
    int m, k;
    vector<uint64_t> words;
    BloomFilter(int m_bits, int k_) : m(max(64, m_bits)), k(k_), words((m + 63) / 64, 0) {}

    void set_bit(int i) { words[i >> 6] |= 1ULL << (i & 63); }

    bool get_bit(int i) const { return (words[i >> 6] >> (i & 63)) & 1ULL; }

    static uint32_t h(const string& s, int seed) {
        uint32_t x = 2166136261u ^ (uint32_t)(seed * 0x9E3779B9u);
        for (unsigned char c : s) {
            x = (x * 16777619u) ^ c;
        }
        return x;
    }

    void add(const string& s) {
        for (int i = 0; i < k; ++i) {
            int idx = (int)(h(s, i) % (uint32_t)m);
            set_bit(idx);
        }
    }

    bool possibly_contains(const string& s) const {
        for (int i = 0; i < k; ++i) {
            int idx = (int)(h(s, i) % (uint32_t)m);
            if (!get_bit(idx)) return false;
        }
        return true;
    }
};

int main() {
    BloomFilter bf(256, 5);
    bf.add("hello");
    assert(bf.possibly_contains("hello"));
    assert(!bf.possibly_contains("not-inserted-xyz-12345"));
    cout << "BloomFilter OK" << endl;
    return 0;
}
