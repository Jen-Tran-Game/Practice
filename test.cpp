#include <iostream> 
#include <string> 
#include <fstream>
#include <iomanip> 

using namespace std; 

int main ()
{
    string username, password, inputUsername, inputPassword, storedPassword;
    vector <string> usernames; 
    vector <string> passwords;  
    int mode; 
    cout << "Press 0: Sign up" << endl << "Press 1: Log in " << endl; 
    cin >> mode; 
    if (mode == 0)
    {
        cout << "Create username: "; 
        cin >> username;
        fstream write_usr_pw ("Users.txt", fstream::out );
        write_usr_pw << "Username: " << username; 
        write_usr_pw.close(); 

    }

}