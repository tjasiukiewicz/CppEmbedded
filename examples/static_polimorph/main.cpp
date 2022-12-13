#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
class Instances {
protected:
	Instances() {
		Instances::instances.emplace_back(static_cast<T*>(this));
		(static_cast<T*>(this))->cyk();
	}
	~Instances() {
		auto & inst = Instances::instances;
		inst.erase(std::remove(inst.begin(), inst.end(), this), inst.end());
	}
public:
	static std::vector<T*> get_instances() {
		
		return Instances::instances;
	}
	void run() const {
		std::cout << "RUN Forest :)\n";
	}
private:
	static std::vector<T*> instances;
};

template<typename T>
std::vector<T*> Instances<T>::instances;


class Airplane: public Instances<Airplane> {
//template<typename ... Politics>
//class Airplane: public Politics... {
public:
	Airplane(const std::string& name_)
		: name{name_} {
	}
	const std::string& get_name() const {
		run();
		return name;
	}
	void cyk() {
		std::cout << "No to cyk!\n";
	}

private:
	const std::string name;
};

int main() {
	auto a1 = Airplane("F35");
	auto a2 = Airplane("F16");
	auto a3 = Airplane("Pirat");

	for (const auto & a: Instances<Airplane>::get_instances()) {
		std::cout << a->get_name() << '\n';
	}
	for (const auto & a: a1.get_instances()) {
		std::cout << a->get_name() << '\n';
	}
	{
		auto a4 = Airplane("Bocian");
	}
	for (const auto & a: Airplane::get_instances()) {
		std::cout << a->get_name() << '\n';
	}
}
