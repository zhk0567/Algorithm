# LeetCode 175 — Combine Two Tables（组合两个表）

> **SQL only** — 本题在 LeetCode 上仅以 SQL 形式提交，故仅提供 `solution.sql`，无 Python / C++ 实现。

## 题面

- **来源**：LeetCode 175
- **链接**：<https://leetcode.cn/problems/combine-two-tables/>
- **简述**：联表查询，无论 `Address` 表中是否有对应行，都需返回 `Person` 中每个人。

## 思路

`LEFT JOIN`：以 `Person` 为左表，按 `personId` 关联 `Address`。

```sql
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a ON p.personId = a.personId;
```
