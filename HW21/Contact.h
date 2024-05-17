#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class Contact
{
private:
	char* name;
	char* surname;
	char* patronymic;
	int homePhone;
	int mobilePhone;
	char* additionalInfo;

public:

	Contact(const char* name,const char* surname,const char* patronymic ,int homePhone, int mobilePhone, const char* additionalInfo);

	void setName(const char* name) {
	 if (strlen(name) != 0) {
	  this->name = new char [strlen(name) + 1] {};
	  strcpy_s(this->name, strlen(name) + 1, name);
	 }
	 else {
	  throw "Empty name";
	 }
	}

	const char* getName() {
		return name;
	}

	void setSurname(const char* surname) {
	 if (strlen(surname) != 0) {
	  this->surname = new char [strlen(surname) + 1] {};
	  strcpy_s(this->surname, strlen(surname) + 1, surname);
	 }
	 else {
	  throw "Empty surname";
	 }
	}

	const char* getSurname() {
	 return surname;
	}

	void setPatronymic(const char* patronymic) {
	 if (strlen(patronymic) != 0) {
	  this->patronymic = new char [strlen(patronymic) + 1] {};
	  strcpy_s(this->patronymic, strlen(patronymic) + 1, patronymic);
	 }
	 else {
	  throw "Empty patronymic";
	 }
	}

	const char* getPatronymic() {
	 return patronymic;
	}

	void setHomePhone(int homePhone) {
		int copyPhone = homePhone;
		int count = 0;
		while (copyPhone != 0) {
			copyPhone /= 10;
			++count;
		}
		if (count == 7) {
			this->homePhone = homePhone;
		}
		else {
			throw "Error";
		}
	}



	int getHomePhone() {
		return homePhone;
	}

	void setMobilePhone(int mobilePhone) {
		int copyPhone = mobilePhone;
		int count = 0;
		while (copyPhone != 0) {
			copyPhone /= 10;
			++count;
		}
		if (count == 10 || count == 12) {
			this->mobilePhone = mobilePhone;
		}
		else {
			throw "Error";
		}
	}



	int getMobilePhone() {
		return mobilePhone;
	}

	void setAddInfo(const char* additionalInfo) {
	 if (strlen(additionalInfo) != 0) {
	  this->additionalInfo = new char [strlen(additionalInfo) + 1] {};
	  strcpy_s(this->additionalInfo, strlen(additionalInfo) + 1, additionalInfo);
	 }
	 else {
	  throw "Empty additional information";
	 }
	}

	const char* getAdditionalInfo() {
	 return additionalInfo;
	}
	 
	void showInfo();

	void showMenu();

	void addContact();
	void showAllContacts();

	void searchContact(const char* fullName);
	void deleteContact(const char* fullName);


	~Contact();
};

