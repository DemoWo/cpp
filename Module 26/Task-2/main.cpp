#include <iostream>
#include <map>
#include <string>

class PhoneBook
{
    std::map <std::string ,std::string> book;
    std::string lastName;
    std::string numberPhone;

public:

    std::string checkNumber (std::string number)
    {
        std::cout << "Input number phone contacts:" << std::endl;
        std::cin >> number;

        if (number.size() == 12)
        {
            if (number[0] == '+' && number[1] == '7'){
                for (int i = 2; i != number.size(); ++i)
                {
                    if (number[i] < '0' || number[i] > '9')
                    {
                        std::cerr << "Error input numbers!" << std::endl;
                        std::cout << "Input number phone contacts:" << std::endl;
                        std::cin >> number;
                    }
                }
            }
            else
            {
                std::cerr << "The number must have the form +7 <10 digits>!" << std::endl;
                return checkNumber(number);
            }
        }
        else
        {
            std::cerr << "The number must have the form +7 <10 digits>!" << std::endl;
            return checkNumber(number);
        }
        return number;
    }

    void showContacts (const std::string& user, const std::string& mess)
    {
        bool res = true;
        std::cout << "---------------------------------" << std::endl;
        for (auto it = book.begin(); it != book.end(); ++it)
        {
            if (it -> first == user)
            {
                std::cout << "Name Contacts: "<< it -> first << std:: endl;
                std::cout << "Number Contacts: " << it -> second << std:: endl;
                std::cout << mess << std::endl;
                res = true;
                break;
            }
            else if (it -> second == user)
            {
                std::cout << "Name Contacts: "<< it -> first << std:: endl;
                std::cout << "Number Contacts: " << it -> second << std:: endl;
                std::cout << mess << std::endl;
                res = true;
                break;
            }
            else
                res = false;
        }
        if (!res)
        {
            std::cout << "Contact not found!" << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }

    void contacts()
    {
        std::cout << "Input Last Name contacts:" << std::endl;
        std::cin >> lastName;
        numberPhone = checkNumber(numberPhone);
        book.insert(std::pair <std::string ,std::string> (lastName, numberPhone));
    }

    void search(const std::string& requestContacts,const std::string& operation)
    {
        std::string text;
        if (!book.empty()){
            if (operation == "call") {
                text = "Contact called!";
                showContacts(requestContacts, text);
            }
            else if (operation == "sms"){
                std::cout << "Enter the text to send:" << std::endl;
                std::cin >> text;
                //std::getline(std::cin,text);
                showContacts(requestContacts, text);
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