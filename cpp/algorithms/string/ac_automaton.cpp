// Aho–Corasick 自动机（多模式匹配）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct ACAutomaton {
    struct Node {
        array<int, 26> next{};
        int fail = 0;
        vector<pair<int, int>> out;  // (pattern_id, length)
        Node() { next.fill(-1); }
    };
    vector<Node> nodes{Node()};

    int idx(char c) { return c - 'a'; }

    void add(const string& pat, int pid) {
        if (pat.empty()) throw runtime_error("empty pattern not supported");
        int u = 0;
        for (char c : pat) {
            int id = idx(c);
            if (nodes[u].next[id] == -1) {
                nodes[u].next[id] = (int)nodes.size();
                nodes.emplace_back();
            }
            u = nodes[u].next[id];
        }
        nodes[u].out.emplace_back(pid, (int)pat.size());
    }

    void build() {
        queue<int> q;
        for (int c = 0; c < 26; ++c) {
            int v = nodes[0].next[c];
            if (v != -1) {
                nodes[v].fail = 0;
                q.push(v);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int c = 0; c < 26; ++c) {
                int v = nodes[u].next[c];
                if (v == -1) continue;
                q.push(v);
                int f = nodes[u].fail;
                while (f && nodes[f].next[c] == -1) f = nodes[f].fail;
                nodes[v].fail = nodes[f].next[c] == -1 ? 0 : nodes[f].next[c];
                auto& ov = nodes[v].out;
                auto& of = nodes[nodes[v].fail].out;
                ov.insert(ov.end(), of.begin(), of.end());
            }
        }
    }

    vector<array<int, 3>> find_all(const string& text) {
        vector<array<int, 3>> res;
        int state = 0;
        for (int i = 0; i < (int)text.size(); ++i) {
            int c = idx(text[i]);
            while (state && nodes[state].next[c] == -1) state = nodes[state].fail;
            if (nodes[state].next[c] != -1) state = nodes[state].next[c];
            for (auto [pid, ln] : nodes[state].out) {
                res.push_back({i - ln + 1, pid, ln});
            }
        }
        return res;
    }
};

int main() {
    vector<string> pats{"he", "she", "his", "hers"};
    ACAutomaton ac;
    for (int i = 0; i < (int)pats.size(); ++i) ac.add(pats[i], i);
    ac.build();
    auto hits = ac.find_all("ushers");
    vector<pair<int, int>> got, want{{1, 1}, {2, 0}, {2, 3}};
    for (auto& h : hits) got.push_back({h[0], h[1]});
    sort(got.begin(), got.end());
    sort(want.begin(), want.end());
    assert(got == want);
    try {
        ac.add("", 0);
        assert(false);
    } catch (const runtime_error&) {
    }
    cout << "ac_automaton OK" << endl;
    return 0;
}
