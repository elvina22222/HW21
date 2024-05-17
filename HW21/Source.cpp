#include <iostream>
#include "Contact.h"
#include <conio.h>

using namespace std;

int main() {
    Contact myContact("John", "Doe", "Smith", 1234567, 1234567890, "Some additional info");
    char choice;

    do {
        system("cls");
        myContact.showMenu();
        cout << "Enter your choice: "<<endl;
        choice = _getch();

        switch (choice) {
        case '1':
            myContact.addContact();
            break;
        case '2':
            myContact.showAllContacts();
            break;
        case '3': {
            char fullName[100];
            cout << "Enter the full name to search: ";
            cin.getline(fullName, 100);
            myContact.searchContact(fullName);
            break;
        }
        case '4': {
            char fullName[100];
            cout << "Enter the full name to delete: ";
            cin.getline(fullName, 100);
            myContact.deleteContact(fullName);
            break;
        }
        case '5':
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
        cout << "\nPress any key to continue...";
        _getch();
    } while (choice != '5');

    return 0;
}