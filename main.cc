#include <iostream>

void test(const int a, const int b, std::unordered_map<int, int> &cache)
{
    const int key = a + b;
    if (cache.find(key) != cache.end()) // since c++20 contains() can be used to perform the same task e.g cache.contains(key)
    {
        std::cout << "returning from cache: " << cache[key] << std::endl;
        return;
    }

    const int result = key;
    std::cout << "executing for the first time: " << result << std::endl;
    cache[key] = result;
}

int main() {
    std::unordered_map<int, int> cache;
    test(2, 2, cache);
    test(2, 2, cache);
    test(3, 1, cache);
    test(3, 7, cache);
    test(5, 5, cache);

    return 0;
}
