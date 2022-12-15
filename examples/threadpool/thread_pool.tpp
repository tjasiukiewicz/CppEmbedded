template std::future<int> ThreadPool::enqueue(int(&)(int), int&&);
template std::future<int> ThreadPool::enqueue(int(&)());
