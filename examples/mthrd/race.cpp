#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

int counter = 65535;
std::mutex lk;

void worker(int delta) {
	for (auto i = 0U; i < 100; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		{
			std::lock_guard<std::mutex> _(lk);
			//lk.lock();
			counter += delta;
			//lk.unlock();
		}
		// ....
	}
}

int main() {
	auto t1 = std::thread(worker, 1);
	auto t2 = std::thread(worker, -1);

	t2.join();
	t1.join();
	std::cout << "counter=" << counter << '\n';
}
