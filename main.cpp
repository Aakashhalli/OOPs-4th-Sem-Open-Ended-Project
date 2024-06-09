#include <bits/stdc++.h>
#include "ui.h"
using namespace std;

int generateUid() {
    static int uid = 0;
    return ++uid;
}

class Person {
    std::string name, email, username;
    int age;
    long int phone_no;
public:
    Person() : age(0), phone_no(0) {}
    Person(std::string username, std::string name, int age, long int phone_no, std::string email)
        : username(username), name(name), age(age), phone_no(phone_no), email(email) {}

    std::string getUsername() const { return username; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    int getAge() const { return age; }
    long int getPhoneNo() const { return phone_no; }

    void setDetails(std::string username, std::string name, int age, long int phone_no, std::string email) {
        this->username = username;
        this->name = name;
        this->age = age;
        this->phone_no = phone_no;
        this->email = email;
    }

    bool isDetailsEmpty() const {
        return name.empty() || email.empty() || age == 0 || phone_no == 0;
    }
};

class Owner : public Person {
    std::vector<std::string> carList;
public:
    Owner() : Person() {}
    Owner(std::string username, std::string name, int age, long int phone_no, std::string email)
        : Person(username, name, age, phone_no, email) {}

    void addCar(const std::string& car) {
        carList.push_back(car);
    }

    void removeCar(const std::string& car) {
        auto it = std::find(carList.begin(), carList.end(), car);
        if (it != carList.end()) {
            carList.erase(it);
        }
    }

    std::vector<std::string> getCarList() const {
        return carList;
    }
};

class Lessee : public Person {
    std::string license;
    std::vector<int> rentedCars;
public:
    Lessee() : Person() {}
    Lessee(std::string username, std::string name, int age, long int phone_no, std::string email)
        : Person(username, name, age, phone_no, email) {}

    void setLicense(const std::string& license) {
        this->license = license;
    }

    std::string getLicense() const {
        return license;
    }

    void rentCar(int carId) {
        rentedCars.push_back(carId);
    }

    void returnCar(int carId) {
        auto it = std::find(rentedCars.begin(), rentedCars.end(), carId);
        if (it != rentedCars.end()) {
            rentedCars.erase(it);
        }
    }

    std::vector<int> getRentedCars() const {
        return rentedCars;
    }
};

class Car {
    string name, make;
    int year, carId;
    double pricePerDay;
    bool isAvailable;
    std::string rentedBy;
    std::string ownerUsername;  // Add this to track the owner's username

public: 
    Car() : carId(generateUid()), year(0), pricePerDay(0.0), isAvailable(true), rentedBy("") {}
    Car(std::string name, std::string make, int year, double pricePerDay, std::string ownerUsername)
        : name(name), make(make), year(year), carId(generateUid()), pricePerDay(pricePerDay), isAvailable(true), rentedBy(""), ownerUsername(ownerUsername) {}

    void displayInfo() const {
        cout << "CarID: " << carId << ", Name: " << name << ", Make: " << make << ", Year: " << year 
             << ", Price per day: $" << pricePerDay << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }

    int getCarId() const {
        return carId;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    double getPricePerDay() const {
        return pricePerDay;
    }

    void setAvailability(bool available) {
        isAvailable = available;
    }

    void setRentedBy(const std::string& username) {
        rentedBy = username;
    }

    std::string getRentedBy() const {
        return rentedBy;
    }

    std::string getOwnerUsername() const {
        return ownerUsername;
    }
};

class Payment {
public:
    static void makePayment(const std::string& ownerUsername, const std::string& lesseeUsername, double amount) {
        cout << "Payment of $" << amount << " from Lessee " << lesseeUsername << " to Owner " << ownerUsername << " completed." << endl;
    }

