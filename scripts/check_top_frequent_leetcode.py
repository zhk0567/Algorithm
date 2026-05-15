#!/usr/bin/env python3
"""Check interview/top_frequent/notes.md links to problems/leetcode/ dirs exist; compare py/cpp index tables."""

from __future__ import annotations

import re
import sys
from pathlib import Path

# ](../../problems/leetcode/0001_two_sum/)
_LEETCODE_LINK = re.compile(
    r"\]\(\.\./\.\./problems/leetcode/([0-9]{4}_[a-z0-9_]+)/\)",
    re.IGNORECASE,
)

# top_frequent 题单版本；扩题时先在 docs/doc-tasks.md 升级目标并改此常量
EXPECTED_SLUG_COUNT = 103


def repo_root() -> Path:
    return Path(__file__).resolve().parent.parent


def extract_slugs(md_text: str) -> list[str]:
    found = _LEETCODE_LINK.findall(md_text)
    return found


def check_slugs_exist(slugs: list[str], repo: Path) -> list[str]:
    errors: list[str] = []
    for slug in sorted(set(slugs)):
        py_dir = repo / "python" / "problems" / "leetcode" / slug
        cpp_dir = repo / "cpp" / "problems" / "leetcode" / slug
        if not py_dir.is_dir():
            errors.append(f"missing python dir: {py_dir.relative_to(repo)}")
        if not cpp_dir.is_dir():
            errors.append(f"missing cpp dir: {cpp_dir.relative_to(repo)}")
    return errors


def main() -> int:
    repo = repo_root()
    py_notes = repo / "python" / "interview" / "top_frequent" / "notes.md"
    cpp_notes = repo / "cpp" / "interview" / "top_frequent" / "notes.md"
    for p in (py_notes, cpp_notes):
        if not p.is_file():
            print(f"ERROR: missing file {p}", file=sys.stderr)
            return 1

    py_text = py_notes.read_text(encoding="utf-8")
    cpp_text = cpp_notes.read_text(encoding="utf-8")
    py_slugs = extract_slugs(py_text)
    cpp_slugs = extract_slugs(cpp_text)

    set_py = set(py_slugs)
    set_cpp = set(cpp_slugs)
    if set_py != set_cpp:
        only_py = sorted(set_py - set_cpp)
        only_cpp = sorted(set_cpp - set_py)
        print("ERROR: slug sets differ between python and cpp top_frequent/notes.md", file=sys.stderr)
        if only_py:
            print(f"  only in python: {only_py}", file=sys.stderr)
        if only_cpp:
            print(f"  only in cpp: {only_cpp}", file=sys.stderr)
        return 1

    dup_py = [s for s in set_py if py_slugs.count(s) > 1]
    if dup_py:
        print(f"ERROR: duplicate slugs in python table: {sorted(dup_py)}", file=sys.stderr)
        return 1

    if len(set_py) != EXPECTED_SLUG_COUNT:
        print(
            f"ERROR: top_frequent v1 expects {EXPECTED_SLUG_COUNT} slugs, got {len(set_py)}. "
            "Update EXPECTED_SLUG_COUNT in this script and doc-tasks.md when bumping the list version.",
            file=sys.stderr,
        )
        return 1

    err = check_slugs_exist(py_slugs, repo)
    if err:
        print("ERROR: missing leetcode directories:", file=sys.stderr)
        for e in err:
            print(f"  {e}", file=sys.stderr)
        return 1

    print(f"check_top_frequent_leetcode OK ({len(set_py)} slugs, python/cpp tables match)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
