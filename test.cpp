#include <iostream> 
#include <string> 
#include <fstream>
#include <iomanip> 

using namespace std; 

int main ()
{
    string username, password, inputUsername, inputPassword, storedPassword; 
    int mode; 
    cout << "Press 0: Sign up" << endl << "Press 1: Log in " << endl; 
    cin >> mode; 
    fstream write_usr_pw ("Users.txt", fstream::out); 
    write_usr_pw.close();
    if (mode == 0)
    {
        cout << "Create username: "; 
        cin >> username; 

    }

}