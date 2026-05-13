"""布隆过滤器：字符串集合，k 次哈希。"""

from __future__ import annotations


class BloomFilter:
    def __init__(self, m_bits: int, k: int) -> None:
        if m_bits < 8:
            m_bits = 8
        self._m = m_bits
        self._k = k
        self._buf = bytearray((m_bits + 7) // 8)

    def _set_bit(self, i: int) -> None:
        self._buf[i >> 3] |= 1 << (i & 7)

    def _get_bit(self, i: int) -> bool:
        return ((self._buf[i >> 3] >> (i & 7)) & 1) == 1

    @staticmethod
    def _hash(s: str, seed: int) -> int:
        h = 2166136261 ^ (seed * 0x9E3779B9)
        for c in s:
            h = (h * 16777619) ^ ord(c)
            h &= 0xFFFFFFFF
        return h

    def add(self, s: str) -> None:
        for i in range(self._k):
            idx = self._hash(s, i) % self._m
            self._set_bit(idx)

    def possibly_contains(self, s: str) -> bool:
        for i in range(self._k):
            idx = self._hash(s, i) % self._m
            if not self._get_bit(idx):
                return False
        return True


if __name__ == "__main__":
    bf = BloomFilter(256, 5)
    bf.add("hello")
    assert bf.possibly_contains("hello")
    # 误判概率存在，但随机串大概率 false
    assert not bf.possibly_contains("not-inserted-xyz-12345")
    print("BloomFilter OK")