    static void generateReceipt(int lesseeId, int carId, double amount, const std::string& ownerName, const std::string& lesseeName, const std::string& license) {
        cout << "Receipt: Lessee ID " << lesseeId << " (" << lesseeName << ", License: " << license << ") has returned Car ID " << carId << ". Amount due: $" << amount << ". Owner: " << ownerName << endl;
    }
};

unordered_map<std::string, unique_ptr<Owner>> owners;
unordered_map<std::string, unique_ptr<Lessee>> lessees;
unordered_map<int, Car> cars;

void writeUserDetailsToFile(const std::string& filename, const Person& person) {
    ofstream fout(filename, ios::app);
    if (fout.is_open()) {
        fout << person.getUsername() << "\t"
             << person.getName() << "\t"
             << person.getAge() << "\t"
             << person.getPhoneNo() << "\t"
             << person.getEmail() << "\n";
    }
    fout.close();
}

bool readUserDetailsFromFile(const std::string& filename, const std::string& username, Person& person) {
    ifstream fin(filename);
    if (fin.is_open()) {
        std::string line, file_username, name, email;
        int age;
        long int phone_no;

        while (getline(fin, line)) {
            istringstream iss(line);
            iss >> file_username >> name >> age >> phone_no >> email;

            if (file_username == username) {
                person.setDetails(username, name, age, phone_no, email);
                fin.close();
                return true;
            }
        }
        fin.close();
    }
    return false;
}

void Owner_loggedin(const std::string& username) {
    auto& owner = owners[username];
    if (owner->isDetailsEmpty()) {
        std::string name, email;
        int age;
        long int phone_no;

        cout << "Enter your details:\n";
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
        cout << "Phone Number: "; cin >> phone_no;
        cout << "Email: "; cin >> email;

        owner->setDetails(username, name, age, phone_no, email);
        writeUserDetailsToFile("Owners.txt", *owner);
    }

    int choice;
    do {
        cout << "1. List a car for rent\n2. Remove a car from list\n3. View listed cars\n4. Logout\n";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1: {
                string name, make;
                int year;
                double pricePerDay;

                cout << "Enter car details:\n";
                cout << "Name: "; cin >> name;
                cout << "Make: "; cin >> make;
                cout << "Year: "; cin >> year;
                cout << "Price per day: "; cin >> pricePerDay;

                Car car(name, make, year, pricePerDay, username);
                cars[car.getCarId()] = car;
                owner->addCar(to_string(car.getCarId()));

                cout << "Car listed successfully.\n";
                break;
            }
            case 2: {
                std::string carIdStr;
                cout << "Enter Car ID to remove: "; cin >> carIdStr;
                int carId = stoi(carIdStr);
                owner->removeCar(carIdStr);
                cars.erase(carId);

                cout << "Car removed successfully.\n";
                break;
            }
            case 3: {
                auto carList = owner->getCarList();
                cout << "Listed cars:\n";
                for (const auto& carIdStr : carList) {
                    int carId = stoi(carIdStr);
                    cars[carId].displayInfo();
                }
                break;
            }
        }
    } while (choice != 4);
}

void Lessee_loggedin(const std::string& username) {
    auto& lessee = lessees[username];
    if (lessee->isDetailsEmpty()) {
        std::string name, email, license;
        int age;
        long int phone_no;

        cout << "Enter your details:\n";
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
        cout << "Phone Number: "; cin >> phone_no;
        cout << "Email: "; cin >> email;
        cout << "License: "; cin >> license;

        lessee->setDetails(username, name, age, phone_no, email);
        lessee->setLicense(license);
        writeUserDetailsToFile("Lessees.txt", *lessee);
    }

    int choice;
    do {
        cout << "1. View available cars\n2. Rent a car\n3. Return a car\n4. View rented cars\n5. Logout\n";
        cin >> choice;
        int days;
        system("cls");
        switch (choice) {
            case 1: {
                cout << "Available cars:\n";
                for (const auto& pair : cars) {
                    const Car& car = pair.second;
                    if (car.getAvailability()) {
                        car.displayInfo();
                    }
                }
                break;
            }
            case 2: {
                int carId;
                cout << "Enter Car ID to rent: "; cin >> carId;
                cout << "Enter number of days to rent: "; cin >> days;
                if (cars.find(carId) != cars.end() && cars[carId].getAvailability()) {
                    cars[carId].setAvailability(false);
                    lessee->rentCar(carId);
                    cars[carId].setRentedBy(username);  // Set the lessee's username as the renter
                    double totalAmount = cars[carId].getPricePerDay() * days;
                    cout << "Car rented successfully for " << days << " days. Total amount: $" << totalAmount << "\n";
                } else {
                    cout << "Car ID not found or already rented.\n";
                }
                break;
            }
            case 3: {
                string carIdStr;
                cout << "Enter Car ID to return: ";
                cin >> carIdStr;
                try {
                    int carId = stoi(carIdStr);
                    if (cars.find(carId) != cars.end() && !cars[carId].getAvailability() && cars[carId].getRentedBy() == username) {
                        cars[carId].setAvailability(true);
                        lessee->returnCar(carId);
                        cout << "Car returned successfully.\n";
                        
                        std::string ownerUsername = cars[carId].getOwnerUsername();

                        double totalAmount = days*cars[carId].getPricePerDay();
                        Payment::makePayment(ownerUsername, username, totalAmount);
                        cout << "Payment made successfully.\n";
                    } else {
                        cout << "Car ID not found, not rented, or not rented by you.\n";
                    }
                } catch (const std::invalid_argument& e) {
                    cout << "Invalid input for Car ID. Please enter a valid integer.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }
            case 4: {
                auto rentedCars = lessee->getRentedCars();
                cout << "Rented cars:\n";
                for (int carId : rentedCars) {
                    cars[carId].displayInfo();
                }
                break;
            }
        }
    } while (choice != 5);
}

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

void LoginOrSignup();
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
                if (owners.find(username) == owners.end()) {
                    owners[username] = make_unique<Owner>();
                }
                if (!readUserDetailsFromFile("Owners.txt", username, *owners[username])) {
                    // New owner, will enter details later
                }
                logged_in();
                Owner_loggedin(username);
            } else {
                cout << "Not registered or incorrect credentials.\n";
                cout << "Try again" << endl;
                Sleep(2000);
                system("cls");
                LoginOrSignup();            
            }
        }
        break;
        case 2: {
            if (check_credentials("Lessee_credentials.txt", username, password)) {
                if (lessees.find(username) == lessees.end()) {
                    lessees[username] = make_unique<Lessee>();
                }
                if (!readUserDetailsFromFile("Lessees.txt", username, *lessees[username])) {
                    // New lessee, will enter details later
                }
                logged_in();
                Lessee_loggedin(username);
            } else {
                cout << "Not registered or incorrect credentials.\n";
                cout << "Try again" << endl;
                Sleep(2000);
                system("cls");
                LoginOrSignup();
            }
        }
        break;
    }
}

void Signup() {
    int choice;
    string username, password;
    signup_page();
    cin >> choice;
    cout << "Create Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;
    switch (choice) {
        case 1 :{   
            ofstream fout("Owner_credentials.txt", ios::app);
            fout << username << "\t" << password << endl;
            fout.close();
            signedup();
        }
        break;
        case 2 :{   
            ofstream fout("Lessee_credentials.txt", ios::app);
            fout << username << "\t" << password << endl;
            fout.close();
            signedup();
        }
        break;
    }
}

void LoginOrSignup() {
    int loschoice;
    do {
        LOS();
        cin >> loschoice;
        system("cls");
        switch(loschoice) {
            case 1: 
                Signup();
                break;
            case 2: 
                Login();
                break;
        }
    } while (loschoice < 3);
}

int main() {
    intro();
    LoginOrSignup();
    return 0;
}
