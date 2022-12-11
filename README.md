# better_sort

better_sort is a lightweight header only library designed for fast and lightweight bogo sorting. It supports any container with iterators and the comparison function can be overloaded. Usage is much like std::sort, except for being better. Supports C++11 and up, tested and working on MSVC.

Example usage:
```cpp
std::vector<int> list = { 3, 17, 0, 420, 69, 15, 999, 1 };

int main() {
    bsort::bogo_sort(list.begin(), list.end(), [](int a1, int a2) { return a1 > a2; });

    for (const auto& it : list)
        std::cout << it << "\n";

    return 0;
}
```

Outputs:
```cpp
999
420
69
17
15
3
1
0
```
