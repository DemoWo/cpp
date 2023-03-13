#include <iostream>
#include <string>
#include <vector>

class Talent
        {
        public:
            virtual void show_talents () = 0;
        };

class Swimming : public Talent
        {
        public:
            virtual void show_talents ()
            {
                std::cout << "It can \"Swim\"" << std::endl;
            }
        };

class Dancing : public Talent
        {
        public:
            virtual void show_talents ()
            {
                std::cout << "It can \"Dance\"" << std::endl;
            }
        };

class Counting : public Talent
        {
        public:
            virtual void show_talents ()
            {
                std::cout << "It can \"Count\"" << std::endl;
            }
        };

class Dog
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
        for(int i = 0; i < talents_.size(); ++i) {
            talents_[i]->show_talents();
        }
    }

    ~Dog()
    {
        std::cout << "Delete " << name_ << std::endl;
    }
};

int main() {
    Swimming swimming;
    Counting counting;
    Dancing dancing;
    Dog dog("Steven");
    dog.add_talent(&swimming);
    dog.add_talent(&counting);
    dog.add_talent(&dancing);
    dog.show_talents();
    return 0;
}
