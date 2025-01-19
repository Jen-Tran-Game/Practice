#include <iostream> 
#include <string> 
#include <fstream>
#include <iomanip> 
#include "json.hpp"

using namespace std;
using json = nlohmann::json;  

int main()
{
    int mode; 
    string password;  
    string inputPassword; 
    cout << "Press 1: Register \nPress 2: Log in" << endl;
    cout << "Enter your choice: "; 
    cin >> mode; 
    if (mode == 1)
    {   
        cout << "Enter your new password: "; 
        cin >> password; 
        fstream createPW ("test.txt", fstream::out); 
        createPW << password; 
        createPW.close(); 
    } 
    else if (mode == 2)
    {
        cout << "Enter your password to log in: "; 
        cin >> inputPassword; 
        string storedPassword; 
        fstream checkPW ("test.txt", fstream::in);
        getline (checkPW, storedPassword); 
        checkPW.close(); 
        while (inputPassword != storedPassword)
        {
            cout << "Your password is wrong" << endl; 
            cout << "Please try again: "; 
            cin >> inputPassword;
        }
        cout << "Log in successfully!"; 
    }
}