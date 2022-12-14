#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>
#include <string>

struct Seaman {
public:
	constexpr static unsigned Road_Width = 11;
	constexpr static unsigned Show_Road_Delay = 100;
	constexpr static unsigned Change_Position_Delay = 500;
	constexpr static unsigned Tendency = +50;

	Seaman()
		: position{Road_Width / 2}, stop{false} {
		thr_left = std::thread(&Seaman::change_position, this, -1);
		thr_right = std::thread(&Seaman::change_position, this, 1);

		// FIXME: Test stop under lock!
		while (!stop) {
			show_road();
		}
	}
	~Seaman() {
		// FIXME: Change stop under lock!
		stop = true;
		thr_right.join();
		thr_left.join();
	}
private:
	void show_position(unsigned pos) const {
		std::cout << '|' << std::string(pos - 1, '-') << '*'
			  << std::string(Road_Width - pos - 1, '-') << "|\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(Show_Road_Delay));
	}
	void show_road() const {
		unsigned pos;
		{
			std::lock_guard<std::mutex> _(mtx);
			pos = position;
		}
		// FIXME: Test stop under lock!
		while(!stop) {
			show_position(pos);
			{
				std::lock_guard<std::mutex> _(mtx);
				pos = position;
			}
		}
		show_position(pos);
	}
	void change_position(int delta) {
		// FIXME: Test stop under lock!
		while(!stop) {
			{
				std::lock_guard<std::mutex> _(mtx);
				position += delta;
				if ((position == 1) || (position == (Road_Width - 1))) {
					stop = true;
					break;
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(
				Change_Position_Delay + Tendency * delta));
		}
	}
	mutable std::mutex mtx;
	unsigned position;
	std::thread thr_left;
	std::thread thr_right;
	bool stop;
};

int main() {
	Seaman seaman;
}
