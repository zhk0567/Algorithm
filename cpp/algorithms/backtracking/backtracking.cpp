#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> nums) {
    vector<vector<int>> out;
    vector<int> path;
    function<void(int)> dfs = [&](int i) {
        if (i == (int)nums.size()) {
            out.push_back(path);
            return;
        }
        dfs(i + 1);
        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
    };
    dfs(0);
    return out;
}

vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> out;
    vector<int> path;
    function<void(int)> dfs = [&](int start) {
        if ((int)path.size() == k) {
            out.push_back(path);
            return;
        }
        for (int x = start; x <= n; ++x) {
            path.push_back(x);
            dfs(x + 1);
            path.pop_back();
        }
    };
    dfs(1);
    return out;
}

vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> out;
    vector<int> path;
    vector<char> used(nums.size(), 0);
    function<void()> dfs = [&]() {
        if ((int)path.size() == (int)nums.size()) {
            out.push_back(path);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = 1;
            path.push_back(nums[i]);
            dfs();
            path.pop_back();
            used[i] = 0;
        }
    };
    dfs();
    return out;
}

int n_queens(int n) {
    unordered_set<int> cols, d1, d2;
    int ans = 0;
    function<void(int)> dfs = [&](int r) {
        if (r == n) {
            ++ans;
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (cols.count(c) || d1.count(r - c) || d2.count(r + c)) continue;
            cols.insert(c);
            d1.insert(r - c);
            d2.insert(r + c);
            dfs(r + 1);
            cols.erase(c);
            d1.erase(r - c);
            d2.erase(r + c);
        }
    };
    dfs(0);
    return ans;
}

int main() {
    auto s = subsets({1, 2});
    assert(s.size() == 4);
    auto c = combinations(4, 2);
    assert(c.size() == 6);
    auto p = permute({1, 2, 3});
    assert(p.size() == 6);
    assert(n_queens(4) == 2);
    cout << "backtracking OK" << endl;
    return 0;
}
