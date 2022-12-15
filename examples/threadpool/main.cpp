#include "thread_pool.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <mutex>
#include <vector>
#include <future>

std::mutex ioMtx;

int foo(int val) {
    for(auto i = 0U; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lk(ioMtx);
        std::cout << "foo() val = " << val << '\n';
    }
    return val * 12;
}

int bar(int val) {
    for(auto i = 0U; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::lock_guard<std::mutex> lk(ioMtx);
        std::cout << "bar() val = " << val << '\n';
    }
    return (val * 10) / 2;
}

int zoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "zoo()\n";
    return 4789;
}

template<typename T>
void showResults(std::vector<T>& vec) {
    std::cout << "Results:\n";
    std::transform(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "),
        [](T& ftr){ return ftr.get(); });
    std::cout << '\n';
}

int main() {
    std::vector<std::future<int>> results;
    {
        ThreadPool pool(8);
        results.reserve(10);

        for(auto i = 0; i < 5; ++i) {
            results.emplace_back(pool.enqueue(foo, i + 10));
        }

        for(auto i = 0; i < 5; ++i) {
            results.emplace_back(pool.enqueue(zoo));
        }
        pool.do_shutdown();
    }

    showResults(results);
    std::cout << "Result size = " << results.size() << '\n';
}
