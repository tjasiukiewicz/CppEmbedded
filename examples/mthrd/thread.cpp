#include <thread>
#include <iostream>

void worker(int value) {
	std::cout << "I'm worker() value= " << value << '\n';
}

struct X {
	void operator()(int value) {
		std::cout << "I'm X::operator(" << value << ")\n";
	}
	void run(int value) {
		std::cout << "I'm X::run(" << value << ")\n";
	}
};

void runner(int& value) {
	std::cout << "I'm runner(" << value << ")\n";
	++value;
}

int main() {
	X x;
	int value = 10;
	auto t1 = std::thread(worker, 42);
	auto t2 = std::thread([](int a){ std::cout << "a=" << a << '\n'; }, 34);
	auto t3 = std::thread(x, 54);
	auto t4 = std::thread(&X::run, &x, 84);
	auto t5 = std::thread(runner, std::ref(value));
	std::thread t6;
	t6 = std::move(t5);

	for (auto & t: {&t6, &t5, &t4, &t3, &t2, &t1}) {
		if (t->joinable()) {
			t->join();
		}
	}
}
