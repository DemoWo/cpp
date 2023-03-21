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
public:
    shared_ptr_toy() = default;

    shared_ptr_toy(Toy* _ptr) {
        ptr = _ptr;
        count = new int(1);
    }

    shared_ptr_toy(std::string name) {
        ptr = new Toy(name);
        count = new int(1);
    }

    shared_ptr_toy(const shared_ptr_toy& oth) {
        ptr = oth.ptr;
        count = oth.count;
        ++(*count);
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& oth) {
        if (&oth == this)
            return *this;
        if (ptr != nullptr) {
            --(*count);
            if (!*count) {
                delete ptr;
                delete count;
            }
        }
        ptr = oth.ptr;
        count = oth.count;
        ++(*count);
        return *this;
    }
    ~shared_ptr_toy() {
        --(*count);
        if (!*count) {
            delete ptr;
            delete count;
        }
    }
    Toy* operator->() {
        return ptr;
    }
private:
    int* count = nullptr;
    Toy* ptr = nullptr;
};

shared_ptr_toy make_shared_ptr(std::string name) {
    return shared_ptr_toy(name);
}
shared_ptr_toy make_shared_ptr(shared_ptr_toy oth) {
    return shared_ptr_toy(oth);
}

int main()
{
    shared_ptr_toy bone = make_shared_ptr("bone");
    shared_ptr_toy sphere("sphere");
    shared_ptr_toy toy(new Toy("toy"));
    shared_ptr_toy bone_two; // no state

    bone_two = make_shared_ptr(bone); // set state

    std::cout << bone->getName() << " and " << sphere->getName() << std::endl;
    sphere = bone;
    std::cout << "Call operator =" << std::endl;
    std::cout << bone->getName() << " and " << sphere->getName() << std::endl;

    std::cout << "Bone two: " << bone_two->getName() << std::endl;
    return 0;
}
