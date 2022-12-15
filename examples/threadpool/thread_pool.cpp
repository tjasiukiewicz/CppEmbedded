#include "thread_pool.hpp"
#include <memory>
#include <stdexcept>

ThreadPool::ThreadPool(unsigned thrdNumbers_)
    : thrdNumbers{thrdNumbers_}, jobQueue{},
      workThread{}, mtx{}, cv{},
      shutdown{false} {
    if (thrdNumbers == 0) {
        thrdNumbers = std::thread::hardware_concurrency();
        thrdNumbers = (thrdNumbers == 0 ? 2: thrdNumbers);
    }

    workThread.reserve(thrdNumbers);
    while(thrdNumbers--) {
        workThread.emplace_back(&ThreadPool::worker, this);
    }
}

ThreadPool::~ThreadPool() {
    do_shutdown();
    for(auto& thrd: workThread) {
        thrd.join();
    }
}


void ThreadPool::do_shutdown() {
    {
        std::lock_guard<std::mutex> lk(mtx);
        shutdown = true;
    }
    cv.notify_all();
}

void ThreadPool::worker() {
    for(;;) {
        decltype(jobQueue)::value_type task;
        {
            std::unique_lock<std::mutex> lk(mtx);
            cv.wait(lk, [this] { return shutdown || (!jobQueue.empty());});
            if(shutdown && jobQueue.empty()) {
                break;
            }
            task = std::move(jobQueue.front());
            jobQueue.pop();
        }
        task();
    }
}

template<typename F, typename... Args>
auto ThreadPool::enqueue(F&& func, Args&& ... args ) -> std::future<typename std::result_of<F(Args...)>::type> {

    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(func), std::forward<Args>(args)...));

    std::future<return_type> result = task->get_future();

    {
        std::lock_guard<std::mutex> lk(mtx);
        if(shutdown) {
            throw std::runtime_error("enqueue on stopped ThreadPool");
        }
        jobQueue.emplace([task] { (*task)(); });
    }
    cv.notify_one();
    return result;
}

#include "thread_pool.tpp"
