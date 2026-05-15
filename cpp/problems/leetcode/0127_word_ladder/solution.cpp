// LeetCode 127: Word Ladder
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> seen = {beginWord};
        while (!q.empty()) {
            auto [w, depth] = q.front();
            q.pop();
            if (w == endWord) return depth;
            for (int i = 0; i < (int)w.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    string nw = w;
                    nw[i] = c;
                    if (words.count(nw) && !seen.count(nw)) {
                        seen.insert(nw);
                        q.push({nw, depth + 1});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    vector<string> wl{"hot", "dot", "dog", "lot", "log", "cog"};
    assert(Solution().ladderLength("hit", "cog", wl) == 5);
    vector<string> wl2{"hot", "dot", "dog"};
    assert(Solution().ladderLength("hit", "cog", wl2) == 0);
    vector<string> wl3{"a", "b", "c"};
    assert(Solution().ladderLength("a", "c", wl3) == 2);
    cout << "0127 OK" << endl;
    return 0;
}
