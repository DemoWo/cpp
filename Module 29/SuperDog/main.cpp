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
        protected:
            bool swimming = false;
            bool dancing = false;
            bool counting = false;

        };
class Swimming : virtual public Talent
        {
        public:
            void setSwimming (bool _swimming)
            {
                swimming = _swimming;
                if (swimming){
                    std::cout << "It can Swim" << std::endl;
                }
            }
        };

class Dancing : virtual public Talent
        {
        public:
            void setDancing (bool _dancing)
            {
                dancing = _dancing;
                if (dancing){
                    std::cout << "It can Dance" << std::endl;
                }
            }
        };

class Counting : virtual public Talent
        {
        public:
            void setCounting (bool _counting)
            {
                counting = _counting;
                if (counting)
                {
                    std::cout << "It can Count" << std::endl;
                }
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
            void show_talents (bool _swimming, bool _dancing, bool _counting)
            {
                setSwimming(_swimming);
                setDancing(_dancing);
                setCounting(_counting);
            }
        };

int main() {
    Dog d("Steve");
    d.show_talents(0,1,1);
    return 0;
}
