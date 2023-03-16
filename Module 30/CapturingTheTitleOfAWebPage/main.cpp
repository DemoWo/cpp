#include <iostream>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Get(cpr::Url("https://httpbin.org/get"));
    std::cout << r.text << std::endl;
    return 0;
}
