#include <iostream>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Get(cpr::Url("https://httpbin.org/html"));
    std::size_t b = r.text.find("<h1>"), e = r.text.find("</h1>");
    std::string header = r.text.substr(b + 4, e - b - 4);
    std::cout << header << std::endl;
    return 0;
}
