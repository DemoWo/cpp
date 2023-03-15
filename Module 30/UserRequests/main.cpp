#include <iostream>
#include <cpr/cpr.h>
#include <string>

void command (std::string cmd)
{
    std::string url = "https://httpbin.org/" + cmd;
    cpr::Response r;
    if (cmd == "get") r = cpr::Get(cpr::Url(url));
    else if (cmd == "post")
    {
        r = cpr::Post(cpr::Url(url));
    }
    else if (cmd == "put")
    {
        r = cpr::Put(cpr::Url(url));
    }
    else if (cmd == "delete")
    {
        r = cpr::Delete(cpr::Url(url));
    }
    else if (cmd == "patch")
    {
        r = cpr::Patch(cpr::Url(url));
    }
    std::cout << r.text << std::endl;
}

int main() {
    std::string cmd;
    while (cmd != "exit")
    {
        std::cout << "Enter the command: (get,post, put, delete, patch, exit)" << std::endl;
        std::cin >> cmd;
        if (cmd == "get") command(cmd);
        else if (cmd == "post") command(cmd);
        else if (cmd == "put") command(cmd);
        else if (cmd == "delete") command(cmd);
        else if (cmd == "patch") command(cmd);
        else if (cmd != "exit") std::cout << "Error input!" << std::endl;
    }
    return 0;
}
