#include <iostream>
#include <future>
#include <iomanip>

int main() { 
	std::future<int> f1 = std::async([](int a) { std::cout << "a=" << a << '\n'; return ++a; }, 42);
	//std::cout << "result=" << f1.get() << '\n';

	f1 =  std::async(std::launch::async, [](int a) { std::cout << "a=" << a << '\n'; return 2 * a; }, f1.get());
	std::cout << std::boolalpha << f1.valid() << '\n';
	std::cout << "result=" << f1.get() << '\n';
}
