#include <iostream>
#include <string>
#include <vector>

template<typename T1, typename T2>
class Container {
    std::vector<std::pair<T1, T2>> data;
public:
    void add(T1 key, T2 value) {
        data.push_back({ key, value });
    }
    void remove(T1 key) {
        for (auto it = data.begin(), ite = data.end(); it != ite; ++it) {
            if (it->first == key)
                data.erase(it);
        }
    }
    void print() {
        for (auto& e : data) {
            std::cout << e.first << " => " << e.second << std::endl;
        }
    }
    void find(T1 key) {
        for (auto it = data.begin(), ite = data.end(); it != ite; ++it) {
            if (it->first == key)
                std::cout << it->second << std::endl;
        }
    }
};

int main()
{
    Container<int, int> cont;
    std::string cmd;
    int a, b;
    std::cout << "Input command (add, remove, print, find, exit): " << std::endl;
    while (cmd != "exit") {
        std::cin >> cmd;
        if (cmd == "add") {
            std::cout << "Input two elements:" << std::endl;
            std::cin >> a >> b;
            cont.add(a, b);
        }
        else if (cmd == "remove") {
            std::cout << "Input one element:" << std::endl;
            std::cin >> a;
            cont.remove(a);
        }
        else if (cmd == "print") {
            cont.print();
        }
        else if (cmd == "find") {
            std::cout << "Input one element:" << std::endl;
            std::cin >> a;
            cont.find(a);
        }
        std::cout << "Input command (add, remove, print, find, exit): " << std::endl;
    }
    return 0;
}