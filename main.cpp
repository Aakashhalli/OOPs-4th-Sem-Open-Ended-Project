#include<bits/stdc++.h>
#include "ui.h"
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

class Car {
    string name, make;
    int year,carId;
    double pricePerday;
    bool isAvailble;
public: 
    Car(){}
};
bool check_credentials(const string& filename, const string& username, const string& password) {
    ifstream fin(filename);
    string file_username, file_password;

    while (fin >> file_username >> file_password) {
        if (file_username == username && file_password == password) {
            fin.close();
            return true;
        }
    }

    fin.close();
    return false;
}

void Login() {
    int choice;
    string username, password;
    login_page();
    cin >> choice;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;
    switch (choice) {
        case 1: {
            if (check_credentials("Owner_credentials.txt", username, password)) {
                logged_in();
            } else {
                cout<<"                   Not registered or incorrect credentials.\n";
                cout<<"                               Try again"<<endl;
                Sleep(2000);
                system("cls");
                Login();            
            }
        }
        break;
        case 2: {
            if (check_credentials("Lessee_credentials.txt", username, password)) {
                logged_in();
            } else {
                cout<<"                   Not registered or incorrect credentials.\n";
                cout<<"                               Try again"<<endl;
                Sleep(2000);
                system("cls");
                Login();
            }
        }
        break;
    }
}

void Signup() {
    int choice;
    string username,password;
    signup_page();
    cin>>choice;
    cout<<"Create Username : ";
    cin>>username;
    cout<<"Password : ";
    cin>>password;
    switch(choice) {
        case 1 :{   ofstream fout("Owner_credentials.txt", ios::app);
                    fout<<username<<"\t"<<password<<endl;
                    fout.close();
                    
                    signedup();
        }
                break;

        case 2 :{   ofstream fout("Lessee_credentials.txt", ios::app);
                    fout<<username<<"\t"<<password<<endl;
                    fout.close();
                    
                    signedup();
        }
                break;
    }
}

int main(){
    int choice,loschoice;
    intro();
    do {
los:    LOS();
        cin>>loschoice;
        system("cls");
        switch(loschoice) {
            case 1: Signup();
                goto los;
                break;
            case 2: Login();
                break;
        }
    }while(choice<3);
    return 0;
}