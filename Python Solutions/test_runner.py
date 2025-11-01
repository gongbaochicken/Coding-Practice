#!/usr/bin/env python3
"""
Test Runner Utility for Python Interview Solutions

Usage:
    python test_runner.py                    # Run all tests in all categories
    python test_runner.py arrays             # Run all tests in arrays category
    python test_runner.py arrays/two_sum.py  # Run specific solution file
"""

import sys
import os
import importlib.util
from pathlib import Path


def is_not_implemented(file_path: Path) -> bool:
    """Check if a solution file is not implemented (only has pass or placeholder)"""
    try:
        import re
        content = file_path.read_text()

        # Find the Solution class
        class_match = re.search(r'class Solution:.*?(?=\nclass |\n\n#|\Z)', content, re.DOTALL)
        if not class_match:
            return True

        class_body = class_match.group(0)

        # Remove all docstrings first (both triple-quoted strings)
        class_body = re.sub(r'"""[^"]*"""', '', class_body, flags=re.DOTALL)
        class_body = re.sub(r"'''[^']*'''", '', class_body, flags=re.DOTALL)

        # Remove all comments
        class_body = re.sub(r'#.*', '', class_body)

        # Now check if there's any actual code besides 'pass'
        lines = class_body.split('\n')
        for line in lines:
            stripped = line.strip()
            # Skip empty lines, class definition, method definitions, and 'pass'
            if not stripped:
                continue
            if stripped.startswith('class '):
                continue
            if stripped.startswith('def '):
                continue
            if stripped == 'pass':
                continue

            # If we find any other line, it's implemented
            return False

        return True
    except:
        return False


def run_file(file_path: Path) -> tuple[str, str]:
    """Run a single Python file and capture results
    Returns: (status, message) where status is 'passed', 'failed', or 'skipped'
    """
    # Check if not implemented
    if is_not_implemented(file_path):
        return 'skipped', f"⊘ {file_path.relative_to(Path.cwd())}"

    try:
        spec = importlib.util.spec_from_file_location("module", file_path)
        if spec is None or spec.loader is None:
            return 'failed', f"Failed to load {file_path}"

        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)

        if hasattr(module, 'test_solution'):
            module.test_solution()
            return 'passed', f"✓ {file_path.relative_to(Path.cwd())}"
        else:
            return 'failed', f"⚠ {file_path.relative_to(Path.cwd())} - No test_solution() found"

    except AssertionError as e:
        return 'failed', f"✗ {file_path.relative_to(Path.cwd())} - {str(e)}"
    except Exception as e:
        return 'failed', f"✗ {file_path.relative_to(Path.cwd())} - {type(e).__name__}: {str(e)}"


def find_python_files(path: Path) -> list[Path]:
    """Find all Python files in a directory (excluding test_runner and templates)"""
    if path.is_file() and path.suffix == '.py':
        return [path]

    files = []
    for py_file in path.rglob('*.py'):
        if py_file.name not in ['test_runner.py', 'solution_template.py', '__init__.py']:
            files.append(py_file)
    return sorted(files)


def main():
    base_path = Path(__file__).parent

    if len(sys.argv) > 1:
        target = base_path / sys.argv[1]
        if not target.exists():
            print(f"Error: {target} does not exist")
            sys.exit(1)
    else:
        target = base_path

    files = find_python_files(target)

    if not files:
        print(f"No Python solution files found in {target}")
        sys.exit(0)

    print(f"Running tests from: {target.relative_to(Path.cwd())}")
    print("=" * 60)

    passed = 0
    failed = 0
    skipped = 0
    results = []

    for file_path in files:
        status, message = run_file(file_path)
        results.append(message)
        if status == 'passed':
            passed += 1
        elif status == 'skipped':
            skipped += 1
        else:
            failed += 1

    # Print results
    for result in results:
        print(result)

    print("=" * 60)
    total = passed + failed + skipped
    print(f"Results: {passed} passed, {failed} failed, {skipped} skipped, {total} total")

    sys.exit(0 if failed == 0 else 1)


if __name__ == "__main__":
    main()
