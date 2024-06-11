#include <iostream>
#include <windows.h>
using namespace std;

void intro(){
    system("cls");
    Sleep(200);
    cout<<endl<<endl;
    cout<<"                                            B";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                            BE";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                            BEL";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                            BELA";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                            BELAG";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                            BELAGA";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                            BELAGAV";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                            BELAGAVI"<<endl;
    cout<<"       _________    ____       ____  _______   ___________    __       _______  __________________________        "<<endl;
    cout<<"      / ____/   |  / __ \\     / __ \\/ ____/ | / /_  __/   |  / /      / ___/\\ \\/ / ___/_  __/ ____/  |/  /       "<<endl;
    cout<<"     / /   / /| | / /_/ /    / /_/ / __/ /  |/ / / / / /| | / /       \\__ \\  \\  /\\__ \\ / / / __/ / /|_/ /        "<<endl;
    cout<<"    / /___/ ___ |/ _, _/    / _, _/ /___/ /|  / / / / ___ |/ /___    ___/ /  / /___/ // / / /___/ /  / /         "<<endl;
    cout<<"    \\____/_/  |_/_/ |_|    /_/ |_/_____/_/ |_/ /_/ /_/  |_/_____/   /____/  /_//____//_/ /_____/_/  /_/          "<<endl;
                                                                        
    Sleep(2000);
    system("cls");
}
void title() {
    cout<<"                       -:  Belagavi Car Rental System  :-                "<<endl<<endl;
}
void LOS() {
    cout<<"                 -----------                        ----------    "<<endl;
    cout<<"                |1. Signup  |                      |2. Login  |    "<<endl;
    cout<<"                 -----------                        ----------   "<<endl;
    cout<<"                               Enter choice : ";
}
void signup_page(){
    cout<<endl;
    cout<<"                                 ----------"<<endl;
    cout<<"                                |  Signup  |"<<endl;
    cout<<"                                 ----------"<<endl;
    cout<<"                 ----------                        ----------    "<<endl;
    cout<<"                |1. Owner  |                      |2. Lessee |    "<<endl;
    cout<<"                 ----------                        ----------   "<<endl;
    cout<<"                                  Signup as : ";
}
void signedup() {
    cout<<"                            Signup Successful"<<endl;
    cout<<"                              Please Login"<<endl;
    Sleep(2000);
    system("cls");
}
void login_page(){
    cout<<endl;
    cout<<"                                 ---------"<<endl;
    cout<<"                                |  Login  |"<<endl;
    cout<<"                                 ---------"<<endl;
    cout<<"                 ----------                        ----------    "<<endl;
    cout<<"                |1. Owner  |                      |2. Lessee |    "<<endl;
    cout<<"                 ----------                        ----------   "<<endl;
    cout<<"                                  Login as : ";
}
void logged_in(const string& username) {
    system("cls");
    cout<<endl<<"                                     Login Successful"<<endl;;
    cout<<"                                      Welcome "<<username<<endl;
    Sleep(2000);
    system("cls");
}

void Loading() {
    string loadChars = "|/-\\";
    int numCycles = 5; // Number of cycles for the loading animation
    int delay = 100;    // Delay in milliseconds between each frame

    for (int cycle = 0; cycle < numCycles; ++cycle) {
        for (char c : loadChars) {
            cout << "\rLoading... " << c << flush; // '\r' moves the cursor to the beginning of the line
            Sleep(delay);
        }
    }
    cout << "\rLoading... Done!   " << endl; // Clear the loading line after completion
    Sleep(500);
    system("cls");
}

void Clear() {
    Sleep(2000);
    system("cls");
}