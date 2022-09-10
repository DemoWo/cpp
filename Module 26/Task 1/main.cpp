#include <iostream>
#include <ctime>
#include <iomanip>

class Track
        {

            std::string NameTrack;
            std::time_t t = std::time(nullptr);
public:
            std::tm* local = std::localtime(&t);

        };
int main() {
    Track* track = new Track;
    std::cout << std::put_time(track -> local, "%Y/%m/%d %H:%M:%S") << std::endl;

    return 0;
}
