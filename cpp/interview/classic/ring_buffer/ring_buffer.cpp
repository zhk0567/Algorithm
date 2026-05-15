// 定长环形缓冲区（int 示例，可模板化）
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class RingBuffer {
public:
    explicit RingBuffer(size_t cap) : cap_(cap), buf_(cap), head_(0), tail_(0), size_(0) {
        if (cap == 0) throw invalid_argument("cap>=1");
    }

    bool empty() const { return size_ == 0; }
    bool full() const { return size_ == cap_; }

    void push(int x) {
        if (full()) throw runtime_error("full");
        buf_[tail_] = x;
        tail_ = (tail_ + 1) % cap_;
        ++size_;
    }

    int pop() {
        if (empty()) throw runtime_error("empty");
        int v = buf_[head_];
        head_ = (head_ + 1) % cap_;
        --size_;
        return v;
    }

private:
    size_t cap_;
    vector<int> buf_;
    size_t head_, tail_, size_;
};

int main() {
    RingBuffer rb(3);
    rb.push(1);
    rb.push(2);
    assert(rb.pop() == 1);
    rb.push(3);
    rb.push(4);
    assert(rb.pop() == 2);
    assert(rb.pop() == 3);
    assert(rb.pop() == 4);
    assert(rb.empty());
    try {
        rb.pop();
    } catch (const runtime_error&) {
    } catch (...) {
        assert(false);
    }
    rb.push(10);
    assert(rb.pop() == 10);
    cout << "ring_buffer OK" << endl;
    return 0;
}
