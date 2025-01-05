#include <iostream> 
#include <string> 
#include <fstream>
#include <iomanip> 

using namespace std; 

int main ()
{
    string username, password, inputUsername, inputPassword, storedPassword; 
    int mode; 
    cout << "Press 1: Sign up \nPress 2: Log in" << endl; 
    cin >> mode; 
    fstream createFile ("users.json", fstream::out); 
    createFile << 
    createFile.close(); 
    if (mode == 1)
    {
        cout << "Create your username: ";
        cin >> username; 
        cout << "Your new password: "; 
        cin >> password; 
        fstream writeFile ("users.json", fstream::app)
        writeFile << "Username: " << username << endl; 
        writeFile << "Password: " << password << endl; 
        
    }
}