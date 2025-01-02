#include <iostream> 
#include <string> 
#include <nlohmann/json.hpp> 
#include <fstream>
#include <iomanip>  

using json = nlohmann::json; 
using namespace std; 

int main ()
{
    string username, password, inputUsername, inputPassword, storedPassword;     
    int mode; 
    json j; 
    cout << "Press 0: Sign up " << endl << "Press 1: Log in ";
    cout << "Your option: "; 
    cin >> mode; 
    fstream write_usr_pw ("users.json", fstream::out); 
    write_usr_pw << j; 
    write_usr_pw.close(); 
    j["users"] = json::array();
    if (mode == 0)
    {
        cout << "Create username: "; 
        cin >> username; 

        bool usernameTaken = false; 
        for (const auto &user : j["users"])
        {
            if (users["username"] == username)
            {
                usernameTaken = true; 
                break; 
            }
        }
        if (usernameTaken)
        {
            cout << "Username already taken. Please choose another username"; 
            return 1; 
        }
        cout << "Create password: "; 
        cin >> password; 

        j["users"].push_back({{"username", username}, {"password", password}});
        fstream read_usr_pw ("users.json", fstream::in); 
        read_usr_pw << setw(4) << j << endl; 
        cout << "Sign up successfully" << endl; 
    }
    else if (mode == 1)
    {
        cout << "Enter your username: "; 
        cin >> inputUsername;

        bool userFound = false; 
        for (const auto &user : j["users"])
        {
            if (users["username"] == inputUsername)
            {
                storedPassword == users["password"];
                userFound = true; 
                break; 
            }
        }

        if (!userFound)
        {
            cout << "Username not found" << endl; 
            return 1; 
        }

        bool loggedIn = false; 
        while (!loggedIn)
        {
            cout << "Enter your password: "; 
            cin >> inputPassword; 
            
            if (inputPassword == storedPassword)
            {
                cout << "Login successfully" << endl; 
                loggedIn = true; 
            }
            else 
            {
                cout << "Unthorized. Please try again" << endl; 
            }
        }
    }
    else
    {
        cout << "Invalid option selected" << endl; 
    }

    return 0;
}