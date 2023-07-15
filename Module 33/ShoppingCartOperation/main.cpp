#include <iostream>
#include <string>
#include <map>
#include <exception>

struct ArticleNotFoundException : std::exception {
    const char* what() const noexcept override {
            return "acticul not found";
    }
};
struct NoHaveCountException : std::exception {
    const char* what() const noexcept override {
            return "articul not have this count";
    }
};

class Base {
    std::map<std::string, int> base;
public:
    void add(std::string ar, int co) {
        if (base.find(ar) == base.end()) {
            base.insert({ ar, co });
        }
        else {
            base[ar] += co;
        }
    }
    void remove(std::string ar, int co) {
        auto it = base.find(ar);
        if (it == base.end())
            throw ArticulNotFoundException();
        if (base[ar] < co)
            throw NoHaveCountException();
        base[ar] -= co;
        if (base[ar] == 0)
            base.erase(it);
    }
};

int main()
{
    Base base;
    std::string cmd, buf;
    int dBuf = 0;
    std::cout << "Enter commands: (add or remove) " << std::endl;
    while (cmd != "exit") {
        std::cin >> cmd;
        if (cmd == "add") {
            std::cout << "Input article and count: " << std::endl;
            std::cin >> buf >> dBuf;
            base.add(buf, dBuf);
        }
        else if (cmd == "remove") {
            std::cout << "Input article and count: " << std::endl;
            std::cin >> buf >> dBuf;
            try {
                base.remove(buf, dBuf);
            }
            catch (ArticleNotFoundException& e) {
                std::cerr << e.what() << std::endl;
            }
            catch (NoHaveCountException& e) {
                std::cerr << e.what() << std::endl;
            }
        }
        std::cout << "Enter commands: (add or remove) " << std::endl;
    }
    return 0;
}
