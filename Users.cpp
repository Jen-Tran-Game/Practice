#include <iostream> 
#include <string> 
#include <nlohmann/json.hpp> 
#include <fstream>

using json = nlohmann::json; 
using namespace std; 

int main ()
{
    string username; 
    string password; 
    int mode; 
    json j; 
    cout << "Press 0: Sign up " << endl << "Press 1: Log in ";
    cout << "Your option: "; 
    cin >> mode; 
    if (mode == 0)
    {
        cout << "Create username: "; 
        cin >> username; 
        cout << "New password: "; 
        cin >> password; 
        fstream write_usr_pw ("Users.json", fstream::out); 
        write_usr_pw << j; 
        write_usr_pw.close(); 
        cout << "Sign up successfully"; 
    }
    else
    {
        
    }

}