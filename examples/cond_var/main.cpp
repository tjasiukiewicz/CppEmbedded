#include <iostream>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <chrono>

std::queue<int> que;
std::mutex mtx;
std::condition_variable cv;

void reader() {
	for (auto i = 0U; i < 5; ++i) {
		std::unique_lock<std::mutex> lk(mtx);
		cv.wait(lk, []{ return !que.empty(); });
		int value = que.front();
		que.pop();
		std::cout << value << std::endl;
	}
}

void writer() {
	for (auto i = 0U; i < 10; ++i) {
		{
			std::lock_guard<std::mutex> lk(mtx);
			que.emplace(i);
		}
		cv.notify_one();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main() {
	auto t1 = std::thread(writer);
	auto t2 = std::thread(reader);
	auto t3 = std::thread(reader);

	t3.join();
	t2.join();
	t1.join();
}
