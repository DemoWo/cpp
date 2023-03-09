#include <iostream>
#include <string>
#include <vector>

class Animal
        {
        protected:
            std::string name;
        };

class Talent : virtual public Animal
        {
        public:
            virtual void show_talents (bool swimming, bool dancing, bool counting) = 0;
        };
class Swimming : virtual public Talent
        {
        public:
            virtual void setSwimming ()
            {
                std::cout << "It can Swim" << std::endl;
            }
        };

class Dancing : virtual public Talent
        {
        public:
            virtual void setDancing ()
            {
                std::cout << "It can Dance" << std::endl;
            }
        };

class Counting : virtual public Talent
        {
        public:
            virtual void setCounting ()
            {
                std::cout << "It can Count" << std::endl;
            }
        };

class Dog : virtual public Swimming, virtual public Dancing, virtual public Counting
        {
        public:
            Dog (std::string _name)
            {
                name = _name;
                std::cout << "This is "<< name << " and it has some talents: " << std::endl;
            }
            virtual void show_talents (bool swimming, bool dancing, bool counting)
            {
                if (swimming) setSwimming();
                if (dancing) setDancing();
                if (counting) setCounting();
            }
        };

int main() {
    Talent* d = new Dog("Steven");
    d -> show_talents(1,1,0);
    return 0;
}
