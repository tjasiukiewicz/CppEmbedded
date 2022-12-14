#include <iostream>
#include <thread>
#include <future>

int main() {
	std::packaged_task<int(int)> pt1{[](int a) { return a * 120; }};
	auto f1 = pt1.get_future();
	//auto f2 = std::async(std::move(pt1), 12);
	//auto t1 = std::jthread(std::move(pt1), 100);
	pt1(12);
	std::cout << f1.get() << '\n';
	pt1.reset();
	f1 = pt1.get_future();
	pt1(100);
	std::cout << f1.get() << '\n';
}
