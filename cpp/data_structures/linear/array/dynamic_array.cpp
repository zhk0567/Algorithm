// 手写动态数组（封装 vector + 显式扩容演示）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class DynamicArray {
    vector<int> data_;
    size_t cap_;

    void ensure_extra(size_t extra) {
        if (data_.size() + extra > cap_) {
            cap_ = max(cap_ * 2, data_.size() + extra);
            data_.reserve(cap_);
        }
    }

public:
    explicit DynamicArray(size_t initial_capacity = 4) : cap_(max<size_t>(1, initial_capacity)) {
        data_.reserve(cap_);
    }

    size_t size() const { return data_.size(); }
    size_t capacity() const { return cap_; }

    int at(size_t index) const {
        if (index >= data_.size()) throw out_of_range("at");
        return data_[index];
    }

    void push_back(int v) {
        ensure_extra(1);
        data_.push_back(v);
    }

    int pop_back() {
        if (data_.empty()) throw underflow_error("pop_back");
        int v = data_.back();
        data_.pop_back();
        return v;
    }

    void insert(size_t index, int v) {
        if (index > data_.size()) throw out_of_range("insert");
        ensure_extra(1);
        data_.insert(data_.begin() + (ptrdiff_t)index, v);
    }

    void erase(size_t index) {
        if (index >= data_.size()) throw out_of_range("erase");
        data_.erase(data_.begin() + (ptrdiff_t)index);
    }
};

int main() {
    DynamicArray a(2);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    assert(a.size() == 3 && a.at(2) == 3);
    a.insert(1, 99);
    assert(a.at(1) == 99);
    a.erase(1);
    assert(a.at(1) == 2);
    assert(a.pop_back() == 3);
    assert(a.size() == 2);
    cout << "DynamicArray OK" << endl;
    return 0;
}
