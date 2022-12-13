#include <memory>
#include <iostream>
#include <string>

class Person {
public:
	Person(const std::string& name_)
		: name{name_} {
		std::cout << "Person construct name=" << name << '\n';
	}
	~Person() {
		std::cout << "Person destruct name=" << name << '\n';
	}

	const std::string& get_name() const {
		return name;
	}
private:
	const std::string name;
};

void consume(std::unique_ptr<Person> uptr) {
	std::cout << "Before consume...\n";
	std::cout << uptr->get_name() << '\n';
	std::cout << "After consume...\n";
}

int main() {
	auto u_p1 = std::make_unique<Person>("Adam");
	auto u_p2 = std::make_unique<Person>("Ewa");
	std::cout << "Before action...\n";
	{
		std::unique_ptr<Person> u_p3;
		u_p3 = std::move(u_p2);
		consume(std::move(u_p3));
	}
	std::cout << "After action...\n";

	std::cout << "End main...\n";
}
