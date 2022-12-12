#include <iostream>
#include <string>
#include <cassert>

class Person {
public:
	Person(const std::string& name_, unsigned age_)
		: name{new std::string(name_)}, age{age_} {
		std::cout << "Person construct name=" << *name << '\n';
	}
	~Person() {
		std::cout << "Person destruct name=";
		if (name != nullptr) {
			std::cout << *name << '\n';
		} else {
			std::cout << "nullptr\n";
		}
		delete name;
	}
	// noncopyable
	Person(const Person&) = delete;
	Person& operator=(const Person&) = delete;
	// move sem.
	Person(Person&& other_person) {
		if (other_person.name == nullptr) {
			std::cout << "NULLPTR!!!!\n";
			exit(1);
		}
		this->name = other_person.name;
		other_person.name = nullptr;
		this->age = other_person.age;
		other_person.age = 0;
		std::cout << "Person move construct name=" << *name << '\n';
	}
	Person& operator=(Person&& other_person) {
		if (other_person.name == nullptr) {
			std::cout << "NULLPTR!!!!\n";
			exit(1);
		}
		this->name = other_person.name;
		other_person.name = nullptr;
		this->age = other_person.age;
		other_person.age = 0;
		std::cout << "Person move operator=() name=" << *name << '\n';
		return *this;
	}

	const std::string& get_name() const {
		assert(name != nullptr);
		return *name;
	}

	const unsigned get_age() const {
		return age;
	}
private:
	std::string * name;
	unsigned age;
};

void show(Person&& person) {
	std::cout << person.get_name() << '\n';
	//std::cout << "In show()\n";
}

int main() {
	Person person{"Adam Jajczarski", 32};
	Person person2 = std::move(person);
	show(std::move(person2));
	// To jest "niefajne" :) !!
	//std::cout << person.get_name() << '\n';
}
