// Implementation file for the NumberList class
#include <iostream>  // For cout
#include "NumberList.h"
#include <string>
#include <time.h>

using namespace std;

//time variables
time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int currentDay = aTime->tm_mday;
int currentMonth = aTime->tm_mon + 1;

//constructor
AddressBook::AddressBook()
{
    head = nullptr;
    length = 0;
    listData = NULL;

}

void AddressBook::putItem(std::string firstName, std::string lastName, int birthMonth, int birthDay, int birthYear, std::string address, int anniversaryMonth, int anniversaryDay, int anniversaryYear)
{
   PersonInfo *newNode;					// A new node
   PersonInfo *nodePtr;					// To traverse the list
   PersonInfo *previousNode = nullptr;	// The previous node
   PersonInfo *tempNode;
   bool moreToSearch;
   nodePtr = listData;
   previousNode = NULL;

   moreToSearch = true;

   // Allocate a new node and store input data there.
   newNode = new PersonInfo;
   newNode->firstName = firstName;
   newNode->lastName = lastName;
   newNode->birthMonth = birthMonth;
   newNode->birthDay = birthDay;
   newNode->birthYear = birthYear;
   newNode->address = address;
   newNode->anniversaryMonth = anniversaryMonth;
   newNode->anniversaryDay = anniversaryDay;
   newNode->anniversaryYear = anniversaryYear;

   // Allocate a temp node and store input data there.
   tempNode = new PersonInfo;

   //find insertion point
   while(moreToSearch)
   {

        if (!head)
        {
            head = newNode;
            newNode->next = nullptr;
        }

        else  // Otherwise, insert newNode
        {
            // Position nodePtr at the head of list.
            nodePtr = head;

            // Initialize previousNode to nullptr.
            previousNode = nullptr;

            // Skip all nodes untill the end of the list is reached

            while (nodePtr != nullptr)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            // If the new node is to be the 1st in the list,
            // insert it before all other nodes.
            if (previousNode == nullptr)
            {
                head = newNode;
                newNode->next = nodePtr;
            }
           // if new element is greater than previous node
            if (lastName > previousNode->lastName)
            {
                previousNode->next = newNode;
                newNode->next = nodePtr;
            }
            // if new element is less than previous node
            if (lastName < previousNode->lastName)
            {
                tempNode->firstName = previousNode->firstName;
                tempNode->lastName = previousNode->lastName;
                tempNode->birthMonth = previousNode->birthMonth;
                tempNode->birthDay = previousNode->birthDay;
                tempNode->birthYear = previousNode->birthYear;
                tempNode->address = previousNode->address;
                tempNode->anniversaryMonth = previousNode->anniversaryMonth;
                tempNode->anniversaryDay = previousNode->anniversaryDay;
                tempNode->anniversaryYear = previousNode->anniversaryYear;

                previousNode->firstName = firstName;
                previousNode->lastName = lastName;
                previousNode->birthMonth = birthMonth;
                previousNode->birthDay = birthDay;
                previousNode->birthYear = birthYear;
                previousNode->address = previousNode->address;
                previousNode->anniversaryMonth = previousNode->anniversaryMonth;
                previousNode->anniversaryDay = previousNode->anniversaryDay;
                previousNode->anniversaryYear = previousNode->anniversaryYear;

                previousNode->next = tempNode;
                newNode->next = nodePtr;
            }
    }
        moreToSearch = false;
   }

   length++;


}

int AddressBook::getLength(AddressBook& listToSearch)
{
   int length = 0;

   PersonInfo *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Move to the next node.
      nodePtr = nodePtr->next;

      //update the length of the list
      length++;
   }

   return length;

}

//delete node
void AddressBook::deleteNode(std::string lName)
{
   PersonInfo *nodePtr;					// To traverse the list
   PersonInfo *previousNode = nullptr;	// The previous node

   // If the list is empty, do nothing.
   if (!head)
      return;

   // Determine if the first node is the one.
   if (head->lastName == lName)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
      cout << "The following name was deleted: " << lName << endl;
      cout << "" << endl;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != nullptr && nodePtr->lastName != lName)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
         cout << "The following name was deleted: " << lName << endl;
         cout << "" << endl;
      }
   }
}

//delete node
void AddressBook::changeName(std::string originalLastName, std::string newLastName, std::string newFirstName)
{
   PersonInfo *nodePtr;					// To traverse the list
   PersonInfo *previousNode = nullptr;	// The previous node

   // If the list is empty, do nothing.
   if (!head)
      return;

   // Determine if the first node is the one.
   if (head->lastName == originalLastName)
   {
      head->lastName = newLastName;
      head->firstName = newFirstName;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != nullptr && nodePtr->lastName != originalLastName)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         head->lastName = newLastName;
         head->firstName = newFirstName;
      }
   }
}

//display the list
void AddressBook::printList()
{
   PersonInfo *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
        cout << "" << endl;
        cout << nodePtr->firstName << " " << nodePtr->lastName << endl;
        cout << "Birthday: " << nodePtr->birthMonth << "/" << nodePtr->birthDay << "/" << nodePtr->birthYear << endl;
        cout << "Address: " << nodePtr->address << " " << endl;
        cout << "Anniversay" << nodePtr->anniversaryMonth << "/" << nodePtr->anniversaryDay << "/" << nodePtr->anniversaryYear << endl;
        cout << "" << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
   }
   cout << "" << endl;
}

