#include <iostream>
#include <string>
#include <vector>

template<typename T>
class Container {
	std::vector<T> data;
public:
	void add(T val) {
		data.push_back(val);
	}
	T calculate() {
		T sum = 0;
		for (auto& e : data) {
			sum += e;
		}
		return sum / static_cast<T>(data.size());
	}
};

int main()
{
	Container<int> arr;
	std::string cmd;
	int a = 0;
    std::cout << "Input command ( add, calc, exit ): " << std::endl;
	while (cmd != "exit") {
		std::cin >> cmd;
		if (cmd == "add") {
            std::cout << "Input number:" << std::endl;
			std::cin >> a;
			arr.add(a);
		}
		else if (cmd == "calc") {
			std::cout << arr.calculate() << std::endl;
		}
        std::cout << "Input command ( add, calc, exit ): " << std::endl;
	}
    return 0;
}