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

int main() {
	auto s_p1 = std::make_shared<Person>("Adam");
	auto s_p2 = std::make_shared<Person>("Ewa");

	std::cout << "Before action...\n";
	{
		std::shared_ptr<Person> s_p3;
		std::shared_ptr<Person> s_p4;
		s_p3 = s_p2;
		std::cout << s_p3.use_count() << '\n';
		s_p4 = std::move(s_p1);
		std::cout << s_p1.use_count() << '\n';

	}
	std::cout << s_p2.use_count() << '\n';
	std::cout << "After action...\n";

	std::cout << "End main...\n";
}
