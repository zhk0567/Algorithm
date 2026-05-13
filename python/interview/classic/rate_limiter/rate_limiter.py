"""令牌桶限流器。"""

from __future__ import annotations

import threading
import time
from typing import Optional


class TokenBucket:
    def __init__(self, rate: float, capacity: float) -> None:
        if rate <= 0 or capacity <= 0:
            raise ValueError("rate and capacity must be positive")
        self._rate = float(rate)
        self._cap = float(capacity)
        self._tokens = float(capacity)
        self._last = time.monotonic()
        self._lock = threading.Lock()

    def _refill(self) -> None:
        now = time.monotonic()
        elapsed = now - self._last
        if elapsed > 0:
            self._tokens = min(self._cap, self._tokens + elapsed * self._rate)
            self._last = now

    def try_acquire(self, n: float = 1.0) -> bool:
        with self._lock:
            self._refill()
            if self._tokens >= n:
                self._tokens -= n
                return True
            return False

    def acquire(self, n: float = 1.0, timeout: Optional[float] = None) -> bool:
        if n > self._cap:
            raise ValueError("n exceeds capacity")
        deadline = None if timeout is None else time.monotonic() + timeout
        while True:
            with self._lock:
                self._refill()
                if self._tokens >= n:
                    self._tokens -= n
                    return True
                missing = n - self._tokens
                wait = missing / self._rate
            if deadline is not None:
                remain = deadline - time.monotonic()
                if remain <= 0:
                    return False
                wait = min(wait, remain)
            time.sleep(wait)


if __name__ == "__main__":
    bucket = TokenBucket(rate=5.0, capacity=5.0)
    start = time.monotonic()
    granted = 0
    for _ in range(12):
        if bucket.try_acquire():
            granted += 1
        time.sleep(0.09)
    dur = time.monotonic() - start
    # 初始 5 个 + 速率 5/s * 时间
    upper = 5 + 5.0 * dur + 1  # 容差 1
    lower = 5  # 初始至少能拿走 5 个
    assert lower <= granted <= upper, (granted, lower, upper, dur)

    # acquire 带超时阻塞：清空后等下一令牌
    drain = TokenBucket(rate=10.0, capacity=2.0)
    assert drain.try_acquire(2)
    t0 = time.monotonic()
    assert drain.acquire(1, timeout=1.0)
    assert (time.monotonic() - t0) >= 0.05  # 至少等到下一令牌
    print("rate_limiter OK")
