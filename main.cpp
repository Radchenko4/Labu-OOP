#include <iostream>
#include <string>

using namespace std;

class Student {
  // поля
  string firstName;
  string lastName;
  string phoneNumber;
  int id;
  int age;

public:
  // конструктор без параметрів
  Student() {
    this->firstName = "Bogdan";
    this->lastName = "Radchenko";
    this->phoneNumber = "0980081633";
    this->id = 0421413;
    this->age = 18;
  }

  // конструктор з параметрами
  Student(string firstName, string lastName, string phoneNumber, int id, int age) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->id = id;
    this->age = age;
  }

  // методи для отримання і присвоєння значень
  void setFirstName(string firstName) {
    this->firstName = firstName;
  }

  string getFirstName() {
    return firstName;
  }

  void setLastName(string lastName) {
    this->lastName = lastName;
  }

  string getLastName() {
    return lastName;
  }

  void setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
  }

  string getPhoneNumber() {
    return phoneNumber;
  }

  void setId(int id) {
    this->id = id;
  }

  int getId() {
    return id;
  }

  void setAge(int age) {
    this->age = age;
  }

  int getAge() {
    return age;
  }

  // метод print () для виводу на екран значень екземпляра
  void print() {
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "ID: " << id << endl;
    cout << "Age: " << age << endl;
    system("pause");
  }
};