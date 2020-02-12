// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <string>


class AddressBook
{
private:
    //structure for person information
    struct PersonInfo
    {
        std::string firstName;
        std::string lastName;
        int birthMonth;
        int birthDay;
        int birthYear;
        std::string address;
        int anniversaryMonth;
        int anniversaryDay;
        int anniversaryYear;

        PersonInfo *next;
    };

    PersonInfo *head;
    PersonInfo* listData;

    //length of list
    int length;

public:
    // Constructor
   AddressBook();

    //destructor
    ~AddressBook();

    void putItem(std::string firstName, std::string lastName, int birthMonth, int birthDay, int birthYear, std::string address, int anniversaryMonth, int anniversaryDay, int anniversaryYear);
    void deleteNode(std::string lName);
    void changeName(std::string originalLastName, std::string newLastName, std::string newFirstName);
    int getLength(AddressBook& listToSearch);
    void printList();
    void loadMainMenu();
    void generateBirthdayCard();
    void generateAnniversaryCard();
};

#endif
