#include <iostream>
#include <optional>

std::optional<int> calc(int a, int b) {
	if (b == 0) {
		return {};
	}
	return std::make_optional<int>(a / b);
}

int main() {
	auto result = calc(10, 2);
	if (result.has_value()) {
		std::cout << "result = " << result.value() << '\n';
	} else {
		std::cout << "result unknown!\n";
	}
	std::cout << result.value_or(0) << '\n';
}
