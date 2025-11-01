#!/usr/bin/env python3
"""
Converter script to migrate C++ solutions to Python format

Usage:
    python convert_cpp_to_python.py                    # Convert all files
    python convert_cpp_to_python.py --category arrays  # Convert specific category
"""

import os
import re
from pathlib import Path
from typing import Dict, List, Tuple


# Category mapping from C++ to Python
CATEGORY_MAP = {
    "Array & String": "arrays",
    "BackTracking & DFS & BFS": "backtracking",
    "Binary Search": "binary_search",
    "Design": "design",
    "Divide And Conquer": "divide_conquer",
    "Dynamic_Programming": "dynamic_programming",
    "Greedy": "greedy",
    "HashTable": "hash_table",
    "Intervals": "intervals",
    "LinkedList": "linked_lists",
    "Math & Bit Manipulation": "math_bit",
    "Range Query & Segment Tree": "range_query",
    "SegmentTree": "range_query",
    "SpecialTopics": "special_topics",
    "Stack & Queue & Heap": "stack_queue",
    "Tree": "tree",
    "Trie": "trie",
    "UnionFind": "union_find",
}


def extract_problem_info(cpp_content: str, filename: str) -> Dict[str, str]:
    """Extract problem information from C++ file"""
    lines = cpp_content.split('\n')

    # Extract comments at the beginning
    description_lines = []
    for line in lines[:30]:  # Check first 30 lines
        stripped = line.strip()
        if stripped.startswith('//'):
            description_lines.append(stripped[2:].strip())
        elif stripped.startswith('/*'):
            description_lines.append(stripped[2:].strip())
        elif stripped.startswith('*'):
            description_lines.append(stripped[1:].strip())
        elif stripped and not stripped.startswith('#include'):
            break

    description = '\n'.join(description_lines) if description_lines else "TODO: Add problem description"

    # Extract LC number and name from filename
    lc_match = re.match(r'LC(\d+)_(.+)\.cpp', filename)
    if lc_match:
        lc_number = lc_match.group(1)
        problem_name = lc_match.group(2).replace('_', ' ')
        return {
            'number': lc_number,
            'name': problem_name,
            'description': description,
            'has_lc_number': True
        }
    else:
        # No LC number in filename
        problem_name = filename.replace('.cpp', '').replace('_', ' ')
        return {
            'number': '',
            'name': problem_name,
            'description': description,
            'has_lc_number': False
        }


def generate_python_solution(info: Dict[str, str], filename: str) -> str:
    """Generate Python solution file content"""

    if info['has_lc_number']:
        title = f"Problem: {info['name']}\nDifficulty: [Easy/Medium/Hard]\nSource: LeetCode #{info['number']}"
    else:
        title = f"Problem: {info['name']}\nDifficulty: [Easy/Medium/Hard]\nSource: [TODO: Add source]"

    template = f'''"""
{title}

Description:
{info['description']}

Examples:
[TODO: Add examples]

Constraints:
[TODO: Add constraints]
"""

from typing import List, Optional


class Solution:
    def solve(self, param):
        """
        Approach: [TODO: Describe approach]
        Time Complexity: O(?)
        Space Complexity: O(?)
        """
        # TODO: Implement solution
        pass


# ============= Test Cases =============
def test_solution():
    """Test cases for the solution"""
    sol = Solution()

    # Test case 1
    # assert sol.solve(...) == expected, "Test case 1 failed"

    # Test case 2
    # assert sol.solve(...) == expected, "Test case 2 failed"

    print("✓ All test cases passed!")


if __name__ == "__main__":
    test_solution()
'''
    return template


def convert_file(cpp_file: Path, output_dir: Path) -> None:
    """Convert a single C++ file to Python"""
    try:
        cpp_content = cpp_file.read_text(encoding='utf-8', errors='ignore')
        info = extract_problem_info(cpp_content, cpp_file.name)

        # Generate output filename
        if info['has_lc_number']:
            output_name = f"LC{info['number'].zfill(4)}_{info['name'].replace(' ', '')}.py"
        else:
            output_name = cpp_file.stem + '.py'

        output_file = output_dir / output_name

        # Skip if already exists
        if output_file.exists():
            print(f"⊘ Skipping {output_name} (already exists)")
            return

        python_content = generate_python_solution(info, cpp_file.name)
        output_file.write_text(python_content)
        print(f"✓ Converted {cpp_file.name} → {output_name}")

    except Exception as e:
        print(f"✗ Error converting {cpp_file.name}: {e}")


def main():
    import sys

    base_dir = Path(__file__).parent.parent
    cpp_solutions_dir = base_dir / "C++ Solutions"
    python_solutions_dir = base_dir / "Python Solutions"

    if not cpp_solutions_dir.exists():
        print(f"Error: C++ Solutions directory not found at {cpp_solutions_dir}")
        sys.exit(1)

    # Process each C++ category
    for cpp_category in cpp_solutions_dir.iterdir():
        if not cpp_category.is_dir() or cpp_category.name == "Python Solutions":
            continue

        python_category = CATEGORY_MAP.get(cpp_category.name, "misc")
        python_category_dir = python_solutions_dir / python_category
        python_category_dir.mkdir(exist_ok=True)

        print(f"\n📁 Processing {cpp_category.name} → {python_category}/")
        print("=" * 60)

        cpp_files = list(cpp_category.glob("*.cpp"))
        for cpp_file in sorted(cpp_files):
            convert_file(cpp_file, python_category_dir)

    print("\n" + "=" * 60)
    print("✓ Conversion complete!")
    print("\nNext steps:")
    print("1. Review generated files and fill in TODOs")
    print("2. Implement solutions")
    print("3. Add test cases")
    print("4. Run: python3 test_runner.py")


if __name__ == "__main__":
    main()
