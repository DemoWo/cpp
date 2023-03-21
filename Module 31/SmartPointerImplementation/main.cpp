#include <iostream>
#include <string>

class Toy {
public:
    Toy() : Toy("unk") {}
    Toy(std::string _name) : name(_name) {}
    std::string getName() {
        return name;
    }
private:
    std::string name;
};

class shared_ptr_toy
{

};

shared_ptr_toy make_shared_ptr ()
{

};

shared_ptr_toy make_shared_ptr()
{

};


int main()
{

    return 0;
}
