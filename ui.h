#include <iostream>
#include <windows.h>
using namespace std;

void intro(){
    system("cls");
    Sleep(200);
    cout<<endl<<endl;
    cout<<"                                 W";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                 WE";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                 WEL";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                 WELC";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                 WELCO";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                 WELCOM";
    Sleep(200);
    system("cls");
    cout<<endl<<endl;
    cout<<"                                 WELCOME"<<endl;
    // cout<<"       _________    ____       ____  _______   ___________    __       _______  __________________________        "<<endl;
    // cout<<"      / ____/   |  / __ \     / __ \/ ____/ | / /_  __/   |  / /      / ___/\ \/ / ___/_  __/ ____/  |/  /       "<<endl;
    // cout<<"     / /   / /| | / /_/ /    / /_/ / __/ /  |/ / / / / /| | / /       \__ \  \  /\__ \ / / / __/ / /|_/ /        "<<endl;
    // cout<<"    / /___/ ___ |/ _, _/    / _, _/ /___/ /|  / / / / ___ |/ /___    ___/ /  / /___/ // / / /___/ /  / /         "<<endl;
    // cout<<"    \____/_/  |_/_/ |_|    /_/ |_/_____/_/ |_/ /_/ /_/  |_/_____/   /____/  /_//____//_/ /_____/_/  /_/          "<<endl;
                                                                             
    Sleep(2000);
    system("cls");
}
void LOS() {
    cout<<"                 -----------                        ----------    "<<endl;
    cout<<"                |1. Signup  |                      |2. Login  |    "<<endl;
    cout<<"                 -----------                        ----------   "<<endl;
    cout<<"                               Enter choice : ";
}
void signup_page(){
    cout<<endl<<endl;
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
    cout<<endl<<endl;
    cout<<"                                 ---------"<<endl;
    cout<<"                                |  Login  |"<<endl;
    cout<<"                                 ---------"<<endl;
    cout<<"                 ----------                        ----------    "<<endl;
    cout<<"                |1. Owner  |                      |2. Lessee |    "<<endl;
    cout<<"                 ----------                        ----------   "<<endl;
    cout<<"                                  Login as : ";
}
void logged_in() {
    cout<<"                            Login Successful"<<endl;
    Sleep(2000);
    system("cls");
}