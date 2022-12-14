#include <condition_variable>
#include <mutex>
#include <iostream>
#include <queue>
#include <chrono>
#include <optional>

struct QueueMthrd {
	QueueMthrd()
		: stop{false} {}

	~QueueMthrd() {
		halt();
	}
	[[nodiscard]] bool push(int value) {
		std::lock_guard<std::mutex> _(mtx);
		if(stop) {
			return false;
		}
		que.emplace(value);
		cv.notify_one();
		return true;
	}
	/*
	bool pop(int& data) {
	}
	*/
	std::optional<int> pop() {
		std::unique_lock<std::mutex> lk(mtx);
		cv.wait(lk, [this]{ return (!que.empty()) || stop; });
		if (stop) {
			return {};
		}
		int value = que.front();
		que.pop();
		return {value};
	}

	std::optional<int> immediate_pop() {
		int value; 
		if (mtx.try_lock() && (!que.empty())) {
			value = que.front();
			que.pop();
			mtx.unlock();
			return {value};
		}
		return {};
	}

	void halt() {
		std::lock_guard<std::mutex> _(mtx);
		stop = true;
		cv.notify_all();
	}
private:
	std::queue<int> que;
	std::mutex mtx;
	std::condition_variable cv;
	bool stop;
};

void writer(QueueMthrd& que) {
	for (auto i = 0U; i < 10; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		if(!que.push(i)) {
			std::cout << "Write ERROR!" << std::endl;
		}
	}
}

void reader(QueueMthrd& que) {
	for (auto i = 0U; i < 5; ++i) {
		auto op = que.pop();
		if (op) {
			std::cout << *op << '\n';
		} else {
			std::cout << "!\n";
		}
	}
}

int main() {
	QueueMthrd que;
	auto t1 = std::thread(writer, std::ref(que));
	auto t2 = std::thread(reader, std::ref(que));
	auto t3 = std::thread(reader, std::ref(que));

	std::this_thread::sleep_for(std::chrono::milliseconds(70));
	que.halt();

	t3.join();
	t2.join();
	t1.join();
}
