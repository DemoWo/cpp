#include <iostream>
#include <string>
#include <vector>

class Animal
        {
        protected:
            std::string name;
        };

class Talent : public Animal
        {
        public:
    [[maybe_unused]] virtual void show_talents () = 0;
        };
class Swimming : public Talent
        {
        public:
            void show_talents ()
            {
                std::cout << "It can Swim" << std::endl;
            }
        };

class Dancing : public Talent
        {
        public:
            void show_talents ()
            {
                std::cout << "It can Dance" << std::endl;
            }
        };

class Counting : public Talent
        {
        public:
            void show_talents ()
            {
                std::cout << "It can Count" << std::endl;
            }
        };

class Dog : public Animal
{
    std::vector<Talent*> talents_;
    std::string name_;

public:
    Dog (std::string name)
    {
        name_ = name;
        std::cout << "This is "<< name_ << " and it has some talents: " << std::endl;

    }
    void add_talent(Talent* talent) {
        talents_.push_back(talent);
    }
    void show_talents ()
    {
        if (talents_.empty())
        {
            std::string word;
            add_talent();
        }
        else
        {
            for(int i = 0; i < talents_.size(); ++i) {
                talents_[i]->show_talents();
            }
        }
    }
};

int main() {
    //Talent d;
    Dog dog("Steven");
    dog.show_talents();
    return 0;
}
