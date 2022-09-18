#include <iostream>
#include <vector>

class PhoneBook
{
    std::vector <std::vector<std::string>> book;
    std::string lastName;
    std::string numberPhone;

public:

    static std::string checkNumber (std::string number)
    {
        std::cout << "Input number phone contacts:" << std::endl;
        std::cin >> number;

        for (int i = 0; i < 2; ++i)
        {
            if (number[0] != '+' || number[1] != '7') {
                std::cerr << "Error input numbers!" << std::endl;
                std::cout << "Input number phone contacts:" << std::endl;
                std::cin >> number;
            }
        }
        for (int k = 2; k < 12; ++k)
        {
            if (number[k] < '0' || number[k] > '9' || number.size() != 12)
            {
                std::cerr << "Error input numbers!" << std::endl;
                std::cout << "Input number phone contacts:" << std::endl;
                std::cin >> number;
            }
        }
        return number;
    }

    void showContacts (int h)
    {
        //for (int h = 0; h < book.size(); h++){
        for ( int k = 0; k < book[h].size(); k++){
            if (k == 0)
            {
                std::cout << "Name Contacts: "<< book[h][k] << std:: endl;
            }
            else if (k == 1)
            {
                std::cout << "Number Contacts: " << book[h][k] << std:: endl;
            }

        }
        std::cout << std::endl;
        // }
    }

    void contacts()
    {
        std::cout << "Input Last Name contacts:" << std::endl;
        std::cin >> lastName;
        numberPhone = checkNumber(numberPhone);
        book.push_back(std::vector<std::string>{lastName, numberPhone});

    }
    void search(const std::string& requestContacts, const std::string& operation)
    {
        if (!book.empty()){
            for (int h = 0; h < book.size() ; h++){
                for ( int k = 0; k < book[h].size(); k++){
                    if ((k == 0 && book[h][k] == requestContacts) ||
                        (k == 1 && book[h][k] == requestContacts))
                    {
                        if (operation == "call") {
                            std::cout << "Contact called:" << std::endl;
                            showContacts(h);
                            break;
                        }
                        else if (operation == "sms"){
                            std::cout << "The message was sent to the contact:" << std::endl;
                            showContacts(h);
                            break;
                        }
                    } else if (k == book.size())
                        std::cout << "Contact not found!" << std::endl;
                }
            }
        }
        else
            std::cout << "Contact not found!" << std::endl;
    }
};

class Phone
{
    PhoneBook* phoneBook = new PhoneBook();
    std::string request;
    std::string operation;

public:
    void add ()
    {
        phoneBook -> contacts();
    }
    void call ()
    {

        std::cout << "Enter the contact's number or name:" << std::endl;
        std::cin >> request;
        phoneBook -> search(request, operation = "call");
    }
    void sms ()
    {
        std::cout << "Enter the contact's number or name:" << std::endl;
        std::cin >> request;
        phoneBook -> search(request, operation = "sms");
    }

};

int main() {
    auto* phone = new Phone();
    std::string command;

    while (command != "exit"){

        std::cout << "Input command phone: (add/call/sms/exit)" << std:: endl;
        std::cin >> command;

        if (command == "add")
        {
            phone -> add();
        }
        else if (command == "call")
        {
            phone -> call();
        }
        else if (command == "sms")
        {
            phone -> sms();
        }
        else if (command != "exit")
        {
            std::cerr << "Error input!" << std:: endl;
        }
    }
    std::cout << "The program is closed!" << std::endl;
    return 0;
}