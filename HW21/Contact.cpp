#include <iostream>
#include <fstream>
#include "Contact.h"
#include <string>
using namespace std;


Contact::Contact(const char* name, const char* surname, const char* patronymic,int homePhone,int mobilePhone, const char* additionalInfo) {
 setName(name);
 setSurname(surname);
 setPatronymic(patronymic);
 setHomePhone(homePhone);
 setMobilePhone(mobilePhone);
 setAddInfo(additionalInfo);

}

void Contact::showInfo() {
 cout << "Name:\t\t\t" << name << endl;
 cout << "Surname:\t\t" << surname << endl;
 cout << "Patronymic:\t\t" << patronymic << endl;
 cout << "Home phone number:\t" << homePhone << endl;
 cout << "Mobile phone number:\t" << mobilePhone << endl;
 cout << "Additional information:\t" << additionalInfo << endl;
 cout << '\n';
}

void Contact::showMenu() {
	cout << "1.Add contact" << endl;
	cout << "2.Show all contacts " << endl;
	cout << "3.Search contact by \"Name Surname Patronymic\"" << endl;
	cout << "4.Delete contact" << endl;
	cout << '\n';
}

void Contact::addContact() {
    char newName[20], newSurname[20], newPatronymic[20], newAdditionalInfo[100];
    int newHomePhone, newMobilePhone;

    cout << "Enter name: ";
    cin >> newName;
    cout << "Enter surname: ";
    cin >> newSurname;
    cout << "Enter patronymic: ";
    cin >> newPatronymic;
    cout << "Enter home phone number: ";
    cin >> newHomePhone;
    cout << "Enter mobile phone number: ";
    cin >> newMobilePhone;
    cout << "Enter additional information: ";
    cin.ignore();
    cin.getline(newAdditionalInfo, 100);

    setName(newName);
    setSurname(newSurname);
    setPatronymic(newPatronymic);
    setHomePhone(newHomePhone);
    setMobilePhone(newMobilePhone);
    setAddInfo(newAdditionalInfo);

    Contact newContact(newName, newSurname, newPatronymic, newHomePhone, newMobilePhone, newAdditionalInfo);

    ofstream outFile("contacts.txt", ios::app);
    if (outFile.is_open()) {
        outFile << newContact.getName() << "," << newContact.getSurname() << "," << newContact.getPatronymic() << ","
            << newContact.getHomePhone() << "," << newContact.getMobilePhone() << "," << newContact.getAdditionalInfo() << endl;
        outFile.close();
        cout << "Contact added successfully!" << endl;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

void Contact::showAllContacts() {
    ifstream inFile("contacts.txt");
    if (inFile.is_open()) {
        cout << "All Contacts:\n";
        string line;
        int contactNumber = 1;
        while (getline(inFile, line)) {
            cout << "Contact " << contactNumber++ << ":\n";
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "No contacts found." << endl;
    }
}

void Contact::searchContact(const char* fullName) {
    ifstream inFile("contacts.txt");
    if (inFile.is_open()) {
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);
            size_t pos3 = line.find(",", pos2 + 1);
            size_t pos4 = line.find(",", pos3 + 1);

            string name = line.substr(0, pos1);
            string surname = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string patronymic = line.substr(pos2 + 1, pos3 - pos2 - 1);
            string homePhone = line.substr(pos3 + 1, pos4 - pos3 - 1);
            string mobilePhone = line.substr(pos4 + 1);

            string fullNameInFile = name + " " + surname + " " + patronymic;
            if (fullNameInFile == fullName) {
                found = true;
                cout << "Contact found:\n";
                cout << "Name:\t\t\t" << name << endl;
                cout << "Surname:\t\t" << surname << endl;
                cout << "Patronymic:\t\t" << patronymic << endl;
                cout << "Home phone number:\t" << homePhone << endl;
                cout << "Mobile phone number:\t" << mobilePhone << endl;
                cout << "Additional information:\t" << additionalInfo << endl;
                cout << '\n';
                break; 
            }
        }
        inFile.close();
        if (!found) {
            cout << "Contact not found." << endl;
        }
    }
    else {
        cout << "No contacts found." << endl;
    }
}

void Contact::deleteContact(const char* fullName) {
    ifstream inFile("contacts.txt");
    ofstream tempFile("temp.txt");

    if (inFile.is_open() && tempFile.is_open()) {
        string line;
        bool deleted = false;
        while (getline(inFile, line)) {
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);
            size_t pos3 = line.find(",", pos2 + 1);

            string name = line.substr(0, pos1);
            string surname = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string patronymic = line.substr(pos2 + 1, pos3 - pos2 - 1);

            string fullNameInFile = name + " " + surname + " " + patronymic;
            if (fullNameInFile == fullName) {
                deleted = true;
                cout << "Contact found and deleted:\n";
                cout << "Name:\t\t\t" << name << endl;
                cout << "Surname:\t\t" << surname << endl;
                cout << "Patronymic:\t\t" << patronymic << endl;
                cout << '\n';
            }
            else {
                tempFile << line << endl;
            }
        }
        inFile.close();
        tempFile.close();

        remove("contacts.txt");
        rename("temp.txt", "contacts.txt");

        if (!deleted) {
            cout << "Contact not found." << endl;
        }
    }
    else {
        cout << "Error: Unable to open files." << endl;
    }
}




Contact::~Contact() {
 delete[] name;
 delete[] surname;
 delete[] patronymic;
 delete[] additionalInfo;
}
