#pragma once

#include <type_traits>
#include <vector>
#include <thread>
#include <future>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <functional>

class ThreadPool {
public:
    explicit ThreadPool(unsigned thrdNumbers_ = 0);
    ~ThreadPool();

    template<typename F, typename ... Args>
    auto enqueue(F&& func, Args&& ... args ) -> std::future<typename std::result_of<F(Args...)>::type>;

    void do_shutdown(); // gently stop
private:
    void worker();
    unsigned thrdNumbers;
    std::queue<std::function<void()>> jobQueue;
    std::vector<std::thread> workThread;
    std::mutex mtx;
    std::condition_variable cv;
    bool shutdown;
};

