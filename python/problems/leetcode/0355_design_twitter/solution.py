"""LeetCode 355: Design Twitter."""

from __future__ import annotations

import heapq
from collections import defaultdict


class Twitter:
    def __init__(self) -> None:
        self._time = 0
        self._tweets: dict[int, list[tuple[int, int]]] = defaultdict(list)
        self._follows: dict[int, set[int]] = defaultdict(set)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self._time += 1
        self._tweets[userId].append((self._time, tweetId))

    def getNewsFeed(self, userId: int) -> list[int]:
        users = self._follows[userId] | {userId}
        heap: list[tuple[int, int, int]] = []
        for u in users:
            if self._tweets[u]:
                t, tid = self._tweets[u][-1]
                heapq.heappush(heap, (-t, u, len(self._tweets[u]) - 1))
        res: list[int] = []
        while heap and len(res) < 10:
            negt, u, idx = heapq.heappop(heap)
            res.append(self._tweets[u][idx][1])
            if idx > 0:
                t2, _ = self._tweets[u][idx - 1]
                heapq.heappush(heap, (-t2, u, idx - 1))
        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self._follows[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self._follows[followerId].discard(followeeId)


if __name__ == "__main__":
    tw = Twitter()
    tw.postTweet(1, 5)
    assert tw.getNewsFeed(1) == [5]
    tw.postTweet(1, 3)
    assert tw.getNewsFeed(1) == [3, 5]
    tw.follow(1, 2)
    tw.postTweet(2, 6)
    assert tw.getNewsFeed(1) == [6, 3, 5]
    tw.unfollow(1, 2)
    assert tw.getNewsFeed(1) == [3, 5]
    print("0355 OK")
