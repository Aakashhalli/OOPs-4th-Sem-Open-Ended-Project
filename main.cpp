#include<bits/stdc++.h>
using namespace std;

int generateUid();

class Person {
    std::string name, email;
    int age, uid;
    long int phone_no;
public:
    friend int generateUid();
    Person() {
        this->uid = generateUid();
    }
    Person(std::string name, int age, long int phone_no, std::string email) {
        this->name = name;
        this->age = age;
        this->phone_no = phone_no;
        this->email = email;
        this->uid = generateUid();
    }
};

class Owner : public Person {
    std::vector<std::string> carList;
public:
    Owner() : Person() {}
    Owner(std::string name, int age, long int phone_no, std::string email)
        : Person(name, age, phone_no, email) {}
};

class Lessee : public Person {
    std::string license;
public:
    Lessee() : Person() {}
    Lessee(std::string name, int age, long int phone_no, std::string email)
        : Person(name, age, phone_no, email) {}
};
int generateUid(){
    
}
int main(){
    
    return 0;
}