//load the main menu
void AddressBook::loadMainMenu()
{

int optionSelected;

cout << "Welcome to the address book main menu!" << endl;
cout << "--------------------------------------" << endl;
cout << "Please choose an option listed below: " << endl;
cout << "1.  Enter a new name into the address book" << endl;
cout << "2.  Delete a name from the address book" << endl;
cout << "3.  Change a name or date in the address book" << endl;
cout << "4.  Generate birthday cards" << endl;
cout << "5.  Generate anniversary cards" << endl;
cout << "6.  Exit the card program" << endl;
cout << "" << endl;
cout << "Enter option number:  ";
cin >> optionSelected;

if (optionSelected == 1)

{
    std::string fName;
    std::string lName;
    int bMonth;
    int bDay;
    int bYear;
    std::string address;
    int aMonth;
    int aDay;
    int aYear;


    cout << "" << endl;
    cout << "Enter the first name: " << endl;
    cin >> fName;

    cout << "" << endl;
    cout << "Enter the last name: " << endl;
    cin >> lName;

    cout << "" << endl;
    cout << "Enter the birth month: " << endl;
    cin >> bMonth;

    cout << "" << endl;
    cout << "Enter the birth day: " << endl;
    cin >> bDay;

    cout << "" << endl;
    cout << "Enter the birth year: " << endl;
    cin >> bYear;

    cout << "" << endl;
    cout << "Enter the person's address: " << endl;
    cin >> address;

    cout << "" << endl;
    cout << "Enter the person's anniversay month: " << endl;
    cin >> aMonth;

    cout << "" << endl;
    cout << "Enter the person's anniversay day: " << endl;
    cin >> aDay;

    cout << "" << endl;
    cout << "Enter the person's anniversay year: " << endl;
    cin >> aYear;

    putItem(fName, lName, bMonth, bDay, bYear, address, aMonth, aDay, aYear);

    cout << "" << endl;
    cout << "The following entry has been added to the address book: " << endl;
    cout << "" << endl;
    cout << fName << " " << lName << endl;
    cout << "Birthday: " << bMonth << "/" << bDay << "/" << bYear << endl;
    cout << "Address: " << address << " " << endl;
    cout << "Anniversay" << aMonth << "/" << aDay << "/" << aYear << endl;
    cout << "" << endl;

    loadMainMenu();
}

if (optionSelected == 2)
{
    std::string nameToDelete;

    cout << "" << endl;
    cout << "Enter the last name of the person you want deleted: " << endl;
    cout << "" << endl;
    cin >> nameToDelete;
    cout << "" << endl;

    deleteNode(nameToDelete);

    printList();

    loadMainMenu();
}

if (optionSelected == 3)
{
    std::string lastNameToChange;
    std::string newLastName;
    std::string newFirstName;

    cout << "" << endl;
    cout << "Enter the last name of the person you want to change: " << endl;
    cout << "" << endl;
    cin >> lastNameToChange;
    cout << "" << endl;

    cout << "Enter the new last name: " << endl;
    cin >> newLastName;
    cout << "" << endl;

    cout << "Enter the new first name: " << endl;
    cin >> newFirstName;
    cout << "" << endl;

    changeName(lastNameToChange, newLastName, newFirstName);

    printList();

    loadMainMenu();
}

if (optionSelected == 4)
{
    generateBirthdayCard();
    cout << "" << endl;
    loadMainMenu();
}

if (optionSelected == 5)
{
    generateAnniversaryCard();
    cout << "" << endl;
    loadMainMenu();
}

if (optionSelected == 6)
{
    std::exit;
}

}

void AddressBook::generateBirthdayCard()
{

   PersonInfo *nodePtr;					// To traverse the list
   PersonInfo *previousNode = nullptr;	// The previous node

   // If the list is empty, do nothing.
   if (!head)
      return;

   // Determine if the first node is the one.
   if ((head->birthMonth == currentMonth) && (head->birthDay == currentDay))
   {
        cout << "" << endl;
        cout << "Dear " << head->firstName << "," << endl;
        cout << "Hope your birthday is really wonderful and this coming year is the best yet!" << endl;
        cout << "Love, " << endl;
        cout << "Joanne" << endl;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != nullptr && nodePtr->birthMonth != currentMonth && nodePtr->birthDay != currentDay)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
        cout << "" << endl;
        cout << "Dear " << nodePtr->firstName << "," << endl;
        cout << "Hope your birthday is really wonderful and this coming year is the best yet!" << endl;
        cout << "Love, " << endl;
        cout << "Joanne" << endl;
      }
   }

}

void AddressBook::generateAnniversaryCard()
{
    PersonInfo *nodePtr;					// To traverse the list
   PersonInfo *previousNode = nullptr;	// The previous node

   // If the list is empty, do nothing.
   if (!head)
      return;

   // Determine if the first node is the one.
   if ((head->anniversaryMonth == currentMonth) && (head->anniversaryDay == currentDay))
   {
        cout << "" << endl;
        cout << "Dear " << head->firstName << "," << endl;
        cout << "Hope your anniversary is really wonderful and this coming year is the best yet!" << endl;
        cout << "Love, " << endl;
        cout << "Joanne" << endl;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != nullptr && nodePtr->anniversaryMonth != currentMonth && nodePtr->anniversaryDay != currentDay)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
        cout << "" << endl;
        cout << "Dear " << nodePtr->firstName << "," << endl;
        cout << "Hope your anniversary is really wonderful and this coming year is the best yet!" << endl;
        cout << "Love, " << endl;
        cout << "Joanne" << endl;
      }
   }

}

//destructor
AddressBook::~AddressBook()
{
   PersonInfo *nodePtr;   // To traverse the list
   PersonInfo *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }

}
